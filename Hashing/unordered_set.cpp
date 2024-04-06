#include<bits/stdc++.h>

using namespace std;

// int main(){
//     unordered_set<int> s;
//     s.insert(10);
//     s.insert(5);
//     s.insert(15);
//     s.insert(20);
//     s.insert(20);
//     for(auto it=s.begin();it!=s.end();it++){
//         cout<<(*it)<<endl;
//     }
    
//     cout<<"Number of element = "<<s.size()<<endl;
//     // s.clear();
//     // cout<<"Number of element = "<<s.size();

//     int key = 20;

//     // if(s.find(key) == s.end()){
//     //     cout<<"Key not found"<<endl;
//     // }
//     // else{
//     //     auto temp = s.find(key);
//     //     s.erase(temp);
//     // }

//     if(s.find(key) != s.end()){
//         auto temp = s.find(key);
//         s.erase(temp);
//     }
//     cout<<"Number of element = "<<s.size()<<endl;

//     if(s.count(5)){
//         cout<<"key found"<<endl;
//     }
//     else{
//         cout<<"not found"<<endl;
//     }
// }

int main(){
    unordered_set<string> s;
    s.insert("Babita");
    s.insert("Anisha");
    s.insert("Nilam");
    s.insert("Barsha");
    s.insert("Alka");

    for(auto it=s.begin();it!=s.end();it++){
        cout<<(*it)<<endl;
    }

    cout<<"Size of set = "<<s.size()<<endl;
    s.erase(s.find("Barsha"));
    
    for(auto it=s.begin();it!=s.end();it++){
        cout<<(*it)<<endl;
    }

    cout<<"Size of set = "<<s.size()<<endl;
    
    
}