// Class Participation Tracker.cpp : This file contains the 'main' function. Program execution begins and ends here.
// Author: Blake Bissell
// Date: 9/15/2020

#include <iostream>
#include <vector>
#include "Course.h"
#include "Student.h"

using namespace std;

void printCourseList(vector<Course> list, int listSize);
Course selectCourse(vector<Course> list);
void rateStudent(int rating, Student* student);
void shutdown(vector<Course> list);

int main()
{
    // Variables
    vector<Course> courseList;
    int listSize = 0;
    bool running = true;

    // Debugging stuff
    Course c1 = Course("class 1", "Class1.csv");
    //Course c2 = Course("class 2");

    //Push the course into the list
    courseList.push_back(c1);
    //courseList.push_back(c2);

    // Function
    //Initial user input and information
    cout << "Welcome to the class participation tracker." << endl;
    printCourseList(courseList, courseList.size());
    // Select Initial course
    Course selectedCourse = selectCourse(courseList);


    //User input loop
    //Do this while the selected course is 
    while (running) {
        //integer selector for user input
        int selector = NULL;
        cout << selectedCourse.getCourseName() << " is selected." << endl;
        //Get a random student from the selected course.
        Student randStudent = selectedCourse.getRandomStudent();
        //Report student name and how many qeustions they have been asked
        cout << "--------------- Random Student ---------------" << endl;
        cout << randStudent.getName() << "has been asked " << randStudent.getQuestionsAsked() << endl;
        //Give list of inputs accepted.
        cout << "--------------- Inputs ---------------" << endl;
        cout << "To give a rating as following: " << endl << " 1 for skip " << endl << " 2 for Unsatisfactory " << endl;
        cout << " 3 for Satisfactory " << endl << " 4 for Exceptional " << endl;
        cout << "If you would like to go back to course selection please press 5." << endl;
        cout << "If you would like to exit the program press 6" << endl;
        //Take in user input for selection
        cin >> selector;
        if (selector < 5 && selector > 0) {
            rateStudent(selector, &randStudent);
        }
        else if (selector == 5) {
            selectedCourse = selectCourse(courseList);
        }
        else if (selector == 6) {
            running = false;
        }
    }
  

    system("pause");
    return 0;
}

//This function shutsdown the applicationa and saves all user data into files. 
void shutdown(vector<Course> list) {
    //Take the list of courses and parse through information to distill into a file which can be saved locally, and overwritten each time the program is
    // opened and closed to save the information. 
}

//Prints the current course list to the console with some input instructions. 
void printCourseList(vector<Course> list, int listSize) {
    // Basic information posted
    cout << "Please select a course you would like to work on from the list below." << endl;
    cout << "If you would like to create a new course please type " << list.size() + 1 << endl;
    cout << "If you would like to exit the program type " << list.size() + 2 << endl;
    // List all courses stored at current time. 
    for (int i = 0; i < list.size(); i++) {
        cout << i + 1 << " | " << list.at(i).getCourseName() << " has " << list.at(i).getNumOfStudents() << " students."  << endl;
    }

    //input loop call. 
}

//Take user input to select the course which they want to manipulate. Returns a course which the user selected
//This method takes in the list of courses as a vector
Course selectCourse(vector<Course> list) {
    //Set the selector to nothing 
    int selector = NULL;
    
    //Run this 1 time before checking that the person selected a valid instruction.
    do {
        cout << "enter course number" << endl;
        cin >> selector;
        //Create a new course if the user input is 1 over the number of courses, this matches the above instructions
        if (selector == list.size() + 1) {
            cout << "Creating new course" << endl;
            system("pause");
        }
        //Exit the program if the user input is 2 over the number of courses, this matches the above instructions.
        else if (selector == list.size() + 2) {
            cout << "Exiting Now." << endl;
            system("pause");
        }
        //If the user inputed a valid number then select that course and return it.
        else if (selector <= list.size()) {
            Course select = list.at(selector - 1);
            cout << "You have selected " << select.getCourseName() << endl;
            return select;
        }
        //Check that the selection isnt bigger then the list of options.
    } while (selector > list.size());
}

//Take user input to rate the students answer to the questions.
void rateStudent(int rating, Student* student) {
    cout << "5" << endl;
    //When user inputs 1 add a skip to student
    if (rating == 1) {
        student->giveSkip();
    }
    else if (rating == 2) {
        student->giveUnsat();
    }
    else if (rating == 3) {
        student->giveSatis();
    }
    else if (rating == 4) {
        student->giveExcep();
    }
    cout << student->getName() << "has been now asked " << student->getQuestionsAsked() << endl;
}