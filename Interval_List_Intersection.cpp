#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList)
{
    int n=firstList.size(), m=secondList.size(), i=0, j=0;
    vector<vector<int>> ans;
    while(i<n and j<m)
    {
        int front= max(firstList[i][0], secondList[j][0]);
        int back= min(firstList[i][1], secondList[j][1]);
        if(back-front >= 0)
        {
            ans.push_back({front,back});
        }
        if(firstList[i][1]<secondList[j][1])
            i++;
        else
            j++;
    }
    return ans;
}
int main()
{
    int n,m;
    cin>>n;
    vector<vector<int>> firstList;
    for(int i=0; i<n; i++)
    {
        vector<int> temp;
        int d1,d2;
        cin>>d1>>d2;
        temp.push_back(d1);
        temp.push_back(d2);
        firstList.push_back(temp);
    }
    cin>>m;
    vector<vector<int>> secondList;
    for(int i=0; i<m; i++)
    {
        vector<int> temp;
        int d1,d2;
        cin>>d1>>d2;
        temp.push_back(d1);
        temp.push_back(d2);
        secondList.push_back(temp);
    }
    cout<<endl;
    vector<vector<int>> ans=intervalIntersection(firstList,secondList);
    for(int i=0; i<ans.size(); i++)
    {
        for(int j=0; j<2; j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
