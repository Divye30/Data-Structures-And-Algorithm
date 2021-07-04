#include<iostream>
#include<queue>
using namespace std;
int main()
{
    priority_queue<int> left;
    priority_queue<int,vector<int>, greater<int>> right;
    int d;
    cin>>d;
    left.push(d);
    float med=d;
    cout<<med<<endl;
    while(d!=-1)
    {
        cin>>d;
        if(left.size()>right.size())
        {
            if(d<med)
            {
                right.push(left.top());
                left.pop();
                left.push(d);
            }
            else{
                right.push(d);
            }
            med=(left.top()+right.top())/2.0;
        }
        else if(left.size()==right.size())
        {
            if(d<med)
            {
                left.push(d);
                med=left.top();
            }
            else{
                right.push(d);
                med=right.top();
            }
        }
        else{
            if(d>med)
            {
                left.push(right.top());
                right.pop();
                right.push(d);
            }
            else{
                left.push(d);
            }
            med=(left.top()+right.top())/2.0;
        }
        if(d!=-1)
        cout<<med<<endl;
    }
}
