/*
ID:thtfive
LANG:C++
TASK:theme
*/
#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;
int notes[5000];

int LCS(int shift,int N)
{
    int counter=0;
    int tmp=0;
    bool flag=false;
    int D=-129032;
    int Dtmp;
    for(int i=0;i<N-shift;i++)
    {
        Dtmp=notes[i+shift]-notes[i];
        if(Dtmp==D)
        {
            tmp++;
        }
        else
        {
            tmp=1;
            D=Dtmp;
        }


        counter=counter>tmp?counter:tmp;
    }
    counter=counter<shift?counter:shift;

    return counter;
}

int main()
{
    ifstream fin("theme.in");
    ofstream fout("theme.out");
    int N;
    fin>>N;
    for(int i=0;i<N;i++)
        fin>>notes[i];


    int result=0;
    int tmp=0;

    for(int shift=1;shift<N-1;shift++)
    {
        tmp=LCS(shift,N);
        result=result>tmp?result:tmp;
    }

    if(result<5)result=0;
    cout<<result<<"\n";
    fout<<result<<"\n";




    return 0;
}
