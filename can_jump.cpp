#include<iostream>
#include<vector>
using namespace std;
bool canJump(vector<int> nums)
{
    if(nums.size()==1)
        return true;
    int dist=0;
    for(int i=0; i<nums.size(); i++)
    {
        dist=max(dist,nums[i]);
        if(dist==0 and i!=nums.size()-1)
            return false;
        dist--;
    }
    return true;
}
int main()
{
    int n;
    cin>>n;
    vector<int> nums;
    for(int i=0; i<n; i++)
    {
        int data;
        cin>>data;
        nums.push_back(data);
    }
    if(canJump(nums))
        cout<<"True"<<endl;
    else
        cout<<"False"<<endl;
}
