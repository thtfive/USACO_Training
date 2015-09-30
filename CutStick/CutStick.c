#include<stdio.h>
#define maxn 53
#define inf 1000000000
int place[maxn];
int d[maxn][maxn];
int main()
{
    //freopen("input.txt","r",stdin);
    int L;
    scanf("%d",&L);
    while(L)
    {
        int N;
        scanf("%d",&N);
        place[0]=0;
        place[N+1]=L;
        int i;
        for(i=1;i<=N;i++)
        {
            scanf("%d",&place[i]);
        }
        for(i=0;i<=N;i++)
            d[i][i+1]=0;
        int len;
        int start;
        int mid;
        int finish;
        for(len=2;len<=N+1;len++)
        {
            for(start=0;start+len<=N+1;start++)
            {
                finish=start+len;
                d[start][finish]=inf;
                for(mid=start+1;mid<finish;mid++)
                {
                    int tmp=d[start][mid]+d[mid][finish]+place[finish]-place[start];
                    if(tmp<d[start][finish])
                        d[start][finish]=tmp;
                }
            }
        }
        printf("The minimum cutting is %d.\n",d[0][N+1]);
        scanf("%d",&L);;
    }
    return 0;
}
