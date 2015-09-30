/*
ID:thtfive
LANG:C++
TASK:lamps
*/
#include<fstream>
#include<iostream>
using namespace std;

void inside(int N,int start,int *state,int (*status)[4],int &statusnum)
{
    if (N==0)
    {
        for (int i=0;i<4;i++)status[statusnum][i]=state[i];
        statusnum++;
    }
    else
    {
        for (int i=start;i<4;i++)
        {
            state[i]=1;
            inside(N-1,i+1,state,status,statusnum);
            state[i]=0;
        }
    }
}

void statusdecide(int C,int (*status)[4],int &statusnum)
{
    int state[4];
    for (int i=0;i<4;i++)state[i]=0;
    for (int i=C;i>=0;i=i-2)
    {
        inside(i,0,state,status,statusnum);
    }
}

void compare(int N,int (*status)[4],int (*lamps)[16],int &statusnum,bool *on,bool *off,int *mark)
{
    for (int i=0;i<statusnum;i++)///for every status
        for (int j=0;j<4;j++)///for every button
        {
            if (status[i][j]==1)
            {
                int start;
                int step;
                switch (j)///choose the way
                {
                    case 0:start=0;step=1;break;
                    case 1:start=0;step=2;break;
                    case 2:start=1;step=2;break;
                    case 3:start=0;step=3;break;
                }
                for (int k=start;k<N;k+=step)///for every lamp
                {
                    lamps[k][i]++;///lamps: the i-th status, the k-th lamp
                    lamps[k][i]%=2;
                }
            }
        }
    for (int i=0;i<statusnum;i++)
        for (int k=0;k<N;k++)
        {
            if (on[k]&&lamps[k][i]!=1)mark[i]=0;
            if (off[k]&&lamps[k][i]!=0)mark[i]=0;
        }

}

void order(int N,int counter,int (*lamps)[16],int *mark,int &statusnum)
{
    int value[statusnum];
    for (int i=0;i<statusnum;i++)value[i]=0;

    for (int i=0;i<statusnum;i++)
    {
        for (int j=0;j<10;j++)value[i]=value[i]*2+lamps[j][i];
    }

    for (int i=0;i<statusnum;i++)
        for (int j=1;j<statusnum;j++)
        {
            int tmp;
            int mark_tmp;
            int lamps_tmp[N];
            if(value[j-1]>value[j])
            {
                tmp=value[j-1];
                value[j-1]=value[j];
                value[j]=tmp;

                mark_tmp=mark[j-1];
                mark[j-1]=mark[j];
                mark[j]=mark_tmp;

                for (int k=0;k<N;k++)
                lamps_tmp[k]=lamps[k][j-1];
                for (int k=0;k<N;k++)
                lamps[k][j-1]=lamps[k][j];
                for (int k=0;k<N;k++)
                lamps[k][j]=lamps_tmp[k];
            }
            if(value[j-1]==value[j])
            {
                mark[j]=0;
            }
        }
}

void putout(int N,int counter,int (*lamps)[16],int *mark,int &statusnum,ofstream &fout)
{
    if (counter==0)fout<<"IMPOSSIBLE\n";
    else
    {
        order(N,counter,lamps,mark,statusnum);
        for (int i=0;i<statusnum;i++)
        {
            if(mark[i]==1)
            {
                for (int j=0;j<N;j++)fout<<lamps[j][i];
                fout<<"\n";
            }
        }
    }
}

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int N,C;
    fin>>N>>C;
    bool on[N],off[N];
    int status[16][4];
    for (int i=0;i<16;i++)
        for (int j=0;j<4;j++)status[i][j]=0;

    int statusnum=0;
    int counter=0;
    for (int i=0;i<N;i++){on[i]=false;off[i]=false;}
    int temp;
    fin>>temp;
    while(temp!=-1){on[temp-1]=true;fin>>temp;}
    fin>>temp;
    while(temp!=-1){off[temp-1]=true;fin>>temp;}

    if (C>4)
    {
        if (C%2==1)C=3;
        else C=4;
    }

    statusdecide(C,status,statusnum);

    int lamps[N][16];
    for (int i=0;i<statusnum;i++)
        for (int j=0;j<N;j++)lamps[j][i]=1;



    int mark[statusnum];///for marking the valid status
    for (int i=0;i<statusnum;i++)mark[i]=1;


    compare(N,status,lamps,statusnum,on,off,mark);

    for (int i=0;i<statusnum;i++)if(mark[i]==1)counter++;

    putout(N,counter,lamps,mark,statusnum,fout);

    return 0;
}
