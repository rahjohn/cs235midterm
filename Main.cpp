/* Rachel Johnson
 * CS 235 Fall 2016 Midterm
 */
#include <iostream>
#include "RedRover.h"
#include <sstream>
#include <iostream>
#include <fstream>

using namespace std;

void inputPlayers(RedRover * redRover){
    string txt;
    string input;
    stringstream ss;
    ifstream file("test.txt");
    if (file.is_open())
        while (file.good())
        {
            getline(file, txt);
            ss << txt << " ";
        }
    file.close();
    input = ss.str();
    if(redRover->addToRoster(input)) {
        cout << redRover->getRoster() << endl;
        redRover->createTeams();
        redRover->sendSomeoneOver(redRover->teamAAt(2), redRover->teamBAt(2));
    } else {
        cout << "something didn't work" << endl;
    }
}

int main(){
    RedRover * redRover = new RedRover();
    inputPlayers(redRover);
    return 0;
}
