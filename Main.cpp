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
        redRover->shuffleRoster();
        redRover->createTeams();
        cout << redRover->getRoster() << endl;
        cout << redRover->getTeamA() << endl;
        cout << redRover->getTeamB() << endl;
        //redRover->sendSomeoneOver(NULL, NULL);
        redRover->autoPlay();
    } else {
        cout << "something didn't work" << endl;
    }
}

int main(){
    RedRover * redRover = new RedRover();
    inputPlayers(redRover);
    return 0;
}
