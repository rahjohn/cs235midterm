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
    if(redRover->addToRoster(input)) {
        cout << redRover->getRosterSize() << endl;
        cout << redRover->getRoster() << endl;
    } else {
        cout << "something didn't work" << endl;
    }
    getline(cin, input);
    if(redRover->addToRoster(input)) {
        cout << redRover->getRosterSize() << endl;
        cout << redRover->getRoster() << endl;
    } else {
        cout << "something didn't work" << endl;
    }
}

int main(){
    RedRover * redRover = new RedRover();
    inputPlayers(redRover);
    return 0;
}
