/**
 * Name - David Joves
 * 
 * 
 * Assignment - Chapter 20 - Recursion and a Free Tee??
 * 
 * 
 * Date 4 - MAY - 2023
*/

//Specification file for QNode and SeaFoodQ
#ifndef DynamicQ_H
#define DynamicQ_H

#include<string>    

using namespace std;

class QNode
{
    //Public member variables
    public:

        string name;        //Customer name
        int raffle;         //Customer raffle number

        QNode* next;    //Pointer to next node

        //Constructor 
        QNode(string customer, int num)
        {
            name = customer;
            raffle = num;
            next = nullptr;
        }
};

class SeaFoodQ
{
    //Private Member variables
    private:
        QNode *front;   //Front of queue 
        QNode *rear;    //Rear of queue 

        int countNode(QNode *) const;
        void searchNode(QNode *, int) const;

    public: 
        //Constructor
        SeaFoodQ();

        //Destructor 
        ~SeaFoodQ();

        //Queue operations (Mutator Functions)
        void enqueue(string, int);
        void dequeue(string &); 
        int draw();

        int numQ()
        { return countNode(front); } 
        
        void search(int raffleNum)
        { searchNode(front, raffleNum); }

        void displayQ();
        bool isEmpty();
};
#endif