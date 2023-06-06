/**
 * Name - David Joves
 * 
 * 
 * Assignment - Chapter 18 Programming Assignment
 * 
 * 
 * Date 05 - APR - 2023
*/

//Implementation file for LinkedList class
#include "LinkedList.h" //Needed for the LinkedList class
#include <iostream>     //Needed for cout 
#include <cstdlib>      //Needed for exit function

using namespace std; 

//***********************************************************************************
// The constructor sets head to nullptr and the size of the LinkedList to 0         *
//***********************************************************************************
LinkedList::LinkedList()
{
    head = nullptr;
    size = 0;
}

//***********************************************************************************
// The destructor releases all the memory that is used by the list through          *
// traversing through the list and deleting nodes from it and from memory           *
//***********************************************************************************
LinkedList::~LinkedList()
{
    ListNode* nodePtr = head;     //Position nodePtr at head of list
    ListNode* nextNode;           //To point to next node

               

    while(nodePtr!= nullptr)    //While nodePtr is not nullptr
    {
        nextNode = nodePtr->next;   //Link nextnode to one after nodePtr
        delete nodePtr;             //delete current node
        nodePtr = nextNode;         //move on to next node
    }
}

//***********************************************************************************
// appendNode appends a node containing the data passed into newData, to the end    *
// end of the list. Executes exit failure if any invalid parameters have been       *
// passed                                                                            *
//***********************************************************************************
void LinkedList::appendNode(string newData)
{
    ListNode* nodePtr;      //To traverse list
    ListNode* newNode;      //Point to new node
    int currPos = 0;        //Declare and initialize currPos to 0

    newNode = new ListNode(newData);   //Allocate a new node and store data in node

    //Low-Level validation
    //If new data is not valid, exit failure
    if (newData != "turquoise" && newData != "gold" && newData != "copper" && newData != "coral") 
    {
        cout << "Error: Invalid data. Data must be turquoise, gold, copper, or coral." << endl;
        exit(EXIT_FAILURE);
    }

    if(!head)       //If empty list, make newNode head 
    {
        head = newNode;
        cout << "Thank you a " << newData << " bead was added at position 0" << endl;
    }
    else
    {
        nodePtr = head;     //Have nodePtr point to head

        while(nodePtr->next != nullptr) //Traverse list until end
        {
            nodePtr = nodePtr->next; 
            currPos++;
        }

        nodePtr->next = newNode;    //When at the end, add new node at end
        cout << "Thank you a " << newData << " bead was added at position " << currPos + 1 << endl;
    }

    size++;     //Increment size of list
}

//***********************************************************************************
// The insertNode function inserts a node with newData copied to it's data member   *
// at the position that has been passed with it inside the list. Returns -1 or      *
// executes exit failure if any invalid parameters have been passed                 *
//***********************************************************************************
int LinkedList::insertNode(string newData, int position)
{
    ListNode* nodePtr;      //To traverse list
    ListNode* newNode;      //Point to new node
    int currPos = 0;        //Declare and initialize currPos to 0

    newNode = new ListNode(newData);   //Allocate new node and store data in it

    //Low-Level validation
    //If new data is not valid, exit failure
    if (newData != "turquoise" && newData != "gold" && newData != "copper" && newData != "coral") 
    {
        cout << "Error: Invalid data. Data must be turquoise, gold, copper, or coral." << endl;
        exit(EXIT_FAILURE);
    }

   
    if(position < 0)                //If negative position is negative, return -1
    {
        cout << "Position cannot be unsigned int!" << endl;
        delete newNode;
        return -1;
    }
    
    else if(position > size)        //If position is bigger than size, return -1
    {
        cout << "Insert position cannot be bigger than list!" << endl;
        delete newNode;
        return -1;
    }

    if(position == 0 || !head)      //If position is 0 or empty list, set new node as head and link to next node 
    {
        newNode->next = head;   
        head = newNode;
        cout << "Thank you " << newData << " was added at position " << position << endl;
    }       
    else
    {
        nodePtr = head;     //Have nodePtr point to head

        while(nodePtr != nullptr && currPos < position - 1)     //Go through the list until desired position
        {
            nodePtr = nodePtr->next;
            currPos++;
        }

        newNode->next = nodePtr->next;      //Insert and link new node at position
        nodePtr->next = newNode; 

        cout << "Thank you " << newData << " was inserted at position " << position << endl;
    }

    size++; 
    return 0;
}

//***********************************************************************************
// The deleteNode function searches for a node in the position that was passed, and *
// The node, if it exists in said position, is deleted from the list and from       *
// memory. Returns -1 if invalid position was passed                                *
//***********************************************************************************
int LinkedList::deleteNode(int position)
{

    ListNode* nodePtr;              //To traverse list
    ListNode* trailPtr;             //Trail behind nodePtr
    int currPos = 0;                //Declare and initialize currPos to 0

    if(position < 0 || position >= size)    //If position is negative or greater than current size, prompt error
    {
        cout << "Invalid position!" << endl;
        return -1;
    }

    if(position == 0)   //If position is 0, delete head node and make next one head
    {
        nodePtr = head;
        head = head->next;
        delete nodePtr;
    }
    else 
    {
        nodePtr = head; //Have nodePtr point to head

        while(nodePtr!= nullptr && currPos != position) //Go through the list until desired position
        {
            trailPtr = nodePtr;          //Point to current node
            nodePtr = nodePtr->next;     //Move to next node
            currPos++;                   //increment currPos
        }

        trailPtr->next = nodePtr->next; //Link node on trailPtr to one node after nodePtr
        delete nodePtr;                 //Delete current node on nodePtr
    }
    size--; //decrement size
    return 0;
}

//***********************************************************************************
// The searchNode function traverses through the list until it finds a node data    *
// member that matches newData. If found, it will display the position in the list. *
// Returns -1 if list is empty, or newData does not exist in the list.              *
//***********************************************************************************
int LinkedList::searchNode(string newData)
{
    ListNode* nodePtr; 
    int position = 0; 
    bool found = false;

    if (newData != "turquoise" && newData != "gold" && newData != "copper" && newData != "coral") 
    {
        cout << "Error: Invalid data. Data must be turquoise, gold, copper, or coral." << endl;
        exit(EXIT_FAILURE);
    }

    if(!head)
    {
        cout << "List is empty! Insert beads" << endl;
        return -1;
    }
    else
    {
        nodePtr = head; 
        while(nodePtr!= nullptr)
        {
            if(nodePtr->data == newData)
            {
                cout << "There is a " << newData << " bead at position (" << position << ")" << endl;
                found = true;
            }       
            nodePtr = nodePtr->next;
            position++;
        }
    }
    
    if(!found)
    {
        return -1;
    }
    return 0;

}

//***********************************************************************************
// The display function shows the data stored in each node of the linked list that  *
// is being pointed by head                                                         *
//***********************************************************************************
void LinkedList::display()
{
    ListNode* nodePtr; 
    int position = 0;

    if(!head)
    {
        cout << "List is empty! Insert beads" << endl;
    }

    else
    {
        nodePtr = head;
        cout << "Here is your current list: " << endl;
        while(nodePtr!= nullptr)
        {
            cout <<"(" << position << ") " << nodePtr->data << endl;
            nodePtr = nodePtr->next;
            position++;
        }
        cout << endl;
    }
}

//***********************************************************************************
// getSize function returns the value of the member variable size                   *
//***********************************************************************************
int LinkedList::getSize()
{
    return size;
}