#include <iostream>
#include<string.h>
#include<iomanip>

using namespace std;

int main() {
    
    // array to store HW and Labs scores
    double arr[2][5]; 
    
    // The best, worst, average and total scores of HW
    double hwBest;
    double hwWorst;
    double hwTotal = 0;
    double hwAvg;
    
    
    // The best, worst, average and total scores of Lab
    double labBest; 
    double labWorst;
    double labTotal = 0;
    double labAvg;
    
    bool is_passed;
    string enter_component_here;
    bool reason = false;
    
        
    // Ask the users to input their 5 HW Scores 
    for (int i = 0; i < 5; i++){
      cout << "Please enter HW #" << i + 1 << " Scores: ";
      // Store the inputed valued from user to HW score array
      cin >> arr[0][i];
    }
    
    // Ask the users to input their 5 Lab Scores 
    for (int i = 0; i < 5; i++){
      cout << "Please enter Lab #" << i + 1<< " Scores: ";
      // Store the inputed valued from user to Lab score array
      cin >> arr[1][i];
    }
    
    // Set the default values for the Best and Worst score of HW and Lab
    hwBest = arr[0][0];
    hwWorst = arr[0][0];
    labBest = arr[0][0];
    labWorst = arr[0][0];

    // find the best, the worst and average of Homework
    for (int i = 0; i < 5; i++){
      // find the best HW score
      if(arr[0][i] > hwBest){ //if the HW score is larger the defualt value of hwBest
        hwBest = arr[0][i];   // then it will replace that value
      }
      
      // find the worst HW score
      if(arr[0][i] < hwWorst){ //if the Lab score is small the defualt value of hwWorst
        hwWorst = arr[0][i];   // then it will replace that value
      }
      
      // Add the HW scores
      hwTotal += arr[0][i];
      // Calculate the average of
      hwAvg = hwTotal / 5;
    }
    
    // find the best, the worst and average of Lab
    for (int i = 0; i < 5; i++){
      
      // find the best Lab score
      if(arr[1][i] > labBest){  //if the HW score is larger the defualt value of LabBest
        labBest = arr[0][i];    // then it will replace that value
      }
      
      // find the Worst Score of Lab
      if(arr[1][i] < labWorst){  //if the HW score is larger the defualt value of LabBest
        labWorst = arr[1][i];   // then it will replace that value
      }
      
      // Add the Lab scores 
      labTotal += arr[1][i];
      // Calculate the average of Lab
      labAvg = labTotal / 5;
    }
  
    // Print the Result table
    cout<<"\t1\t\t2\t\t3\t\t4\t\t5\t\tBEST\t WORST\t AVG"<<endl;
    cout<<"\t*************************************************************"<<endl;
    for(int i = 0; i < 2; i++){
      
      // Print the Scores of HW at a row
      // setprecision(2) for 2 decimal places
      if(i == 0){
        cout<<"HW\t";
        for(int j = 0; j < 5; j++){
          cout << fixed << setprecision(2) << arr[i][j]<<"\t";
        }
        cout << fixed << setprecision(2) << hwBest << "\t" << hwWorst << "\t" << hwAvg;
      }
      
      // print the scores of Law at a row
      if(i == 1){
        cout<<"LAB\t";
        for(int j = 0; j < 5; j++){
            cout << arr[i][j] << setprecision(2) << "\t";
        }
        cout << fixed << setprecision(2) << labBest << "\t" << labWorst << "\t" << labAvg;
      }
      cout << endl;
    }
  
    //finding which is passes or failed
    if(hwAvg >= 50){
      is_passed = true;
      enter_component_here = "Average in LAB ";
    } else if(labAvg >= 50){
      is_passed = true;
      enter_component_here = "Average in HW ";
    }
  
  double overall = 0;
  double sum = 0;
  cout << endl << "AVG\t";
  
  //finding overall average  
  for(int i = 0;i < 5; i++){ // loop 5 times
    for(int j = 0;j < 2; j++){ // loop twice sum  of a set of HW and Lab scores
      sum += arr[j][i];
    }
    cout << sum / 2 <<"\t"; // avg / 2 is the average of 1 HW and 1 Lab (HW#1 + Lab#1) / 2
    
    if(sum / 2 < 50){    // if one of the average of a set of HW and Lab is less than 50, then it fails
      is_passed = false; // 
      reason = true;
    }
    overall += sum / 2; 
    sum = 0; // set the sum = 0 before repeating the for loop
  }
  cout << "Overall : " << overall / 5 << endl;
  
  
  //Determin the student is passed ot not passed
  if(is_passed == true){
    cout<<"Congratulations! You passed the class"<< endl;
  } else {
    if(reason){
      cout<<"I'm sorry to inform you that you failed the class, because your performance in "<< enter_component_here <<"was <50%. Try again next semester. ";
    } else {
      cout<<"I'm sorry to inform you that you failed the class, because your performance in Subjects was <50%. Try again next semester. ";
    }
  }
  return 0;
}

/*
  The output of the program:

  Please enter HW #1 Scores: 100
  Please enter HW #2 Scores: 90
  Please enter HW #3 Scores: 70
  Please enter HW #4 Scores: 60
  Please enter HW #5 Scores: 100
  Please enter Lab #1 Scores: 70
  Please enter Lab #2 Scores: 60
  Please enter Lab #3 Scores: 100
  Please enter Lab #4 Scores: 70
  Please enter Lab #5 Scores: 100
  1		2		3		4		5		BEST	 WORST	 AVG
  *************************************************************
  HW	100.00	90.00	70.00	60.00	100.00	100.00	60.00	84.00
  LAB	70.00	60.00	100.00	70.00	100.00	100.00	60.00	80.00
  
  AVG	85.00	75.00	85.00	65.00	100.00	Overall : 82.00
  Congratulations! You passed the class


*/