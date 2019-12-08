//
//  bullet.hpp
//  fantastic-finale-danniely
//
//  Created by user on 11/19/19.
//

#ifndef bullet_hpp
#define bullet_hpp

#include <stdio.h>
#include "ofMain.h"
#include <iostream>
#include <math.h>

class bullet{
public:
    bullet();
    bullet(float x, float y, float dir_x, float dir_y, float angle);
    ~bullet();
    
    void setup(float x, float y, float dir_x, float dir_y, float angle);
    void update();
    void draw();
    void initialize();
    bool maxDistanceReached();
    float getDistance();
    float fireDist;
    float lifeTime;
    ofImage bullet_;
    float bullet_x, bullet_y;
    float direc_x, direc_y;
    float bulletSpeed = 8;
    float rotate_ang;
    double total_direc;
    char is_exist = '0';
};
#endif /* bullet_hpp */
