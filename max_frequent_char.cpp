#include<iostream>
#include<string>
using namespace std;
void max_char(char str[1000])
{
    int arr[256]={0};
    int max=arr[0];
    int index=0;
    for(int i=0; str[i]!='\0'; i++)
    {
        arr[str[i]]+=1;
    }
    for(int j=1; j<256; j++)
    {
        if(max<arr[j])
        {
            max=arr[j];
            index=j;
        }
    }
    char ch=index;
    cout<<ch<<endl;
}
int main()
{
    char ch[1000];
    cin.getline(ch,1000);
    max_char(ch);
}
