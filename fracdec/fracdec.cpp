/*
ID:thtfive
LANG:C++
TASK:fracdec
*/
#include<fstream>
#include<iostream>
#include<iomanip>
using namespace std;

string lib="0123456789";
void division(int *flag,int N,int D,string &str,int &index);

int main()
{
//    ifstream fin("fracdec.in");
//    ofstream fout("fracdec.out");
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int N,D;
    fin>>N>>D;
    int flag[D];
    for (int i=0;i<D;i++)
        flag[i]=-1;

    string str="";
    int index=0;

    int beforedot=N/D;

    do
    {
        str=lib[beforedot%10]+str;
        beforedot/=10;
    }
    while(beforedot!=0);

    str+=".";
    division(flag,N%D,D,str,index);
    int counter=0;

    if (index!=-1){
        str+=")";
        int len=str.length();
        int place;
        place=len-index-2;

        int idx=0;
        while(idx<len)
        {
            if (counter%76==0&&counter!=0)fout<<"\n";
            fout<<str[idx];
            if (counter==place){fout<<"(";counter++;}
            idx++;
            counter++;
        }
    }
    else
    {
        int len=str.length();
        while(counter<len)
        {
            if (counter%76==0&&counter!=0)fout<<"\n";
            fout<<str[counter];
            counter++;
        }
    }

    return 0;
}


void division(int *flag,int N,int D,string &str,int &index)
{
    int aux=0;
    while(flag[N]==-1)
    {
        flag[N]=aux;
        aux++;
        int ans;
        N=N*10;
        ans=N/D;
        N=N%D;
        str+=lib[ans];
        if (N==0)break;
    }

    if (N==0){index=-1;return;}
    if (flag[N]!=-1){index=aux-flag[N];return;}


}
