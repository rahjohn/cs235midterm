/* Rachel Johnson
 * CS 235 Fall 2016 Midterm
 */
#ifndef doubleLinkedList_h
#define doubleLinkedList_h
#include "PlayerInterface.h"

class Player : public PlayerInterface {
public:
    Player();
    virtual ~Player();
    virtual string getName();
    virtual int getStrength();
    virtual int getSpeed();
};

#endif
