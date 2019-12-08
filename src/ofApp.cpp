#include "ofApp.h"
#include "bullet.hpp"
#include "Zombie.hpp"
#include <math.h>
#include <vector>
#include <iostream>
#include <type_traits>
#include <optional>
#include <string>

float x,y;

//--------------------------------------------------------------
void ofApp::setup(){
    
    x = ofGetWidth()/2;
    y = ofGetHeight()/2;
    
    x_lb = 0;
    x_ub = ofGetWidth();
    y_lb = 0;
    y_ub = ofGetHeight();
    
    player_image.load("player2.png");
    player_image.resize(40, 40);
    
    bullet_image.load("bullet4.png");
    bullet_image.resize(30,30);
    
    game_state = "start";
    int score = 0;
    player_1.setup();
    
    gunshot.load("gunshot.mp3");
    zombie_die.load("zombie_die.mp3");
    player_hurt.load("player_hurt.mp3");
    stage_cleared.load("stage_cleared.mp3");
    
}
//--------------------------------------------------------------
void ofApp::positionButtons()
{
    map_sand.load("sand.jpg");
    map_sand.resize(100, 100);
    map_snow.load("snow.jpg");
    map_snow.resize(100, 100);
    map_forest.load("forest.png");
    map_forest.resize(100, 100);
    
    map_sand.draw(ofGetWidth()/2 - 120, ofGetHeight()/2);
    map_snow.draw(ofGetWidth()/2, ofGetHeight()/2);
    map_forest.draw(ofGetWidth()/2 + 120, ofGetHeight()/2);
    

}
//--------------------------------------------------------------
void ofApp::update(){
    if(game_state == "game"){
        
        player_1.posX = x;
        player_1.posY = y;
        xDistance = (mouse_x - x);
        yDistance = (mouse_y - y);
        
        rotateAngle = atan2(yDistance, xDistance) * 180 / PI;
        std::string current_hp = std::to_string(player_1.hp);
        std::string stage = std::to_string(current_stage);
        
        ofDrawBitmapString("current_stage: " + stage,ofGetWidth()/2,10);
        ofDrawBitmapString("Hp: " + current_hp,100,100);
        
        stage_change();
        zombie_spawn();
        zombie_update(x, y);
        updateBullets();
        collide();
        zombie_count++;
        
        
        if(player_1.hp < 1){
            game_state = "end";
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofDrawCircle(mouse_x, mouse_y, mouse_size);
    if(game_state == "start"){
    
        ofDrawBitmapString("Choose a map to start", ofGetWidth()/2, ofGetHeight()/2-30);
        myFont.drawString("Choose a map to start.", ofGetWidth()/2,ofGetHeight()/2 - 30);
        
        positionButtons();

        
    }else if(game_state == "game"){
        
        bg_image.draw(0,0);
        if(playerUp == true){
            if(playerLeft == true){
                x = x - player_1.diagMoveSpeed;
                y = y - player_1.diagMoveSpeed;
            }else if(playerRight == true){
                x = x + player_1.diagMoveSpeed;
                y = y - player_1.diagMoveSpeed;
            }else y = y - player_1.moveSpeed;
        }
        if(playerDown == true){
            if(playerLeft == true){
                x = x - player_1.diagMoveSpeed;
                y = y + player_1.diagMoveSpeed;
            }else if(playerRight == true){
                x = x + player_1.diagMoveSpeed;
                y = y + player_1.diagMoveSpeed;
            }else y = y + player_1.moveSpeed;
        }
        if(playerLeft == true){
            if(playerDown == true){
                x = x - player_1.diagMoveSpeed;
                y = y + player_1.diagMoveSpeed;
            }else if(playerUp == true){
                x = x - player_1.diagMoveSpeed;
                y = y - player_1.diagMoveSpeed;
            }else x = x - player_1.moveSpeed;
        }
        if(playerRight == true){
            if(playerDown == true){
                x = x + player_1.diagMoveSpeed;
                y = y + player_1.diagMoveSpeed;
            }else if(playerUp == true){
                x = x + player_1.diagMoveSpeed;
                y = y - player_1.diagMoveSpeed;
            }else x = x + player_1.moveSpeed;
        }
        
        ofPushMatrix();
        ofTranslate(x,y);
        ofRotateDeg(rotateAngle + 90);
        player_image.setAnchorPoint(player_image.getWidth()/2, player_image.getHeight()/2);
        player_image.draw(0, 0);
        ofPopMatrix();
        
        zombie_draw();
  
        if(fire == true){
            if(count == 4){
                bullet *tempBullet = new bullet(player_1.posX, player_1.posY, xDistance, yDistance, rotateAngle);
                bullets.push_back(tempBullet);
                count = 0;
                
                gunshot.play();
            }else count++;
        }
        
        drawBullets();
        update();
        
    }else if(game_state == "end"){
        ofDrawBitmapString("Gameover", ofGetWidth()/2, ofGetHeight()/2);
    }else if(game_state == "cleared"){
        ofDrawBitmapString("Congradulation! You made it.", ofGetWidth()/2, ofGetHeight()/2);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == OF_KEY_F12) {
        ofToggleFullscreen();
        bg_image.resize(ofGetWidth(),ofGetHeight());
        return;
    }
    
    int upper_key = toupper(key);
    
    if(upper_key == 'W'){
        playerUp = true;
    }
    if(upper_key == 'S'){
        playerDown = true;
    }
    if(upper_key == 'A'){
        playerLeft = true;
    }
    if(upper_key == 'D'){
        playerRight = true;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if(game_state == "start"){
//        if(key == ' '){
//            game_state = "game";
//        }
    }
    else if(game_state == "game"){
        int upper_key = toupper(key);
        
        if(upper_key == 'W'){
            playerUp = false;
        }
        if(upper_key == 'S'){
            playerDown = false;
        }
        if(upper_key == 'A'){
            playerLeft = false;
        }
        if(upper_key == 'D'){
            playerRight = false;
        }
    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
    mouse_x = x;
    mouse_y = y;
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    mouse_x = x;
    mouse_y = y;
    if(game_state == "game"){
        if(button == 0){
            fire = true;
        }
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    mouse_x = x;
    mouse_y = y;
    
    if(game_state == "game"){
        if(button == 0){
            fire = true;
        }
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    if(game_state == "start"){
        if(button == 0){
            float z = ofGetWidth()/2;
            if(y > ofGetHeight()/2 && y < ofGetHeight()/2 + 100){
        
                if(x > ofGetWidth()/2 - 120 && x < ofGetWidth()/2 - 20){
                    bg_image.load("sand.jpg");
                    bg_image.resize(ofGetWidth(),ofGetHeight());
                    game_state = "game";
                }else if(x > ofGetWidth()/2 && x < ofGetWidth()/2 + 100){
                    bg_image.load("snow.jpg");
                    bg_image.resize(ofGetWidth(),ofGetHeight());
                    game_state = "game";
                }else if(x > ofGetWidth()/2 + 120 && x < ofGetWidth()/2 + 220){
                    bg_image.load("forest.png");
                    bg_image.resize(ofGetWidth(),ofGetHeight());
                    game_state = "game";
                    
                }
            }
        }
    }
    else if(game_state == "game"){
        if(button == 0){
            fire = false;
        }
    }
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

//--------------------------------------------------------------
void ofApp::drawBullets(){
//    if(bullets.size() != 0){
//        for(bullet * singleBullet : bullets){
//            singleBullet->draw();
//        }
//    }
    auto it = bullets.begin();
    while(it != bullets.end()){
        (*it)->draw();
        it++;
    }
}

void ofApp::updateBullets(){
    if(!bullets.empty()){
        for(bullet *singlebullet : bullets){
            if(singlebullet == nullptr){
                continue;
            }
            singlebullet->update();
        }
    }
}
//-------------------------------------------------------------------
bool ofApp::outOfBounds(bullet singleBullet){
    if(singleBullet.bullet_x < 0 || singleBullet.bullet_y > 900 || singleBullet.bullet_x > 1300 || singleBullet.bullet_y < 0 ){
        return true;
    } else return false;
}
//-------------------------------------------------------------------
void ofApp::collide(){
    bool isBulletsLeft;
    bool iterator_erased;
    bool class_empty;
    
    auto i = bullets.begin();
    while(i != bullets.end()){
        if(bullets.size() == 1){
            isBulletsLeft = false;
        }else isBulletsLeft = true;
        
        iterator_erased = false;
        
        while(*i == nullptr){
            i = i + 1;
        }
        
        if(i == bullets.end()){
            break;
        }
    
        if(outOfBounds(*(*i)) == true){
            i = bullets.erase(i);
        }
        
        for(auto zombie_it = zombie_vector.begin(); zombie_it != zombie_vector.end(); zombie_it++){
            if(i == bullets.end()){
                isBulletsLeft = false;
                break;
            }
            float dx = zombie_it->posX - (*i)->bullet_x;
            float dy = zombie_it->posY - (*i)->bullet_y;
            float distance = sqrtf(pow(dx, 2) + pow(dy, 2));
        
            if(distance < 30){
                zombie_it->blood();
                zombie_it->hp += -2;
                i = bullets.erase(i);
                iterator_erased = true;
            }
        }
        if(isBulletsLeft == false){
            break;
        }else if(iterator_erased == false) i++;
    }
}
//-------------------------------------------------------------------
void ofApp::zombie_spawn(){
    if(zombie_count > zombie_spawn_limit){
        
    }
    else if(zombie_count % 100 == 0){
        Zombie zombie;
        zombie.setup(0,ofGetHeight()/2, x, y);
        if(current_stage == 2){
            zombie.moveSpeed = 2.0;
        }else if(current_stage == 3){
            zombie.moveSpeed = 3.0;
        }
        zombie_vector.push_back(zombie);
    }
}
//-------------------------------------------------------------------
void ofApp::zombie_update(float player_x, float player_y){

    auto it = zombie_vector.begin();
    
    while(it != zombie_vector.end()){
        
        float player_hit_x = it->posX - x;
        float player_hit_y = it->posY - y;
        float distance_zombie = sqrtf(pow(player_hit_x, 2) + pow(player_hit_y, 2));
        
        if(distance_zombie < 30){
            player_hit_count += 1;
            if(player_hit_count == 6){
                player_hurt.play();
                player_1.hp -= 1;
                player_hit_count = 0;
            }
        }
        
        if(it->hp == 0){
            zombie_die.play();
            it = zombie_vector.erase(it);
        }else{
            it->update(player_x, player_y);
            it++;
        }
    }
}
//-------------------------------------------------------------------
void ofApp::zombie_draw(){
    for(Zombie zombie : zombie_vector){
        zombie.draw();
    }
}
//-------------------------------------------------------------------
void ofApp::stage_change(){
    if(zombie_count >= 2200){
        if(zombie_vector.size() == 0){
            if(current_stage == 1){
                current_stage = 2;
                zombie_count = 0;
                zombie_spawn_limit = 1400;
            }else if(current_stage == 2){
                current_stage = 3;
                zombie_count = 0;
                zombie_spawn_limit = 2100;
            }else if(current_stage == 3){
                game_state = "cleared";
            }
            stage_cleared.play();
        }
    }
}
