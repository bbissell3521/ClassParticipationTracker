// This class is designed to contain student data. This includes name, and ratings for questions answered.
// Author: Blake Bissell
// Date: 9/15/2020
#include "Student.h"

using namespace std;

/**
This is the student constructor.
This takes in the students name in n.
This also sets all ratings to 0 for the student by default.
*/
Student::Student(string n) {
	name = n;
	int satis = 0;
	int unsat = 0;
	int excep = 0;
	int skip = 0;
}

//Basic getter for the students name
string Student::getName() {
	return name;
}
//Incremental method to add 1 to the number of satisfactory ratings
void Student::giveSatis() {
	satis++;
}
//Incremental method to add 1 to the number of unsatisfactory ratings
void Student::giveUnsat() {
	unsat++;
}
//Incremental method to add 1 to the number of exceptional ratings
void Student::giveExcep() {
	excep++;
}
//Incremental method to add 1 to the number of skip ratings
void Student::giveSkip() {
	skip++;
}
//This returns the total number of questions the student has a rating for.
int Student::getQuestionsAsked() {
	cout << "sat:" << satis << endl;
	cout << "unsat:" << unsat << endl;
	cout << "excep:" << excep << endl;
	cout << "skip:" << skip << endl;
	return satis + unsat + excep + skip;
}

//Unused deconstructor
Student::~Student() {

}
