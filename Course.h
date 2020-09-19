// This class is designed to contain 1 class worth of information including up to 50 students and the course name.
// Author: Blake Bissell
// Date: 9/15/2020
#pragma once
#include "Student.h"
#include <vector>

class Course
{
private:
	string courseName;
	vector<Student> students;

public:
	Course(string name, string fileName);
	string getCourseName();
	int getNumOfStudents();
	Student getRandomStudent();
	~Course();
};

