#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class shape{
public:
    virtual void area() = 0;
    
    // get the specific parameters for a particular shape
    virtual void getParameters() = 0;
};

// circle class
class circle : public shape{
private:
    double radius;

public:
    
    //get the radius from user
    void getParameters(){
        cout << "Enter the radius of the Circle: ";
        cin >> radius;        
    }

    void area(){
        cout << "The area of this circle is: " << M_PI * radius * radius << endl;
    }
};

// rectangle class
class rectangle : public shape{
private:
    double length;
    double width;

public:
    
    // get the length and width from user
    void getParameters(){
        cout << "Enter the length of the Rectangle: ";
        cin >> length;        
        cout << "Enter the width of the Rectangle: ";
        cin >> width;
    }

    void area(){
        cout << "The area of this Rectangle is: " << length * width <<"\n";
    }
};

// triangle class
class triangle : public shape{
private:
    double base;
    double height;

public:
    
    // get the hieght and basse from user
    void getParameters(){
        cout<<"Enter the base length of the Triangle: ";
        cin>>base;        
        cout<<"Enter the height of the Triangle: ";
        cin>>height;
    }
    
    void area(){
        cout<<"The area of this Triangle is: " << 0.5 * base * height << endl;
    }
};

// function prototype
void menu();

int main(int argc, char *argv[]){
    
    // declare the size of the vector
    // ask user how many shapes user want
    int size;
    cout << "Enter the size of the vector of shape pointers: ";
    cin >> size;

    //declare vector
    vector<shape*> shapes(size);
    

    //loop over all the pointers
    for(int i = 0; i < size; i++){
        menu();
        int selection;
        cout << "Enter choice for shape "<< i+1 << ": ";
        cin >> selection;
        
        while(selection < 1 || selection > 3){
            cout<<"Invalid selection! Enter choice again: ";
            cin >> selection;
        }

        // create the shape accroding to user's selection
        if (selection == 1) {
            shapes[i] = new circle;
        } else if (selection == 2) {
            shapes[i] = new rectangle;
        } else if (selection == 3) {
            shapes[i] = new triangle;
        }

        //get parameters for corresponding shapes
        shapes[i]->getParameters();
        
        // show the results for corresponding shapes 
        shapes[i]->area();
        cout << endl;
    }
    return 0;
}

void menu(){
    cout << "Shapes" <<endl;
    cout << "1. Circle" << endl;
    cout << "2. Rectangle" << endl; 
    cout << "3. Triangle" << endl;
}