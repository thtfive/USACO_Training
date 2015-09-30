/*
ID:thtfive
LANG:C++
TASK:prime3
*/
#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;
ifstream fin("prime3.in");
ofstream fout("prime3.out");

int totalN,firstNum;
int result;
int G[7][7];
bool flag;
int totalnum=0;
int primes[10000][6];

void init()
{
    fin>>totalN>>firstNum;
    flag=false;
}

bool isprime(int i1,int i2,int i3,int i4,int i5)
{
    int num=i1*10000+i2*1000+i3*100+i4*10+i5;
    for(int i=2;i*i<=num;i++)
    {
        if(num%i==0)return false;
    }
    return true;
}

void primemake()
{
    for(int i1=1;i1<=9;i1++)
    {
        for(int i2=0;i2<=9;i2++)
        {
            for(int i3=0;i3<=9;i3++)
            {
                for(int i4=0;i4<=9;i4++)
                {
                    for(int i5=1;i5<=9;i5++)
                    {
                        if(i5!=2&&i5!=5&&i1+i2+i3+i4+i5==totalN&&isprime(i1,i2,i3,i4,i5))
                        {
                            totalnum++;
                            primes[totalnum][1]=i1;
                            primes[totalnum][2]=i2;
                            primes[totalnum][3]=i3;
                            primes[totalnum][4]=i4;
                            primes[totalnum][5]=i5;
                        }
                    }
                }
            }
        }
    }
}

void solution()
{
    primemake();
    for(int i=1;i<=totalnum;i++)///第一行
    {
        if(primes[i][1]==firstNum)
        {
            for(int j=1;j<=totalnum;j++)///第一列
            {
                if(primes[j][1]==firstNum)
                {

                }
            }
        }
    }

//
//    for(int i=1;i<=totalnum;i++)
//    {
//    }

}

void print()
{
    cout<<result<<"\n";
    fout<<result<<"\n";
}
int main()
{
    init();
    solution();
    print();
}
