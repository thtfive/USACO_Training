/*
ID:thtfive
LANG:C++
TASK:shopping
*/
#include<iostream>
#include<fstream>
using namespace std;
int record[6][6][6][6][6];
int NumOfSpecial;
int effectNum;
int NeedNum;
int Special[100][12];
int Offer[100][6];
int Items[5],Code[5],Price[5];
bool ifoffereffect[100];

void OfferSelection()
{

    for (int i=0;i<NumOfSpecial;i++)///judge every special offer
    {

        if(Special[i][0]>NeedNum)continue;///if the items of special offer is more than NeedNum, is not effect
        else
        {

            for (int k=0;k<6;k++)Offer[effectNum][k]=0;///initialize
            int counter=0;///for checking whether all items is within the Code
            for (int j=0;j<NeedNum;j++)
            {
                for(int idx=1;idx<=Special[i][0]*2-1;idx+=2)///the place 1,3,5,7,9 is used for code
                {
                    int code=Special[i][idx];
                    if(Code[j]==code)
                    {
                        counter++;
                        Offer[effectNum][j]=Special[i][idx+1];

                    }
                }
            }
            Offer[effectNum][5]=Special[i][11];
            if (counter==Special[i][0])effectNum++;
        }
    }
}

int solution(int a,int b,int c,int d,int e)
{
    int min;
    if(record[a][b][c][d][e]!=-1)return record[a][b][c][d][e];
    else
    {
        min=a*Price[0]+b*Price[1]+c*Price[2]+d*Price[3]+e*Price[4];
        for (int i=0;i<effectNum;i++)
        {
            int a1=a-Offer[i][0];
            int b1=b-Offer[i][1];
            int c1=c-Offer[i][2];
            int d1=d-Offer[i][3];
            int e1=e-Offer[i][4];
            if(a1>=0&&b1>=0&&c1>=0&&d1>=0&&e1>=0)
            {
                int money=Offer[i][5]+solution(a1,b1,c1,d1,e1);
                min=min<money?min:money;
            }
        }
    }
    record[a][b][c][d][e]=min;
    return min;
}

int main()
{
    for(int i=0;i<100;i++)
    {
        ifoffereffect[i]=false;
    }
    ifstream fin("shopping.in");
    ofstream fout("shopping.out");
    effectNum=0;
    fin>>NumOfSpecial;
    for (int i=0;i<NumOfSpecial;i++)
        for (int j=0;j<12;j++)
            Special[i][j]=0;

    for (int i=0;i<NumOfSpecial;i++)
    {
        int n;
        fin>>n;
        Special[i][0]=n;
        for (int j=1;j<=2*n;j=j+2)
            fin>>Special[i][j]>>Special[i][j+1];
        fin>>Special[i][11];
    }
    for (int i=0;i<5;i++)
    {
     Price[i]=0;
     Items[i]=0;
     Code[i]=0;
    }
    for (int i=0;i<=5;i++)
        for (int j=0;j<=5;j++)
            for (int k=0;k<=5;k++)
                for (int m=0;m<=5;m++)
                    for (int n=0;n<=5;n++)
                        record[i][j][k][m][n]=-1;
    record[0][0][0][0][0]=0;

    fin>>NeedNum;
    for (int i=0;i<NeedNum;i++)
        fin>>Code[i]>>Items[i]>>Price[i];

    OfferSelection();
//    for (int i=0;i<effectNum;i++)
//    {
//        for(int j=0;j<6;j++)
//        cout<<Offer[i][j]<<" ";
//        cout<<"\n";
//    }
    int result=solution(Items[0],Items[1],Items[2],Items[3],Items[4]);
    cout<<result<<endl;
    fout<<result<<endl;
//    for (int i=0;i<NumOfSpecial;i++)
//    {
//        for(int j=0;j<12;j++)
//        cout<<Special[i][j]<<" ";
//        cout<<"\n";
//    }
}
