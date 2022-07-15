/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include<vector>
#include<climits>
using namespace std;
void print(vector<vector<int>>&mat){
    for(vector<int> t : mat){
        for(int val:t){
            if(val <= 9)
                cout<<"0"<<val<<" " ;
            else
                cout<<val<<" ";
        }
        cout<<endl;
    }
    cout <<" ++++++++++++++++++ "<<endl;
}

void solve(vector<vector<int>>&mat,int xs,int ys, int xd,int yd,vector<vector<int>>&visited,int& max,int count){
    if(xs == xd && ys == yd)
    {
        //cout<<"Reached " << count+1 <<" " << max <<endl;
        visited[xs][ys] = count+1;
        count +=1;
        if(count > max){
            max = count;
            print(visited);
        }
        visited[xs][ys] = 0;
        return ;
    }
    //cout<< xs << " " << ys << " || " << xd <<" " << yd <<endl;
    if(xs < 0 || xs >= mat.size() || ys< 0 || ys>= mat[0].size() || mat[xs][ys] == 0 || visited[xs][ys] != 0)
        return ;
        
    visited[xs][ys] = count+1;
        solve(mat,xs,ys-1,xd,yd,visited,max,count+1); // left
        solve(mat,xs,ys+1,xd,yd,visited,max,count+1); // right
        solve(mat,xs-1,ys,xd,yd,visited,max,count+1); // Up
        solve(mat,xs+1,ys,xd,yd,visited,max,count+1); // down
    visited[xs][ys] = 0;
    return ;    
}

int findLongestPath(vector<vector<int>>&mat,int xs,int ys, int xd,int yd)
{
    if(mat[xs][ys] == 0 || mat[xd][yd] == 0)
        return 0;
    int maxLength = INT_MIN;
    int N = mat.size();
    int M = mat[0].size();
    vector<vector<int>>visited(N,vector<int>(M,0));
    solve(mat,xs,ys,xd,yd,visited,maxLength,0);
    if(maxLength == INT_MIN)
    return 0;
    return maxLength-1;
    
}
int main()
{
    vector<vector<int>> mat={ 
                      { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
                      { 1, 1, 0, 1, 1, 0, 1, 1, 0, 1 },
                      { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }};

    cout<< findLongestPath(mat, 0, 0, 1, 7);
    
    return 0;
}
