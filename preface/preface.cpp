/*
ID:thtfive
LANG:C++
TASK:preface
*/
#include<fstream>
#include<iostream>
#include<cmath>
using namespace std;
string Romelib="IVXLCDM";

void setcount(int (*count)[10],int N)
{
    int thousand=0,hundred=0,ten=0,single=0;
    single=N%10;
    N/=10;
    ten=N%10;
    N/=10;
    hundred=N%10;
    N/=10;
    thousand=N%10;
    for (int i=1;i<10;i++)count[0][i]=thousand*100+hundred*10+ten;
    for (int i=1;i<=single;i++)count[0][i]++;

    for (int i=1;i<10;i++)count[1][i]=thousand*100+hundred*10;
    for (int i=1;i<ten;i++)count[1][i]+=10;
    for (int i=ten,j=0;j<=single;j++)count[1][i]++;

    for (int i=1;i<10;i++)count[2][i]=thousand*100;
    for (int i=1;i<hundred;i++)count[2][i]+=100;
    for (int i=hundred,j=0;j<=ten*10+single;j++)count[2][i]++;

    for (int i=1;i<thousand;i++)count[3][i]+=1000;
    for (int i=thousand,j=0;j<=hundred*100+ten*10+single;j++)count[3][i]++;
    count[0][0]=0;
    count[1][0]=0;
    count[2][0]=0;
    count[3][0]=0;
}

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int result[7];
    for (int i=0;i<7;i++)result[i]=0;
    int N;
    fin>>N;
    int count[4][10];
    for (int i=0;i<4;i++)
        for (int j=0;j<10;j++)
            count[i][j]=0;

    setcount(count,N);

    result[0]=count[0][1]+count[0][2]*2+count[0][3]*3+count[0][4]+count[0][6]+count[0][7]*2+count[0][8]*3+count[0][9];
    result[1]=count[0][4]+count[0][5]+count[0][6]+count[0][7]+count[0][8];
    result[2]=count[0][9]+count[1][1]+count[1][2]*2+count[1][3]*3+count[1][4]+count[1][6]+count[1][7]*2+count[1][8]*3+count[1][9]*1;
    result[3]=count[1][4]+count[1][5]+count[1][6]+count[1][7]+count[1][8];
    result[4]=count[1][9]+count[2][1]+count[2][2]*2+count[2][3]*3+count[2][4]+count[2][6]+count[2][7]*2+count[2][8]*3+count[2][9];
    result[5]=count[2][4]+count[2][5]+count[2][6]+count[2][7]+count[2][8];
    result[6]=count[2][9]+count[3][1]+count[3][2]*2+count[3][3]*3+count[3][4]+count[3][6]+count[3][7]*2+count[3][8]*3+count[3][9];

    for (int i=0;i<7;i++)if (result[i]!=0)fout<<Romelib[i]<<" "<<result[i]<<"\n";


    return 0;
}
