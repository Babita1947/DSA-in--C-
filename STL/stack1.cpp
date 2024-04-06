#include<iostream>
#include<stack>
#include<vector>
#include<list>
using namespace std;
int main()
{
    stack<int>s1; //By default implemented indeque
    stack<int,vector<int>> s2;//vector
    stack<int,list<int>> s3;  //list

    //methods of stack
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.pop();
    cout<<"Top = "<<s1.top()<<endl;
    cout<<"Size = "<<s1.size();
    
}