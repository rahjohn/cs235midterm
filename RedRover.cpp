/* Rachel Johnson
 * CS 235 Fall 2016 Midterm
 */
#include "RedRover.h"
#include <sstream>

RedRover::RedRover(){
    roster = new doubleLinkedList<Player*>();
    teamA  = new doubleLinkedList<Player*>();
    teamB  = new doubleLinkedList<Player*>();
}

RedRover::~RedRover(){
    roster->clear();
    teamA->clear();
    teamB->clear();
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
*/
bool RedRover::addToRoster(string player_list) {
    bool added = false;
    string name, strength, speed;
    stringstream ss(player_list);
    do {
        ss >> name;
        if (ss.fail()) return false;
        ss >> strength;
        if (ss.fail()) return false;
        ss >> speed;
        if (ss.fail()) return false;
        Player * player = new Player(name, strength, speed);
        roster->insertHead(player);
        added = true;
    } while(ss);
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
    return 1;
}

/*
* getTeamBSize()
*
* Returns the number of players on Team B.
*/
int RedRover::getTeamBSize() {
    return 1;
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
    string name;
    int size = roster->size();
    for(int i=0; i<size; i++){
        if(i == size-1) {
            //ss << roster->at(i);
        } else {
            //ss << roster->at(i) << " ";
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
    return NULL;
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
    return NULL;
}

/*
* rosterAt()
*
* Returns a pointer to the player at the given index in the roster.
* Returns NULL if the index is out of range
*/
PlayerInterface* RedRover::rosterAt(int index) {
    return roster->at(index);
}

/*
* teamAAt()
*
* Returns a pointer to the player at the given index in Team A.
* Returns NULL if the index is out of range
*/
PlayerInterface* RedRover::teamAAt(int index) {
    return teamA->at(index);
}

/*
* teamBAt()
*
* Returns a pointer to the player at the given index in Team B.
* Returns NULL if the index is out of range
*/
PlayerInterface* RedRover::teamBAt(int index) {
    return teamB->at(index);
}

/*
* shuffleRoster()
*
* Shuffles the players in the roster
* Does not affect the players in Team A or Team B
*/
void RedRover::shuffleRoster() {}

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
*/
bool RedRover::createTeams() {
    if(roster->size() < 4) {
        return false;
    } else {
        int size = roster->size();
        for(int i=0; i<size; i++){

        }
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
*/
void RedRover::sendSomeoneOver(PlayerInterface *runner, PlayerInterface *defender){}

/*
* teamReset()
*
* Empties both teams (does not affect the roster)
*/
void RedRover::teamReset() {}

/*
* rosterReset()
*
* Empties all players from the roster
* (does nothing to Team A or Team B)
*/
void RedRover::rosterReset() {}

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
void RedRover::autoPlay() {}