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
    cout << input << endl;
    if(redRover->addToRoster(input)) {
        cout << redRover->getRosterSize() << endl;
        cout << redRover->getRoster() << endl;
        redRover->shuffleRoster();
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
