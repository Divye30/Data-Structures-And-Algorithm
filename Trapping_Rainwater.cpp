#include<iostream>
#include<vector>
using namespace std;
int trapWater(vector<int> &height)
{
    int n=height.size();
    int l=0,r=n-1;
    int res=0;
    int lm=0,rm=0;
    while(l<=r)
    {
        if(height[l]<height[r])
        {
            if(height[l]>=lm)
            {
                lm=height[l];
            }
            else
            {
                res+=lm-height[l];
            }
            l++;
        }
        else
        {
            if(height[r]>=rm)
            {
                rm=height[r];
            }
            else
            {
                res+=rm-height[r];
            }
            r--;
        }
    }
    return res;
}
int main()
{
    int n;
    cin>>n;
    vector<int> height;
    for(int i=0; i<n; i++)
    {
        int data;
        cin>>data;
        height.push_back(data);
    }
    cout<<trapWater(height)<<endl;
}
