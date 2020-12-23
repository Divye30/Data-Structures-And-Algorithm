#include<iostream>
#include<string>
using namespace std;
void calculation(string s1, string s2)
{
    int i=0;
    while(s1[i]!='\0' || s2[i]!='\0')
    {
        if(s1[i]!=s2[i])
        {
            cout<<"1";
            i++;
        }
        else
        {
            cout<<"0";
            i++;
        }
    }
}
int main()
{
    int t;
    string s1, s2;
    cin>>t;
    for(int i=0; i<t; i++)
    {
        cin>>s1;
        cin>>s2;
        calculation(s1, s2);
        cout<<endl;
    }
}
