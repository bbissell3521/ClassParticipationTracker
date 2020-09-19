// This class is designed to contain 1 class worth of information including up to 50 students and the course name.
// Author: Blake Bissell
// Date: 9/15/2020
#include "Course.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <utility>
#include <stdlib.h>
#include <time.h>

using namespace std;

//This constructor creates a new course 
//name is the desired course name
//fileName is the name of the file which contains student names to be added to the course.
Course::Course(string name, string fileName) {
	//set the course name.
	courseName = name;
	//Helper variables for setting names from file.
	string studentName;
	
	ifstream nameFile;
	//Open the file containing names.
	nameFile.open(fileName);
	//Check to make sure file opened without errors.
	if (nameFile.is_open()) {
		//Get the next line of the file
		while (getline(nameFile, studentName)) {
			//If there is 50 or less students then add the student to the class and increase the count by 1
			if (students.size() <= 50) {
				Student spush = Student(studentName);
				cout << spush.getName() << " has " << spush.getQuestionsAsked() << endl;
				students.push_back(spush);
				/**for (int i = 0; i < students.size(); i++) {
					cout << students.at(i).getName() << endl;
					cout << students.at(i).getQuestionsAsked() << endl;
				}*/
			}
			else {
				//Throws error if there are too many student names.
				cerr << "Too many students please check file to keep under 50 students" << endl;
				break;
			}
		}
		//Close file after done using it.
		nameFile.close();
	}
	else {
		cerr << "Error: Unable to open file." << endl;
	}



}

//Get function for course name
string Course::getCourseName() {
	return courseName;
}

//Gets the number of students in the class
int Course::getNumOfStudents() {
	return students.size();
}

//Gets a random student from the course
Student Course::getRandomStudent() {
	int studentNum;
	srand(time(NULL));

	studentNum = rand() % getNumOfStudents();
	return students.at(studentNum);
}

Course::~Course() {

}