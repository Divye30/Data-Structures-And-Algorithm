#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
void LCS(string s1,string s2)
{
    int n1=s1.length();
    int n2=s2.length();
    vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
    for(int i=1;i<=n1;i++)
    {
        for(int j=1;j<=n2;j++)
        {
            if(s1[i-1]==s2[j-1])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    int i=n1,j=n2;
    vector<char> result;
    while(i!=0 and j!=0)
    {
        if(dp[i][j]==dp[i][j-1])
        {
            j--;
        }
        else if(dp[i][j]==dp[i-1][j])
        {
            i--;
        }
        else
        {
            result.push_back(s1[i-1]);
            i--;
            j--;
        }
    }
    reverse(result.begin(),result.end());
    for(int k=0; k<result.size();k++)
    {
        cout<<result[k];
    }
    cout<<endl;
}
int main()
{
    string s1,s2;
    cin>>s1;
    cin>>s2;
    LCS(s1,s2);
}
