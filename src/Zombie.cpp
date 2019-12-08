//
//  Zombie.cpp
//  fantastic-finale-danniely
//
//  Created by user on 11/20/19.
//

#include "Zombie.hpp"
#include <math.h>

Zombie::Zombie(){
    posX = 0;
    posY = 0;
    target_x = 0;
    target_y = 0;
}
Zombie::Zombie(float x, float y, float player_x, float player_y){
    
    posX = x;
    posY = y;
    target_x = player_x;
    target_y = player_y;
    zombie_image.load("zombie.png");
    zombie_image.resize(40,40);
    blood_splatter.load("blood.png");
    blood_splatter.resize(50,50);
    
    distance_x = target_x - posX;
    distance_y = target_y - posY;
    direct = atan(distance_x/distance_y);
    total_distance = sqrt(pow(distance_x,2)+pow(distance_y,2));
    moveSpeed = 1.0;
    
}

Zombie::~Zombie(){};

//--------------------------------------------------------------
void Zombie::setup(float x, float y, float player_x, float player_y){
    posX = x;
    posY = y;
    target_x = player_x;
    target_y = player_y;
    zombie_image.load("zombie.png");
    zombie_image.resize(40,40);
    blood_splatter.load("blood.png");
    blood_splatter.resize(50,50);
    
    distance_x = target_x - posX;
    distance_y = target_y - posY;
    direct = atan2(distance_x,distance_y);
    total_distance = sqrt(pow(distance_x,2)+pow(distance_y,2));
    moveSpeed = 1.0;
}

//--------------------------------------------------------------
void Zombie::update(float player_x, float player_y){
    target_x = player_x;
    target_y = player_y;
    distance_x = target_x - posX;
    distance_y = target_y - posY;
    
    direct = -atan2(distance_x,distance_y);
    total_distance = sqrt(pow(distance_x,2)+pow(distance_y,2));
    posX +=  distance_x/total_distance*moveSpeed;
    posY +=  distance_y/total_distance*moveSpeed;
}

//--------------------------------------------------------------
void Zombie::draw(){
    
    ofPushMatrix();
    ofTranslate(posX,posY);
    ofRotateDeg(direct*180/PI - 180);
    zombie_image.setAnchorPoint(zombie_image.getWidth()/2, zombie_image.getHeight()/2);
    zombie_image.draw(0, 0);
    ofPopMatrix();

}

void Zombie::blood(){
    ofPushMatrix();
    ofTranslate(posX,posY);
    ofRotateDeg(direct*180/PI - 180);
    blood_splatter.setAnchorPoint(blood_splatter.getWidth()/2, blood_splatter.getHeight()/2);
    blood_splatter.draw(0,0);
    ofPopMatrix();
}

//--------------------------------------------------------------
void Zombie::keyPressed(int key){

}

//--------------------------------------------------------------
void Zombie::keyReleased(int key){

}

//--------------------------------------------------------------
void Zombie::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void Zombie::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void Zombie::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void Zombie::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void Zombie::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void Zombie::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void Zombie::windowResized(int w, int h){

}

//-------------------------------------------------------------
