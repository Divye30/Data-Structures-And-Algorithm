#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;
unordered_map<string, vector<string>> G;
unordered_set<string> seen;
vector<vector<string>> ans;
void dfs(string& email)
{
    seen.insert(email);
    ans.back().push_back(email);
    for(auto& adjEmail : G[email])
        if(!seen.count(adjEmail))
            dfs(adjEmail);
}
vector<vector<string>> accountsMerge(vector<vector<string>>& A)
{
    for(auto& acc : A)
        for(int i = 2; i < size(acc); i++)
        {
            G[acc[i]].push_back(acc[i-1]);
            G[acc[i-1]].push_back(acc[i]);
        }
    for(auto& acc : A)
        if(!seen.count(acc[1]))
        {
            ans.push_back({acc[0]});
            dfs(acc[1]);
            sort(begin(ans.back())+1,end(ans.back()));
        }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<vector<string>> A(n);
    for(int i=0; i<n; i++)
    {
        string name;
        cin>>name;
        A[i].push_back(name);
        int m;
        cin>>m;
        for(int j=0; j<m; j++)
        {
            string eid;
            cin>>eid;
            A[i].push_back(eid);
        }
    }
    vector<vector<string>> ans=accountsMerge(A);
    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i][0]<<":";
        for(int j=0; j<ans[i].size()-1; j++)
        {
            cout<<ans[i][j+1]<<", ";
        }
        cout<<endl;
    }
}
