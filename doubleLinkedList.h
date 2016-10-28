#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;


template<class T> class doubleLinkedList {
private:
    struct Node { //creating nodes for the linked list
        T data;
        Node * next;
        Node * prev;
        Node(T data) : data(data) {
            this -> next = NULL;
        };
        Node (T data, Node * next, Node * prev) : data(data), next(next), prev(prev){};
        virtual ~Node(){};
    };
    Node * a = NULL;
    Node * head = NULL;
    Node * curr;
    Node * tail = head;
    Node * b = NULL;

public:
    doubleLinkedList() {
        head = NULL;
    };
    virtual ~doubleLinkedList() {
        clear();
    };
    /*
           insertHead

           A node with the given value should be inserted at the beginning of the list.

           Do not allow duplicate values in the list.
    */


    bool valueIsInList(T data) {
        if (this->size() > 0) {
            if (head->data == data) {
                return true;
            }
            curr = head;
            while (curr->next != NULL) {
                curr = curr->next;
                if (curr->data == data) {
                    return true;
                }
            }
        }
        return false;
    }
    bool valid(T data) {
        bool valid = true;
        Node * temp = head;
        while (valid == true && temp != NULL) {
            if (data == temp -> data) {
                valid = false;
            }
            temp = temp -> next;
        }
        temp = NULL;
        return (!valueIsInList(data) && valid) ;
    }
    bool empty(T data) {
        if (head ==NULL) {
            head = new Node(data);
            return true;
        } else {
            return false;
        }
    }
    /*
    virtual void insertHead(T data) {
        if (empty(data)) {
            return;
        }
        if(valid(data)) {
            Node * insert = new Node(data, head, NULL);
            head = insert;
            insert = NULL;
        }

    }
     */
    /*
           insertTail

           A node with the given value should be inserted at the end of the list.

           Do not allow duplicate values in the list.
    */
    virtual bool insertTail(T data) {
        if(head == NULL){
            head = new Node(data);
            head->prev = NULL;
            head->next = NULL;
            tail = NULL;
            return true;
        }
        if(valid(data)) {
            Node * insert = new Node(data, NULL, tail);
            Node * temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = insert;
            insert->prev = tail;
            tail = insert;
            tail->next = NULL;
        }
    }
    /*
           insertAfter

           A node with the given value should be inserted immediately after the
           node whose value is equal to insertionNode.

           A node should only be added if the node whose value is equal to
           insertionNode is in the list. Do not allow duplicate values in the list.
    */
/*
    virtual void insertAfter(T data, T insertionNode) {
        if(valid(data) == false && valid(insertionNode) == true) {
            return;
        }
        if(valid(data) == true && valid(insertionNode) == false) {
            Node * temp = head;
            while (temp -> data != insertionNode) {
                temp = temp -> next;
            }
            Node * insert = new Node(data, temp -> next, );
            temp -> next = insert;
            temp = NULL;
            insert = NULL;
        }
    }
    */
    /*
           remove

           The node with the given value should be removed from the list.

           The list may or may not include a node with the given value.
    */
    virtual void remove(T data) {
        if(valid(data)) { //if the node doesn't exist exit out
            return;
        }
        Node * temp = head;
        if(head->data == data) { //if node is head
            removeHead();
        } else { //if the node is in the middle or tail
            if(temp->next == NULL){ //something went wrong
                return;
            }
            while (temp -> next -> data != data) { //while we have not reached our desired node keep going down the list
                if (temp -> next == NULL) { //check for errors
                    return;
                }
                temp = temp -> next; //just go to the next node
            }
            Node * curr = temp -> next; //the one we want to delete
            Node * a = curr->next; //the one after the one we want to delete
            if (curr == tail) { //if the one we want to delete is tail
                removeTail();
            } else { //if the one we want to delete is in the middle somewhere
                temp -> next = curr -> next;
                a->prev = temp;
                delete curr;
            }
        }
    }

    virtual void removeHead() {
        if(head->next != NULL) {
            Node * temp = head;
            head = temp->next;
            head->prev = NULL;
            delete temp;
        } else {
            head = NULL;
        }
    }

    virtual void removeTail(){
        Node * temp = tail->prev;
        delete tail;
        temp->next=NULL;
        tail=temp;
    }
    /*
           clear

           Remove all nodes from the list.
    */
    virtual void clear() {
        if(head == NULL) {
            return;
        }
        Node * temp = head;
        Node * curr;
        while(temp -> next != NULL) {
            curr = temp;
            temp = temp -> next;
            delete curr;
        }
        delete temp;
        temp = NULL;
        curr == NULL;
        head = NULL;
    }
    /*
           at

           Returns the value of the node at the given index. The list begins at
           index 0.

           If the given index is out of range of the list, throw an out of range exception.
    */
    T at(int index) {
        if (index < 0) {
            throw out_of_range("Index cannot be a negative number.");
        } else if (index >= this -> size()) {
            throw out_of_range("Index is out of bounds.");
        } else if (head == NULL) {
            throw out_of_range("Cannot get index of an empty list.");
        } else {
            Node * temp = head;
            for (int i = 0; i < index; i++) {
                temp = temp -> next;
            }
            T info = temp -> data;
            return info;
        }
    }
    /*
           size

           Returns the number of nodes in the list.
    */
    virtual int size() {
        int size = 0;
        Node * temp = head;
        if (head ==NULL) {
            size = 0;
        } else {
            size = 1;
            while (temp -> next != NULL) {
                size++;
                temp = temp -> next;
            }
        }
        return size;
    }
};

#endif
