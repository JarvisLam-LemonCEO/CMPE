//
//  main.cpp
//  Lab4Section6
//
//  Created by Vishwa Shah on 2/23/22.
//

#include <iostream>
#include <vector>
using namespace std;


vector<int> processQueries(int a[], int a_size, int b[], int b_size, vector<vector<int>> queries){
    vector<int> result;
    
    for(int q=0; q < queries.size(); q++){
        if(queries[q].size() == 2){
            //{1,5}
            int targetSum = queries[q][1];
            int count = 0;
            for(int j=0; j< a_size; j++){
                for(int k=0; k < b_size; k++){
                    if(a[j] + b[k] == targetSum){
                        count++;
                    }
                }
            }
            result.push_back(count);
        }
        // size 3 {1,1,5}
        else{
            a[queries[q][1]] = queries[q][2];
        }
    }
    
    return result;
}


vector<int> findMaxAndSecondMax(int a[], int a_size){
    int max = a[0];
    int s_max = -1;
    
    for(int i=1; i < a_size; i++){
        if(max < a[i]){
            s_max = max;
            max = a[i];
        }else if(s_max < a[i] && a[i] != max){
            s_max = a[i];
        }
    }
    
    vector<int> result(2);
    result.push_back(max);
    result.push_back(s_max);
    return result;
}


int main(int argc, const char * argv[]) {
        int n = 3;
        vector<vector<int>> queries(n);
        queries[0].push_back(1);
        queries[0].push_back(5);
        queries[1].push_back(0);
        queries[1].push_back(0);
        queries[1].push_back(1);
        queries[2].push_back(1);
        queries[2].push_back(5);
        int a[2] = {3,4};
        int b[3] = {1,2,3};
        int b_size = 3;
        int a_size = 2;
        vector<int> results = processQueries(a,a_size, b,b_size, queries);
        for(int i =0; i < results.size() ; i++){
            cout<<results[i]<<" ";
        }
    return 0;
}
