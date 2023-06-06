/**
 * Name - David Joves
 * 
 * 
 * Assignment - Chapter 20 - Recursion and a Free Tee??
 * 
 * 
 * Date 4 - MAY - 2023
*/

//Implementation file for SeaFoodQ

#include "DynamicQ.h"       //Needed for SeaFoodQ class
#include <iostream>         //Needed for cout 
#include <string>           //Needed for strings
#include <cstdlib>          //Needed for exit_failure
#include <vector>           //Needed for vector<int> raffles for draw()
#include <iomanip>          //Needed for setw(), left 

using namespace std; 

const int MAX_LENGTH = 20;
const int MIN_RAFFLE = 1; 
const int MAX_RAFFLE = 500;


//***************************************************************************
// The constructor sets front and rear to nullptr                           *
//***************************************************************************
SeaFoodQ :: SeaFoodQ()
{   
    //Set front and rear to nullptr
    front = nullptr; 
    rear = nullptr; 
}

//***************************************************************************
// The destructor releases all the memory that is used by the queue by      *
// traversing through the queue and deleting nodes from it and from memory  *
//***************************************************************************
SeaFoodQ :: ~SeaFoodQ()
{
    QNode* nodePtr;  //To traverse queue

    while(front != nullptr)
    {
        nodePtr = front;        //Set nodePtr at front
        front = front->next;    //Move front to next node
        delete nodePtr;         //Delete node at nodePtr
    }
}

//***************************************************************************
// Member function enqueue, queues a node containing customer and raffle    *
//***************************************************************************
void SeaFoodQ :: enqueue(string customer, int raffle)
{
    QNode *newNode; //Pointer to new node 

    newNode = new QNode(customer, raffle);

    //If string is longer than 20 char or blank, exit failure
    if(customer.length() > MAX_LENGTH || customer.length() == 0)
    {
        cout << "Invalid String! Executing exit failure" << endl;
        exit(EXIT_FAILURE);
    }

    //If int is over 500 or less than 1, exit failure
    if(raffle > 500 || raffle < 1)
    {
        cout << "Invalid int! Executing exit failure" << endl;
        exit(EXIT_FAILURE);
    }

    //If queue is empty, adjust front and rear to point to newNode
    if(isEmpty())
    {
        front = newNode; 
        rear = newNode; 
    }
    //Otherwise, adjust rear to point to added newNode 
    else
    {
        rear->next = newNode; 
        rear = newNode; 
    }
}

//***************************************************************************
// Member function dequeue, dequeues the value at the front of the queue    *
// and copies it into the variables passed by reference                     *
//***************************************************************************
void SeaFoodQ :: dequeue(string &customer)
{
    QNode *nodePtr = nullptr; //To traverse list 

    if(isEmpty())
    {
        cout << "The queue is empty" << endl;
    }
    else
    {
        //Save front node values
        customer = front->name;

        //Remove front node and delete 
        nodePtr = front; 
        front = front->next;
        delete nodePtr;

        //If queue becomes empty after dequeuing, adjust rear pointer
        if(front == nullptr)
        {
            rear = nullptr; 
        }
    }
}

//***************************************************************************
// Member function countNode, counts the nodes in the queue using recursion.*
// Base case is when there is no more nodes in the queue, recursive case is *
// when there is a node inside the queue.                                   *
//***************************************************************************
int SeaFoodQ :: countNode(QNode *nodePtr) const 
{
    //Recursive Case: While there is still a node, continue to count until returns 1 + whatever instances were
    //                called.
    if (nodePtr != nullptr)
    {
        return 1 + countNode(nodePtr->next);
    }
    //Base Case: If there is no mores nodes return 0
    else
    {
        return 0;
    }
}

//***************************************************************************
// Member function searchNode, traverses through the queue recursively until*
// the base case for raffleNum is found or not found is met. The recursive  *
// case is when there is an available node to search for raffleNum .        *
//***************************************************************************
void SeaFoodQ :: searchNode(QNode *nodePtr, int raffleNum) const
{
    int choice = 0;     //Declare and initialize choice to be 0;

    //Check to see queue is empty
    if(nodePtr == nullptr)
    {
        cout << "The queue is empty!" << endl;
    }
    //Base Case: raffleNum is found
    else if(nodePtr->raffle == raffleNum)
    {
       cout << "Congrats! " << nodePtr->name << " please choose your prize" << endl;
       cout << "1. A free Tee Shirt " << endl;
       cout << "2. A free side dish" << endl;

       cin >> choice;  

       switch(choice)
       {
            case 1: 
                cout << "Enjoy your free tee " << nodePtr->name << "!" << endl;
                break;
            case 2:
                cout << "Enjoy your free side dish " << nodePtr->name << "!" << endl;
                break;
            default:
                cout << "Only 1 or 2" << endl;
                break;
       }
       
    }
    //Base Case: raffleNum is not found
    else if(nodePtr->next == nullptr)
    {
        cout << "The winning raffle was not found" << endl;
    }
    //Recursive Case: Search for node until raffleNum is found
    else
    {
        searchNode(nodePtr->next, raffleNum);
    }
}

//***************************************************************************
// Member function isEmpty, returns boolean determining if queue is empty   *
// by looking if the front points to nullptr or to a node                   *
//***************************************************************************
bool SeaFoodQ :: isEmpty()
{
    bool status;        //Declare boolean status

    //If front is nullptr, queue is empty
    if(!front)
    {
        status = true; 
    }
    //Otherwise, queue is not empty
    else
    {
        status = false; 
    }

    //Return bool
    return status;
}

//***************************************************************************
// Member function displayQ, traverses through the queue to then output     *
// the position, name, and raffle for each node.                            *
//***************************************************************************
void SeaFoodQ :: displayQ()
{
    QNode *nodePtr = front; //Traverse list 
    int position = 0;       //Declare and initialize position to 0

    //if empty, prompt user
    if(isEmpty())
    {
        cout << "Queue is empty!" << endl;
        return;
    }
    //Otherwise, output position in queue, customer name, and their raffle number
    else
    {
        nodePtr = front; //Point to front of queue
        cout << left << setw(15) << "Position" << setw(15) << "Customer" << setw(15) << "Raffle Number" << endl;
        cout << "----------------------------------------------------------" << endl;

        //While nodePtr is not null
        while (nodePtr)
        {   
            //Output position, name, and raffle
            cout << left << setw(17) << position << setw(20) << nodePtr->name << setw(15) << nodePtr->raffle << endl;

            nodePtr = nodePtr->next; //move to next node
            position++; //increment to next position in queue
        }
    }

}

//***************************************************************************
// Member function draw, traverses through the queue, accessing each node's *
// raffle number and pushing it into a vector to hold them. Will return the *
// raffle number                                                            * 
//***************************************************************************
int SeaFoodQ::draw()
 {
    QNode *nodePtr = front;     //Traverse Q
    vector<int> raffles;        //Initialize vector to hold raffles
    int raffle = -1;            //Initialize raffle to -1

    //If queue is empty, return
    if (isEmpty()) 
    {
        cout << "The queue is empty!" << endl;
        return raffle; 
    }
    else
    {
        //While there's a node, push it's raffle into vector
        while (nodePtr != nullptr)
        {
            raffles.push_back(nodePtr->raffle);
            
            nodePtr = nodePtr->next;
        }
        
        int index = rand() % raffles.size();    //Random number for index 

        raffle = raffles[index];                //raffle is set to random index in vector
        
        cout << "The winning raffle is: " << raffle << endl;

    }
    //Return raffle number
    return raffle;
}