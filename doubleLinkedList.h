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
        T value;
        Node * next;
        Node(T data) : data(data) {
            this -> next = NULL;
        };
        Node (T data, Node * next) : data(data), next(next){};
        virtual ~Node(){};
    };
    Node * head = NULL;
    Node * curr;
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

    bool valueIsInList(T value) {
        if (this->size() > 0) {
            if (head->value == value) {
                return true;
            }
            curr = head;
            while (curr->next != NULL) {
                curr = curr->next;
                if (curr->value == value) {
                    return true;
                }
            }
        }
        return false;
    }
    bool valid(T value) {
        bool valid = true;
        Node * temp = head;
        while (valid == true && temp != NULL) {
            if (value == temp -> data) {
                valid = false;
            }
            temp = temp -> next;
        }
        temp = NULL;
        return (!valueIsInList(value) && valid) ;
    }
    bool empty(T value) {
        if (head ==NULL) {
            head = new Node(value);
            return true;
        } else {
            return false;
        }
    }
    virtual void insertHead(T value) {
        if (empty(value)) {
            return;
        }
        if(valid(value)) {
            Node * insert = new Node(value, head);
            head = insert;
            insert = NULL;
        }

    }
    /*
           insertTail

           A node with the given value should be inserted at the end of the list.

           Do not allow duplicate values in the list.
    */
    virtual void insertTail( T value) {
        if(empty(value)) {
            return;
        }
        if(valid(value)) {
            Node * insert = new Node(value);
            Node * temp = head;
            while (temp -> next != NULL) {
                temp = temp -> next;
            }
            temp -> next = insert;
            temp = NULL;
            insert = NULL;
        }
    }
    /*
           insertAfter

           A node with the given value should be inserted immediately after the
           node whose value is equal to insertionNode.

           A node should only be added if the node whose value is equal to
           insertionNode is in the list. Do not allow duplicate values in the list.
    */

    virtual void insertAfter(T value, T insertionNode) {
        if(valid(value) == false && valid(insertionNode) == true) {
            return;
        }
        if(valid(value) == true && valid(insertionNode) == false) {
            Node * temp = head;
            while (temp -> data != insertionNode) {
                temp = temp -> next;
            }
            Node * insert = new Node(value, temp -> next);
            temp -> next = insert;
            temp = NULL;
            insert = NULL;
        }
    }
    /*
           remove

           The node with the given value should be removed from the list.

           The list may or may not include a node with the given value.
    */
    virtual void remove(T value) {
        if(valid(value)) {
            return;
        }
        Node * temp = head;
        if(temp -> data == value) {
            head = temp -> next;
            delete temp;
        } else {
            if(temp -> next == NULL){
                return;
            }
            while (temp -> next -> data != value) {
                if (temp -> next == NULL) {
                    return;
                }
                temp = temp -> next;
            }
            Node * curr = temp -> next;
            if (curr -> next == NULL) {
                temp -> next = NULL;
            } else {
                temp -> next = curr -> next;
            }
            delete curr;
            curr = NULL;
            temp = NULL;
        }
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
