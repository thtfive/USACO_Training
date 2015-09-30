/*
ID:thtfive
LANG:C++
TASK:sprime
*/

#include<iostream>
#include<fstream>
using namespace std;

ofstream fout("sprime.out");

void create_sprime(int n,int num,int N)
{
    if (n==0)
    {
        create_sprime(1,2,N);
        create_sprime(1,3,N);
        create_sprime(1,5,N);
        create_sprime(1,7,N);
    }
    if (n<N&&n!=0)
    {
        int tmp;
        for (int i=1;i<10;i=i+2)
        {
            tmp=num*10+i;
            bool flag=true;
            for (int j=2;j*j<=tmp;j++)if(tmp%j==0){flag=false;break;}
            if(flag==true)create_sprime(n+1,tmp,N);
        }
    }
    if (n==N)
    {
        fout<<num<<"\n";
    }
}

int main()
{
    ifstream fin("sprime.in");

    int N;
    fin>>N;
    create_sprime(0,0,N);

}
