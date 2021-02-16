#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
vector<string> ans;
void permute(string input, string output, int i)
{
    if(input[i]=='\0')
    {
        if(input>output)
        {
            ans.push_back(input);
        }
        return;
    }
    for(int j=i; input[j]!='\0'; j++)
    {
        swap(input[i],input[j]);
        permute(input,output,i+1);
        swap(input[i],input[j]);
    }
    return;
}
int main()
{
    string input;
    cin>>input;
    string output(input);
    permute(input,output,0);
    sort(ans.begin(),ans.end());
    for(auto i= ans.begin(); i!= ans.end(); ++i)
        cout<<*i<<endl;
}
