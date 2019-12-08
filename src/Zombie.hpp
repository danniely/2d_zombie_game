//
//  Zombie.hpp
//  fantastic-finale-danniely
//
//  Created by user on 11/20/19.
//

#ifndef Zombie_hpp
#define Zombie_hpp

#include <stdio.h>
#include <iostream>
#include "ofMain.h"
#include <math.h>

class Zombie{
    public:
    Zombie();
    Zombie(float x, float y, float player_x, float player_y);
    ~Zombie();
        void setup(float x, float y, float player_x, float player_y);
        void update(float player_x, float player_y);
        void draw();
    void blood();
        
        void keyPressed(int key);
        void keyReleased(int key);
        void mouseMoved(int x, int y);
        void mouseDragged(int x, int y, int button);
        void mousePressed(int x, int y, int button);
        void mouseReleased(int x, int y, int button);
        void mouseEntered(int x, int y);
        void mouseExited(int x, int y);
        void windowResized(int w, int h);
        
    float posX, posY;
    float moveSpeed, diagMoveSpeed;
    ofImage zombie_image;
    ofImage blood_splatter;
    float target_x, target_y;
    bool isCaught = false;
    float distance_x, distance_y, total_distance;
    float direct;
    int hp = 10;
    
};

#endif /* Zombie_hpp */
