/*
ID:thtfive
LANG:C++
TASK:wormhole
*/
#include<iostream>
using namespace std;
#include<fstream>
///利用回溯法列出所有可能，然后对所有可能进行测试
///此种方法可行性有待商榷

int Hole[12][2];
bool flag[12];
int result=0;
int counter=0;
int partner[12];
string strlib="123456789ABCDEF";
string strArray[20000];
int str_len=0;
ofstream fout("wormhole.out");

bool search_str(string str){
    for (int i=0;i<str_len;i++)if(str==strArray[i])return true;
    strArray[str_len]=str;
    str_len++;
    return false;
}

bool begintest(int index,int times,int num)
{
    bool flag=false;
    int i=partner[index];

    int min_tmp;
    int cal=0;
    int place;
    int sign=false;
    for (int j=0;(j<num);j++)///找出最靠近i点的右侧邻点
    {
        if((Hole[j][0]>Hole[i][0])&&(Hole[i][1]==Hole[j][1]))
        {
            sign=true;
            cal++;
            if (cal==1){min_tmp=Hole[j][0];place=j;}
            else
            {
                if (Hole[j][0]<min_tmp)
                {
                    min_tmp=Hole[j][0];
                    place=j;
                }
            }
        }
    }
    if(sign==false)return false;

    if (times>num)///
    {
        return true;
    }
    else
    {
        flag=begintest(place,times+1,num);
    }
    return flag;
}

bool test(int num)
{
    ///true represent it may be cycle
    for (int i=0;i<num;i++)
    {
        if (begintest(i,0,num)){return true;}
    }
    return false;
}

void solve(int num,int cur)
{
    if (cur==num)
    {
        if(test(num))result++;
        return;
    }
    if(flag[cur])
    {
        solve(num,cur+1);
    }
    else
    {
        flag[cur]=true;
        for (int i=cur+1;i<num;i++)
        {
            if(!flag[i])
            {
                partner[i]=cur;
                partner[cur]=i;
                flag[i]=true;
                solve(num,cur+1);
                flag[i]=false;
            }
        }
        flag[cur]=false;
    }
}

int main()
{
    ifstream fin("wormhole.in");
    int Num;
    fin>>Num;

    for (int i=0;i<Num;i++)fin>>Hole[i][0]>>Hole[i][1];
    for (int i=0;i<Num;i++)partner[i]=13;
    for (int i=0;i<12;i++)flag[i]=false;

    solve(Num,0);

    fout<<result<<"\n";
    cout<<result<<"\n";

    return 0;
}
