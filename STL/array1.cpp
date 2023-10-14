#include<iostream>
#include<array>
using namespace std;

int main()
{
    array<int,4>a1={10,50,30,40}; //object of array
    array<string,3>a2={"Bhopal","Pune","Jaipur"};  //Initializes object using initializer list.

    //How to access array elements ?
    // 1. using [] subscript operator
    for(int i=0;i<5;i++)
      cout<<a1[i]<<" ";
    cout<<endl;
    // 2. using at()
    try{
    for(int i=0;i<5;i++)
       cout<<a1.at(i)<<" ";
    cout<<endl;   
    }
    catch(std::out_of_range e)
    {
        cout<<"Array out of Index Exception"<<endl;
    }
    
    // 3. using implicit iterator | using range-for loop
    for(auto x:a1) //for object a1
      cout<<x<<" ";
    cout<<endl;

    for(auto x:a2) //for object a2
      cout<<x<<" ";
    cout<<endl;

    // 4. using explicit iterator 
    array<int,4>::iterator i1;
    for(i1=a1.begin();i1!=a1.end();i1++)
    {
        cout<<*i1<<" ";
    }
    cout<<endl;
 
    array<int,4>::reverse_iterator i2;
    for(i2=a1.rbegin();i2!=a1.rend();i2++)
    {
        cout<<*i2<<" ";
    }
    cout<<endl;

    array<int,4>::const_iterator i3;
    i3=a1.cbegin();
    *(a1.begin()+2)=70;
    cout<<*(i3+2)<<" ";
    cout<<a1.back()<<" ";
    cout<<a1.front()<<" ";
    cout<<"\nSize = "<<a1.size();
    
    array<int,4>::const_reverse_iterator i4;
    i4=a1.crbegin();
    cout<<*i4<<" ";
    cout<<endl;
    
    //swap()
    array<int,5> a3={11,22,33,44,55};
    array<int,5> a4={66,77,88,99,100};
    a4.swap(a3);
    for(auto x:a3) 
      cout<<x<<" ";
    cout<<endl;
    for(auto x:a4) 
      cout<<x<<" ";
    cout<<endl;
    
    return 0;
}