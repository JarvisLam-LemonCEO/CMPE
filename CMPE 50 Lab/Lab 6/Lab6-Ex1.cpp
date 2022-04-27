#include <iostream>

using namespace std;

class StudentRecord{
public:
	// memeber functions
	StudentRecord();
	StudentRecord(double quiz1, double quiz2, double quiz3, double mideExam, double finalExam);
	void setQuiz1(double scores);
	void setQuiz2(double scores);
	void setQuiz3(double scores);
	void setMidExam(double scores);
	void setFinalExam(double scores);
	
	double getQuiz1();
	double getQuiz2();
	double getQuiz3();
	double getMidExam();
	double getFinalExam();
	
	void WeightedAverage();
	void output(ostream&);
	
private:
	double quiz1;
	double quiz2;
	double quiz3;
	double midExam;
	double finalExam;
	double average;
	
};

int main(int argc, char *argv[]) {
	
	// using default consturctor 
	StudentRecord student(8,10,10,90,89) ;
	student.WeightedAverage();
	student.output(cout);
	
	// variable 
	int quiz1;
	int quiz2; 
	int quiz3;
	
	// ask user to enter 3 quiz scores and midterm and final exams
	cout << "Quiz 1: ";
	cin >> quiz1;
	cout << "Quiz 2: ";
	cin >> quiz2;
	cout << "Quiz 3: ";
	cin >> quiz3;
	
	cout << "Midterm Exam: ";
	int mid;
	cin >> mid;
	cout << "Final Exam: ";
	int final;
	cin >> final;
	cout << endl;
	
	// create student2 object
	StudentRecord student2 = StudentRecord();
	
	// use mutator for assiging values from input 
	student2.setQuiz1(quiz1);
	student2.setQuiz2(quiz2);
	student2.setQuiz3(quiz3);
	student2.setMidExam(mid);
	student2.setFinalExam(final);
	student2.WeightedAverage();
	student2.output(cout);
}

// Default constructor
StudentRecord::StudentRecord(){
	
}

// constructor with five double parameter
StudentRecord::StudentRecord(double quiz1, double quiz2, double quiz3, double midExam, double finalExam){
	this->quiz1 = quiz1;
	this->quiz2 = quiz2;
	this->quiz3 = quiz3;
	this->midExam = midExam;
	this->finalExam = finalExam;

}

//mutators 
void StudentRecord::setQuiz1(double scores){
	quiz1 = scores;
}

void StudentRecord::setQuiz2(double scores){
	quiz2 = scores;
}

void StudentRecord::setQuiz3(double scores){
	quiz3 = scores;
}

void StudentRecord::setMidExam(double scores){
	midExam = scores;
}

void StudentRecord::setFinalExam(double scores){
	finalExam = scores;
}


// get data member function
double StudentRecord::getQuiz1(){
	return quiz1;
}

double StudentRecord::getQuiz2(){
	return quiz2;
}

double StudentRecord::getQuiz3(){
	return quiz3;
}

double StudentRecord::getMidExam(){
	return midExam;
}

double StudentRecord::getFinalExam(){
	return finalExam;
}

// This member fuction is to calculate Weighted Average
void StudentRecord::WeightedAverage(){
	
	// best 2 out of 3 quiz scores
	if (quiz1 < quiz2 && quiz1 < quiz3){    // if the quiz 2 and quiz3 are the best 2 quiz scores
		average = ((quiz2 + quiz3) / 10 * 0.25 + midExam / 100 * 0.25 + finalExam / 100 * 0.5) * 100;
	} else if (quiz2 < quiz1 && quiz2 < quiz3){ // if the quiz 1 and quiz3 are the best 2 quiz scores
		average = ((quiz1 + quiz3) / 10 * 0.25 + midExam / 100 * 0.25 + finalExam / 100 * 0.5) * 100;
	} else {  // if the quiz 1 and quiz2 are the best 2 quiz scores
		average = ((quiz1 + quiz2) / 10 * 0.25 + midExam / 100 * 0.25 + finalExam / 100 * 0.5) * 100;
	}
}

// This memeber function is to output the result to the screen
void StudentRecord::output(ostream& cout){
	cout << "Student Record " << endl;
	cout << "Quiz 1: " << getQuiz1() << endl;
	cout << "Quiz 2: " << getQuiz2() << endl;
	cout << "Quiz 3: " << getQuiz3() << endl;
	cout << "Midterm Exam: " << getMidExam() << endl;
	cout << "Final Exam: " << getFinalExam() << endl;
	cout << "Weighted Average Numeric Score: " << average << "%" << endl;
	cout << endl;
	
}

/*
	The output of the program

	Student Record 
	Quiz 1: 8
	Quiz 2: 10
	Quiz 3: 10
	Midterm Exam: 90
	Final Exam: 89
	Weighted Average Numeric Score: 117%
	
	Quiz 1: 7
	Quiz 2: 5
	Quiz 3: 9
	Midterm Exam: 100
	Final Exam: 67
	
	Student Record 
	Quiz 1: 7
	Quiz 2: 5
	Quiz 3: 9
	Midterm Exam: 100
	Final Exam: 67
	Weighted Average Numeric Score: 98.5%

*/