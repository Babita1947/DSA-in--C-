#include<iostream>
#include<deque>
using namespace std;

int main()
{
    deque<int> d1={10,35,22,18,70};

    //How to access deque elements
    //1. []
    for(int i=0;i<d1.size();i++)
       cout<<d1[i]<<" ";
    cout<<endl;  
    //2. at()
    for(int i=0;i<d1.size();i++)
       cout<<d1.at(i)<<" ";
    cout<<endl;
    //3. Implicit iterator
    for(auto x:d1)
       cout<<x<<" ";  
    cout<<endl;
    //4. Explicit iterator
    // iterator
    deque<int>::iterator it;
    for(it=d1.begin();it!=d1.end();it++)
       cout<<*it<<" ";
    cout<<endl;
    // const_iterator
    deque<int>::const_iterator it1;
    for(it1=d1.cbegin();it1!=d1.cend();it1++)
       cout<<*it1<<" ";
    cout<<endl;
    // reverse_iterator
    deque<int>::reverse_iterator it2;
    for(it2=d1.rbegin();it2!=d1.rend();it2++)
        cout<<*it2<<" ";
    cout<<endl;
    // const_reverse_iterator
    deque<int>::const_reverse_iterator it3;
    for(it3=d1.crbegin();it3!=d1.crend();it3++)
        cout<<*it3<<" ";
    cout<<endl;

    deque<int>d2;
    d2.assign({11,22,33});
    d2.push_front(44);
    d2.emplace_front(66);
    d2.push_back(55);
    d2.emplace_back(77);
    d2.emplace(d2.begin()+2,99);
    for(auto x:d2)
       cout<<x<<" ";
    cout<<endl;
    
    cout<<d2.empty()<<endl;
    cout<<d2.back()<<endl;
    cout<<d2.front()<<endl;
    
    d2.insert(d2.begin()+3,100);
    for(auto x:d2)
       cout<<x<<" ";
    cout<<endl; 

    d2.erase(d2.begin()+3);
    d2.pop_front();
    d2.pop_back();
    for(auto x:d2)
       cout<<x<<" ";
    cout<<endl;  
    return 0; 
}