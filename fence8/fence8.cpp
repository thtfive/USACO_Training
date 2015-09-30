/*
ID:thtfive
TASK:fence8
LANG:C++
*/
#include<iostream>
#include<fstream>
#include<cstring>
#include<algorithm>
using namespace std;
///���ȶԳ��Ƚ�������
///��checker��������Ƿ�������������ĳ��ȵ�ľ��
///����������ɣ�������һ����ʹ�ö��ֵ�ģʽ��������
///ÿ�μ��ʱ��������rest����Ƿ���У����򲻽�����������������֦��
///rest��ʾʣ�µ�ľ���л����Խ����и���ܳ���
ifstream fin("fence8.in");
ofstream fout("fence8.out");
int Boards[51];
int allBoardsLength;
int smallBoards[1024];
int smallBsum[1024];
int N,M;
int result;

void input()
{
    result=0;
    allBoardsLength=0;
    fin>>N;
    for(int i=1;i<=N;i++)
    {
        fin>>Boards[i];
        allBoardsLength+=Boards[i];
    }
    sort(Boards+1,Boards+N+1);

    smallBsum[0]=0;
    fin>>M;
    for(int i=1;i<=M;i++)
    {
        fin>>smallBoards[i];
    }
    sort(smallBoards+1,smallBoards+M+1);
    for(int i=1;i<=M;i++)
    {
        smallBsum[i]=smallBsum[i-1]+smallBoards[i];
    }
}

bool checker(int num,int startpoint,int rest)
{
    if(num==0)return true;
    if(smallBoards[num]!=smallBoards[num+1])startpoint=N;
    for(int i=startpoint;i>0;i--)
    {
        if(smallBoards[num]<=Boards[i])
        {
            Boards[i]-=smallBoards[num];
            int resttmp=rest-smallBoards[num];

            if(Boards[i]<smallBoards[1])
            {
                resttmp-=Boards[i];
            }
            if(resttmp>=smallBsum[num-1]&&checker(num-1,i,resttmp)){Boards[i]+=smallBoards[num];return true;}
            Boards[i]+=smallBoards[num];
        }
    }
    return false;
}

int solution(int low,int num)
{
    if(low==num)return low;
//    cout<<"num: "<<num<<"\n";
//    cout<<"low:"<<low<<"\n";
    int mid=(low+num)/2+1;
    int rest;
    rest=allBoardsLength;
    if(checker(mid,N,rest))return solution(mid,num);
    else return solution(low,mid-1);
    return 0;
}

void solve()
{
    int finish;
    for(finish=1;finish<=M;finish++)
    {
        if(smallBsum[finish]>allBoardsLength)break;
    }
    result=solution(0,finish-1);
}

void output()
{
    cout<<result<<"\n";
    fout<<result<<"\n";
}

int main()
{
    input();
    solve();
    output();
    return 0;
}
