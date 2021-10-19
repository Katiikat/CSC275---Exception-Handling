#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "ExceptionHandlingExamples.h"

using namespace std;

    //every program needs an awesome intro
    void Examples::Intro()
    {
        //Intro to program
        cout << "\n\n\n\t\t***** Welcome to Exception Handling *****" << endl;
        //explanation of what the program will do -- for the user
        cout << "\n\nThis is a quiz that will help in memorizing a small number of the many exceptions c++ libraries offer." << endl;
        cout << "\nThere are 4 questions worth 25 points each, and a single bonus question worth 10 points." << endl;
        //beginning of the program
        cout <<"\nLets get started!" << endl;
        //this allows the program to stay organized instead of printing out tons of code all at once
        cout << "\nPress enter to continue." << endl;
        cin.get();
    }

    void Examples::runTimeError()
    {
        //standard try/catch format
        try {
            throw runtime_error("Error occurred during runtime.");
        }
        catch(exception& e)
        {
            cout << "Exception Handled: " << e.what() << endl;
        }
    }

    void Examples::outOfRange()
    {
        //create the vector and set the size for the example
        vector<int> myVector(10);

        //standard try/catch format
        try {
            //attempting to manipulate a place in the vector that doesn't exist
            myVector.at(20) = 100; //.at() throws an out of bounds exception
        }
        catch (const out_of_range &oor) {
            cout << "Exception Handled: " << oor.what() << endl;
        }
    }

    void Examples::inValidArgument()
    {
        //standard try/catch format
        try {
            //taking and aschii string
            basic_string<char> a = "A";
            //change the aschii string into a double
            stod(a); //stod turns a string into a double
        }
        catch (const invalid_argument& ia)
        {
            cout << "Exception Handled: " << ia.what() << endl;
        }
    }

    void Examples::throwNum()
    {
        //standard try/catch format
        try {
            throw 21;
        }
        //catch all to demonstrate difference from other catch format
        catch(...)
        {
            cout << "An exception was Handled." << endl;
        }
    }
    void Examples::lengthError()
    {
        //standard try/catch format
        try {
            // vector throws a length_error if resized above max_size
            std::vector<int> myvector;
            myvector.resize(myvector.max_size()+1);
        }
        catch (const std::length_error& le) {
            std::cerr << "Length error: " << le.what() << '\n';
        }
    }
    //parameter is the number of the question being asked, and corresponding element in array
    int Examples::questions(int a)
    {
        //user choice variable
        int ans = 0;
        //questions for the quiz
        string questions[4] = {"Which exception from the list below throws exceptions to signal errors due to resizing?",
                               "Which exception from the list below throws errors that can only be detected during runtime?",
                               "Which exception from this list below throws exceptions when there is a reported violation in a receiving argument?",
                               "Which exception from the list below throws exceptions when attempting to access a non-existent part of a list?"};

        //bonus question about they catch-all statement
        string bonus = "BONUS:: Can you identify the type of catch statement used in the above handled exception?\n";

        //main quiz questions answer choices
        string answerChoices = "1. runtime_error \n2. out_of_range \n3. invalid_argument \n4. length_error\n";
        //bonus question answer choice
        string bonusAnswerChoices = "1. catch(-exception type-)\n2. catch_all";

        //keep variable outside of loop in order to access anywhere in the function
        //b is used as the element for the array location
        int b = 0;
        //score is to keep score of correct and incorrect questions/answers
        int score = 0;
        //go through each element in the array and plus one for the bonus question
        for(b; b <= 4; b++)
        {
            //test if the current question is equal to the element in the array
            if(a == b)
            {   //print out question and give user chance to answer
                cout << questions[b] << endl;
                cout << answerChoices << endl;
                cout << "Please enter the number of your answer: "<< endl;
                cin >> ans;
                cout << "Press enter to continue" << endl;
                cin.get();
                break;
            } else if (a == 4)
            {
                //display bonus question and give user chance to answer
                throwNum();
                cout << bonus << endl;
                cout << bonusAnswerChoices << endl;
                cout << "Please enter the number of your answer: "<< endl;
                cin >> ans;
                cout << "Press enter to continue" << endl;
                cin.get();
                //the correct answer will always be 2, therefore the if statement determines correct or incorrect
                if(ans == 2)
                {
                    score += 10;
                }
                return score;
            }
        }
        //main quiz for-loop
        for(int c = 0; c < 4; c++) {
            //if the user answer matches the answer choice number and it matches the question, then the user got the question correct
            if (ans == 4 && b == 0) {

                lengthError();
                cout
                        << "Length errors are errors that are due to events that try to illegally manipulate lengths of variables, such as strings and vectors."
                        << endl;
                score += 25;
                cin.get();
                return score;
                //if the user answer matches the answer choice number and it matches the question, then the user got the question correct
            } else if (ans == 1 && b == 1) {
                score = +25;
                runTimeError();
                cout
                        << "Runtime errors report errors that are due to events beyond the scope of the program and can not be easily predicted."
                        << endl;

                cin.get();
                return score;
                //if the user answer matches the answer choice number and it matches the question, then the user got the question correct
            } else if (ans == 3 && b == 2) {
                score += 25;
                inValidArgument();
                cout << "Stod simply means to turn a string into a double." << endl;
                cout << "Invalid Argument is a standard exception that can be thrown by programs\nwhen a function is expecting a specific parameter type, but doesn't recieve it."
                        << endl;

                cin.get();
                return score;
                //if the user answer matches the answer choice number and it matches the question, then the user got the question correct
            } else if (ans == 2 && b == 3) {
                score += 25;
                outOfRange();
                cout << "Out of Range is a standard exception that can be thrown by programs\ntrying to manipulate an element of a list that exceeds the list length."
                        << endl;
                cin.get();
                return score;
            }
            return score;
        }
    }
//
// Created by katie on 1/25/20.
//
