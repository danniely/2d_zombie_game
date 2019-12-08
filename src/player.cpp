//
//  player.cpp
//  fantastic-finale-danniely
//
//  Created by user on 11/18/19.
//

#include "player.hpp"
#include <iostream>
#include <math.h>

//--------------------------------------------------------------
void player::setup(){
    moveSpeed = 3.0;
    diagMoveSpeed = sqrtf(powf(moveSpeed, 2)/2 -1);
    
}

//--------------------------------------------------------------
void player::update(){

}

//--------------------------------------------------------------
void player::draw(){
//    ofPushMatrix();
//    ofTranslate(posX, posY);
//    ofRotateDeg(rotateAngle + 90);
//    player_image.setAnchorPoint(player_image.getWidth()/2, player_image.getHeight()/2);
//    player_image.draw(0, 0);
//    ofPopMatrix();
}

//--------------------------------------------------------------
void player::keyPressed(int key){

}

//--------------------------------------------------------------
void player::keyReleased(int key){

}

//--------------------------------------------------------------
void player::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void player::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void player::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void player::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void player::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void player::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void player::windowResized(int w, int h){

}

//-------------------------------------------------------------
