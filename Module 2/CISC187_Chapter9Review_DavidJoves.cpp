/**
 * Name: David Joves
 * 
 * Assignment: Chapter 9 Review Programming Assignment 
 * 
 * Date: 13 - MAR - 2023
*/
#include <iostream> 
#include <limits>
#include <exception> 

using namespace std; 

//Global Constant 
const int SIZE = 4; 

//Function Prototypes 

void displayAs2D(int* array);
void findInteger(int* array);
void swapColumns(int* array); 
void displayMenu();

int main()
{
    displayMenu();
    return 0;
}

// ********************************************************
// name:      displayAs2D
// called by: displayMenu, swapColumns
// passed:    int* array
// returns:   nothing
// calls:     nobody
// The displayAs2D function outputs the elements of the   *
// one-dimensional array as a two-dimensional array.      *  
// Utilizing pointer addressing than indexing.            * 
// ********************************************************
void displayAs2D(int* array)
{

    //Iterate through array and display each element represented in rows and columns
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            //Displays elements using the address of where pointer is currently at
            cout << *(array + i * SIZE + j) << "\t";
        }
        //Displays space to put elements in new row
        cout << endl; 
    }
}
// ********************************************************
// name:      findInteger
// called by: displayMenu
// passed:    int* array
// returns:   nothing
// calls:     nobody
// The findInteger function outputs the row and column    *
// coordinate of user's desired integer inside the 1D     * 
// array displayed as a 2D array. Utilizing pointer       *
// addressing than indexing.                              *
// ********************************************************
void findInteger(int* array)
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

    //Iterate through array
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            //If desired integer is found at current pointer, output the coordinates as if it was a 2D array (row then column)
            if(*(array + i * SIZE + j) == desiredInteger)
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
// passed:    int* array
// returns:   nothing
// calls:     displayAs2D
// The swapColumns function swaps all elements in columns *
// 1 and 3 in user's matrix through a temporary variable. * 
// Utilizing pointer addressing than indexing.            *                       
// ********************************************************
void swapColumns(int* array)
{
    // Declare and initialize a temporary variable; 
    int temp = 0;
    //Iterate through array using pointer variable address 
    for(int i = 0; i < SIZE; i++)
    {
        temp = *(array + i * SIZE + 1);
        *(array + i * SIZE + 1) =  *(array + i * SIZE + 3);
        *(array + i * SIZE + 3) = temp;
    }

    //Displays the array after columns 1 and 3 have been switched
    cout << "Switched columns 1 and 3!" << endl;
    displayAs2D(array);

}
// ********************************************************
// name:      displayMenu
// called by: main
// passed:    nothing
// returns:   nothing
// calls:     displayAs2D, findInteger, swapColumns
// The displayMenu function allows user input to choose   *
// how to manipulate the 1D array represented as a 2D     *  
// array.                                                 *
// ********************************************************
void displayMenu()
{
    //Declare and initialize 1D array 
    int array[] = {1, 3, 5, 7,9, 11, 13, 15,17, 19, 21, 23,25, 27, 29, 31};

    //Declare and initialize pointer variable 
    int* pointer = nullptr; 
    pointer = array; 
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
                displayAs2D(pointer);
                cout << endl;
                break;
            case 2: 
                findInteger(pointer);
                cout << endl;
                break;
            case 3:
                swapColumns(pointer);
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