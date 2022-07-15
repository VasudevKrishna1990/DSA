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
void print1(vector<vector<int>>&mat){
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

/*

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
*/

void solve(vector<vector <int>>&mat,int xs,int ys,vector<vector<int>>&visited,vector<vector <int>>&res,vector<int>&path)
{
    //cout<<xs << " " << ys << endl;
    if(xs == mat.size()-1 && ys == mat[0].size()-1){
        visited[xs][ys] = 1;
        path.push_back(mat[xs][ys]);
        res.push_back(path);
        path.pop_back();
        visited[xs][ys] = 0;
        return;
    }
    
    if(xs<0 || xs >= mat.size() || ys<0 || ys >= mat[0].size() || visited[xs][ys] != 0)
        return;

    visited[xs][ys] = 1;
    path.push_back(mat[xs][ys]);
        solve(mat,xs+1,ys,visited,res,path);
        solve(mat,xs,ys+1,visited,res,path);
    path.pop_back();
    visited[xs][ys] = 0;
    return;
}
void print(vector<vector<int>>mat){
    for(vector<int>res:mat){
        for(int v:res)
               cout<< v <<" " ;
        cout<<endl;
    }
}
vector<vector <int> > printAllpaths(vector<vector<int> > & mat , int m , int n)
{
    vector<vector<int>>res;
    vector<int>path;
    int N = mat.size();
    int M = mat[0].size();
    vector<vector<int>>visited(N,vector<int>(M,0));
    solve(mat,0,0,visited,res,path);
    print(res);
    return res;
}

int main()
{
    vector<vector<int>> mat={ {1,2},{3,4}};

    printAllpaths(mat, 0, 0);
    
    return 0;
}
