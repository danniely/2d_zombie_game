#pragma once

#include "ofMain.h"
#include "player.hpp"
#include "bullet.hpp"
#include "Zombie.hpp"
#include <iostream>
#include <vector>
#include <map>
#include <optional>
#include "ofxDatGui.h"

class ofApp : public ofBaseApp{
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
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    void drawBullets();
    void updateBullets();
    bool outOfBounds(bullet singleBullet);
    void collide();
    void zombie_spawn();
    void zombie_update(float, float);
    void zombie_draw();
    void onButtonEvent(ofxDatGuiButtonEvent);
    void positionButtons();
    void stage_change();
    
    player player_1;
    Zombie *zombie_1 = new Zombie();
    bullet *bullet_1 = new bullet();
    ofImage player_image;
    ofImage bg_image;
    ofImage bullet_image;
    
    ofImage zombie_image;
    string game_state;
    ofSoundPlayer gunshot;
    ofSoundPlayer zombie_die;
    ofSoundPlayer player_hurt;
    ofSoundPlayer stage_cleared;
    
    std::deque<bullet*> bullets;
    std::deque<std::deque<bullet*>::iterator> bullets_iterator;
    
    std::deque<Zombie> zombie_vector;
    int NumOfZombies;
    
    float moveSpeed;
    int score;
    bool playerUp, playerDown, playerLeft, playerRight;
    float x_lb, x_ub, y_lb, y_ub;
    float mouse_x, mouse_y;
    int mouse_size = 5;
    float xDistance, yDistance;
    float rotateAngle;
    float temp;
    bool fire;
    int count = 0;
    int zombie_count = 0;
    int player_hit_count = 0;
    int zombie_spawn_limit = 700;
    int current_stage = 1;
    ofImage map_sand;
    ofImage map_snow;
    ofImage map_forest;    
    ofTrueTypeFont myFont;
};

