#include<iostream>
#include<string>
#include<ctype.h>
using namespace std;
void number_of_words(char str[1000])
{
    for(int i=0; str[i]!='\0'; i++)
    {
        if((isupper(str[i]) && !isupper(str[i+1])) || (!isupper(str[i]) && !isupper(str[i+1])))
        {
            cout<<str[i];
        }
        else if(!isupper(str[i]) && isupper(str[i+1]))
        {
            cout<<str[i]<<endl;
        }
        else if(isupper(str[i]) && isupper(str[i+1]))
        {
            cout<<str[i]<<endl;
        }
    }
    cout<<endl;
}
int main()
{
    char a[1000];
    cin.getline(a,1000);
    number_of_words(a);
}
