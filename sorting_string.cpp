#include<iostream>
#include<cstring>
using namespace std;
string extract_token(string str, int key)
{
    char *ch= strtok((char*)str.c_str()," ");
    while (key>1){
        ch=strtok(NULL," ");
        key--;
    }
    return (string)ch;
}

int main()
{
    int n;
    cin>>n;
    cin.get();
    string *s=new string[n];
    int key;
    for(int i=0; i<n; i++)
    {
        getline(cin,s[i]);
    }
    cin>>key;
    bool reversed;
    cin>>reversed;
    string s1;
    cin>>s1;
    for(int j=0; j<n; j++)
    {
        cout<<s[j]<<endl;
    }
}
