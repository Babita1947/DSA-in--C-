#include<iostream>
#include<vector>

using namespace std;
int majorityElement(vector<int>& nums);
int main()
{
    vector<int>nums={2,2,1,1,1,2,2};
    
    cout<<majorityElement(nums);
    

}

int majorityElement(vector<int>& nums)
{
    //BRUTE FORCE SOLUTION
    // int n=nums.size();
    // int cnt;
    // for(int i=0;i<n;i++)
    // {
    //    cnt=0;
    //    for(int j=0;j<n;j++)
    //    {
    //     if(nums[j]==nums[i])
    //        cnt++;
    //    }
    //    if(cnt>n/2)
    //      return nums[i];
    // }
    // return -1;

    //OPTIMAL SOLUTION

    int cnt=0;
    int el;
    int n=nums.size();
    for(int i=0;i<n;i++)
    {
        if(cnt==0)
        {
            cnt=1;
            el=nums[i];
        }
        else if(nums[i]==el){
            cnt++;
        }
        else{
            cnt--;
        }

    }
    int cnt1=0;
    for(int i=0;i<n;i++)
    {
        if(nums[i]==el)
           cnt++;
    }
    if(cnt > n/2)
       return el;
    return -1;   
}