/* Rachel Johnson
 * CS 235 Fall 2016 Midterm
 */
#ifndef REDROVER_H
#define REDROVER_H
#include "Player.h"
#include "PlayerInterface.h"
#include "RedRoverInterface.h"
#include "doubleLinkedList.h"

class RedRover : public RedRoverInterface {
public:
    RedRover();
    virtual ~RedRover();
    virtual bool addToRoster(string player_list);
    virtual int getRosterSize();
    virtual int getTeamASize();
    virtual int getTeamBSize();
    virtual string getRoster();
    virtual string getTeamA();
    virtual string getTeamB();
    virtual PlayerInterface* rosterAt(int index);
    virtual PlayerInterface* teamAAt(int index);
    virtual PlayerInterface* teamBAt(int index);
    virtual void shuffleRoster();
    virtual bool createTeams();
    virtual void sendSomeoneOver(PlayerInterface* runner, PlayerInterface* defender);
    virtual void teamReset();
    virtual void rosterReset();
    virtual void autoPlay();
private:
    doubleLinkedList<Player*> * roster;
    doubleLinkedList<Player*> * teamA;
    doubleLinkedList<Player*> * teamB;
    doubleLinkedList<PlayerInterface*> *getTeam(PlayerInterface *person);
    virtual bool sameTeam(PlayerInterface *person1, PlayerInterface *person2);
    virtual int linkStrength(PlayerInterface *defender);
    virtual PlayerInterface *nextToDefender(PlayerInterface *defender);
    virtual PlayerInterface *strongestPlayer(PlayerInterface *defender);
    virtual int playerIndex(PlayerInterface *person);
};

#endif
