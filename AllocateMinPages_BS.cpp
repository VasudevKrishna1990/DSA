/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include<climits>
#include<vector>
using namespace std;

int maxofArray(vector<int>a){
    int max = INT_MIN;
    for(int val: a){
        if(max < val)
            max = val;
    }
    return max;
}

int sumofArray(vector<int>a){
    int sum =0;
    for(int val:a){
        sum += val;
    }
    return sum;
}

bool isValidPartition(vector<int>a,int mid ,int k){
    int students = 1;
    int sum = 0;
    for(int i = 0;i<a.size();i++){
        sum += a[i];
        if(sum > mid){
            students +=1;
            sum = a[i];
        }
        
        if(students > k)
            return false;
    }
    return true;
    
}

int findMinimumPages(vector<int>a,int k){
    
    int s = maxofArray(a);
    int e = sumofArray(a);
    int minPages = -1;
    
    while(s<=e){
        int mid = s + (e-s)/2;
        if(isValidPartition(a,mid,k)){
            minPages = mid;
            e = mid -1;
        }
        else{
            s = mid + 1;
        }
    }
    return minPages;
}

int main()
{
    vector<int>a ={51 ,151, 227, 163, 55};
    int k = 3;
    cout<<findMinimumPages(a,k);
    return 0;
}
