#include<iostream>
#include<vector>
using namespace std;
int change(vector<int> coins, int amount)
{
    vector<int> dp(amount+1,0);
    dp[0]=1;
    for(int i=0; i<coins.size(); i++)
    {
        for(int j=coins[i]; j<dp.size(); j++)
        {
            dp[j]+=dp[j-coins[i]];
        }
    }
    return dp[amount];
}
int main()
{
    int n;
    cin>>n;
    vector<int> coins;
    for(int i=0; i<n; i++)
    {
        int data;
        cin>>data;
        coins.push_back(data);
    }
    int amount;
    cin>>amount;
    cout<<change(coins,amount)<<endl;
}
