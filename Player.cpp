/* Rachel Johnson
 * CS 235 Fall 2016 Midterm
 */
#include "Player.h"
#include "doubleLinkedList.h"
#include <sstream>

Player::Player(string name, int strength, int speed){
    this->name = name;
    this->strength = strength;
    this->speed = speed;
}
Player::~Player(){}

/*
* getName()
*
* returns the name of the player
*/
string Player::getName(){
    return name;
}

/*
*getStrength()
*
*returns the strength of the player
*/
int Player::getStrength() {
    return strength;
}

/*
*getSpeed()
*
*returns the speed of the player
*/
int Player::getSpeed() {
    return speed;
}