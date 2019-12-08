Week 1 (11/14 - 11/19):
I changed the topic of my final project, from bank transaction app to zombie defense game. I have set up the default methods in ofApp.cpp. Week 1's goal was to implement basic movement of a character and ability to rotate followed by the mouse pointer. Beside, basic background of the game map was set to 'sand.jpg'. Since openframeworks renders(or refreshes) the movement once at a time, movement has to be based on the boolean, not the actual input key itself. So when the player press certain keys, it should make that specific direction boolean to true, which allows the player to keep move smoothly. It makes it false only if the key is released.

Week 2 (11/20 - 11/26):
Basic movement was implemented. So I created other classes such as Zombie.cpp and player.cpp to see if the programme can handle more than one objects' movements. Zombie image was loaded. Zombie's movement was implemented such that it could track a player's movement and follows. Also, a player speed and zombie speed were adjusted; always player faster than zombie.

Week 3 (11/27 - 12/3):
For week 3, spent most of the time implementing bullet.cpp. I had two options to whether make bullets 'hitscan' or 'projectile'. Since I have experienced both type of bullet motions often while playing other games, I thought of making those 'projectile' would make the game more fun and adequate. Hard part was to come up with a method to store all the bullets & shoot at the same time. Eventually, I used std::deque to implement this.
Besides, I have fixed an issue of openframeworks rotating images at the left top corner. I fixed this using setAnchorPoint(). 

Week 4 (12/4 - 12/11):
In week 4, I have implemented collision part. There should be total 2 types of collision; between bullets and zomies and between zombies and the player. I have set a boundary from the center of the objects, and once other objects comes within the raduis, it detects a collision. I set the hp of zombies and the player, so once their hp hits 0, they die. If the player dies, game is over. Sound effect was added as well. When zombies are hit by a bullet, it makes a zombie sound. When player shoots, it makes a gun shoot sound. When the player is hit, it makes a pain sound.
Another part was the stage part. There are total 3 stages, and you can only go to the next stage once you eliminate all the zombies on the board. Once you are done, you can go to the next stage. After stage 3, there pops an message saying congradulation. 
When the program is run, there is a starting screen which allows you to choose the map; sand, snow and forest. 
