#include<iostream>
using namespace std;
class Item
{
    private:
        int a,b;
    public:
        void setData(int a,int b)
        {
            this->a=a;
            this->b=b;
        }
        void showData()
        {
            cout<<"a="<<a<<"b="<<b;
        }
        bool operator>(Item i)  //operator overloading
        {
            if(a+b > i.a+i.b)
              return true;
            else 
              return false;  
        }
        Item greater(Item obj)
        {
            if(a+b >obj.a+obj.b)
              return *this;
            else  
              return obj;  
        }

};