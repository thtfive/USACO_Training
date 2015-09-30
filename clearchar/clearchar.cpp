#define LOCAL
#include<iostream>
#include<algorithm>
#include<fstream>
using namespace std;
int result=0;

string shortenstr(string str)
{
    string strtmp=str;
    string newstr;
    while(true)
    {
        newstr="";
        int length=strtmp.length();
        int idx=0;
        while(idx<length)
        {
            if(strtmp[idx]!=strtmp[idx+1])
            {
                newstr+=strtmp[idx];///???
           //     cout<<"idx:"<<idx<<"\n";
            //    cout<<strtmp[idx]<<" "<<strtmp[idx+1]<<"\n";
                idx++;
                continue;
            }
            else
            {
                int i=idx;
                for(;i<length;i++)
                {
                    if(strtmp[i]!=strtmp[idx])break;
                }
                idx=i;
            }
        }
        if(strtmp.length()==newstr.length())break;
        strtmp=newstr;
    }
    return newstr;
}

void solution(string str)
{
    int length=str.length();
    int minlength=111;
    if(length==0)
    {
        result=0;
        return;
    }
    for(int i=0;i<length;i++)
    {
        string strtmp=str.substr(0,i)+str[i]+str.substr(i,length-i);
    //       cout<<strtmp<<" "<<" ans:"<<shortenstr(strtmp)<<"\n";
        string ansstr=shortenstr(strtmp);
        int tmp=ansstr.length();
        minlength=min(minlength,tmp);
    }
    result=length+1-minlength;
}

int main()
{
    #ifdef LOCAL
    freopen("input.txt","r",stdin);
    #endif // LOCAL
    int T;
    cin>>T;
    string str;
    while(T--)
    {
        cin>>str;
      //  cout<<str<<"->\n";
        solution(str);
        cout<<result<<"\n";
        str="";
    }
    shortenstr("ABCCBCCCAA");
 //   cout<<shortenstr("ABCCBCCCAA")<<"\n";
}
