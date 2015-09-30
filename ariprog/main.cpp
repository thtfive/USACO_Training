/*
ID:thtfive
LANG:C++
TASK:ariprog
*/
#include<iostream>
#include<fstream>
using namespace std;

ofstream fout("ariprog.out");



void create_sequence(int *&array,int M)
{
    for (int i=0;i<=M;i++)
        for (int j=i;j<=M;j++)
        {
            array[i*i+j*j]=1;
        }
}


void test(int *array,int N,int M)
{
    int counter=0;
    int num=2*M*M+1;
    bool flag;
    int k;
    int a,b;
    for (b=1;b<=num/(N-1)+1;b++)
    {
        for (a=0;a+(N-1)*b<num;a++)///this is important
        {
            flag=true;
            for (k=0;k<N;k++)
            {
                if (array[a+b*k]==0)
                {
                    flag=false;break;
                }
            }
            if (flag){counter++;fout<<a<<" "<<b<<"\n";}
        }
    }
    if (counter==0)fout<<"NONE\n";
}

int main()
{
    int N,M;
    ifstream fin("ariprog.in");
    ofstream fout("ariprog.out");

    fin>>N>>M;
    int *array;
    int num=2*M*M+1;
    array=new int[num];
    for (int i=0;i<num;i++)array[i]=0;
    create_sequence(array,M);
    test(array,N,M);

    return 0;
}
