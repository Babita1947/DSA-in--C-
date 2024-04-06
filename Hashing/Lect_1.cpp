#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

bool hashTable[MAX+1][2];

void insert(int a[],int n){
    for(int i=0;i<n;i++){
        if(a[i]>=0){
          hashTable[a[i]][0] = 1;
        }
        else{
            hashTable[abs(a[i])][1] = 1;
        }
    }
}

bool search(int find){
    if(find >= 0){
        if(hashTable[find][0] == 1){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        find = abs(find);
        if(hashTable[find][1] == 1){
            return true;
        }
        else{
            return false;
        }
    }
}

int main(){
    int arr[] = {-1,9,2,-5,3,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    insert(arr,n);

    int find = 1;
    if(search(find)){
        cout<<"Element is present"<<endl;
    }
    else{
        cout<<"Element is not present"<<endl;
    }
    return 0;
}




