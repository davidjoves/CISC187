/**
 * Name - David Joves
 * 
 * Assignment - Chapter 13 Programming Assignment
 * 
 * Date - 22 - MAR - 2023
*/

//Implementation file for Inventory class
#include "Inventory.h"  //Needed for the Recntangle class
#include <iostream>     //Needed for cout
#include <cstdlib>      //Needed for exit function
#include <cctype>       //Needed for isdigit, isalpha 



using namespace std; 

//Global Variables 

const int MAX_LICENSE_LENGTH = 10;
const int MAX_NAME_LENGTH = 15;
const int MAX_PHONE_LENGTH = 11;


//***********************************************************************************
// The constructor sets dogLicense, dogName, ownerPhone, and priceQuoted to "" or 0 *
// to it's respective data type.                                                    *
//***********************************************************************************
Inventory::Inventory()
{
    dogLicense = ""; 
    dogName = "";
    ownerPhone = ""; 
    priceQuoted = 0.0;
}

//***********************************************************************************
// setDogLicense sets the value of the member variable dogLicense                   *
//***********************************************************************************
void Inventory :: setDogLicense(string license)
{
    if(license.length() < MAX_LICENSE_LENGTH)
    {
        dogLicense = license;
    }
    else
    {
        cout << "Invalid dog license: Dog license is too long! " << endl;
        exit(EXIT_FAILURE);
    }
}

//***********************************************************************************
// setDogName sets the value of the member variable dogName                         *
//***********************************************************************************
void Inventory :: setDogName(string name)
{
    for(char c : name)
    {
        if(isalpha(c) && name.length() < MAX_NAME_LENGTH)
        {
            dogName = name; 
            break;
        }
        else
        {
            cout << "Invalid dog name!: Name must contain only letters and be less than 15 characters long!" << endl;
            exit(EXIT_FAILURE);
        }
    }
}

//***********************************************************************************
// setOwnerPhone sets the value of the member variable ownerPhone                   *
//***********************************************************************************
void Inventory :: setOwnerPhone(string phone)
{
    for(char c : phone)
    {
        if(isdigit(c) && phone.length() < MAX_PHONE_LENGTH)
        {
            ownerPhone = phone;
            break;
        }
        else 
        {
            cout << "Invalid phone number: Phone number must contain only digits and be less than 11 characters long!" << endl;
            break;
            exit(EXIT_FAILURE);
        }
    }
}

//***********************************************************************************
// setPriceQuoted sets the value of the member variable priceQuoted                 *
//***********************************************************************************
void Inventory :: setPriceQuoted(float price)
{
    if(price >= 0)
    {
        priceQuoted = price;
    }
    else
    {
        cout << "Invalid price! Has to be greater than or equal to 0! " << endl;
        exit(EXIT_FAILURE);
    }
}

//***********************************************************************************
// getDogLicense returns the value of the member variable dogLicense                   *
//***********************************************************************************
string Inventory :: getDogLicense()
{
    return dogLicense;
}

//***********************************************************************************
// getDogName returns the value of the member variable dogName                         *
//***********************************************************************************
string Inventory :: getDogName()
{
    return dogName;
}

//***********************************************************************************
// getOwnerPhone returns the value of the member variable ownerPhone                   *
//***********************************************************************************
string Inventory :: getOwnerPhone()
{
    return ownerPhone;
}

//***********************************************************************************
// getPriceQuoted returns the value of the member variable priceQuoted                 *
//***********************************************************************************
float Inventory :: getPriceQuoted()
{
    return priceQuoted;
}