/**
 * Name - David Joves
 * 
 * 
 * Assignment - Chapter 19 Programming Assignment - The Say What (!?!) Stack
 * 
 * 
 * Date 20 - APR - 2023
*/
//Specification file for StackNode and StoryStack class
#ifndef WordStack_H
#define WordStack_H

#include<string>

using namespace std;

class StackNode
{
    //Public member variables
    public:

        string data;        //Data in node

        StackNode* next;    //Pointer to next node

        //Constructor 
        StackNode(string newData)
        {
            data = newData;
            next = nullptr;
        }
};

class StoryStack
{
    //Private member variables
    private:
        StackNode *top;     //Pointer to stack top

        int size;           //Size of stack
    //Public member variables
    public:
        //Constructor
        StoryStack();

        //Destructor
        ~StoryStack();

        //Stack operations (Mutator Functions)
        void push(string);
        void pop(string &);
        void capitalize();
        void displayStack();
        bool isEmpty();
        int getSize();    
};
#endif