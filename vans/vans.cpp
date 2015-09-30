/*
ID:thtfive
LANG:C++
TASK:vans
*/
#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;
ifstream fin("vans.in");
ofstream fout("vans.out");
int base=100000000;
int N;
int result;
string strlib="0123456789";


class BigInteger
{
public:
    int data[100];
    BigInteger()
    {
        memset(data,0,sizeof(data));
    }
    BigInteger(int init)
    {
        memset(data,0,sizeof(data));
        data[0]=init;
    }
    BigInteger operator +(BigInteger tmp)
    {
        BigInteger c;
        int sign=0;
        for(int i=0;i<100;i++)
        {
            int ans=tmp.data[i]+data[i]+sign;
            c.data[i]=ans%base;
            sign=ans/base;
        }
        return c;
    }
    BigInteger operator -(BigInteger tmp)
    {
        int sign=0;
        BigInteger c;
        for(int i=0;i<100;i++)
        {
            int ans=data[i]-tmp.data[i]+sign;
            if(ans<0)sign=-1;
            else sign=0;
            c.data[i]=(ans+base)%base;
        }
        return c;
    }

    BigInteger operator =(const BigInteger &tmp)
    {
        for(int i=0;i<100;i++)
        {
            data[i]=tmp.data[i];
        }
        return *this;
    }
};

BigInteger f[1010];
BigInteger g[1010];
void init()
{
    result=0;
    fin>>N;
}

void solution()
{
    f[1]=0;
    g[1]=2;
    f[2]=2;
    g[2]=2;
    f[3]=4;
    g[3]=8;
    for(int i=4;i<=N;i++)
    {
        g[i]=f[i-1]+f[i-1]+g[i-1]+g[i-2]-g[i-3];
        f[i]=g[i-1]+f[i-1];
    }
}

void print()
{
    string str;
    for(int i=99;i>=0;i--)
    {
        int value=f[N].data[i];
        string strtmp;
        for(int i=1;i<=8;i++)
        {
            int tmp=value%10;
            strtmp=strlib[tmp]+strtmp;
            value/=10;
        }
        str+=strtmp;
    }
    int length=str.length();
    int start;
    for(start=0;start<length;start++)
    {
        if(str[start]!='0')break;
    }

    if(start!=length)
    {
        for(int i=start;i<length;i++)
            fout<<str[i];
    }
    else
    {
        fout<<"0";
    }
    fout<<"\n";

    if(start!=length)
    {
        for(int i=start;i<length;i++)
            cout<<str[i];
    }
    else
    {
        cout<<"0";
    }
    cout<<"\n";

}
int main()
{
    init();
    solution();
    print();
}
