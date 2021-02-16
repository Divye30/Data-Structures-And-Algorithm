#include<iostream>
#include<cstring>
using namespace std;
char table[][10]={" ", ".+@$", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
string searchIn []={"prateek", "sneha", "deepak", "arnav", "shikha", "palak", "utkarsh", "divyam", "vidhi", "sparsh", "akku"};
void generate_patterns(char *input, char *out, int i, int j)
{
    if(input[i]=='\0')
    {
        out[j]='\0';
        for(int x=0; x<11; x++)
        {
            auto found= searchIn[x].find(out,0);
            if(found!=string::npos)
            {
                cout<<searchIn[x]<<endl;
            }
        }
        return;
    }
    int digit=input[i]-'0';
    for(int k=0; table[digit][k]!='\0'; k++)
    {
        out[j]=table[digit][k];
        generate_patterns(input, out, i+1, j+1);
    }
    return;
}
int main()
{
    char input[100];
    cin>>input;
    char out[100];
    generate_patterns(input, out, 0, 0);
}
