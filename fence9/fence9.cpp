/*
ID:thtfive
LANG:C++
TASK:fence9
*/
#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

int main()
{
    ifstream fin("fence9.in");
    ofstream fout("fence9.out");
    double N,M,P;
    fin>>N>>M>>P;
    int counter=0;

    for (int height=1;height<M;height++)
    {
        int start=N/M*height+1;
        int finish=ceil((N-P)*height/M+P)-1;
        if (finish>=start)counter+=finish-start+1;
    }
    cout<<counter<<"\n";
    fout<<counter<<"\n";
    return 0;
}
