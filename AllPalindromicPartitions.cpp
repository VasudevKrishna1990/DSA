/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include<vector>
using namespace std;

bool isPalindrome(string s){
    for(int i =0,j=s.length()-1;i<=j;i++,j--){
        if(s.at(i) != s.at(j))
            return false;
    }
    return true;
}

void solve(string s,vector<string>&res,string op){
    if(s.length() == 0){
        op.pop_back();
        res.push_back(op);
        return;
    }
    
    for(int i =0;i<s.length();i++){
        string left = s.substr(0,i+1);
        if(isPalindrome(left)){
            solve(s.substr(i+1),res,op+left+" ");
        }
    }
}

void palindromicPartitions(string s){
    vector<string> res;
    solve(s,res,"");
    for(string str:res)
        cout<<str<<" " <<endl;
    return;
}

int main()
{
    string s ="GEEKS";
    palindromicPartitions(s);
    return 0;
}
