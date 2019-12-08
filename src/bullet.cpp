//
//  bullet.cpp
//  fantastic-finale-danniely
//
//  Created by user on 11/19/19.
//

#include "bullet.hpp"
#include <iostream>

bullet::bullet(){
    bullet_x = 0;
    bullet_y = 0;
    direc_x = 0;
    direc_y = 0;
    rotate_ang = 0;
    total_direc = 0;
    bullet_.load("bullet4.png");
    bullet_.resize(30,30);
    is_exist = '1';
}

bullet::bullet(float x, float y, float dir_x, float dir_y, float angle){
    bullet_x = x;
    bullet_y = y;
    direc_x = dir_x;
    direc_y = dir_y;
    rotate_ang = angle;
    bullet_.load("bullet4.png");
    bullet_.resize(30,30);
    total_direc = sqrt(pow(direc_x,2)+pow(direc_y,2));
    is_exist = '1';
}

bullet::~bullet() {}

void bullet::setup(float x, float y, float dir_x, float dir_y, float angle){
    bullet_x = x;
    bullet_y = y;
    direc_x = dir_x;
    direc_y = dir_y;
    if(direc_x < 0.01){
        direc_x = 0;
    }
    if(direc_y < 0.01){
        direc_y = 0;
    }
    rotate_ang = angle;
    bullet_.load("bullet4.png");
    bullet_.resize(30,30);
    total_direc = sqrt(pow(direc_x,2)+pow(direc_y,2));
    is_exist = '1';
}

void bullet::draw(){
        update();
        ofPushMatrix();
        ofTranslate(bullet_x,bullet_y);
        ofRotateDeg(rotate_ang+180);
        bullet_.setAnchorPoint(bullet_.getWidth()/2, bullet_.getHeight()/2);
        bullet_.draw(0,0);
        ofPopMatrix();
}

void bullet::update(){
    if(total_direc == 0){
        
    }else{
        bullet_x +=  direc_x/total_direc*bulletSpeed;
        bullet_y +=  direc_y/total_direc*bulletSpeed;
    }
}
