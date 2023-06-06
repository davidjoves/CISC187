/**
 * Name - David Joves
 * 
 * 
 * Assignment - Chapter 20 - Recursion and a Free Tee??
 * 
 * 
 * Date 4 - MAY - 2023
*/

//Driver File (main) for SeaFoodQ

#include "DynamicQ.h"       //Needed for SeaFoodQ class
#include <iostream>         //Needed for cout 
#include <string>           //Needed for strings
#include <cstdlib>          //Needed for exit_failure
#include <cctype>           //Needed for isalpha
#include <exception>        //Needed for try-catch 
#include <limits>           //Needed for numeric_limits<streamsize>::max()
#include <ctime>            //Needed for srand()



using namespace std; 

const int MAX_LENGTH = 10;
const int MIN_RAFFLE = 1; 
const int MAX_RAFFLE = 500;


//Function Prototypes 

void addCustomer(SeaFoodQ &line);
void placeOrder(SeaFoodQ &line);
void countNames(SeaFoodQ &line);
void drawRaffle(SeaFoodQ &line);
void displayLine(SeaFoodQ &line);

int assignRaffle();
void displayMenu();


int main()
{
    displayMenu();
    return 0;
}   


// ********************************************************
// name:      addCustomer 
// called by: displayMenu
// passed:    SeaFoodQ &line
// returns:   nothing
// calls:     nothing
// The addCustomer function allows user to enqueue a      *
// customer in a FIFO manner. User will input their name  *
// and will be assigned a raffle number randomly by the   *
// program.
// ********************************************************
void addCustomer(SeaFoodQ &line)
{
    //Declare local variables
    string customer;    
    int raffleNum; 


    //Declare validating variables
    bool validName = false;
    bool validInput = false;


    //While input is not valid, have user do inputs
    while(!validInput)
    {
        cout << "Enter your name: " << endl;
        getline(cin >> ws, customer);

        //If customer contains digit, set bool to false
        for (char c : customer) 
        {
            if (isdigit(c)) 
            {
                validName = false;
                break;
            } 
            else 
            {
                validName = true;
            }
        }
        //If customer string is too long, prompt user
        if(customer.length() > MAX_LENGTH)
        {
            cout << "Word is too long! Make it less than 20 letters!" << endl;
        }
        else if(!validName)
        {
            cout << "Only enqueue proper customer names!" << endl;
        }
        //Otherwise, assign raffle number and then enqueue 
        else
        {
            raffleNum = assignRaffle();
            line.enqueue(customer,raffleNum);
            cout << "Welcome to Point Loma Seafoods - your raffle number is " << raffleNum << endl;
            validInput = true;
        }
    }
}


// ********************************************************
// name:      placeOrder 
// called by: displayMenu
// passed:    SeaFoodQ &line
// returns:   nothing
// calls:     nothing
// The placeOrder function allows user to dequeue customer*
// at the front of the queue.                             *
// ********************************************************
void placeOrder(SeaFoodQ &line)
{
    string customer;        //Declare string

    line.dequeue(customer); //Dequeue front

    cout << customer << ", you can order now!" << endl;
}

// ********************************************************
// name:      countNames
// called by: displayMenu
// passed:    SeaFoodQ &line
// returns:   nothing
// calls:     nothing
// The countNames function allows user to see number of   *
// nodes inside the queue.                                *
// ********************************************************
void countNames(SeaFoodQ &line)
{
    int size = 0;       //Initialize and declare size to 0

    size = line.numQ(); //Count nodes in queue

    cout << "Number of people in line: " << size << endl; 
}

// ********************************************************
// name:      drawRaffle
// called by: displayMenu
// passed:    SeaFoodQ &line
// returns:   nothing
// calls:     nothing
// The drawRaffle function allows user to participate in a*
// raffle draw where it will draw a random raffle assigned*
// to a node already. 
// ********************************************************
void drawRaffle(SeaFoodQ &line)
{
    int winner = 0;         //Initialize and declare winner to 0

    winner = line.draw();   //Draw raffle number

    //If winner is -1, return to menu
    if(winner == -1)
    {
        return; 
    }
    //Otherwise search for winner
    else
    {
        line.search(winner);    
    }
}

// ********************************************************
// name:      displayLine
// called by: displayMenu
// passed:    SeaFoodQ &line
// returns:   nothing
// calls:     nothing
// The displayLine function displays customer's position, *
// name, and raffle number inside the queue               *
// ********************************************************
void displayLine(SeaFoodQ &line)
{
    line.displayQ();    //Displays line
}

// ********************************************************
// name:      assignRaffle
// called by: enqueue
// passed:    SeaFoodQ &line
// returns:   integer
// calls:     nothing
// The assignRaffle function allows a node to be assigned *
// a random raffle number between 1-500. Will return that *
// random raffle number.                                  *
// ********************************************************
int assignRaffle()
{
    srand(time(NULL));          //For different ranges of numbers 
    int num = rand() % 500 + 1; //Random number between 1-500
    return num;
}

// ********************************************************
// name:      displayMenu
// called by: main
// passed:    nothing
// returns:   nothing
// calls:     addCustomer, placeOrder, countNames,
//            drawRaffle, and displayLine
// The displayMenu function will output to console the    *
// menu functions where user will be able to enqueue and  *
// dequeue nodes that hold a customer name and raffle num *
// Will also be able to count, display, and draw a random *
// raffle to win prizes.                                  *
// ********************************************************
void displayMenu()
{
    SeaFoodQ line;   //Declare SeaFoodQ (dynamic queue)
    int choice = 0;  //Declare and initialize choice to 0
    

    do
    {
        cout << "**************************************" << endl;
        cout << "*******     DISPLAY MENU     **********" << endl;
        cout << "*******    1. Add Customer   *********" << endl;
        cout << "*******    2. Place Order    *********" << endl;
        cout << "*******    3. Count          *********" << endl;
        cout << "*******    4. Draw Raffle    *********" << endl;
        cout << "*******    5. Display Line   *********" << endl;
        cout << "*******    6. Exit Menu      *********" << endl;
        cout << "**************************************" << endl;

        cin >> choice; 


        try
        {
            //If invalid menu option
            if(cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');                
                throw runtime_error("Invalid input: Not an integer");
            }

        }catch(runtime_error e)
        {
            //Output error message to console and allow user to try again
            cout << e.what() << endl;
        }


        switch(choice)
        {
            case 1:
                addCustomer(line);
                break;
            case 2: 
                placeOrder(line);
                break;
            case 3:
                countNames(line);
                break;
            case 4: 
                drawRaffle(line);
                break;
            case 5:
                displayLine(line);
                break;
            case 6: 
                cout << "Exiting Program" << endl;
                break;
            default: 
                cout << "Invalid range! Only choose 1-6!" << endl;
                break;    

        }

    }while(choice != 6);

}