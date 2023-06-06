/**
 * Name - David Joves
 * 
 * 
 * Assignment - Chapter 18 Programming Assignment
 * 
 * 
 * Date 05 - APR - 2023
*/

//Specification file for the ListNode and LinkedList class
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>

using namespace std;

class ListNode
{
    //Public Member variables
    public: 
        string data;            //Data in node
        ListNode* next;         //Pointer to next node
    
        //Constructor
        ListNode(string bead)
        {
            data = bead;
            next = nullptr;
        }

};

class LinkedList
{
    //Private Member variables
    private:
        ListNode *head;         //Pointer to first node
        int size;               //Size of the list

    //Public Member variables
    public:
        //Constructor 
        LinkedList();

        //Destructor
        ~LinkedList();

        //Linked List operations (Mutator Functions)
        void appendNode(string);
        int insertNode(string, int);
        int deleteNode(int);
        int searchNode(string);
        void display();

        //Accessor Functions 
        int getSize();
};
#endif