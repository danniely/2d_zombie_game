//
//  player.hpp
//  fantastic-finale-danniely
//
//  Created by user on 11/18/19.
//

#ifndef player_hpp
#define player_hpp

#include <stdio.h>
#include <iostream>

class player{
    public:
        void setup();
        void update();
        void draw();
        
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
    int hp = 100;
    
};

#endif /* player_hpp */
