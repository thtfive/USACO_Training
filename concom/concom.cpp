/*
ID:thtfive
LANG:C++
TASK:concom
*/
#define max_num 101
#include<iostream>
#include<fstream>
using namespace std;
bool flag[max_num][max_num];
int maxidx=0,minidx=101;
int map[max_num][max_num];
bool sign[max_num];

void concom(int start,int com,int (*result)[max_num])
{
    if (sign[com]==true) return;
    sign[com]=true;

    for (int i=1;i<max_num;i++)result[start][i]+=map[com][i];

    for (int j=1;j<max_num;j++)if (map[com][j]>50)concom(start,j,result);


 L1:for (int k=1;k<max_num;k++)
        if (result[start][k]>50&&sign[k]==false)
        {
            concom(start,k,result);
            goto L1;
        }

    return;
}

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int N;
    fin>>N;

    int x,y,value;
    for (int i=0;i<max_num;i++)
        for (int j=0;j<max_num;j++)
            map[i][j]=0;

    while(fin>>x>>y>>value)
    {
        if (x>maxidx||y>maxidx)maxidx=x>y?x:y;
        if (x<minidx||y<minidx)minidx=x<y?x:y;
        map[x][y]=value;
    }

    int result[maxidx+1][max_num];
    for (int i=1;i<=maxidx;i++)
        for (int j=1;j<max_num;j++)
            result[i][j]=0;

    for (int i=1;i<=maxidx;i++)
    {
        for (int k=1;k<=maxidx;k++)sign[k]=false;
        concom(i,i,result);
    }

    bool signal=false;

    for (int i=1;i<=maxidx;i++)
    {
        for (int k=1;k<=maxidx;k++)
        {
            if (result[i][k]>50&&i!=k)
            {
                signal=true;
                fout<<i<<" "<<k<<"\n";
            }
        }
    }




    if (!signal)fout<<0<<"\n";


    return 0;
}
