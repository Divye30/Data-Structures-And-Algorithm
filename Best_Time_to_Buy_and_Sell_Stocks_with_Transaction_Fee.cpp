#include<iostream>
#include<vector>
using namespace std;
int maxProfit(vector<int> &prices, int fees)
{
    int buy=-prices[0];
    int sell=0;
    for(int i=1; i<prices.size(); i++)
    {
        buy=max(sell-prices[i],buy);
        sell=max(buy+prices[i]-fees,sell);
    }
    return sell;
}
int main()
{
    int n,fees;
    cin>>n;
    vector<int> nums;
    for(int i=0; i<n; i++)
    {
        int data;
        cin>>data;
        nums.push_back(data);
    }
    cin>>fees;
    cout<<maxProfit(nums,fees)<<endl;
}
