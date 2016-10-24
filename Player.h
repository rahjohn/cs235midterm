/* Rachel Johnson
 * CS 235 Fall 2016 Midterm
 */
#ifndef PLAYER_H
#define PLAYER_H
#include "PlayerInterface.h"
#include "DataStructure.h"

class Player : public PlayerInterface {
public:
    Player();
    virtual ~Player();
    virtual string getName();
    virtual int getStrength();
    virtual int getSpeed();
};

#endif
