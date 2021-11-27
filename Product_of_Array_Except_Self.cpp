#include<iostream>
#include<vector>
using namespace std;
vector<int> productExceptSelf(vector<int>& nums)
{
    int n=nums.size();
    vector<int> output(n,1);
    output[0]=nums[0];
    for(int i=1; i<n; i++)
    {
        output[i]=output[i-1]*nums[i];
    }
    int product=1;
    for(int i=n-1; i>=0; i--)
    {
        if(i!=0)
        {
            output[i]=output[i-1]*product;
        }
        else
        {
            output[i]=product;
        }
        product=product*nums[i];
    }
    return output;
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
    vector<int> res=productExceptSelf(nums);
    for(int i=0; i<n; i++)
    {
        cout<<res[i]<<" ";
    }
    cout<<endl;
}
