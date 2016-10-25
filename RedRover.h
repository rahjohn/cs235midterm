/* Rachel Johnson
 * CS 235 Fall 2016 Midterm
 */
#ifndef REDROVER_H
#define REDROVER_H
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
    struct playerStruct {
        string name;
        string strength;
        string speed;
    } player;
    doubleLinkedList<playerStruct> * roster;
    doubleLinkedList<playerStruct> * teamA;
    doubleLinkedList<playerStruct> * teamB;
};

#endif
