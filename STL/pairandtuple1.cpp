#include<iostream>
#include<utility>
#include<tuple>
#include<string>
#include<vector>
using namespace std;
int main()
{
    //Pair
    vector<int> v1={35,67,28,50,60,72,55};
    string n1="Mohit";
    pair<string,vector<int>> p1;
    p1=make_pair(n1,v1); //p1 is a pair of string and vector
    pair<int,string> p2(1,"Bhopal");
    pair<int,int>p3(10,20);
    //How to access pair elements
    cout<<p1.first<<" ";
    for(auto x:p1.second)
       cout<<x<<" ";
    cout<<endl;
    cout<<p2.first<<" "<<p2.second<<endl;
    cout<<p3.first<<" "<<p3.second<<endl;
    
    //Tuple

    tuple<int,double,char> t1{1,4.5,'A'};
    tuple<int,string,string> t2{2,"Amit","Ajmer"};
    tuple<int,string,string> t3;
    t3=make_tuple(3,"Arjun","Pune");
    // How to access tuple elements
    cout<<get<0>(t3)<<" "<<get<1>(t3)<<" "<<get<2>(t3);
    cout<<endl;

    return 0;
}