/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include<map>
#include<vector>
using namespace std;

int main()
{
    cout<<"Graph representation using adjency list "<<endl;
    int n=6;
    vector<pair<int,int>>edges ={{0,3},{1,2},{1,5},{2,4},{3,5},{5,4},{5,0}};
	map<int,vector<int>> graph;

	for(int i=0;i<edges.size();i++) {
		int a=edges[i].first;
		int b=edges[i].second;
		graph[a].push_back(b);
	}

	for(auto a:graph) {
		cout<<a.first<<"---->";
		for(int i=0;i<a.second.size();i++) {
			cout<<a.second[i]<<" ";
		}
		cout<<endl;
	}
    return 0;
}
