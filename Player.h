/* Rachel Johnson
 * CS 235 Fall 2016 Midterm
 */
#ifndef PLAYER_H
#define PLAYER_H
#include "PlayerInterface.h"
#include "doubleLinkedList.h"

class Player : public PlayerInterface {
public:
    Player(string name, string strength, string speed);
    virtual ~Player();
    virtual string getName();
    virtual int getStrength();
    virtual int getSpeed();
private:
    string name;
    int strength;
    int speed;
};


#endif
