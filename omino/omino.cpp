/*
ID:thtfive
LANG:C++
*/
#include<iostream>
#include<fstream>
using namespace std;
bool solve(int X,int R,int C)
{
    if(X==1)return true;
    if(X==2)
    {
        if(R*C%2==0)return true;
        else return false;
    }
    if(X==3)
    {
        if(R*C%3!=0)return false;
        else
        {
            if(R>=2&&C>=2)
                return true;
            else return false;
        }
    }
    if(X==4)
    {
        if(R*C%4!=0)
            return false;
        else
        {
            if(R*C>=12)
                return true;
            else
                return false;
        }
    }

}

int main()
{
    ifstream fin("D-small-attempt0.in");
    ofstream fout("D-small-attempt0.out");

    int T;
    fin>>T;
    for (int Test=1;Test<=T;Test++)
    {
        int X,R,C;
        fin>>X>>R>>C;
        bool result=solve(X,R,C);
        if (result)
            fout<<"Case #"<<Test<<": "<<"GABRIEL"<<"\n";
        else
            fout<<"Case #"<<Test<<": "<<"RICHARD"<<"\n";

    }




}
