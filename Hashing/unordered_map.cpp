#include<bits/stdc++.h>
using namespace std;

int main(){
    // unordered_map<string,int> umap;
    // umap["Prince"] = 44;
    // umap["gfg"] = 56;
    // umap["helloworld"] = 90;

    // // for(auto x: umap){
    // //     cout<<x.first<<" "<<x.second<<endl;
    // // }

    

    // string key = "Prince";

    // if(umap.find(key) != umap.end()){
    //     cout<<"key found"<<endl<<endl;
    // }
    // else{
    //     cout<<"key not found"<<endl<<endl;
    // }

    // if(umap.find(key) != umap.end()){
    //     auto temp = umap.find(key);
    //     cout<<"key is : "<<temp->first<<endl;
    //     cout<<"value is : "<<temp->second<<endl<<endl; 
    // }

    // umap.insert(make_pair("mobile", 17000));

    // key = "helloworld";
    // umap.erase(key);

    // for(auto it = umap.begin();it!=umap.end();it++){
    //     cout<<it->first<<" "<<it->second<<endl;
    // }
    
    // cout<<"\nsize = "<<umap.size()<<endl;


    int arr[] = {7,1,0,3,5,0,1,3,2,5,7,3,8,9,9};
    unordered_map<int,int> mpp;

    for(int i=0;i<15;i++){
        mpp[arr[i]]++;
    }

    for(auto it = mpp.begin();it!=mpp.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
    
}