#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int find(int x, vector<int> &parent)
{
    if(parent[x]==-1)
        return x;
    parent[x]=find(parent[x],parent);
    return parent[x];
}
void Union(int x, int y, vector<int> &parent)
{
    int x1=find(x,parent);
    int y1=find(y,parent);
    if(x1!=y1)
        parent[y1]=x1;
}
int largestComponentSize(vector<int>& nums)
{
    int n=nums.size();
    int m= *max_element(begin(nums), end(nums)) + 1;
    vector<int> parent(m,-1);
    for(int i=0; i<n; i++)
    {
        for(int j=2; j*j<=nums[i]; j++)
        {
            if(nums[i]%j==0)
            {
                Union(nums[i],j,parent);
                Union(nums[i],nums[i]/j,parent);
            }
        }
    }
    unordered_map<int,int> mp;
    for(int i=0; i<n; i++)
    {
        int x=find(nums[i],parent);
        mp[x]++;
    }
    int maxCount=0;
    for(auto &m : mp)
        maxCount=max(maxCount, m.second);
    return maxCount;
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
    cout<<largestComponentSize(nums)<<endl;
}
