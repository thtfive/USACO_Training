/*
ID:thtfive
LANG:C++
TASK:snail
*/
#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;
int Map[122][122];
int N;
int B;

bool operation(int &x,int &y,int direction,int &result)
{
    bool flag=false;
    int xtmp=x,ytmp=y;
    switch(direction)
    {
        case 0:
            for(x=x-1;x>=0;x--)
            {
                if(Map[x][y]==1)
                {
                    result++;
                    Map[x][y]=2;
                }
                else
                {
                    if(Map[x][y]==2)
                    {
                        x++;
                        flag=false;
                        break;
                    }
                    if(Map[x][y]==0)
                    {
                        x++;
                        flag=true;
                        break;
                    }
                }
            }
            break;
        case 1:
            for(y=y+1;y<=N+1;y++)
            {
                if(Map[x][y]==1)
                {
                    result++;
                    Map[x][y]=2;
                }
                else
                {
                    if(Map[x][y]==2)
                    {
                        y--;
                        flag=false;
                        break;
                    }
                    if(Map[x][y]==0)
                    {
                        y--;
                        flag=true;
                        break;
                    }
                }
            }
            break;
        case 2:
            for(x=x+1;x<=N+1;x++)
            {
                if(Map[x][y]==1)
                {
                    result++;
                    Map[x][y]=2;
                }
                else
                {
                    if(Map[x][y]==2)
                    {
                        x--;
                        flag=false;
                        break;
                    }
                    if(Map[x][y]==0)
                    {
                        x--;
                        flag=true;
                        break;
                    }
                }
            }
            break;
        case 3:
            for(y=y-1;y>=0;y--)
            {
                if(Map[x][y]==1)
                {
                    result++;
                    Map[x][y]=2;
                }
                else
                {
                    if(Map[x][y]==2)
                    {
                        y++;
                        flag=false;
                        break;
                    }
                    if(Map[x][y]==0)
                    {
                        y++;
                        flag=true;
                        break;
                    }
                }
            }
            break;
    }
    if(x==xtmp&&y==ytmp)flag=false;
    return flag;
}

void reoperation(int x,int y,int xtmp,int ytmp,int direction)
{
    switch(direction)
    {
        case 0:
            for(x=x-1;x>=xtmp;x--)
            {
                Map[x][y]=1;
            }
            break;
        case 1:
            for(y=y+1;y<=ytmp;y++)
            {
               Map[x][y]=1;
            }
            break;
        case 2:
            for(x=x+1;x<=xtmp;x++)
            {
               Map[x][y]=1;
            }
            break;
        case 3:
            for(y=y-1;y>=ytmp;y--)
            {
               Map[x][y]=1;
            }
            break;
    }

}

int travel(int x,int y,int direction,int result)
{
    int xtmp,ytmp;
    xtmp=x;
    ytmp=y;
    if(operation(xtmp,ytmp,direction,result))
    {
        int tmp1=travel(xtmp,ytmp,(direction+1)%4,result);
        int tmp2=travel(xtmp,ytmp,(direction+3)%4,result);
        if(tmp1>tmp2)result=tmp1;
        else result=tmp2;
    }
    reoperation(x,y,xtmp,ytmp,direction);
    return result;
}

int solution()
{
    int result=0;
    int tmp;
    Map[1][1]=2;
    tmp=travel(1,1,1,1);
    result=result>tmp?result:tmp;
    tmp=travel(1,1,2,1);
    Map[1][1]=1;
    result=result>tmp?result:tmp;
    return result;
}

int main()
{
    ifstream fin("snail.in");
    ofstream fout("snail.out");
    fin>>N>>B;

    memset(Map,0,sizeof(Map));
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            Map[i][j]=1;
        }
    }
    for(int i=0;i<B;i++)
    {
        string tmp;
        fin>>tmp;
        int len=tmp.length();
        int y=tmp[0]-'A'+1;
        int x=0;
        for(int k=1;k<len;k++)
            x=x*10+tmp[k]-'0';
        Map[x][y]=0;
    }

    int result=solution();
    cout<<result<<"\n";
    fout<<result<<"\n";

    return 0;
}
