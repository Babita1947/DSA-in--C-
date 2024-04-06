// In STL there are three types of Containers :
//    1. Sequence Container
//    2. Associative Container
//    3. Container Adapters
// 1. Sequence Container : [vector,array,deque,list,forward_list].
// 2. Associative Container : [set,map,multimap,multiset].
// 3. Container Adapters : [stack,queue,priority_queue].

#include<iostream>
#include<set>
#include<string>
using namespace std;
class Book
{
    private:
       int bookid;
       string title;
       float price;
    public:
       int getBookId()const
       {
        return bookid;
       }
       float getPrice()const
       {
         return price;
       }
       Book(int i,string t,float p):bookid(i),title(t),price(p)//constructor
       {}
       void showBook()const
       {
        cout<<bookid<<" "<<title<<" "<<price<<endl;
       }  
};
class OrderByBookId
{
    public:
       bool operator()(const Book &b1,const Book &b2)const
       {
          if(b1.getBookId()<b2.getBookId())
             return true;
          else
             return false;   
       }
};
class OrderByPrice
{
    public:
       bool operator()(const Book &b1,const Book &b2)const
       {
          if(b1.getPrice()<b2.getPrice())
             return true;
          else
             return false;   
       }
};
class desc
{
    public: 
      //to make set elements in descending order 
      bool operator()(const int &a,const int &b)const //writing const after function means do not change anything in member variables
        {
           if(a>b)
             return true;
           else 
             return false;
        }
};
int main()
{
    /*Primitive Data Type*/
    set<int,desc>s1={10,30,20,50,40,10,20};
    
    // for(auto x:s1)
    //   cout<<x<<" ";
    // cout<<endl;

   
    // set<int>::iterator it;
    // for(it=s1.begin();it!=s1.end();it++)
    //    cout<<*it<<" ";
    // cout<<endl; 

    /*Non-Primitive Data Type*/
    set<Book,OrderByPrice>s2={*new Book(1,"Java",340.0),
                 *new Book(2,"Python",405.0),
                 *new Book(3,"CPP",275.0),
                 *new Book(4,"Django",805.0),
                 *new Book(5,"NodeJs",907.0)
                 };
    for(auto x:s2)
       x.showBook();
    cout<<endl;
    set<Book,OrderByPrice>::iterator it;
    for(it=s2.begin();it!=s2.end();it++)
       it->showBook();
    cout<<s2.empty()<<endl;
    cout<<s1.count(10)<<endl;
    s1.emplace(70);
    for(auto x:s1)
      cout<<x<<" ";
    cout<<endl;
    set<int,desc>::iterator it1=s1.begin();
    set<int,desc>::iterator it2=s1.end();
    it1++;
    it2--;
    s1.erase(it1,it2);
    for(auto x:s1)
      cout<<x<<" ";
    cout<<endl;
    

   return 0;
}