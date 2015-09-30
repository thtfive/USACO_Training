#include<iostream>
#include<fstream>
using namespace std;

int result;
int N;

void solve()
{
    int last1;
    int sum=0;
    if(N%2!=0||N==0)
    {
        result=0;
        return;
    }
    if(N==2)
    {
        result=3;
        return;
    }

    last1=3;
    sum=1;
    for(int i=4;i<=N;i+=2)
    {
        result=(last1*3+2*sum)%12357;
        sum=(sum+last1)%12357;
        last1=result;
    }
}

void output()
{
    cout<<result<<"\n";
}

int main()
{
    cin>>N;
    solve();
    output();
    return 0;
}
