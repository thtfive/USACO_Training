/*
ID:thtfive
LANG:C++
TASK:ttwo
*/
#include<iostream>
#include<fstream>
using namespace std;
bool flag[144][144];
char Map[12][12];

void next_position(int &C_x,int &C_y,int &F_x,int &F_y,int &dirct1,int &dirct2,int &mark)
{
    if(flag[C_x*12+C_y][F_x*12+F_y])mark++;
    else mark=0;

    flag[C_x*12+C_y][F_x*12+F_y]=true;

    switch (dirct1)
    {
        case 0: if(Map[C_x-1][C_y]!='*')
                   C_x--;
                else
                    dirct1=(dirct1+1)%4;
                break;
        case 1: if(Map[C_x][C_y+1]!='*')
                   C_y++;
                else
                    dirct1=(dirct1+1)%4;
                break;
        case 2: if(Map[C_x+1][C_y]!='*')
                   C_x++;
                else
                    dirct1=(dirct1+1)%4;
                break;
        case 3: if(Map[C_x][C_y-1]!='*')
                   C_y--;
                else
                    dirct1=(dirct1+1)%4;
                break;
    }
    switch (dirct2)
    {
        case 0: if(Map[F_x-1][F_y]!='*')
                   F_x--;
                else
                    dirct2=(dirct2+1)%4;
                break;
        case 1: if(Map[F_x][F_y+1]!='*')
                   F_y++;
                else
                    dirct2=(dirct2+1)%4;
                break;
        case 2: if(Map[F_x+1][F_y]!='*')
                   F_x++;
                else
                    dirct2=(dirct2+1)%4;
                break;
        case 3: if(Map[F_x][F_y-1]!='*')
                    F_y--;
                else
                    dirct2=(dirct2+1)%4;

                break;
    }
}

int main()
{
//    ifstream fin("input.txt");
//    ofstream fout("output.txt");
    ifstream fin("ttwo.in");
    ofstream fout("ttwo.out");

    char tmp;

    int C_x,C_y,F_x,F_y;
    for (int i=1;i<11;i++)
        for (int j=1;j<11;j++)
        {
            fin>>tmp;
            if (tmp=='*')Map[i][j]=tmp;
            else
            {
                Map[i][j]='.';
                if (tmp!='.')
                {
                    if (tmp=='C')
                    {
                        C_x=i;
                        C_y=j;
                    }
                    else
                    {
                        F_x=i;
                        F_y=j;
                    }
                }
            }
        }

    for (int i=0;i<12;i++)
    {
        Map[0][i]='*';
        Map[11][i]='*';
        Map[i][0]='*';
        Map[i][11]='*';
    }


    for (int i=0;i<144;i++)
        for (int j=0;j<144;j++)
            flag[i][j]=false;

    int dirct1=0,dirct2=0;

    int mark=0;
    int counter=0;
    while(1)
    {
        if (flag[C_x*12+C_y][F_x*12+F_y]&&mark==6)
        {
            counter=0;
            break;
        }
        else
        {
            next_position(C_x,C_y,F_x,F_y,dirct1,dirct2,mark);
            counter++;
        }
        if (C_x==F_x&&C_y==F_y)break;
    }

    fout<<counter<<"\n";
    cout<<counter<<"\n";

    return 0;
}
