/**
 * Name: David Joves
 * 
 * Assignment: Chapter 6 & 7 Review Programming Assignment - Integers
 * 
 * Date: 09 - MAR - 2023
*/

#include <iostream>
#include <stdexcept>
#include <limits>

//Global Constant

const int COLS = 4;
const int ROWS = 4;

using namespace std; 

//Function Prototypes

void displayMatrix(int matrix [][COLS]);
void findInteger(int matrix[][COLS]);
void swapColumns(int matrix[][COLS]);
void displayMenu();

int main()
{
    displayMenu();
    return 0;
}

// ********************************************************
// name:      displayMatrix
// called by: displayMenu
// passed:    int matrix [][COLS]
// returns:   nothing
// calls:     nobody
// The displayMatrix function outputs the elements of the *
// matrix into it's canonical form of rows and columns.   *                                    
// ********************************************************
void displayMatrix(int matrix[][COLS])
{
    //Iterate through matrix 
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            //Output element to console
            cout << matrix[i][j] << "\t";
        }
        //New line for new row
        cout <<endl;
    }
}
// ********************************************************
// name:      findInteger
// called by: displayMenu
// passed:    int matrix [][COLS]
// returns:   nothing
// calls:     nobody
// The findInteger function outputs the row and column    *
// coordinate of user's desired integer inside the matrix.*                                    
// ********************************************************
void findInteger(int matrix[][COLS])
{
    //Initialize user's desired number and bool if their integer is found is found
    int desiredInteger = 0; 
    bool foundInteger = false;

    //Asks user to input the integer they want to find
    while(true)
    {
        cout << "Enter integer you want to find!" << endl;
        cin >> desiredInteger; 

        //Handles exception where user does not enter an integer
        try
        {
            if(cin.fail())
            {
                //Clear the input buffer and then throw exception
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');                
                throw runtime_error("Invalid input: Not an integer");
            }
        break;
        } catch(runtime_error e)
        {
            //Output error message to console and allow user to try again
            cout << e.what() << endl;
            continue;  
        }
    }
    //Iterate through matrix 
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            //If desired integer is found, output the coordinates of matrix to console
            if(matrix[i][j] == desiredInteger)
            {
                cout << "Integer found at row: " << i << " column: " << j << endl;
                foundInteger = true;
                break;
            }
        }
    }
    //If Integer is not found, output to console that is it not in the matrix
    if(!foundInteger)
    {
        cout << "Integer not found in matrix!" << endl;
    }
}
// ********************************************************
// name:      swapColumns
// called by: displayMenu
// passed:    int matrix [][COLS]
// returns:   nothing
// calls:     nobody
// The swapColumns function swaps all elements in columns *
// 1 and 3 in user's matrix through a temporary variable. *                                    
// ********************************************************
void swapColumns(int matrix[][COLS])
{
    //Declare and initialize a temporary var
    int temp = 0; 
    //Iterate through the elements in each row
    for(int i = 0; i < ROWS; i++)
    {
        //Set temporary var to element in row i and column 1
        temp = matrix[i][1];
        
        //Set element in row i and column 1 to element in row i and column 3
        matrix[i][1] = matrix[i][3];
        //Set element in row i and column 3 to temporary var
        matrix[i][3] = temp;
    }
}
// ********************************************************
// name:      displayMenu
// called by: main
// passed:    nothing
// returns:   nothing
// calls:     displayMatrix, findInteger, swapColumns
// The displayMenu function allows user input to choose   *
// how to manipulate the established 4x4 matrix.          *                                    
// ********************************************************
void displayMenu()
{
    //Declaring and initializing matrix
    int userMatrix[][COLS] = 
    {
        {1, 3, 5, 7}, 
        {9, 11, 13, 15},
        {17, 19, 21, 23},
        {25, 27, 29, 31}
    };

    //Declare and initialize choice var
    int choice = 0;
    while(choice!= 4) 
    {
        cout << "************* Display Menu ****************" << endl;
        cout << "*      1. Display Matrix                  *" << endl;
        cout << "*      2. Find My Integer                 *" << endl;
        cout << "*      3. Swap Column 1 with Column 3     *" << endl;
        cout << "*      4. Exit Program                    *" << endl;
        cout << "*******************************************" << endl;
        cin >> choice;

        //Handles exception if user inputs an invalid choice
        try
        {
            if(cin.fail())
            {
                //Clears input buffer and throws exception
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');                
                throw runtime_error("Invalid input: Not an integer");
            }
        } catch(runtime_error e)
        {
            //Output error message to console and allow user to try again
            cout << e.what() << endl;
        }
        switch(choice)
        {
            case 1: 
                cout << endl;
                displayMatrix(userMatrix);
                cout << endl;
                break;
            case 2: 
                findInteger(userMatrix);
                cout << endl;
                break;
            case 3:
                swapColumns(userMatrix);
                break;
            case 4:
                break;
            default: 
                //If user inputs number less than 1 or greater than 4, have user try again
                cout << "Only enter numbers 1-4 please!" << endl;
                break;
        }
    }
    cout << "End of Program!" << endl;
}