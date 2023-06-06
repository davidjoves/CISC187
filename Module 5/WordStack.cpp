/**
 * Name - David Joves
 * 
 * 
 * Assignment - Chapter 19 Programming Assignment - The Say What (!?!) Stack
 * 
 * 
 * Date 20 - APR - 2023
*/

//Implementation file for StoryStack class
#include "WordStack.h"      //Needed for StoryStack class
#include <iostream>         //Needed for cout 
#include <string>           //Needed for strings
#include <cstdlib>          //Needed for exit_failure
#include <cctype>           //Needed for toupper()

using namespace std; 

const int MAX_LENGTH = 10;

//***************************************************************************
// The constructor sets top to nullptr and the size of the stack to 0       *
//***************************************************************************
StoryStack :: StoryStack()
{
    top = nullptr;
    size = 0;
}

//***************************************************************************
// The destructor releases all the memory that is used by the stack through *
// traversing through the stack and deleting nodes from it and from memory  *
//***************************************************************************
StoryStack :: ~StoryStack()
{
    StackNode *nodePtr;     //To traverse stack
    StackNode *nextNode;    //To hold nextNode in stack

    nodePtr = top;

    while(nodePtr != nullptr)
    {
        nextNode = nodePtr->next;
        delete nodePtr;
        nodePtr = nextNode;
    }
}

//***************************************************************************
// Member function push, pushes the argument (string) onto the stack        *
//***************************************************************************
void StoryStack :: push(string word)
{

    StackNode *newNode; //Pointer to a new node 

    newNode = new StackNode(word);  //Allocating for new node

    //If string is longer than 10 or blank, exit failure
    if(word.length() > MAX_LENGTH || word.length() == 0)
    {
        cout << "Invalid String! Executing exit failure" << endl;
        exit(EXIT_FAILURE);
    }

    //If stack is empty, make newNode first node
    if(isEmpty())
    {
        top = newNode;              //Inserts newNode at top of stack
        newNode->next = nullptr;    //Sets pointer for newNode to null
    }
    //Otherwise, insert before top of stack
    else
    {
        newNode->next = top;        //Have newNode inserted before top
        top = newNode;              //Make top of stack newNode
    }

    size++;
}

//***************************************************************************
// Member function pop, pops the value at the top of the stack off and      *
// copies it into the variable passed as an argument                        *
//***************************************************************************
void StoryStack :: pop(string &word)
{
    StackNode* nodePtr;         //To traverse stack

    //If empty, cout error
    if(isEmpty())
    {
        cout << "Stack isn't empty" << endl;
    }
    //Otherwise, pop off value from top of stack
    else
    {
        word = top->data;       //sets referenced variable to top data value
        nodePtr = top->next;    //Points to next node after top
        delete top;             //Deletes top and set top to next node
        top = nodePtr;          
    }
    
    size--;
}

//***************************************************************************
// Member function capitalize, traverses through the stack to access        *
// the string to then rewrite the string using cctype library, toUpper, for *
// each character in the string                                             *
//***************************************************************************
void StoryStack :: capitalize()
{
    StackNode *nodePtr;      // To traverse stack  

    //If empty, prompt user
    if(isEmpty())
    {
        cout << "Stack is empty! Push words into it!" << endl;
    }
    //Otherwise, traverse stack and capitalize each word using toupper()
    else
    {
        nodePtr = top;      // Point to top of stack

        //While nodePtr does not point to null
        while(nodePtr != nullptr)
        {
            string& word = nodePtr->data;   //Reference string inside the stack

            for(char& c : word)             //Reference character of string in stack
            {
                c = toupper(c);             //Capitalize each character
            }

            nodePtr = nodePtr->next;        //Move to next node
        }
    }

}

//***************************************************************************
// Member function displayStack, traverses through the stack to then output *
// the strings in the stack                                                 *
//***************************************************************************
void StoryStack :: displayStack()
{
    StackNode* nodePtr;     //To traverse stack

    //If stack is empty, prompt user
    if(isEmpty())
    {
        cout << "Stack is empty! Push words onto the stack!" << endl;
    }

    //Otherwise display stack
    else
    {
        nodePtr = top;     //Point to top of stack

        //While nodePtr is not null
        while(nodePtr)
        {   
            cout << nodePtr->data << endl;      //Output word from stack

            nodePtr = nodePtr->next;            //Move to next node
        }
    }
}

//***************************************************************************
// Member function isEmpty, returns boolean determining if stack is empty   *
// by looking if top points to null or to a node                            *
//***************************************************************************
bool StoryStack :: isEmpty()
{   
    bool status;        //Declare boolean

    //If top is null, set status to true
    if(!top)
    {
        status = true;  //Stack is empty
    }
    //Otherwise, set status to false
    else
    {
        status = false; //Stack is not empty
    }

    return status;      //Return status
}

//***************************************************************************
// Member function getSize, returns the size of the stack                   *
//***************************************************************************
int StoryStack :: getSize()
{
    return size;
}