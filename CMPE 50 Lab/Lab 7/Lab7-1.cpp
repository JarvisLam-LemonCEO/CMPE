#include <iostream>

using namespace std;

// resource class
class Resource{
public:
	// constructor
	Resource();
	// constructor with int parameter
	Resource(int num);
	
	// accessors
	int get_status() const;
	int get_writeTo() const;
	
	// mutator
	void set_status(int s);
	void set_writeTo(int w);
	
	// output function
	void output(ostream& out);
	
	// friend function
	friend bool check_status(const Resource& res1, const Resource& res2);
	
private:
	int status;
	int writeTo;
	
};

int main(int argc, char *argv[]) {
	Resource resource1, resource2, resource3(1);
	cout << "resource1: ";
	resource1.output(cout);
	cout << "resource2: ";
	resource2.output(cout);
	cout << "resource3: ";
	resource3.output(cout);
	
	cout << "modify resource2, resource3\n";
	resource2.set_status(1);
	resource2.set_writeTo(1);
	resource3.set_status(1);
	cout << "resource2: ";
	resource2.output(cout);
	cout << "resource3: ";
	resource3.output(cout);
	
	cout << "check status resource1 and resource2: ";
	if (check_status(resource1, resource2))
		{
			cout << "resource available\n";
		}
	else
		{
			cout << "resource unavailable\n";
		}
	
	cout << "check status resource 2 and resource 3: ";
	if (check_status(resource2, resource3))
		{
			cout << "resource available\n";
		}
	else
		{
			cout << "resource unavailable\n";
		}

	
}

// constructor function
Resource::Resource(){
	
}

// constructor function int parameter
Resource::Resource(int num){
	if (num > 1 || num < 0){
		writeTo = 0;
	}else{
		writeTo = num;
	}
}

// get_status accessor function
int Resource::get_status() const{
	return status;
}

// get_writeTo accessor function
int Resource::get_writeTo() const{
	return writeTo;
}

// set_status mutator function
void Resource::set_status(int s){
	if (s > 1 || s < 0){
		status = 0;
	}else{
		status = s;
	}
}
		
// set_writeTo mutator function		
void Resource::set_writeTo(int w){
	if (w > 1 || w < 0){
		writeTo = 0;
	}else{
		writeTo = w;
	}
}

// output function
void Resource::output(ostream& out){
	out << "status: " << status << " , writeTo: " << writeTo << endl;
}

// friend function
bool check_status(const Resource& res1, const Resource& res2){
	return (res1.status == 1) && (res2.status == 1);
}


/* The output of the program
	resource1: status: 0 , writeTo: 0
	resource2: status: 0 , writeTo: 0
	resource3: status: 0 , writeTo: 1
	modify resource2, resource3
	resource2: status: 1 , writeTo: 1
	resource3: status: 1 , writeTo: 1
	check status resource1 and resource2: resource unavailable
	check status resource 2 and resource 3: resource available

*/