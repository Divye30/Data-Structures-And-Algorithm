#include<iostream>
#include<string>
using namespace std;
void difference_between_char(string str)
{
    int a;
    for(int i=0; str[i]!='\0'; i++)
    {
        cout<<str[i];
        if(str[i+1]!='\0')
        {
            a=str[i+1]-str[i];
            cout<<a;
        }
    }
    cout<<endl;
}
int main()
{
    string s;
    getline(cin,s);
    difference_between_char(s);
}
