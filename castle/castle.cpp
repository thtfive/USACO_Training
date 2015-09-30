/*
ID:thtfive
LANG:C++
TASK:castle
*/

///解决该问题，先用flood fill的算法把所有相邻的位置标示出来，用map来进行标示
///然后对map中的每一个点进行遍历，寻找两个房间合并最大可能的面积
#include<iostream>
#include<fstream>
#include<queue>
using namespace std;
bool wall_less(int num,int i)///judge if there is a wall,i==1 means the wall to west,2 means n,4 means w,8 means s
{
    num/=i;
    if(num%2==0)return true;
    return false;
}

class point///self-defined class,used for stored the place of map in queue
{
    public:
    int x;
    int y;
};

bool inside_range(int M,int N,int i,int j)///for checking if i & j is outside the range
{
    if (i<M&&i>=0&&j<N&&j>=0)return true;
    else return false;
}

int main()
{
    ifstream fin("castle.in");
    ofstream fout("castle.out");
    queue <point>que;

    int M,N;
    int counter=0;
    fin>>N>>M;
    int map[M][N];
    int wall[M][N];
    int mark[M][N];
    for (int i=0;i<M;i++)
        for (int j=0;j<N;j++)
            {
                fin>>wall[i][j];
                map[i][j]=-1;///
                mark[i][j]=-1;///mark is used for mark those points have been added into the queue
            }



    int countt[M*N+1];
    for (int i=0;i<=M*N;i++)countt[i]=0;


    for (int i=0;i<M;i++)
        for (int j=0;j<N;j++)///used flood fill method to color map
        {
            if (map[i][j]==-1){

                counter++;
                point tmp;
                tmp.x=i;
                tmp.y=j;
                que.push(tmp);
                int i_tmp=i,j_tmp=j;
                while(que.empty()==false)
                {
                    i_tmp=que.front().x;
                    j_tmp=que.front().y;
                    map[i_tmp][j_tmp]=counter;
                    countt[counter]++;
                    que.pop();
                    if(wall_less(wall[i_tmp][j_tmp],1)&&map[i_tmp][j_tmp-1]==-1){if(mark[i_tmp][j_tmp-1]==-1){mark[i_tmp][j_tmp-1]=1;tmp.x=i_tmp;tmp.y=j_tmp-1;que.push(tmp);}}
                    if(wall_less(wall[i_tmp][j_tmp],2)&&map[i_tmp-1][j_tmp]==-1){if(mark[i_tmp-1][j_tmp]==-1){mark[i_tmp-1][j_tmp]=1;tmp.x=i_tmp-1;tmp.y=j_tmp;que.push(tmp);}}
                    if(wall_less(wall[i_tmp][j_tmp],4)&&map[i_tmp][j_tmp+1]==-1){if(mark[i_tmp][j_tmp+1]==-1){mark[i_tmp][j_tmp+1]=1;tmp.x=i_tmp;tmp.y=j_tmp+1;que.push(tmp);}}
                    if(wall_less(wall[i_tmp][j_tmp],8)&&map[i_tmp+1][j_tmp]==-1){if(mark[i_tmp+1][j_tmp]==-1){mark[i_tmp+1][j_tmp]=1;tmp.x=i_tmp+1;tmp.y=j_tmp;que.push(tmp);}}

                }
            }
        }

    int maxtworoom=0;
    int place_i,place_j;
    char dirction;

    for (int j=0;j<N;j++)///to calculate the max two rooms,and record the place of the wall in place_i & place_j
        for (int i=M-1;i>=0;i--)
            {
                if(inside_range(M,N,i-1,j))
                {
                    if(map[i][j]!=map[i-1][j])
                    {
                        if(maxtworoom<(countt[map[i][j]]+countt[map[i-1][j]]))
                        {
                            maxtworoom=countt[map[i][j]]+countt[map[i-1][j]];
                            place_i=i;place_j=j;
                            dirction='N';
                        }
                    }
                }
                if(inside_range(M,N,i,j+1))
                {
                    if(map[i][j]!=map[i][j+1])
                    {
                        if(maxtworoom<(countt[map[i][j]]+countt[map[i][j+1]]))
                        {
                            maxtworoom=countt[map[i][j]]+countt[map[i][j+1]];
                            place_i=i;place_j=j;
                            dirction='E';
                        }
                    }
                }
            }

    /*cout<<maxtworoom<<"\n";


    for (int i=0;i<M;i++)
    {
        for (int j=0;j<N;j++)
            cout<<map[i][j]<<" ";
        cout<<endl;
    }*/

    int maxroom=0;
    for (int i=1;i<=counter;i++)maxroom=maxroom>countt[i] ? maxroom :countt[i];

    fout<<counter<<"\n";
    fout<<maxroom<<"\n";
    fout<<maxtworoom<<"\n";
    fout<<place_i+1<<" "<<place_j+1<<" "<<dirction<<"\n";
    return 0;
}
