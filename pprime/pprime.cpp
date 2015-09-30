/*
ID:thtfive
LANG:C++
TASK:pprime
*/
#include<iostream>
#include<fstream>
#include<cmath>

using namespace std;

string strlib="0123456789";
ifstream fin("pprime.in");
ofstream fout("pprime.out");
int minnum;
int maxnum;

bool isprime(int num)
{
    for (int i=2;i*i<=num;i++)
    {
        if (0==num%i)return false;
    }
    return true;
}

bool ispal(int num)
{
    int index;
    string str="";
    while(num!=0)
    {
        index=num%10;
        str+=strlib[index];
        num=num/10;
    }

    int len=str.length();
    for (int i=0;i<len;i++)
    {
        if (str[i]!=str[len-1-i])return false;
    }
    return true;
}

void createpal(int nDigit,int pDigit,int number)
{
    int num;
    int tmp;
    for (int i=0;i<10;i++)
    {
        tmp=1;
        for (int j=0;j<(pDigit-1);j++)tmp*=10;
        num=number+i*tmp;

        if((nDigit+1-pDigit)!=pDigit)
        {
            tmp=1;
            for (int j=0;j<(nDigit-pDigit);j++)tmp*=10;
            num+=i*tmp;
        }


        if (pDigit!=(nDigit+1)/2)
        {
            createpal(nDigit,pDigit+1,num);
        }
        else
        {
            bool flag=false;
            if (num%10!=0)
            {
                if (isprime(num)&&minnum<=num&&num<=maxnum)flag=true;
                if (flag)fout<<num<<"\n";
            }
        }
    }
    return;
}

int main ()
{
    int minlen,maxlen;
    fin>>minnum>>maxnum;

    int starter=minnum;
    if (starter%2==0)starter++;

    int index;
    string str="";
    int num=minnum;
    while(num!=0)
    {
        index=num%10;
        str+=strlib[index];
        num=num/10;
    }
    minlen=str.length();

    str="";
    num=maxnum;
    while(num!=0)
    {
        index=num%10;
        str+=strlib[index];
        num=num/10;
    }
    maxlen=str.length();

    if (maxlen>8)maxlen=8;

    for (int i=minlen;i<=maxlen;i++)
    {
        createpal(i,1,0);
    }

    return 0;
}
