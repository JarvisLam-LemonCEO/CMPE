#include <iostream>
using namespace std;

class DayOfYear{
public:
    // declare friend functions
    friend bool isAfter(DayOfYear date1, DayOfYear date2);
    friend bool isBefore(DayOfYear date1, DayOfYear date2);
    friend DayOfYear add(DayOfYear date1, DayOfYear date2);
    friend bool equal(DayOfYear date1, DayOfYear date2);
    
    // declare member functions
    DayOfYear(int the_month, int the_day);
    DayOfYear();
    void input();
    void output();
    int get_month();
    int get_day();
    
private:
    void check_date();
    int month;
    int day;
};

int main(){
    
    // declare two DayOfYear object
    DayOfYear date1(12, 30);
    DayOfYear date2(12, 29);

    // print the output to the screen
    cout << "date1:(day month) " << date1.get_month() << " " << date1.get_day() << endl;
    cout << "date2:(day month) " << date2.get_month() << " " << date2.get_day() << endl;

    // check if date1 is after the date2
    if(isAfter(date1, date2)){
        cout << "date1 is after the date2." << endl;
    }
    // check if the date1 is before the date 2
    if(isBefore(date1, date2)){
        cout << "date1 is before the date2." << endl;
    }

    // create date3 object after adding date1 and date2
    DayOfYear date3;
    date3 = add(date1, date2);
    cout << "date3 = date1 + date2:(day month) " << date3.get_month() << " " << date3.get_day() << endl;

}

// add function
DayOfYear add(DayOfYear date1, DayOfYear date2){
    int month, day;
    
    month = date1.month + date2.month;

    if(month>12){ // if the month is greater than 12
        if(month == 24){ // if the month equal 24
            month = 12;  // set month to 12
        }
        else{      
            month = month % 12; // get the month
        }
    }

    day = date1.day + date2.day;
    
    if(day>30){ // if the day is greater than 30
        if(day == 60){ // if the day equal 60
            day = 30;  // set date to 30
        }
        else{  
            day = day % 30; //get the day 
        }
    
        month += 1; // month increases 1
    }

    if(month>12){ //if the month is greater than 12
        if(month == 24){ // if the month equal 24
            month = 12; // set month to 12
        }
        else{
            month = month % 12; //get the month
        }
    }
    return DayOfYear(month, day); // return DayOfYear
}

// isAfter function
bool isAfter(DayOfYear date1, DayOfYear date2){
    if(date1.month > date2.month){   // if the date1 is greter than date2
        return true;                 // then return ture
    }
    
    if(date1.month == date2.month){   // if the date1 and date2 are equal
        if(date1.day > date2.day){   // check if the day of date1 is after the day of date2
            return true;             // then return true
        }
    }
    return false; // if none of the case above, then return false
}

// isBefore function
bool isBefore(DayOfYear date1, DayOfYear date2){
    if(date1.month < date2.month){  // date1 is less than date2
        return true;               // then return ture
    }
    
    if(date1.month == date2.month){ // if date1 and date2 are equal
        if(date1.day < date2.day){  // check if the day of date1 is before the day of date2
            return true;           // then return true
        }
    }
    return false; // if none of the case above, then return false
}


bool equal(DayOfYear date1, DayOfYear date2){
    return ( date1.month == date2.month &&
                            date1.day == date2.day );
}

// constructor with int parameters
DayOfYear::DayOfYear(int the_month, int the_day){
    day = the_day;     // Initialize the date according to the arguments
    month = the_month;
}

// dafault constructor
DayOfYear::DayOfYear(){
    day = 1;      // Inititalize month and day to January 1st 
    month = 1;
}

// This Member function is to get month
int DayOfYear::get_month(){
    return month; // return to month
}

// This Member function is to get day
int DayOfYear::get_day(){
    return day; // return the of month
}

/*
    The output of the program

    date1:(day month) 12 30
    date2:(day month) 12 29
    date1 is after the date2.
    date3 = date1 + date2:(day month) 1 29

*/