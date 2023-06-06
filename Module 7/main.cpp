/**
 * Name - David Joves
 * 
 * 
 * Assignment - Chapter 21 - Programming Assignment
 * 
 * 
 * Date: 18 - MAY - 2023
*/

//Driver File (main) for BinarySearchTree

#include "BinaryTree.h"     //Needed for BinarySearchTree class
#include <iostream>         //Needed for cout 
#include <string>           //Needed for strings
#include <cctype>           //Needed for isalpha
#include <exception>        //Needed for try-catch 
#include <limits>           //Needed for numeric_limits<streamsize>::max()

using namespace std; 

//Global Constants

const int ARRAY_SIZE = 15;
const int NUMBERS[ARRAY_SIZE] = {10, 87, 9, 55, 13, 40, 22, 1, 0, 77, 0, 4, 55, 33, 22};

//Function Prototypes 

void insertInt(BinarySearchTree &tree);
void displayTree(BinarySearchTree &tree);
void displayLeafCount(BinarySearchTree &tree);
void displayTreeHeight(BinarySearchTree &tree);
void displayTreeWidth(BinarySearchTree &tree);
void loadData(BinarySearchTree &tree);
void displayMenu();

int main()
{
    displayMenu();
    return 0;
}

// ********************************************************
// name:      insertInt
// called by: displayMenu
// passed:    BinarySearchTree &tree
// returns:   nothing
// calls:     nothing
// The displayTree function, allows user to input an int  *
// to have it inserted into their binary tree.            *       
// ********************************************************
void insertInt(BinarySearchTree &tree)
{
    string userNum;     //Declare userNum for input 
    int key;            //Declare key to hold converted userNum;
    
    //Declare validating variables
    bool validInt = false;
    bool validInput = false;

    while(!validInput)
    {
        cout << "Input number to insert into tree" << endl;

        getline(cin >> ws, userNum);

        for(char c : userNum)
        {
            if(isalpha(c))
            {
                cout << "Please enter only integers!" << endl;
                break;
            }
            else
            {
                cout << userNum << " was inserted into tree!" << endl;
                key = stoi(userNum);
                tree.insert(key);
                validInput = true; 
                break;
            }
        }
    }
}

// ********************************************************
// name:      displayTree
// called by: displayMenu
// passed:    BinarySearchTree &tree
// returns:   nothing
// calls:     nothing
// The displayTree function, will output the data in each *
// node, organized in order.                              *
// ********************************************************
void displayTree(BinarySearchTree &tree)
{   
    if(!tree.isEmpty())
    {
        cout << "Current Nodes in tree:" << endl;
        tree.displayInOrder();
        cout << endl;
    }
    else
    {
        cout << "Tree is empty!" << endl;
    }
}  

// ********************************************************
// name:      displayLeafCount
// called by: displayMenu
// passed:    BinarySearchTree &tree
// returns:   nothing
// calls:     nothing
// The displayTreeHeight function, will output the amount *
// of leaves in user's binary tree                        *
// ********************************************************
void displayLeafCount(BinarySearchTree &tree)
{
    if(tree.isEmpty())
    {
        cout << "Tree is empty!" << endl;
    }

    int count = tree.getLeafCount();
    cout << "Leaf Count : " << count << endl;
}

// ********************************************************
// name:      displayTreeHeight
// called by: displayMenu
// passed:    BinarySearchTree &tree
// returns:   nothing
// calls:     nothing
// The displayTreeHeight function, will output the height *
// of user's binary tree.                                 *
// ********************************************************
void displayTreeHeight(BinarySearchTree &tree)
{
    if(tree.isEmpty())
    {
        cout << "Tree is empty!" << endl;
    }
    int count = tree.getHeightCount();
    cout << "Height: " << count << endl;
}

// ********************************************************
// name:      displayTreeWidth
// called by: displayMenu
// passed:    BinarySearchTree &tree
// returns:   nothing
// calls:     nothing
// The displayTreeWidth function, goes through each level *
// and determine which level has the most nodes then will *
// output to console.                                     *
// ********************************************************
void displayTreeWidth(BinarySearchTree &tree)
{
    if(tree.isEmpty())
    {
        cout << "Tree is empty!" << endl;
    }
    int maxHeight = tree.getHeightCount();
    int maxWidth = 0;

    for (int level = 1; level <= maxHeight; ++level)
    {
        int currWidth = tree.getWidthCount(level);

        if (currWidth > maxWidth)
        {
            maxWidth = currWidth;
        }
    }
    cout << "Width: " << maxWidth << endl;
}

// ********************************************************
// name:      loadData
// called by: displayMenu
// passed:    BinarySearchTree &tree
// returns:   nothing
// calls:     nothing
// The loadData function, inserts integers from constant  *
// vector into binary tree                                *
// ********************************************************
void loadData(BinarySearchTree &tree)
{
    
    for(int i = 0; i < ARRAY_SIZE; i++)
    {
        tree.insert(NUMBERS[i]);
    }
    cout << "Data is loaded into binary tree!" << endl;
}

// ********************************************************
// name:      displayMenu
// called by: main
// passed:    nothing
// returns:   nothing
// calls:     loadData, insertInt, displayTree, 
//            displayLeafCount,  displayTreeHeight
//            displayTreeWidth.
// The displayMenu function will output to console the    *
// menu functions where user will be able insert nodes,   *
// display their binary Tree, and count leaves, height and*
// width of tree.
// ********************************************************
void displayMenu()
{
    BinarySearchTree tree; 

    int userChoice = 0; 

    while(userChoice != 7) 
    {
        cout << "********************************" << endl;
        cout << "******  Menu Display    ********" << endl;
        cout << "******  1. Load Data    ********" << endl;
        cout << "******  2. Insert       ********" << endl;
        cout << "******  3. Display Tree ********" << endl;
        cout << "******  4. Leaf Count   ********" << endl;
        cout << "******  5. Tree Height  ********" << endl;
        cout << "******  6. Tree Width   ********" << endl;
        cout << "******  7. Exit         ********" << endl;
        cout << "********************************" << endl;

        cin >> userChoice; 

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

        switch(userChoice)
        {
            case 1: 
                loadData(tree);
                break;
            case 2:
                insertInt(tree);
                break;
            case 3:
                displayTree(tree);
                break;
            case 4:
                displayLeafCount(tree);
                break;
            case 5: 
                displayTreeHeight(tree);
                break;
            case 6:
                displayTreeWidth(tree);
                break;
            case 7: 
                cout <<"Exiting Program. . ." << endl;
                tree.~BinarySearchTree();
                break;
            default: 
                cout << "Only enter 1 - 7!" << endl;

        }

    }
}