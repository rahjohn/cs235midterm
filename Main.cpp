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
    //getline(cin, input);
    if(redRover->addToRoster(input)) {
        cout << redRover->getRosterSize() << endl;
        cout << redRover->getRoster() << endl;
        redRover->createTeams();
        cout << redRover->getRosterSize() << endl;
        cout << redRover->getRoster() << endl;
        cout << redRover->getTeamA() << endl;
        cout << redRover->getTeamASize() << endl;
        cout << redRover->getTeamB() << endl;
        cout << redRover->getTeamBSize() << endl;
    } else {
        cout << "something didn't work" << endl;
    }
}

int main(){
    RedRover * redRover = new RedRover();
    inputPlayers(redRover);
    return 0;
}
