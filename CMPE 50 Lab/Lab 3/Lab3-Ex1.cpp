#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  
  // variable of an array to store HW and Labs scores
  double val[2][5];
  
  // Ask the users to input their 5 HW Scores 
  for (int i = 0; i < 5; i++){
    cout << "Please enter HW#" << i + 1 << " scores: ";
    // Store the inputed valued from user to HW score array
    cin >> val[0][i];
  }
  
  // Ask the users to input their 5 Lab Scores 
  for (int i = 0; i < 5; i++){
    cout << "Please enter Lab#" << i + 1 << " scores: ";
    // Store the inputed valued from user to Lab score array
    cin >> val[1][i];
  }
  
  //variable for HW
  double hwBest = 0; //set default value of hw_best be 0
  double hwWorst = 100; //set default value of hw_worst be 100
  double hwAvg = 0; //set default value of hw_best be 0
  
  //variable for Lab
  double labBest = 0; //set default value of hw_best be 0
  double labWorst = 100; //set default value of hw_worst be 100
  double labAvg = 0; //set default value of hw_best be 0
  
  // for loop to find the best and the worst HW scores within 5 scores
  for (int i = 0; i < 5; i++){ 
    // Find the best HW score
    if (val[0][i] > hwBest){ // if current arry is larger than default value of hwBest
      hwBest = val[0][i]; //then store it in the hwBest variable
    }
    
    // Find the worst HW score
    if(val[0][i] < hwWorst){ // if current arry is smaller than default value of hwBest
      hwWorst = val[0][i]; //then store it in the hwWorst variable
      
    }
  }
  
  // for loop to find the best and the worst Lab scores within 5 scores
  for (int i = 0; i < 5; i++){ 
    // Find the best Lab score
    if (val[1][i] > labBest){ // if current arry is larger than default value of labBest
      labBest = val[1][i]; //then store it in the labBest variable
    }
    
    //Find the worst Lab score
    if(val[1][i] < labWorst){ // if current arry is smaller than default value of labBest
      labWorst = val[1][i]; //then store it in the labWorst variable
    }
  
  }
  
  // Using for loop to sum up the total scores of HW
  for(int i = 0; i < 5; i++){
    hwAvg += val[0][i];
  }
  
  // Compute HW average
  hwAvg = hwAvg / 5;
  
  // using for loop to sum up the total scores of HW
  for(int i = 0; i < 5; i++){
    labAvg += val[1][i];
  }
  
  // Compute Lab average
  labAvg = labAvg / 5;
  
  // Compute the overall score
  double overall = 0;
  overall = (labAvg + hwAvg) / 2;
  
  // The average of a set of HW and Lab
  double avgEach[5];
  for(int i = 0; i < 5;i++){
    avgEach[i] = (val[0][i] + val[1][i]) / 2;
  }
  
  // Set the fail be false
  bool is_passed = false;
  if(labAvg >= 50 && hwAvg >= 50){
    is_passed = true; // assign pass as true value
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
        cout << fixed << setprecision(2) << val[i][j]<<"\t";
      }
      cout << fixed << setprecision(2) << hwBest << "\t" << hwWorst << "\t" << hwAvg;
    }
    
    // Print the scores of Law at a row
    if(i == 1){
      cout<<"LAB\t";
      for(int j = 0; j < 5; j++){
        cout << val[i][j] << setprecision(2) << "\t";
      }
      cout << fixed << setprecision(2) << labBest << "\t" << labWorst << "\t" << labAvg;
    }
    cout << endl;
  }
  
  cout << endl << "AVG\t";
  
  // Using for loop to print the values of avgEach array
  for (int i = 0; i < 5; i++){
    cout << avgEach[i] << "\t";
  }
  
  cout << " \t Overall:";
  // print the overall 
  cout << overall << endl;
  
  // Print the message if the user are passed or one assignment is failed
  if(is_passed){
    cout<<"Congratulations! You have passed the class!";
  } else {
    if(labAvg < 50){
      cout<<"I'm sorry to inform you that you failed the class, because your performance in lab assignment was <50 percent. Try again in next semester.";
    } else if(hwAvg < 50){
      cout<<"I'm sorry to inform you that you failed the class, because your performance in hw assignment was <50 percent. Try again in next semester.";
    } else {
      cout<<"I'm sorry to inform you that you failed the class, because your performance in both hw and lab assignment was <50 percent. Try again in next semester.";
    }
  }

return 0;

}


/*
  The output of the program

  Please enter HW#1 scores: 100
  Please enter HW#2 scores: 60
  Please enter HW#3 scores: 80 
  Please enter HW#4 scores: 50
  Please enter HW#5 scores: 90
  Please enter Lab#1 scores: 100
  Please enter Lab#2 scores: 67
  Please enter Lab#3 scores: 90
  Please enter Lab#4 scores: 10
  Please enter Lab#5 scores: 99
  1		2		3		4		5		BEST	 WORST	 AVG
  *************************************************************
  HW	100.00	60.00	80.00	50.00	90.00	100.00	50.00	76.00
  LAB	100.00	67.00	90.00	10.00	99.00	100.00	10.00	73.20
  
  AVG	100.00	63.50	85.00	30.00	94.50	 	 Overall:74.60
  Congratulations! You have passed the class!
  
  Please enter HW#1 scores: 10
  Please enter HW#2 scores: 10
  Please enter HW#3 scores: 10
  Please enter HW#4 scores: 30
  Please enter HW#5 scores: 90
  Please enter Lab#1 scores: 100
  Please enter Lab#2 scores: 100
  Please enter Lab#3 scores: 90
  Please enter Lab#4 scores: 78 
  Please enter Lab#5 scores: 99
  1		2		3		4		5		BEST	 WORST	 AVG
  *************************************************************
  HW	10.00	10.00	10.00	30.00	90.00	90.00	10.00	30.00
  LAB	100.00	100.00	90.00	78.00	99.00	100.00	78.00	93.40
  
  AVG	55.00	55.00	50.00	54.00	94.50	 	 Overall:61.70
  I'm sorry to inform you that you failed the class, because your performance in hw assignment was <50 percent. Try again in next semester.
  
  Please enter HW#1 scores: 100
  Please enter HW#2 scores: 90
  Please enter HW#3 scores: 100
  Please enter HW#4 scores: 89
  Please enter HW#5 scores: 90
  Please enter Lab#1 scores: 10
  Please enter Lab#2 scores: 0
  Please enter Lab#3 scores: 100
  Please enter Lab#4 scores: 56
  Please enter Lab#5 scores: 40
  1		2		3		4		5		BEST	 WORST	 AVG
  *************************************************************
  HW	100.00	90.00	100.00	89.00	90.00	100.00	89.00	93.80
  LAB	10.00	0.00	100.00	56.00	40.00	100.00	0.00	41.20
  
  AVG	55.00	45.00	100.00	72.50	65.00	 	 Overall:67.50
  I'm sorry to inform you that you failed the class, because your performance in lab assignment was <50 percent. Try again in next semester.

*/
