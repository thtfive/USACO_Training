/*
ID:thtfive
LANG:C++
TASK:camelot
*/
#include<iostream>
#include<fstream>
#include<queue>
using namespace std;

void knightmove(int choose,int x,int y,int &ansx,int &ansy)
{
    ansx=x;
    ansy=y;
    switch(choose)
    {
        case 1:ansx-=2;ansy+=1;break;
        case 2:ansx-=1;ansy+=2;break;
        case 3:ansx+=1;ansy+=2;break;
        case 4:ansx+=2;ansy+=1;break;
        case 5:ansx+=2;ansy-=1;break;
        case 6:ansx+=1;ansy-=2;break;
        case 7:ansx-=1;ansy-=2;break;
        case 8:ansx-=2;ansy-=1;break;
    }
}

void kingmove(int choose,int x,int y,int &ansx,int &ansy)
{
    ansx=x;
    ansy=y;
    switch(choose)
    {
        case 1:ansx--;break;
        case 2:ansx--;ansy++;break;
        case 3:ansy++;break;
        case 4:ansx++;ansy++;break;
        case 5:ansx++;break;
        case 6:ansx++;ansy--;break;
        case 7:ansy--;break;
        case 8:ansx--;ansy--;break;
    }
}

bool withinboard(int x,int y,int R,int C)
{
    if(x>0&&x<=R&&y>0&&y<=C)return true;
    return false;
}


int main()
{
    int R,C;
    ifstream fin("camelot.in");
    ofstream fout("camelot.out");
    fin>>C>>R;

    char rowtmp;
    int columntmp;
    int kingplace[2];
    fin>>rowtmp>>columntmp;
    kingplace[0]=rowtmp-'A'+1;
    kingplace[1]=columntmp;
    int knightplaces[26*30+1][2];
    int knightNum=0;
    while(fin>>rowtmp)
    {
        knightNum++;
        fin>>columntmp;
        knightplaces[knightNum][0]=rowtmp-'A'+1;
        knightplaces[knightNum][1]=columntmp;
    }
    int Distance[knightNum+1][R+1][C+1][2];

    for (int i=0;i<=knightNum;i++)
        for(int j=0;j<=R;j++)
            for(int k=0;k<=C;k++)
            {
                Distance[i][j][k][0]=1000000;
                Distance[i][j][k][1]=1000000;
            }

    ///caculate the distance of king to everyplace
    bool flag[R+1][C+1];
    for (int i=0;i<=R;i++)
        for (int j=0;j<=C;j++)
            flag[i][j]=false;
    queue<int>que;
    que.push(kingplace[0]);
    que.push(kingplace[1]);
    Distance[0][kingplace[0]][kingplace[1]][0]=0;
    flag[kingplace[0]][kingplace[1]]=true;
    while(!que.empty())
    {
        int x=que.front();
        que.pop();
        int y=que.front();
        que.pop();
        for(int step=1;step<=8;step++)
        {
            int ansx,ansy;
            kingmove(step,x,y,ansx,ansy);
            if (withinboard(ansx,ansy,R,C)&&!flag[ansx][ansy])
            {
                Distance[0][ansx][ansy][0]=Distance[0][x][y][0]+1;
                flag[ansx][ansy]=true;
                que.push(ansx);
                que.push(ansy);
            }
        }
    }
    ///end

    ///caculate the distance of knights to everyplace
    for (int knight=1;knight<=knightNum;knight++)
    {
        for (int i=0;i<=R;i++)
            for (int j=0;j<=C;j++)
                flag[i][j]=false;
        int x=knightplaces[knight][0];
        int y=knightplaces[knight][1];
        que.push(x);
        que.push(y);
        Distance[knight][x][y][0]=0;
        ///the minimum distance for king to move to the path
        Distance[knight][x][y][1]=Distance[0][x][y][0];

        flag[knightplaces[knight][0]][knightplaces[knight][1]]=true;
        while(!que.empty())
        {
            x=que.front();
            que.pop();
            y=que.front();
            que.pop();
            for(int step=1;step<=8;step++)
            {
                int ansx,ansy;
                knightmove(step,x,y,ansx,ansy);
                if (withinboard(ansx,ansy,R,C)&&!flag[ansx][ansy])
                {
                    Distance[knight][ansx][ansy][0]=Distance[knight][x][y][0]+1;

                    int kingmin=Distance[0][ansx][ansy][0];
                    for(int direct=1;direct<=8;direct++)
                    {
                        int newx,newy;
                        knightmove(direct,ansx,ansy,newx,newy);
                        if(withinboard(newx,newy,R,C)&&flag[newx][newy]&&Distance[knight][newx][newy][0]+1==Distance[knight][ansx][ansy][0])
                        {
                            kingmin=kingmin<Distance[knight][newx][newy][1]?kingmin:Distance[knight][newx][newy][1];
                        }
                    }
                    Distance[knight][ansx][ansy][1]=kingmin;

                    flag[ansx][ansy]=true;
                    que.push(ansx);
                    que.push(ansy);
                }
            }
        }
    }
///end of kinghts' distance caculation
    int result=999999999;
    for (int i=1;i<=R;i++)
        for (int j=1;j<=C;j++)
        {
            int kingmovement=999999999;
            int movement=0;
            for(int k=1;k<=knightNum;k++)
            {
                movement+=Distance[k][i][j][0];
                ///caulate the king's least movement to place(i,j)
                kingmovement=Distance[k][i][j][1]<kingmovement?Distance[k][i][j][1]:kingmovement;
            }
            movement+=kingmovement;
            result=result<movement?result:movement;
        }
    if (knightNum==0)result=0;
    cout<<result<<"\n";
    fout<<result<<"\n";

    return 0;
}
