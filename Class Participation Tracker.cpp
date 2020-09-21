// Class Participation Tracker.cpp : This file contains the 'main' function. Program execution begins and ends here.
// Author: Blake Bissell
// Date: 9/15/2020

#include <iostream>
#include <vector>
#include "Course.h"
#include "Student.h"

using namespace std;

void printCourseList(vector<Course> list);
Course selectCourse(vector<Course> list);
void rateStudent(int rating, Student* student);
void shutdown(vector<Course> list);

int main()
{
    // Variables
    vector<Course> courseList;
    int listSize = 0;
    bool running = true;

    // Start with 1 starter course to show function
    Course c1 = Course("class 1", "Class1.csv");

    //Push the course into the list
    courseList.push_back(c1);
 

    // Function
    //Initial information
    cout << "Welcome to the class participation tracker." << endl;

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
        cout << endl <<  "--------------- Random Student ---------------" << endl;
        cout << randStudent.getName() << "has been asked " << randStudent.getQuestionsAsked() << endl << endl;
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
        //Select a new course
        else if (selector == 5) {
            selectedCourse = selectCourse(courseList);
        }
        //Exit the application
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
void printCourseList(vector<Course> list) {
    // List all courses stored at current time. 
    for (int i = 0; i < list.size(); i++) {
        cout << i + 1 << " | " << list.at(i).getCourseName() << " has " << list.at(i).getNumOfStudents() << " students."  << endl;
    }

}

//Take user input to select the course which they want to manipulate. Returns a course which the user selected
//This method takes in the list of courses as a vector
Course selectCourse(vector<Course> list) {
    //Set the selector to nothing 
    int selector = NULL;
    
    //Run this 1 time before checking that the person selected a valid instruction.
    do {
        // Basic information posted
        cout << "Please select a course you would like to work on from the list below." << endl;
        cout << "If you would like to create a new course please type " << list.size() + 1 << endl;
        cout << "If you would like to exit the program type " << list.size() + 2 << endl;
        printCourseList(list);
        cout << "Enter the input you would like to perform" << endl;
        cin >> selector;

        //If the user inputed a valid number then select that course and return it.
        if (selector <= list.size()) {
            Course select = list.at(selector - 1);
            cout << "You have selected " << select.getCourseName() << endl;
            return select;
        }

        //Create a new course if the user input is 1 over the number of courses, this matches the above instructions
        else if (selector == list.size() + 1) {
            string name;
            cout << "Creating new course" << endl << endl;
            cout << "What would you like the name of the course to be." << endl;
            cout << "There needs to be a file in this directory with coursename.csv as the title." << endl;
            cin >> name;
            //Create a new course with the course name given and the filename associated with that course.
            Course c = Course(name, name.append(".csv"));
            list.push_back(c);
        }

        //Exit the program if the user input is 2 over the number of courses, this matches the above instructions.
        else if (selector == list.size() + 2) {
            cout << "Exiting Now." << endl;
            system("pause");
        }

      //Check that the selection is one of the classes.
    } while (selector > list.size() - 1);
}

//Take user input to rate the students answer to the questions.
void rateStudent(int rating, Student* student) {
    //Based on input give the correct rating
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
}