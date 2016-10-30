/* Rachel Johnson
 * CS 235 Fall 2016 Midterm
 */
#include "RedRover.h"
#include <sstream>

RedRover::RedRover() {
    roster = new doubleLinkedList<Player *>();
    teamA = new doubleLinkedList<Player *>();
    teamB = new doubleLinkedList<Player *>();
}

RedRover::~RedRover() {
    rosterReset();
    teamReset();
}

/*
* addToRoster()
*
* Accepts a string containing the name, strength, and speed of several Players
* and adds those Players to the roster.
*
* The string will be of the format :
* 			"PlayerName0
* 			PlayerStrength0
* 			PlayerSpeed0
* 			PlayerName1
* 			PlayerStrength1
* 			..."
*
* and so on with no trailing endline.
*
* In the example above, Player0 would be the first entry in the roster followed by Player1 and any other Players.
*
* You may assume that the format of the string and the name, strength, and speed of each player will be valid.
*
* Returns true if players were added to the roster, false otherwise
 * This function will accept a string containing the names, strengths, and speeds of player who will
be participating in the game. You may create your own string for testing purposes, but the TAs will use
specific lists of players when grading your program. The string will contain a list of Players to be put on
the roster. The format of the string will look something like this, with one token on each line:
Jordan
25
12
MichaelP
15
20
…
The first integer following a Player's name is that Player's strength. The second integer is that
Player's speed. Using the information for each Player, create a new node and add it to the end of your
roster. If there is a previously existing roster, add the new Players to the end of the roster. You may
assume that the string format will be correct. You may NOT assume that a string will contain an even
number of players or that the string will not be empty. If an empty string is given, advise the user that
no players have been added to the roster. If the string contains information for one player, you should
add that player onto the end of the current roster. You may allow multiple players with the same name
to be placed in the roster.
*/
bool RedRover::addToRoster(string player_list) {
    bool added = true;
    string name, strength, speed;
    int intStrength, intSpeed;
    stringstream ss(player_list);
    int c = 1;
    string str = ss.str();
    int size = str.size();
    for (int i = 0; i < size; i++) {
        if (isspace(str[i])) {
            c++;
        }
    }
    //c -= 1;
    if (c % 3 == 0) {
        while (ss >> name && ss >> strength && ss >> speed) {
            if (ss.fail()) {
                return false;
            } else {
                intStrength = atoi(strength.c_str());
                intSpeed = atoi(speed.c_str());
                Player *player = new Player(name, intStrength, intSpeed);
                roster->insertTail(player);
            }
        }
    } else {
        cout << "No players have been added to the roster\n";
        return false;
    }
    return added;
}

/*
*getRosterSize()
*
* Returns the number of players in the roster.
*/
int RedRover::getRosterSize() {
    return roster->size();
}

/*
*getTeamASize()
*
* Returns the number of players on Team A.
*/
int RedRover::getTeamASize() {
    return teamA->size();
}

/*
* getTeamBSize()
*
* Returns the number of players on Team B.
*/
int RedRover::getTeamBSize() {
    return teamB->size();
}

/*
* getRoster()
*
* Returns a string representing the players currently in the roster.
* The returned string should be of the format
* 		"Player0 Player1 Player2 ..."
* Where Player0 is the Player located at index 0
*
* There should be no trailing space in the string returned
*
* Returns the string representation of the roster
*/
string RedRover::getRoster() {
    stringstream ss;
    int size = roster->size();
    if (size == 0) {
        return "Roster empty";
    }
    for (int i = 0; i < size; i++) {
        if (i == size - 1) { //if it is the last thing in the list don't add a space
            ss << roster->at(i)->getName();
        } else {
            ss << roster->at(i)->getName() << " ";
        }
    }
    return ss.str();
}

/*
* getTeamA()
*
* Returns a string representing the players currently on Team A.
* The returned string should be of the format
* 		"Player0 Player1 Player2 ..."
* Where Player0 is the Player located at index 0
*
* There should be no trailing space in the string returned
*
* Returns the string representation of Team A
*/
string RedRover::getTeamA() {
    stringstream ss;
    int size = teamA->size();
    if (size == 0) {
        return "Team A empty";
    }
    for (int i = 0; i < size; i++) {
        if (i == size - 1) { //if it is the last thing in the list don't add a space
            ss << teamA->at(i)->getName();
        } else {
            ss << teamA->at(i)->getName() << " ";
        }
    }
    return ss.str();
}

/*
* getTeamB()
*
* Returns a string representing the players currently on Team B.
* The returned string should be of the format
* 		"Player0 Player1 Player2 ..."
* Where Player0 is the Player located at index 0
*
* There should be no trailing space in the string returned
*
* Returns the string representation of Team B
*/
string RedRover::getTeamB() {
    stringstream ss;
    int size = teamB->size();
    if (size == 0) {
        return "Team B empty";
    }
    for (int i = 0; i < size; i++) {
        if (i == size - 1) { //if it is the last thing in the list don't add a space
            ss << teamB->at(i)->getName();
        } else {
            ss << teamB->at(i)->getName() << " ";
        }
    }
    return ss.str();
}

/*
* rosterAt()
*
* Returns a pointer to the player at the given index in the roster.
* Returns NULL if the index is out of range
*/
PlayerInterface *RedRover::rosterAt(int index) {
    if (index >= getRosterSize() || index < 0 || roster->at(0) == NULL) {
        return NULL;
    } else {
        return roster->at(index);
    }
}

/*
* teamAAt()
*
* Returns a pointer to the player at the given index in Team A.
* Returns NULL if the index is out of range
*/
PlayerInterface *RedRover::teamAAt(int index) {
    if (index >= getTeamASize() || index < 0 || teamA->at(0) == NULL) {
        return NULL;
    } else {
        return teamA->at(index);
    }
}

/*
* teamBAt()
*
* Returns a pointer to the player at the given index in Team B.
* Returns NULL if the index is out of range
*/
PlayerInterface *RedRover::teamBAt(int index) {
    if (index >= getTeamBSize() || index < 0 || teamB->at(0) == NULL) {
        return NULL;
    } else {
        return teamB->at(index);
    }
}

/*
* shuffleRoster()
*
* Shuffles the players in the roster
* Does not affect the players in Team A or Team B
 * This function will randomly shuffle the Players in your roster. Most students will find it
convenient to use the rand() function to implement their shuffle function. You will receive credit as long
as the list is mostly shuffled, but you will only receive half credit for simplistic shuffling like moving every
Player down one, reversing the order of the list, etc. This function will not affect the order of players
who are already in Team A or Team B. You must implement your own shuffle algorithm; do not use any
C++ library functions to shuffle your list.
*/
void RedRover::shuffleRoster() {
    if (roster->size() <= 1) { //you can't shuffle something that has nothing or only one thing
        return;
    } else {
        srand(time(NULL));
        int size = getRosterSize();
        for (int i = 0; i < size; i++) {
            int random = rand() % getRosterSize();
            if (random < 0 || random >= size) random = 0;
            string name = roster->at(random)->getName();
            int strength = roster->at(random)->getStrength();
            int speed = roster->at(random)->getSpeed();
            Player *player = new Player(name, strength, speed);
            roster->remove(roster->at(random));
            roster->insertTail(player);
        }
    }
}

/*
* createTeams()
*
* Divides the players in the roster into 2 teams, Team A and Team B
*
* The first player in the roster should be added to Team A, the second to Team B, and so on.
* When a player is added to a team, that player is removed from the roster.
*
* Should not remove players from the roster or add them to a team if there are insufficient players in the roster to play the game
* (there must be at least 2 players on each team in order to play).
*
* returns true if Team A and Team B are created successfully, false otherwise
 * This function will divide the Players in the roster into two teams. When adding to the teams, you
must insert at the end of the team's list (i.e. with a new index that is greater than all the existing
indices). Every other Player will be assigned to a different team; the first Player in the roster will be
added to Team A, the second Player to Team B, etc. When a Player is added to a team, he is removed
from the roster. If the roster has an odd number of Players, omit the last Player (the last Player will
remain on the roster). If the roster has less than 4 Players, do not remove any players from the roster
and alert the user that no players have been added to the teams.
*/
bool RedRover::createTeams() {
    if (roster->size() < 4) {
        return false;
    } else {
        int size = roster->size();
        if (size & 2 != 0) {
            size -= 1;
        }
        for (int i = 0; i < size; i++) {
            if (i == 0 || i % 2 == 0) {
                string name = roster->at(0)->getName();
                int strength = roster->at(0)->getStrength();
                int speed = roster->at(0)->getSpeed();
                Player *player = new Player(name, strength, speed);
                teamA->insertTail(player);
                roster->removeHead();
            } else {
                string name = roster->at(0)->getName();
                int strength = roster->at(0)->getStrength();
                int speed = roster->at(0)->getSpeed();
                Player *player = new Player(name, strength, speed);
                teamB->insertTail(player);
                roster->removeHead();
            }
        }
        return true;
    }
}

/*
* sendSomeoneOver()
*
* The Player "runner" is called over and attempts to break through the defender's defenses.
*
* The runner will always attempt to break the link between the defender and the next player in the defender's team.
* If the defender is the last player in the team, the runner attempts to break the link between the last two players of the team.
*
* The runner is successful if the sum of his strength and speed exceeds the sum of the strengths of the defending players.
*
* If the runner is successful the stronger of the two players that he attempted to break through is added to the runner's team after the runner
* If the runner does not break the link, the runner is added to the defender's team after the defender
*
* The names of Players will be unique, they will not exist in more than one team.
*
* If the runner and the defender are on the same team or if one of the players cannot be located, does nothing
* If either the runner or the defender is NULL, does nothing
 * This function will operate as follows:
1. The first player (the runner) will be located in either Team A or Team B, and the second player (the
defender) will be located in the other team.
2. The runner will attempt to break through the link held by the defender and his successor. The link
that the runner attempts to break will always be between the defender and the next player in the list
unless the defender is the last player in the list, at which point the runner will attempt to break the link
between the last two players. For example,
Team A: Kathryn, Adam, MichaelP, Timnah, Derek, Jonathan, Finn, Dallen
Runner: Jonathan
Team B: Jordan, MichaelD, Nick, Jason, Ryan, Jacob, Maxwell, Garrett
Defender: Maxwell
In this example, Jonathan will attempt to break the link between Maxwell and Garrett. The link will be
broken if the sum of Jonathan’s strength and speed exceeds the sum of Maxwell and Garrett's strength.
If the link is broken, then Jonathan returns to his original index on his team and the stronger Player
associated with the link that was broken becomes a part of Jonathan’s team and is inserted after
Jonathan. If the link is not broken then Jonathan will become part of Team B and will be inserted after
Maxwell, between Maxwell and Garrett.
If the attack results in either team winning, then a message should be displayed showing the
members of the winning team and alerting the user that the team has won and the game is over. For
example, if the teams were as follows:
Team A: Riku, Ansem
Team B: Sora, Kairi, Namine, Olette
If Olette is called over to Team A and breaks through the link, then the stronger of the two
players forming the link in Team A would be added to Team B. If Ansem had a higher strength than Riku
the teams would look like this after the attack was over:
Team A: Riku
Team B: Sora, Kairi, Namine, Olette, Ansem
The function should then display something like the following:
“Team B wins! Sora, Kairi, Namine, Olette, Ansem.”
*/
bool RedRover::sameTeam(PlayerInterface *person1, PlayerInterface *person2){
    if(getTeam(person1) == getTeam(person2)){
        return true;
    } else {
        return false;
    }
}

doubleLinkedList<PlayerInterface*> * RedRover::getTeam(PlayerInterface *person){
    for (int i = 0; i < getTeamASize(); i++) { //look through teamA
        if (teamA->at(i) == person) { //if the defender is on teamA then set its location
            return (doubleLinkedList<PlayerInterface *> *) teamA;
        }
    }
    for (int i = 0; i < getTeamASize(); i++) { //if the defender is on teamB then set its location
        if (teamB->at(i) == person) {
            return (doubleLinkedList<PlayerInterface *> *) teamB;
        }
    }
    return NULL;
}

int RedRover::playerIndex(PlayerInterface *person){
    for(int i=0; i<getTeam(person)->size(); i++){
        if(getTeam(person)->at(i) == person){
            return i;
        }
    }
}

PlayerInterface *RedRover::nextToDefender(PlayerInterface *defender){
    int location = playerIndex(defender);
    if(location == getTeam(defender)->size()-1){
        return getTeam(defender)->at(location-1);
    } else {
        return getTeam(defender)->at(location+1);
    }
}
int RedRover::linkStrength(PlayerInterface *defender){
    return defender->getStrength() + nextToDefender(defender)->getStrength();
}

PlayerInterface* RedRover::strongestPlayer(PlayerInterface *defender){
    if(defender->getStrength() >= nextToDefender(defender)->getStrength()){
        return defender;
    } else {
        return nextToDefender(defender);
    }
}
void RedRover::sendSomeoneOver(PlayerInterface *runner, PlayerInterface *defender) {
    //runner = teamA->at(2);
    //defender = teamB->at(0);
    doubleLinkedList<PlayerInterface *> *defenderTeam = getTeam(defender);
    doubleLinkedList<PlayerInterface *> *runnerTeam = getTeam(runner);
    PlayerInterface *strongestplayer = strongestPlayer(defender);
    if(sameTeam(runner, defender)) return;
    int link = linkStrength(defender);
    int runnerTotal = runner->getStrength() + runner->getSpeed();
    if(runnerTotal > link){
        string name = defenderTeam->at(playerIndex(strongestplayer))->getName();
        int strength = defenderTeam->at(playerIndex(strongestplayer))->getStrength();
        int speed = defenderTeam->at(playerIndex(strongestplayer))->getSpeed();
        Player *player = new Player(name, strength, speed);
        runnerTeam->insertAfter(player, runner);
        defenderTeam->remove((Player *) strongestplayer);
    } else {
        string name = runner->getName();
        int strength = runner->getStrength();
        int speed = runner->getSpeed();
        Player *player = new Player(name, strength, speed);
        defenderTeam->insertAfter(player, defender);
        runnerTeam->remove((Player *) runner);
    }
}

/*
* teamReset()
*
* Empties both teams (does not affect the roster)
*/
void RedRover::teamReset() {
    teamA->clear();
    teamB->clear();
}

/*
* rosterReset()
*
* Empties all players from the roster
* (does nothing to Team A or Team B)
*/
void RedRover::rosterReset() {
    roster->clear();
}

/*
* autoPlay()
*
* Simulates a game of Red Rover and notifies the user of the winning team.
*
* Selects a random player from one team to attempt to break through a random player from the other team until one team has won.
*
* Starting with Team A, teams take turns attempting to break through.
*
* When the function ends, both teams should be emptied.
*
* this function returns nothing, but it MUST print out
* 		the name of the runner,
* 		the name of the defender, and
* 		the players on each team
* after each attempt to break through.
*
* At the end of the game, print out the name of the winning team and the players on both teams.
*/
void RedRover::autoPlay() {
    srand(time(NULL));
    int whichPlayerA = 0;
    int whichPlayerB = 0;
    while (getTeamASize() > 1 || getTeamBSize() > 1) {
        if (getTeamASize() <= 1 || getTeamBSize() <= 1) {
            break;
        }
        whichPlayerA = rand() % getTeamASize();
        whichPlayerB = rand() % getTeamBSize();
        sendSomeoneOver(teamA->at(whichPlayerA), teamB->at(whichPlayerB));
        cout << getTeamA() << endl << getTeamB() << endl;
        if (getTeamASize() <= 1 || getTeamBSize() <= 1) {
            break;
        }
        whichPlayerA = rand() % getTeamASize();
        whichPlayerB = rand() % getTeamBSize();
        sendSomeoneOver(teamB->at(whichPlayerB), teamA->at(whichPlayerA));
        cout << getTeamA() << endl << getTeamB() << endl;
    }
    if(getTeamASize() == 1){
        cout << "Team B Wins!\n";
    } else {
        cout << "Team A Wins!\n";
    }
}