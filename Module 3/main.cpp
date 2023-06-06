/**
 * Name - David Joves
 * 
 * Assignment - Chapter 13 Programming Assignment
 * 
 * Date - 22 - MAR - 2023
*/
#include <iostream>     //Needed for cout, cin 
#include <iomanip>      //Needed for fixed, left
#include <cctype>       //Needed for isdigit and isalpha
#include <exception>    //Needed for try-catch blocks
#include <limits>       //Needed for numeric_limits<streamsize>::max()
#include "Inventory.h"  //Needed for Inventory class

using namespace std; 

//Global Variables
const int SIZE = 5;
const int MAX_LICENSE_LENGTH = 10;
const int MAX_NAME_LENGTH = 15;
const int MAX_PHONE_LENGTH = 11;



//Function Prototypes 

void displayMenu();
void addJob(Inventory *dogs);
void listJobs(Inventory *dogs);


int main()
{
    displayMenu();
    return 0;
}

// ********************************************************
// name:      addJob
// called by: displayMenu
// passed:    Inventory *dogs
// returns:   nothing
// calls:     nothing
// The addDog function will create a new dog object in    *
// array, where user will determine it's properties like  *
// dogLicense, dogName, ownerPhone, and price quoted      *
// ********************************************************
void addJob(Inventory *dogs)
{
    // Initialize current number of dogs (i) to 0
    int i = 0;

    //Declare user input variables and booleans
    string license, name, phone, priceInput; 
    float price; 
    bool validLicense = false, validName = false , validPhone = false, validPriceInput = false; 

    //While pointer is not empty, move to next address
    while(((dogs + i)->getDogLicense()) != "" && i < SIZE)
    {
        i++;

        //If i is MAX, return back to menu and to prevent memory leaks
        if(i == SIZE)
        {
            cout << "Max number of dogs reached. Cannot add another job" <<endl;
            return;
        }
    }

    
    //While license input is not valid, have user redo it's input
    while(!validLicense)
    {
        cout << "Enter the dog's license number:" << endl; 
        cin.ignore();
        getline(cin, license);

        if(license.empty())
        {
            cout << "License Can't be empty! Try again: "<< endl;             
            continue;
        }
        else if (!(license.length() < MAX_LICENSE_LENGTH))
        {
            cout << "License has to be less than 10 characters! Try again: "<< endl;             
            continue;              
        }
        else
        {
            validLicense = true;
        }
    }

    //While name input is not valid, have user redo it's input
    while(!validName)
    {
        cout << "Enter the dog's name: " << endl;
        getline(cin, name);

        if(name.empty())
        {
            cout << "Name cannot be empty! Try again!" << endl;              
            continue;
        }

        bool validData = true;
        for(char c : name)
        {   
            if(!isalpha(c) || !(name.length() < MAX_NAME_LENGTH))
            {
                cout << "Name cannot contain numbers and has to be less than 15 characters!" << endl;        
                validData = false;      
                break;
            }
        }

        if(validData)
        {
            validName = true; 
        }
    }

    //While phone input is not valid, have user redo it's input
    while(!validPhone)
    {
        cout << "Enter the owner's phone number: " << endl;
        getline(cin,phone);

        if( phone.empty())
        {
            cout << "Phone number cannot be empty! Try again!" << endl;             
            continue;
        }

        bool validData = true;
        for(char c : phone)
        {
            if(!isdigit(c) || !(phone.length() < MAX_PHONE_LENGTH) )
            {
                cout << "Phone number can only contain numbers and has to be less than 11 characters! Try again!" << endl;  
                validData = false;
                break;
            }
        }

        if(validData)
        {
            validPhone = true;
        }
    }

    //While price input is not valid, have user redo it's input
    while(!validPriceInput)
    {
        cout << "Enter the price quoted: " << endl;
        getline(cin, priceInput); 
        
        if( priceInput.empty())
        {
            cout << "Price cannot be empty! Try again!" << endl;
            continue;
        }

        bool validData = true; 
        for(char c: priceInput)
        {
            //Condition checks for proper input with only digits and allows values with a decimal to be validated
            if(!isdigit(c) && c != '.')
            {
                cout << "Invalid price! Only enter positive numbers! Try again!" << endl;
                validData = false;
                break;
            }
        }
        if(validData)
        {
            //Convert string to float
            price = stof(priceInput);
            validPriceInput = true;
        }
    }

    //Use mutator functions to set properties of each object
    ((dogs + i)->setDogLicense(license));
    ((dogs + i)->setDogName(name));
    ((dogs + i)->setOwnerPhone(phone));
    ((dogs + i)->setPriceQuoted(price));

    cout << "Thank you! We will take good care of " << name << " today!" << endl;

}
// ********************************************************
// name:      listJobs
// called by: displayMenu
// passed:    Inventory *dogs
// returns:   nothing
// calls:     nothing
// The addJob function will output to console the details *
// of each job. The total price of every current job will *
// be determined as well.                                 *
// ********************************************************
void listJobs(Inventory *dogs)
{
    // Initialize and declare current number of jobs (i) to 0
    int i = 0;
    // Initialize and declare current total to 0; 
    float totalPrice = 0.0;

    cout << "Current Jobs: " << endl;

    //While there is a job, print it's properties and move to next job if able
    while(((dogs + i)->getDogLicense()) != "")
    {
        cout << "Job #" << i+1 << endl;
        cout << left << fixed << "Dog license: " << '\t' << ((dogs + i)->getDogLicense()) << endl;
        cout << left << fixed << "Dog Name: " << '\t' << ((dogs + i)->getDogName())<< endl;
        cout << left << fixed << "Customer Phone: " << ((dogs + i)->getOwnerPhone())<< endl;
        cout << left << fixed << "Price Quoted: " << '\t' << setprecision(2) << ((dogs + i)->getPriceQuoted())<< endl;
        cout << "***" << endl;
        totalPrice += ((dogs + i)->getPriceQuoted());
        i++;
        //When i is maxed break while loop to not cause memory leaks
        if(i == SIZE)
        {
            break;
        }
    }
    //If no jobs, output no jobs found
    if(i == 0)
    {
        cout << "No jobs found" << endl;
    }
    //Outputs the total price of all jobs
    else
    {
       cout << "The total price of all jobs are: $" << totalPrice << endl;
    }

}
// ********************************************************
// name:      displayMenu
// called by: main
// passed:    nothing
// returns:   nothing
// calls:     addDog, listDogs
// The displayMenu function will output to console the    *
// menu functions where user will be able to add and      *
// display each job in an array of Inventory objects      * 
// ********************************************************
void displayMenu()
{
    //Declare array and initialize each object to it's default constructor
    Inventory dogs[SIZE]; 

    //Declare and initialize a pointer variable that points to dogs array
    Inventory *ptr = nullptr; 
    ptr = dogs; 

    //Declare and initialize choice variable to 0; 
    int choice = 0; 

    do 
    {
        cout << "*********** You Dirty Dog Menu ***********" << endl; 
        cout << "*           1. Add New Job               *" << endl;
        cout << "*           2. List all Jobs             *" << endl;
        cout << "*           3. Exit                      *" << endl;
        cout << "******************************************" << endl;
        cin >> choice; 
        try
        {
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
                addJob(ptr);
                break;
            case 2:
                listJobs(ptr);
                break;
            case 3: 
                cout << "Thanks for using the menu system and have a nice day." << endl;
                break;
            default: 
                cout << "Only enter numbers 1-3 please!" << endl;
                break;
        }
    } while(choice != 3);
}