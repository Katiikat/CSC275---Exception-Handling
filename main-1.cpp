#include <iostream>
#include <string>
#include <vector>
#include "ExceptionHandlingExamples.h"

using namespace std;

//program should do something besides demonstrating exceptions

int main() {

    //create Examples object
    Examples myObj;
    //use object to display the intro to the program
    myObj.Intro();

    //to keep score of the questions the user gets correct and incorrect
    //max score is 110 points
    int score = 0;
    //goes through each question in the users quiz
    for(int a = 0; a <= 5; a++)
    {
        //each run through, points are returned for correct or incorrect answers
        score += myObj.questions(a);
    }
    //description of catch all catch type and how it differs from the usual catch type
    cout << "\nThere is only one downside to using the catch(...) or catch all type.\n"
            "\nThe type cannot provide a reason why there was an exception.\n"
            "\nCan only state that there was an exception and it was found. That's it.\n"
            "\nCatch all is not the recommended catch type, but used as a last resort"<< endl;

    //display the total score to the user
    cout << "\n\nYour ending score was: " << score;
    //end of program
    return 0;
}
