/*
ID:thtfive
LANG:C++
TASK:combo
*/
#include<iostream>
using namespace std;
#include<fstream>

int main()
{
    int Maxnum,comb1[3],comb2[3];
    int counter=0;
    ifstream fin("combo.in");
    ofstream fout("combo.out");
    fin>>Maxnum>>comb1[0]>>comb1[1]>>comb1[2];
    fin>>comb2[0]>>comb2[1]>>comb2[2];
    if (Maxnum<6)counter=Maxnum*Maxnum*Maxnum;
    else
    {
        int tmp1=(comb1[0]-comb2[0]+Maxnum)%Maxnum;
        int tmp2=(comb1[1]-comb2[1]+Maxnum)%Maxnum;
        int tmp3=(comb1[2]-comb2[2]+Maxnum)%Maxnum;
        if (tmp1>(Maxnum/2))tmp1=Maxnum-tmp1;
        if (tmp2>(Maxnum/2))tmp2=Maxnum-tmp2;
        if (tmp3>(Maxnum/2))tmp3=Maxnum-tmp3;

        if (tmp1<5&&tmp2<5&&tmp3<5)
        {
            counter=250-(5-tmp1)*(5-tmp2)*(5-tmp3);
        }
        else
        {
            counter=250;
        }
    }
    fout<<counter<<"\n";
    return 0;
}
