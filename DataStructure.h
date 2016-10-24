#include "linkedlist.h"

#ifndef DATASTRUCTURE_H
#define DATASTRUCTURE_H

using namespace std;

class DataStructure {
public:
    DataStructure(){}
    virtual ~DataStructure(){}
    virtual void push(int i) = 0;
    virtual void pop() = 0;
    virtual bool empty() = 0;
    virtual int top() = 0;
    virtual bool full() = 0;
    virtual int size() = 0;
    virtual bool valueExists(int i) = 0;
private:
    LinkedList<int> cars;
    int MAX = 5;
};
#endif
