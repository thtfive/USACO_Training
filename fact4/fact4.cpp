/*
ID:thtfive
LANG:C++
TASK:fact4
*/
#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    ifstream fin("fact4.in");
    ofstream fout("fact4.out");
    int N;
    int result=1;
    fin>>N;
    int number[N];
    for (int i=0;i<=N;i++)number[i]=i;

    int counter=0;
    for (int i=5;i<=N;i++)
    {
        int num=number[i];
        while(num%5==0)
        {
            num/=5;
            counter++;
        }
        number[i]=num;
    }

    for (int i=2;i<=N;i++)
    {
        int num=number[i];
        while(num%2==0&&counter>0)
        {
            num/=2;
            counter--;
        }
        number[i]=num;

    }

//    for (int i=1;i<=N;i++)
//        cout<<number[i]<<endl;

    for (int i=1;i<=N;i++)
    {
        result*=number[i];
        result%=10;
    }

    cout<<result<<endl;
    fout<<result<<"\n";


    return 0;
}
