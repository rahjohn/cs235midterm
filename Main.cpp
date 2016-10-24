/* Rachel Johnson
 * CS 235 Fall 2016 Midterm
 */
#include <iostream>
#include "RedRover.h"
#include <sstream>
#include <iostream>

using namespace std;

void inputPlayers(RedRover * redRover){
    string input;
    getline(cin, input);
    redRover->addToRoster(input);
}

void display(RedRover * redRover){
    redRover->getRosterSize();
}

int main(){
    RedRover * redRover = new RedRover();
    inputPlayers(redRover);
    display(redRover);
    return 0;
}
