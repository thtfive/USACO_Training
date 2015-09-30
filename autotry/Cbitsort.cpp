#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <ctime>
using namespace std;
const int N = 1000000;
int store[N];
int number[10*N];
int main()
{
    ofstream fout;
    ofstream fout2("numbers.txt");
    fout.open("output.txt");
    for(int i=0;i<N;i++)
    {
        store[i]=0;
    }
    for(int i=1;i<10*N;i++)
    {
        number[i]=i;
    }

    for(int i=1;i<10*N;i++)
    {
        int a=rand()%(10*N-1)+1;
        int b=rand()%(10*N-1)+1;
        int tmp=number[a];
        number[a]=number[b];
        number[b]=tmp;
    }
    for(int i=1;i<10*N;i++)
    {
      //  fout2<<number[i]<<"\n";
        int idx=number[i]/32;
        int delta=number[i]%32;
        store[idx]=store[idx]^(1<<delta);
    }

//    for(int i=0;i<=10*N;i++)
//    {
//        int idx =i/32;
//        int delta=i%32;
//        if(store[idx]&(1<<delta))
//        {
//            fout<<i<<"\n";
//        }
//    }
    return 0;
}
