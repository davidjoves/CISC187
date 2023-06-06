/**
 * Name - David Joves
 * 
 * 
 * Assignment - Chapter 19 Programming Assignment - The Say What (!?!) Stack
 * 
 * 
 * Date 20 - APR - 2023
*/

#include "WordStack.h"      //Needed for StoryStack class
#include <string>           //Needed for strings
#include <iostream>         //Needed for cout, cin
#include <cctype>           //Needed for isDigit 
#include <exception>        //Needed for try-catch 
#include <limits>           //Needed for numeric_limits<streamsize>::max()
#include <cstdlib>          //Needed for rand()

using namespace std; 

const int MAX_LENGTH = 10;
const int MIN_STORY_WORDS = 5;

//Function prototypes 

void push(StoryStack &story);
void pop(StoryStack &story);
void capitalize(StoryStack &story);
void displayStack(StoryStack &story);
void createStory(StoryStack &story);
void displayMenu();


int main()
{
    displayMenu();
    return 0;
}


// ********************************************************
// name:      push
// called by: displayMenu
// passed:    StoryStack& story
// returns:   nothing
// calls:     nothing
// The push function will allow user to input a string    *
// and push it on to a StoryStack object.                  *
// ********************************************************
void push(StoryStack &story)
{
    string userWord;            //Declare userWord 

    bool validWord = false;     //Declare and initialize validating booleans to false
    bool validInput = false;

    //While not validInput
    while(!validInput)
    {
        cout << "Push a word onto the stack!" << endl;
        getline(cin >> ws, userWord);


        for(char c : userWord)
        {   
            //If userWord contains digit, set bool to false 
            if(isdigit(c))
            {
                validWord= false;
                break;          //If digit found, break out of for loop
            }
            else 
            {
                validWord = true;
            }
        }

        //If userWord is too long, prompt user
        if(userWord.length() > MAX_LENGTH)
        {
            cout << "Word is too long! Make it less than 10 letters!" << endl;
            continue; 
        }
        //If validWord is false, prompt user
        else if (!validWord)
        {
            cout << "Only push words onto the stack! No numbers!" << endl;
        }
        //Otherwise, push validated word onto stack
        else
        {
            cout << userWord << " was pushed onto the stack!" << endl;
            story.push(userWord);
            validInput = true;
        }
    }
}

// ********************************************************
// name:      pop
// called by: displayMenu
// passed:    StoryStack& story
// returns:   nothing
// calls:     nothing
// The pop function will allow user to pop a string they  *
// input off of the top of a StoryStack object.           *
// ********************************************************
void pop(StoryStack &story)
{
    string popWord;     //Declare string to hold popped word

    //If stack is empty, prompt user
    if(story.isEmpty())
    {
        cout << "Stack is empty! Push words onto it!" << endl;
    }
    //Otherwise, pop word at top of stack
    else
    {
        story.pop(popWord);
        cout << "Popped " << popWord << " off of stack" << endl;
    }

}

// ********************************************************
// name:      displayStack
// called by: displayMenu
// passed:    StoryStack& story
// returns:   nothing
// calls:     nothing
// The displayStack function will allow user to see all   *
// strings they've pushed into StoryStack object.         *
// ********************************************************
void displayStack(StoryStack &story)
{
    //If stack is empty, prompt user
    if(story.isEmpty())
    {
        cout << "Stack is empty! Push words onto it!" << endl;
    }
    //Otherwise display current stack
    else
    {
        cout << "Here is your current stack of words:" << endl;
        story.displayStack();
    }
}

// ********************************************************
// name:      capitalize
// called by: displayMenu
// passed:    StoryStack& story
// returns:   nothing
// calls:     nothing
// The capitalize function will allow user to change the  *
// strings they've pushed into StoryStack object to have  *
// it have all uppercase letters.                         *
// ********************************************************
void capitalize(StoryStack &story)
{
    //If stack is empty, prompt user
    if(story.isEmpty())
    {
        cout << "Stack is empty! Push words onto it!" << endl;
    }
    //Otherwise, capitalize all words and display stack with changes
    else
    {
        cout << "Current stack has been capitalized! See below:" << endl;
        story.capitalize();
        story.displayStack();
    }
}

// ********************************************************
// name:      createStory
// called by: displayMenu
// passed:    StoryStack& story
// returns:   nothing
// calls:     nothing
// The createStory function will allow user to output a   *
// a story to console by popping off the strings they     *
// pushed onto the StoryStack object.                     *
// ********************************************************
void createStory(StoryStack &story)
{
    string popWord;         //Declare string to hold popped words
    int difference = 0;     //Declare and initialize difference to 0

    //If size of stack is less than MIN_STORY_WORDS, prompt user to push more words
    if(story.getSize() < MIN_STORY_WORDS)
    {
        //Calculate how many more words are needed to create story
        difference = (MIN_STORY_WORDS - story.getSize());       

        //Prompt user 
        cout << "Not enough words to create the story! Push " << difference << " more word(s) onto the stack!" << endl;     
    }
    //Otherwise, create story with words in stack using pop function
    else
    {
    
        story.pop(popWord);
        cout << "When I was in class, I was being a bit " << popWord; 
        cout << " and I decided to stand up and take myself to ";

        story.pop(popWord);
        cout << popWord;
        cout << ". I eventually found myself at ";

        story.pop(popWord);
        cout<< popWord << " on my computer watching ";

        story.pop(popWord);
        cout<< popWord;

        story.pop(popWord);
        cout << " do " << popWord << "." << endl;
    }
    
}


// ********************************************************
// name:      displayMenu
// called by: main
// passed:    nothing
// returns:   nothing
// calls:     push, pop, displayStack, capitalize, and
//            createStory
// The displayMenu function will output to console the    *
// menu functions where user will be able to push and pop *
// strings onto a stack, display and capitalize the stack *
// and also create a story using the stack.               *
// ********************************************************
void displayMenu()
{

    StoryStack story;       //Declare StoryStack object

    int userInput = 0;      //Declare and initialize userInput to 0

    do
    {
        //Menu
        cout << "-----------------------------------------------" << endl;
        cout << "----------      Display Menu          ---------" << endl;
        cout << "----------      1. Push word          ---------" << endl;
        cout << "----------      2. Pop word           ---------" << endl;
        cout << "----------      3. Display stack      ---------" << endl;
        cout << "----------      4. Capitalize stack   ---------" << endl;
        cout << "----------      5. Create story       ---------" << endl;
        cout << "----------      6. Exit               ---------" << endl;
        cout << "-----------------------------------------------" << endl;

        cin >> userInput; 

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

        switch(userInput)
        {
            case 1: 
                push(story);
                break;
            case 2:
                pop(story);
                break;
            case 3:
                displayStack(story);
                break;
            case 4:
                capitalize(story);
                break;
            case 5:
                createStory(story);
                break;
            case 6:
                story.~StoryStack();
                cout << "Exiting program" << endl;
                break;
            default: 
                cout << "Only choose numbers through 1-6!" << endl;
                break;
        }
    }while(userInput != 6);
   
}