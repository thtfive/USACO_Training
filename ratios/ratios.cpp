/*
ID:thtfive
LANG:C++
TASK:ratios
*/
#include<fstream>
#include<iostream>
using namespace std;
int mtx[3][4];

int minimum_times(int num1,int num2)
{
    if(num1==0||num2==0)return 0;
    for (int idx=1;idx<=num1;idx++)
    {
        if (idx*num2%num1==0)return idx*num2;
    }
    return 0;
}

void standize(int i,int j)
{
    int x=(i+1)%3;
    int y=(i+2)%3;
    for(int k=0;k<3;k++)
    {
        if(mtx[k][j]<0)
        {
            for (int l=0;l<4;l++)
                mtx[k][l]*=(-1);
        }
    }
    int big=minimum_times(mtx[i][j],mtx[x][j]);
    if(big!=0)
    {
        int temp1=big/mtx[x][j];
        int temp2=big/mtx[i][j];
        for (int n=0;n<4;n++)
        {
            mtx[x][n]=mtx[x][n]*temp1-mtx[i][n]*temp2;
        }
    }

    big=minimum_times(mtx[i][j],mtx[y][j]);
    if(big!=0)
    {
        int temp1=big/mtx[y][j];
        int temp2=big/mtx[i][j];
        for (int n=0;n<4;n++)
        {
            mtx[y][n]=mtx[y][n]*temp1-mtx[i][n]*temp2;
        }
    }
}

int main()
{
    ifstream fin("ratios.in");
    ofstream fout("ratios.out");

    int origin[3][4];

    fin>>mtx[0][3]>>mtx[1][3]>>mtx[2][3];
    for (int i=0;i<3;i++)
        for (int j=0;j<3;j++)
            fin>>mtx[j][i];

    for (int i=0;i<3;i++)
        for (int j=0;j<4;j++)
            origin[i][j]=mtx[i][j];

    int a,b,c;

    int number[100];
    for (int i=0;i<100;i++)number[i]=i+2;

    for (int i=0;i<3;i++)
    {
        if (mtx[i][0]!=0)
        {
            a=i;
            standize(i,0);
        }
    }

    if(mtx[(a+1)%3][1]!=0)
    {
        b=(a+1)%3;
        c=(a+2)%3;
    }
    else
    {
        b=(a+2)%3;
        c=(a+1)%3;
    }

    standize(b,1);
    standize(c,2);

    for(int i=0;i<100;i++)
    while(mtx[a][0]%number[i]==0&&mtx[a][3]%number[i]==0)
    {
        mtx[a][0]/=number[i];
        mtx[a][3]/=number[i];
        if(mtx[a][0]==0&&mtx[a][3]==0)break;
    }

    for(int i=0;i<100;i++)
    while(mtx[c][2]%number[i]==0&&mtx[c][3]%number[i]==0)
    {
        mtx[c][2]/=number[i];
        mtx[c][3]/=number[i];
        if(mtx[c][2]==0&&mtx[c][3]==0)break;
    }

    for(int i=0;i<100;i++)
    while(mtx[b][1]%number[i]==0&&mtx[b][3]%number[i]==0)
    {
        mtx[b][1]/=number[i];
        mtx[b][3]/=number[i];
        if(mtx[b][1]==0&&mtx[b][3]==0)break;
    }

    cout<<endl;
    for (int i=0;i<3;i++)
    {
        for (int j=0;j<4;j++)
        cout<<mtx[i][j]<<"\t";
        cout<<endl;
    }


    if (mtx[a][0]<0)
    {
        for (int j=0;j<4;j++)
        {
            mtx[a][j]*=-1;
        }
    }

    if (mtx[b][1]<0)
    {
        for (int j=0;j<4;j++)
        {
            mtx[b][j]*=-1;
        }
    }

    if (mtx[c][2]<0)
    {
        for (int j=0;j<4;j++)
        {
            mtx[c][j]*=-1;
        }
    }


//    cout<<endl;
//    for (int i=0;i<3;i++)
//    {
//        for (int j=0;j<4;j++)
//        cout<<mtx[i][j]<<"\t";
//        cout<<endl;
//    }

    bool flag=true;
    for (int i=0;i<3;i++)
        if(mtx[i][3]<0)flag=false;
    if(mtx[a][0]==0||mtx[b][1]==0||mtx[c][2]==0)flag=false;

    int large=1;
    int x=0;
    int y=0;
    int z=0;
    if(flag)
    {
        large*=mtx[a][0]*mtx[b][1]*mtx[c][2];
        x=mtx[a][3]*large/mtx[a][0];
        y=mtx[b][3]*large/mtx[b][1];
        z=mtx[c][3]*large/mtx[c][2];
    }



    int t=(origin[0][0]*x+origin[0][1]*y+origin[0][2]*z);
    x*=origin[0][3];
    y*=origin[0][3];
    z*=origin[0][3];


    for (int i=0;i<100&&flag;i++)
    {
        while(x%number[i]==0&&y%number[i]==0&&z%number[i]==0&&t%number[i]==0)
        {
            x/=number[i];
            y/=number[i];
            z/=number[i];
            t/=number[i];
        }
    }


    cout<<x<<" "<<y<<" "<<z<<" "<<t<<" \n";

    if (flag)
        fout<<x<<" "<<y<<" "<<z<<" "<<t<<"\n";
    else
    {
        fout<<"NONE\n";
        cout<<"NONE\n";
    }



}
