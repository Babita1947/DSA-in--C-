#include<iostream>
#include<queue>
#include<deque>
#include<vector>
#include<list>
using namespace std;
int main()
{
    queue<int,list<int>> q1;
    q1.push(45);
    q1.push(77);
    q1.push(18);
    q1.push(1);
    q1.push(33);
    q1.pop(); //pop_front element
    
    cout<<"Front = "<<q1.front()<<endl;
    cout<<"Back = "<<q1.back()<<endl;
    cout<<"Size = "<<q1.size()<<endl;
    
    
}