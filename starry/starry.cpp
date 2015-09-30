/*
ID:thtfive
LANG:C++
TASK:starry
*/
#include<iostream>
#include<fstream>
#include<string.h>
#include<queue>

using namespace std;

int H,W;
int maxsize;
int flag[100][100];
int totalnum;
int cluster;
bool allclusters[208][100][100];
bool cut[100][100];
string stars[100];
int starnum[208];
char starmark[208];


void topleft();
void mark(int i,int j,char ch);

bool inRange(int i,int j)
{
    if(0<=i&&i<H&&j>=0&&j<W)
        return true;
    return false;
}

void spin()
{
    bool cuttmp[maxsize][maxsize];
    memset(cuttmp,false,sizeof(cuttmp));
    for(int x=0;x<maxsize;x++)
    {
        for(int y=0;y<maxsize;y++)
        {
            cuttmp[x][y]=cut[maxsize-1-y][x];
        }
    }
    for(int x=0;x<maxsize;x++)
    {
        for(int y=0;y<maxsize;y++)
        {
            cut[x][y]=cuttmp[x][y];
        }
    }
    topleft();
}

void reverse()
{
    bool cuttmp[maxsize][maxsize];
    memset(cuttmp,false,sizeof(cuttmp));
    for(int x=0;x<maxsize;x++)
    {
        for(int y=0;y<maxsize;y++)
        {
            cuttmp[x][y]=cut[x][maxsize-1-y];
        }
    }
    for(int x=0;x<maxsize;x++)
    {
        for(int y=0;y<maxsize;y++)
        {
            cut[x][y]=cuttmp[x][y];
        }
    }
    topleft();
}



void addcluster(int num,char ch)
{
    for(int i=0;i<H;i++)
    {
        for(int j=0;j<W;j++)
        {
            allclusters[totalnum][i][j]=cut[i][j];
        }
    }
    starnum[totalnum]=num;
    starmark[totalnum]=ch;
    totalnum++;
}

void updatecluster(int num,char ch)
{
    addcluster(num,ch);
    reverse();
    addcluster(num,ch);
    reverse();

    spin();
    addcluster(num,ch);
    reverse();
    addcluster(num,ch);
    reverse();

    spin();
    addcluster(num,ch);
    reverse();
    addcluster(num,ch);
    reverse();


    spin();
    addcluster(num,ch);
    reverse();
    addcluster(num,ch);
}

void BFS(int i,int j)
{
    queue <int>que;
    que.push(i);
    que.push(j);
    flag[i][j]=1;
    memset(cut,false,sizeof(cut));
    int counter=0;
    while(!que.empty())
    {
        int x=que.front();
        que.pop();
        int y=que.front();
        que.pop();
        cut[x][y]=true;

        counter++;
        for(int m=x-1;m<=x+1;m++)
        {
            for(int n=y-1;n<=y+1;n++)
            {
                if(inRange(m,n)&&stars[m][n]=='1'&&flag[m][n]==0)
                {
                    flag[m][n]=1;
                    que.push(m);
                    que.push(n);
                }
            }
        }
    }
    topleft();

    bool sign=false;
    char ch;
    for(int t=0;t<totalnum;t++)
    {
        if(starnum[t]==counter)
        {
            bool tmp=true;
            for(int a=0;a<H&&tmp;a++)
            {
                for(int b=0;b<W&&tmp;b++)
                {
                    if(allclusters[t][a][b]!=cut[a][b])
                    {
                        tmp=false;
                    }
                }
            }
            sign=tmp;
            if(sign==true)
            {
                ch=starmark[t];
                break;
            }
        }
    }


    if(sign==false)
    {
        ch='a'+cluster;
        cluster++;
        updatecluster(counter,ch);
    }
    mark(i,j,ch);
}

int main()
{
    ifstream fin("starry.in");
    ofstream fout("starry.out");
    totalnum=0;
    memset(starnum,0,sizeof(starnum));
    fin>>W>>H;
    maxsize=H>W?H:W;
    for(int i=0;i<H;i++)
        fin>>stars[i];

    memset(flag,0,sizeof(flag));
    cluster=0;

    for(int i=0;i<H;i++)
    {
        for(int j=0;j<W;j++)
        {
            if(stars[i][j]=='1'&&flag[i][j]==0)
            {
                BFS(i,j);
            }
        }
    }

    for(int i=0;i<H;i++)
        fout<<stars[i]<<"\n";

    return 0;
}

void topleft()
{
    int top=101,bottom=0,left=101,right=0;

    bool cuttmp[H][W];
    memset(cuttmp,false,sizeof(cuttmp));
    for(int x=0;x<H;x++)
    {
        for(int y=0;y<W;y++)
        {
            cuttmp[x][y]=cut[x][y];
            if(cut[x][y])
            {
                top=top<x?top:x;
                bottom=bottom>x?bottom:x;
                left=left<y?left:y;
                right=right>y?right:y;
            }
        }
    }
    memset(cut,false,sizeof(cut));
    for(int m=top;m<=bottom;m++)
    {
        for(int n=left;n<=right;n++)
        {
            cut[m-top][n-left]=cuttmp[m][n];
        }
    }
}
void mark(int i,int j,char ch)
{
    queue <int>que;
    que.push(i);
    que.push(j);
    flag[i][j]=2;

    while(!que.empty())
    {
        int x=que.front();
        que.pop();
        int y=que.front();
        que.pop();
        stars[x][y]=ch;

        for(int m=x-1;m<=x+1;m++)
        {
            for(int n=y-1;n<=y+1;n++)
            {
                if(inRange(m,n)&&stars[m][n]=='1'&&flag[m][n]!=2)
                {
                    flag[m][n]=2;
                    que.push(m);
                    que.push(n);
                }
            }
        }
    }
}
