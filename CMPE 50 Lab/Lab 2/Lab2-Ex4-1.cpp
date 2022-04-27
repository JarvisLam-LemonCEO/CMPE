#include <iostream>

using namespace std;
// Constant Variables
const int ASSIGNMENT_NUM = 2, SET_NUM = 5;

int main(){ 
  
  double arr[ASSIGNMENT_NUM][SET_NUM];

  // store HW and Lab Scores into the array 
  for (int i = 0; i < SET_NUM; i++){
    cout << "Please enter HW" << i +1 << " scores [0 – 100]: ";
    cin >> arr[0][i];
  }
  
  for (int i = 0; i < SET_NUM; i++){
    cout << "Please enter Lab" << i + 1 << " scores [0 – 100]: ";
    cin >> arr[1][i];
  }
  
  // Let the default values of hwBest, hwWorst, labBest and labWorst 
  double hwBest = 0; 
  double hwWorst=100; 
  double hwAvg=0; 
  double labBest=0; 
  double labWorst=100; 
  double labAvg=0;
  
  // find the best and the worst scores of HW
  for (int i = 0; i < SET_NUM; i++){ 
    // Find the best score of HW
    if (arr[0][i] > hwBest){ // if the current HW score is larger than default value of hwBest
      hwBest = arr[0][i]; // then the value of current score is cpoied into hwBest
    }
    
    if(arr[0][i] < hwWorst){ // if the current HW score is smaller than default value of hwWorst
      hwWorst = arr[0][i]; // then the value of current score is cpoied into hwWorst
    }
  }
  
  //calculate the HW average
  for(int i=0;i<SET_NUM;i++){
    hwAvg += arr[0][i]; // sum the scores of HW
  }
  
  hwAvg = hwAvg / 5;
  
  // Find the best and the worst scores of Lab
  for (int i = 0; i < SET_NUM; i++){
    // Find the best score of Lab
    if (arr[1][i] > labBest){
      labBest = arr[1][i];
    }
    if(arr[1][i] < labWorst){
      labWorst = arr[1][i];
    }
  }
  
  //calculate the Lab average
  for(int i=0;i<SET_NUM;i++){
    labAvg += arr[1][i]; // sum the scores of Lab
  }
  
  labAvg = labAvg / 5;


  double overall = 0;
  overall = (labAvg + hwAvg)/2;
  
  double avg_each[5];
  for(int i=0;i<SET_NUM;i++){
    avg_each[i] = (arr[0][i] + arr[1][i]) / 2;
  }

  bool is_passed = false;
  if(labAvg >= 50 && hwAvg >= 50){
    is_passed = true;
  }
    
  cout<<" "<<" 1 "<<" 2 "<<" 3 "<<" 4 "<<" 5 "<<" BEST "<<" WORST "<<" AVG "<<endl;
  cout<<"**********************************************************************************************************"<<endl;
  cout<<" HW "<<arr[0][0]<<" "<<arr[0][1] << " " << arr[0][2] << " " << arr[0][3] << " " <<arr[0][4] << " " << hwBest << " " << hwWorst << " " << hwAvg << endl;
  cout<<" LAB "<<arr[1][0]<<" "<<arr[1][1] << " " <<arr[1][2] << " " << arr[1][3]<<" "<< arr[1][4]<<" "<<labBest<<" "<<labWorst<<" " << labAvg <<endl;
  cout<<" AVG "<<avg_each[0]<<" "<<avg_each[1]<<" "<<avg_each[2]<<" "<<avg_each[3]<<" "<<avg_each[4]<<" Overall: "<<overall<<endl;
  
  if(is_passed){
    cout << "Congratulations! You have passed the class!" << endl;
  }else{
    if(labAvg<50){
      cout<<"I'm sorry to inform you that you failed the class, because your performance in lab assignment was <50 percent. Try again in next semester."<<endl;
    } else if(hwAvg<50){
      cout<<"I'm sorry to inform you that you failed the class, because your performance in hw assignment was <50 percent. Try again in next semester."<<endl;
    }else{
      cout<<"I'm sorry to inform you that you failed the class, because your performance in both hw and lab assignment was <50 percent. Try again in next semester."<<endl;
    } 
  }
  
  return 0;
}