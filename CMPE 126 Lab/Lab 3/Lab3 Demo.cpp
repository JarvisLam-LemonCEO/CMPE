#include <iostream>

using namespace std;

class person{
private:
	string name; // encapuslation 
public:
	// abstraction 
	string getName(){
		return name;
	}
	
	void setName(string name) {
		this->name = name;
	}
	
	virtual void print(){
		cout << "In the person class" << endl;
	}
	
	// virtual void print() = 0;
	
};

// inheritence
class student:public person{
private:
	int enrollmentNo;
	
public:
	//function
	void print(){
		cout << "In the student class" << endl;
	}
};

//int sum(int a,int b) {
//	return a + b;
//}
//
//int sum(int a, int b, int c){
//	return a + b + c;
//}
//
//float sum(float a, float b){
//	return a + b;
//}


int main(int argc, char *argv[]) {
	
	// person object
	person p;
	p.print();
	
	// student object
	student s;
	s.print();
	
	// pointer
	person *ptr;
	ptr = new student();
	ptr->print();
	
	return 0;
	
}