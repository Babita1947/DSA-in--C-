#include<iostream>
using namespace std;

int main()
{
    int a[100],j,count=0;
    for(int i=0;i<100;i++)
    {
        cout<<"Enter index :";
        cin>>j;
        cout<<"Enter number at index "<<j<<" ";
        cin>>a[j];
        count++;
    cout<<"Elements in array = "<<count<<"\n\n\n";    
    }
    return 0;
}