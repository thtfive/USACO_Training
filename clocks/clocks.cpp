/*
ID:thtfive
LANG:C++
TASK:clocks
*/
#include<iostream>
#include<fstream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
///一共可能的状态有4的9次方个，大约为27万
///从初始状态出发进行搜索，要利用到队列
///搜索到的第一个满足条件的就是最短路径
///该方法类似于广度优先搜索
///
ifstream fin("clocks.in");
ofstream fout("clocks.out");
int init_state[9];
bool vis[270000];
string steps[270000];


void input()
{
    for(int i=0;i<9;i++)
    {
        fin>>init_state[i];
        init_state[i]/=3;
        init_state[i]%=4;
    }
    memset(vis,false,sizeof(vis));
}

int stateconvert(int state,int method)
{
    int states[9];
    for(int i=8;i>=0;i--)
    {
        states[i]=state&3;
        state/=4;
    }
    switch(method)
    {
        case 1: states[0]++;states[1]++;states[3]++;states[4]++;break;
        case 2: states[0]++;states[1]++;states[2]++;break;
        case 3: states[1]++;states[2]++;states[4]++;states[5]++;break;
        case 4: states[0]++;states[3]++;states[6]++;break;
        case 5: states[1]++;states[3]++;states[4]++;states[5]++;states[7]++;break;
        case 6: states[2]++;states[5]++;states[8]++;break;
        case 7: states[3]++;states[4]++;states[6]++;states[7]++;break;
        case 8: states[6]++;states[7]++;states[8]++;break;
        case 9: states[4]++;states[5]++;states[7]++;states[8]++;break;
    }

    int ans=0;
    for(int i=0;i<9;i++)
    {
        ans*=4;
        states[i]%=4;
        ans+=states[i];
    }
    return ans;
}
void solve()
{
    int number=0;
    for(int i=0;i<9;i++)
    {
        number*=4;
        number+=init_state[i];
    }
    queue<int>que;
    que.push(number);
    vis[number]=true;
    while(!que.empty())
    {
        int state=que.front();
        que.pop();
        for(int i=1;i<=9;i++)
        {
            int num=stateconvert(state,i);
            if(!vis[num])
            {
                vis[num]=true;
                que.push(num);
                char str='0'+i;
                steps[num]=steps[state]+str;
            }
        }
        if(vis[0])break;
    }
}

void output()
{
    int length=steps[0].length();
    if(length!=0)
    {
        for(int i=0;i<length-1;i++)
            cout<<steps[0][i]<<" ";
        cout<<steps[0][length-1]<<"\n";
        for(int i=0;i<length-1;i++)
            fout<<steps[0][i]<<" ";
        fout<<steps[0][length-1]<<"\n";
    }
    else
    {
        fout<<"\n";
    }
}
int main()
{
    input();
    solve();
    output();
    return 0;
}
