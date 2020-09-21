// This class is designed to contain student data. This includes name, and ratings for questions answered.
// Author: Blake Bissell
// Date: 9/15/2020
#pragma once
#include <iostream>
#include <list>
using namespace std;

class Student
{
private:
	string name;
	int satis;
	int unsat;
	int excep;
	int skip;

public:
	Student(string n);
	//void getStudent();
	string getName();
	int getQuestionsAsked();
	void giveSatis();
	void giveUnsat();
	void giveExcep();
	void giveSkip();
	~Student();

};

