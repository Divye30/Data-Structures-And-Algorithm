#include<iostream>
#include<vector>
using namespace std;
int coinChange(vector<int> coins, int amount)
{
    vector<int> dp(amount+1,amount+1);
    dp[0]=0;
    for(int i=1; i<=amount; i++)
    {
        for(int j=0; j<coins.size(); j++)
        {
            if(i-coins[j]>=0)
            {
                dp[i]=min(dp[i],1+dp[i-coins[j]]);
            }
        }
    }
    return (dp[amount]!=amount+1)? dp[amount]:-1;
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
    cout<<coinChange(coins, amount)<<endl;
}

