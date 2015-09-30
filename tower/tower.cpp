#include<iostream>
#include<fstream>
#include<queue>
#include<cmath>
using namespace std;
int partition(int (*tower)[3],int start,int finish)
{
    int idx=start-1;
    for(int i=start;i<finish;i++)
    {
        if (tower[i][0]<tower[finish][0])
        {
            idx++;
            int tmp=tower[i][0];
            tower[i][0]=tower[idx][0];
            tower[idx][0]=tmp;

            tmp=tower[i][1];
            tower[i][1]=tower[idx][1];
            tower[idx][1]=tmp;

            tmp=tower[i][2];
            tower[i][2]=tower[idx][2];
            tower[idx][2]=tmp;
        }
    }
    idx++;
    int tmp=tower[idx][0];
    tower[idx][0]=tower[finish][0];
    tower[finish][0]=tmp;

    tmp=tower[idx][1];
    tower[idx][1]=tower[finish][1];
    tower[finish][1]=tmp;

    tmp=tower[idx][2];
    tower[idx][2]=tower[finish][2];
    tower[finish][2]=tmp;
    return idx;

}

void sort(int (*tower)[3],int start,int finish)
{
    if (start>=finish)return;
    int mid=partition(tower,start,finish);
    sort(tower,start,mid-1);
    sort(tower,mid+1,finish);
}

int Adj[1001][1001];
ifstream fin("fin.in");

int main()
{
    int Test;
//    ifstream fin("input.txt");
    fin>>Test;
    for (int T=1;T<=Test;T++)
    {
        int N;
        fin>>N;
        for(int i=0;i<=N;i++)
        {
            for(int j=0;j<=N;j++)
                Adj[i][j]=0;
        }

        int tower[N+1][3];
        for(int i=1;i<=N;i++)
        {
            fin>>tower[i][0]>>tower[i][1]>>tower[i][2];
            for(int j=1;j<i;j++)
            {
                if((tower[i][1]+tower[j][1])>abs(tower[i][0]-tower[j][0]))
                {
                    Adj[i][++Adj[i][0]]=j;
                    Adj[j][++Adj[j][0]]=i;
                }
            }
        }


        int record[N][N];
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                record[i][j]=0;
        sort(tower,0,N-1);

        for(int i=0;i<N;i++)
            record[i][i]=tower[i][2]-tower[i][1]*tower[i][1];

        cout<<"Case #"<<T<<":"<<"\n";


    }
    return 0;
}
