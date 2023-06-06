/**
 * Name - David Joves
 * 
 * Assignment - Chapter 13 Programming Assignment
 * 
 * Date - 22 - MAR - 2023
*/

//Specification file for the Inventory class
#ifndef INVENTORY_H
#define INVENTORY_H
#include <string>

using namespace std; 

class Inventory
{
    //Private Member variables 
    private: 
        string dogLicense; 
        string dogName; 
        string ownerPhone; 
        float priceQuoted; 

    //Public Member variables 
    public: 
        //Constructor #1 (Default Constructor)
        Inventory();
    
        //Mutator Functions (Setter Functions)
        void setDogLicense(string);
        void setDogName(string);
        void setOwnerPhone(string);
        void setPriceQuoted(float);

        //Accessor Functions (Getter Functions)
        string getDogLicense();
        string getDogName();
        string getOwnerPhone();
        float getPriceQuoted();
};
#endif