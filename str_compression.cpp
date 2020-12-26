#include<iostream>
#include<string>
using namespace std;
void compression(string s1)
{
    char temp;
    int count=0;
    int i=0;
    temp=s1[i];
    while(s1[i]!='\0')
    {
        if(s1[i]==temp)
        {
            count+=1;
            i++;
        }
        else
        {
            cout<<temp<<count;
            temp=s1[i];
            count=1;
            i++;
        }
    }
    if(s1[i]=='\0')
    {
        cout<<temp<<count;
    }
}
int main()
{
    string s;
    cin>>s;
    compression(s);
}
