/**
 * Name - David Joves
 * 
 * 
 * Assignment - Chapter 18 Programming Assignment
 * 
 * 
 * Date 05 - APR - 2023
*/
#include "LinkedList.h"
#include <iostream>     //Needed for cout, cin 
#include <iomanip>      //Needed for fixed, left
#include <cctype>       //Needed for isdigit and isalpha
#include <exception>    //Needed for try-catch blocks
#include <limits>       //Needed for numeric_limits<streamsize>::max()

using namespace std;

//Function prototypes 

void appendBead(LinkedList &necklace);
void insertBead(LinkedList &necklace);
void deleteBead(LinkedList &necklace);
void searchBead(LinkedList &necklace);
void displayNecklace(LinkedList &necklace);
bool validateBead(string bead);
string getUserInput(string prompt);
void displayMenu();

int main()
{
    displayMenu();
    return 0;
}

// ********************************************************
// name:      validateBead
// called by: appendBead, insertBead, searchBead
// passed:    string bead
// returns:   bool (true or false)
// calls:     nothing
// The validateBead function will determine a boolean     *
// value that would validate if the string bead passed    *
// is a valid option for the program.                     *
// ********************************************************
bool validateBead(string bead)
{
    //Make string all lowercase
    for(int i = 0; i < bead.length(); i++)
    {
        bead[i] = tolower(bead[i]);
    }
    //If bead is any of the options return true, otherwise return false
    if(bead == "turquoise" || bead == "coral" ||bead == "gold" || bead == "copper" )
    {
        return true;
    }

    return false;
}

// ********************************************************
// name:      getUserInput
// called by: appendBead, insertBead, searchBead 
//            deleteBead
// passed:    string prompt
// returns:   string 
// calls:     nothing
// The getUserInput function outputs a prompt to the      *
// console and user will have a string variable to accept *
// any input given by the user                            *
// ********************************************************
string getUserInput(string prompt)
{
    string userInput;               //Declare and initialize userInput
    cout << prompt;
    getline(cin >> ws, userInput);  //Get the line disregarding any whitespace in stream

    for(int i = 0; i < userInput.length(); i++) //Make all char in userInput lowercase
    {
        userInput[i] = tolower(userInput[i]);
    }
    return userInput;
}

// ********************************************************
// name:      displayMenu
// called by: main
// passed:    nothing
// returns:   nothing
// calls:     appendBead, insertBead, deleteBead 
//            displayNecklace, and searchBead
// The displayMenu function will output to console the    *
// menu functions where user will be able to append,      *
// insert, delete, search, and display beads in linked    *
// list
// ********************************************************
void displayMenu()
{
    LinkedList necklace; //Declare a LinkedList object

    int choice = 0;     //Declare and initialize int choice to 0
    do
    {
        //Menu
        cout << "********************************" << endl;
        cout << "*******       MENU       *******" << endl;
        cout << "******* 1. Append Bead   *******" << endl;
        cout << "******* 2. Insert Bead   *******" << endl;
        cout << "******* 3. Delete Bead   *******" << endl;
        cout << "******* 4.   Display     *******" << endl;
        cout << "******* 5.   Search      *******" << endl;
        cout << "******* 6.    Exit       *******" << endl;
        cout << "********************************" << endl;
        cout << "Choose a menu option!: ";
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

        //Menu options
        switch(choice)
        {
            case 1:
                appendBead(necklace);
                break;
            case 2:
                insertBead(necklace);
                break;
            case 3:
                deleteBead(necklace);
                break;
            case 4:
                displayNecklace(necklace);
                break;
            case 5:
                searchBead(necklace);
                break;
            case 6:
                necklace.~LinkedList();
                cout << "Bye! I hope you are liking your bead choices~" << endl;
                break;
            default: 
                cout << "Not in range! Please choose 1-6" << endl;
                break;
        }
    }while(choice != 6);
}


// ********************************************************
// name:      appendBead
// called by: displayMenu
// passed:    LinkedList &necklace 
// returns:   nothing
// calls:     getUserInput, validateBead
// The appendBead function appends a bead to the end of   *
// the LinkedList object (necklace). User will determine  *
// the bead material that will be appended                *
// ********************************************************
void appendBead(LinkedList &necklace)
{
    string userBead = "";      //Declare and initialize userBead to ""
    bool validBead;            //Declare validBead;
    bool validInput = false;   //Declare and initialize validInput to false
    bool userInput = false;    //Declare and initialize userInput to false

    //While not validInput
    while(!validInput)
    {
        cout << "Beads we have: turquoise, gold, coral, and copper:" << endl;
        userBead = getUserInput("Enter Bead Material: ");
        validBead = validateBead(userBead);

        //Validating userBead
        for(char c : userBead)
        {
            if(isdigit(c))
            {
                cout << "Cannot contain numbers!" << endl;
                userInput = false;
                break;
            }
            else
            {
                userInput = true;
                break;
            }
        }

         //If not valid userInput, redo inputs
        if(!userInput)
        {
            continue;
        }

        //If not validBead, let user know
        if(!validBead)
        {
            cout << "Error: " << userBead << " is not a material that we carry." << endl;
        }
        else
        {   
            //Add bead to necklace
            necklace.appendNode(userBead);
            validInput = true;
        }
    }

}

// ********************************************************
// name:      insertBead
// called by: displayMenu
// passed:    LinkedList &necklace 
// returns:   nothing
// calls:     getUserInput, validateBead
// The insertBead function inserts a bead at a valid      *
// position in the LinkedList object (necklace). User     *
// choose the bead material and position.                 *
// ********************************************************
void insertBead(LinkedList &necklace)
{
    //Declare and initialize userInput and userBead to ""
    string userBead = "";           
    string userPos = "";      
    
    //Declare and initialize booleans for validating data
    bool validBead;              
    bool userInput;    
    bool validInputBead = false; 
    bool validPos = false;                

    //Declare and initialize result and position to 0
    int result = 0;              
    int position = 0;            

    cout << "Beads we have: turquoise, gold, coral, and copper:" << endl;

    //While not valid input for bead
    while(!validInputBead)
    {
        userBead = getUserInput("Enter Bead Material: ");
        
        //Checking char in userBead for digits
        for(char c : userBead)
        {
            if(isdigit(c))
            {
                cout << "Cannot contain numbers!" << endl;
                userInput = false;
                break;
            }
            else
            {
                userInput = true;
                break;
            }
        }

        //If not valid input, redo input
        if(!userInput)
        {
            continue;
        }
        //Otherwise, check for valid bead input
        else
        {
            validBead = validateBead(userBead);
        }

        //If not valid bead input redo input 
        if(!validBead)
        {
            cout << "Error: " << userBead << " is not a material that we carry." << endl;
        }
        else
        {
            validInputBead = true;
        }
    }

    //While not valid input for position
    while(!validPos)
    {
        userPos = getUserInput("Enter Insert Position: ");

        //Checking chars in userPos for letters
        for(char c : userPos)
        {
            if(isalpha(c))
            {
                cout << "No letters!" << endl;
                userInput = false;
                break;
            }
            else
            {
                userInput = true;
                break;
            }
        }

        //If not valid input, redo input
        if(!userInput)
        {
            continue;
        }

        //Initialize position to userPos using stoi()
        position = stoi(userPos);

        //If position is less than 0, redo input
        if(position < 0)
        {
            cout << "Position has to be unsigned int!" << endl;
            continue;
        }
        //If position is bigger than size of necklace, redo inputs
        else if(position > necklace.getSize())
        {
            cout << "I'm sorry, but bead position " << position << " does not exist." << endl;
            continue;
        }   
        //Otherwise, insert bead in position 
        else
        {
            result = necklace.insertNode(userBead,position);
            break;
        }
    }

    //If result is -1, output bead position does not exist
    if(result == -1)
    {
        cout << "I'm sorry, but bead position " << position << " does not exist." << endl;
    }
}

// ********************************************************
// name:      deleteBead
// called by: displayMenu
// passed:    LinkedList &necklace 
// returns:   nothing
// calls:     getUserInput, validateBead
// The deleteBead function deletes a bead in position that*
// user has given. 
// ********************************************************
void deleteBead(LinkedList &necklace)
{
    string userPos = "";    //Declare and initialize userPos to ""

    bool validPos = false;  //Declare and initialize validPos to false

    //Declare and initialize position and result to 0
    int position = 0;       
    int result = 0;

    //While not a valid position
    while(!validPos)
    {
        userPos = getUserInput("What bead position do you wish to delete? ");

        //Checks for letters
        for(char c : userPos)
        {
            if(isalpha(c))
            {
                cout << "No letters!" << endl;
                break;
            }
            else
            {
                break;
            }
        }

        //Set position to userPos with stoi()
        position = stoi(userPos);

        //If position is less than 0, redo inputs
        if(position < 0)
        {
            cout << "Position has to be unsigned int!" << endl;
            continue;
        }
        else
        {
            validPos = true;
        }
        
    }
    result = necklace.deleteNode(position);

    //If result is -1, let user know bead position does not exist
    if(result == -1)
    {
        cout << "I'm sorry, but bead position " << position << " does not exist." << endl;
    }
    //Otherwise, let user know node has been removed
    else
    {
        cout << "Node (" << position << ") has been removed from your list" << endl;
    }
}

// ********************************************************
// name:      displayNecklace
// called by: displayMenu
// passed:    LinkedList &necklace 
// returns:   nothing
// calls:     nothing
// The displayNecklace function, displays each bead in the*
// LinkedList object (necklace).                          *
// ********************************************************
void displayNecklace(LinkedList &necklace)
{
    necklace.display();
}

// ********************************************************
// name:      deleteBead
// called by: displayMenu
// passed:    LinkedList &necklace 
// returns:   nothing
// calls:     getUserInput, validateBead
// The searchBead function looks through each bead in     *
// the LinkedList object, and see if it matches bead user *
// wants to search for. Will output the position, if found*
// ********************************************************
void searchBead(LinkedList &necklace)
{
    //Declare and initialize userInput to ""
    string userBead = "";       

    //Declare and initialize booleans to validate inputs
    bool validBead;
    bool validInput = false;
    
    //Declare and initialize result to 0
    int result = 0;

    //While not validInput, get user input
    while(!validInput)
    {
        userBead = getUserInput("Enter color to search for: ");
        validBead = validateBead(userBead);

        //If not validBead, redo inputs
        if(!validBead)
        {
            cout << "Error: " << userBead << " is not a material that we carry." << endl;
        }
        //Otherwise, exit while loop
        else
        {
            validInput = true;
        }
    }

    result = necklace.searchNode(userBead);

    //If result is -1, let user know there is no bead located anywhere
    if(result == -1)
    {
        cout << "No " << userBead << " located at any position" << endl;
    }
}