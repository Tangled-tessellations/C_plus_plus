/*******************************************************************************
*Author: Alex McEvoy
*Date: 01/10/18
*Description: Implementation file for Utilities. Includes input validation.
*******************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include"Utilities.hpp"
using std::cout;
using std:: endl;
using std::vector;
using std::string;

/***********************************************************************
* Accepts a string message to output to user until they enter a
* valid integer
***********************************************************************/

int isInt(string msg)
{
    int answer;
    do{
        // Taken largely from
        // https://stackoverflow.com/questions/18728754/checking-input-value-is-an-integer
        // chemistpp's answer
        std::cout << msg << std::endl;
        std::cin >> answer;
        if(std::cin.fail())     // this redundancy with cin.fail() is used to eliminate a pause caused by
        {                       // cin.clear() and cin.ignore()
            std::cin.clear();
            std::cin.ignore(256,'\n');
        }
    }while(std::cin.fail() || std::cin.peek() != '\n');

    return answer;
}

/***********************************************************************
* Accepts a string message to output to user until they enter a
* valid integer. Calls isInt() to verify response. then checks that integer
* against a vector of acceptable answers
***********************************************************************/

int validIntInput(string msg, vector<int>& validAnswers)
{
    int answer;
    bool match = false;
    do {
        answer = isInt(msg);                                 //Calls the one argument version of itself to verify int
        for (int i = 0; i < validAnswers.size(); ++i) {      // Checks to see if int is acceptable
            if(validAnswers.at(i) == answer)
            {  match = true;}
        }
    } while(!match);

    return answer;
}

/************************************************************************
* menuOut function takes in a headline string, then a vector strings
* for the users options, then a vector of integers for the acceptable
* responses. Use numRange() function below to get a vector of ints within a
* given range. It then returns the accepted answer
************************************************************************/

int menuInts(string welcomeMsg, vector<string>& choicesStr, vector<int>& choicesInt)
{
    int answer;
    cout << "\n" << welcomeMsg << endl;
    cout << "*********************************************************" << endl;
    for (int i = 0; i < choicesStr.size(); i++) {
        cout << "* " << i + 1 << ": " << choicesStr.at(i) << "\n*" << endl;
    }

    string msg = "Please select from the above options: ";
    answer = validIntInput(msg, choicesInt);

    return answer;

}

/***********************************************************************
* Takes in a vector of ints by reference and an int for the minimum value
* of the range and a value for the max value of the range. Populates the
* vector
***********************************************************************/

vector<int> numRange(int min, int max)
{
    vector<int> tempVec;
    if(min >= max)
    {
        cout << "Minimum must be smaller than maximum" << endl;
        return tempVec;
    }
    for (int i = min; i <= max; i++) {
        tempVec.push_back(i);
    }
    return tempVec;
}

double isDouble(string msg)
{
    double answer;
    cout << msg << endl;
    while (!(std::cin >> answer) || std::cin.peek() != '\n') {
          std::cout << msg << std::endl;
          std::cin.clear();
          while (std::cin.get() != '\n') ; // empty loop
      }

    return answer;
}
