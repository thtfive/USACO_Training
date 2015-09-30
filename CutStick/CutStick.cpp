#include<iostream>
#include<fstream>
#define maxn 53
#define inf 1000000000
using namespace std;
int place[maxn];
int d[maxn][maxn];
int main()
{
    freopen("input.txt","r",stdin);
    int L;
    cin>>L;
    while(L)
    {
        int N;
        cin>>N;
        place[0]=0;
        place[N+1]=L;
        for(int i=1;i<=N;i++)
        {
            cin>>place[i];
        }
        for(int i=0;i<=N;i++)
            d[i][i+1]=0;
        for(int len=2;len<=N+1;len++)
        {
            for(int start=0;start+len<=N+1;start++)
            {
                int finish=start+len;
                d[start][finish]=inf;
                for(int mid=start+1;mid<finish;mid++)
                {
                    d[start][finish]=min(d[start][finish],d[start][mid]+d[mid][finish]+place[finish]-place[start]);
                }
            }
        }
        cout<<"The minimum cutting is "<<d[0][N+1]<<"."<<endl;
        cin>>L;
    }
    return 0;
}
