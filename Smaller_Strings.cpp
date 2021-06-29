#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long int lli;
bool isPalindrome(string s)
{
    int i=0;
    auto len=s.length();
    while(i<=len/2)
    {
        if(s[i]!=s[len-i-1])
            return false;
        i++;
    }
    return true;
}
int generate_subsequences(string a, string out, lli i, lli j,string str)
{
    if(a[i]=='\0')
    {
        out[j]='\0';
        if(isPalindrome(out) and out<a)
           return 1;
    }
    int count=0;
    count+=generate_subsequences(a,out,i+1,j,str);
    out[j]=a[i];
    count+=generate_subsequences(a,out,i+1,j+1,str);
    return count;
}
int main()
{
    int t;
    cin>>t;
    int count=1;
    while(t--)
    {
        int n,k;
        string str;
        cin>>n>>k;
        cin>>str;
        string temp;
        /*char ch='b';
        int var=k;
        while(var--)
        {
            temp.push_back(ch);
            ch++;
        }
        //vector<string> v;
        //v.push_back(temp);
        int size=0;
        do
        {
            if(isPalindrome(temp))
            {
                if(temp<str)
                    size++;//v.push_back(temp);
            }
        }while(next_permutation(temp.begin(),temp.end()));
        cout<<"Case "<<"#"<<count<<": "<<size<<endl;*/
        cout<<"Case "<<"#"<<count<<": "<<generate_subsequences(str, temp, 0, 0)<<endl;
        count++;
    }
}
