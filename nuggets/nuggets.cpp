/*
ID:thtfive
LANG:C++
TASK:nuggets
*/

#include<iostream>
#include<fstream>
using namespace std;
#define max_N 10

int Number[max_N];
int EffectNum[max_N];
int patition(int *intarray,int start,int finish)
{
    int mid=start-1;
    int last=intarray[finish];
    for (int i=start;i<finish;i++)
    {
        if(intarray[i]<last)
        {
            mid++;
            int tmp=intarray[mid];
            intarray[mid]=intarray[i];
            intarray[i]=tmp;
        }
    }
    mid++;
    int tmp=intarray[finish];
    intarray[finish]=intarray[mid];
    intarray[mid]=tmp;
    return mid;
}

void quick_sort(int *intarray,int start,int finish)
{
    if(start<finish)
    {
        int mid=patition(intarray,start,finish);
        quick_sort(intarray,start,mid-1);
        quick_sort(intarray,mid+1,finish);
    }
}

int main()
{
    ifstream fin("nuggets.in");
    ofstream fout("nuggets.out");
    int N;
    fin>>N;
    for (int i=0;i<N;i++)
        fin>>Number[i];

    quick_sort(Number,0,N-1);

    bool flag[N];
    for (int i=0;i<N;i++)
        flag[i]=true;
    for(int i=0;i<N;i++)
        for(int j=i+1;j<N;j++)
            if(Number[j]%Number[i]==0)
                flag[j]=false;
    int counter=0;
    for(int i=0;i<N;i++)
    {
        if(flag[i])
        {
            EffectNum[counter++]=Number[i];
        }
    }

    N=counter;///the effective number of these packages
    int maxnum=EffectNum[N-1];

//    for(int i=0;i<N;i++)
//        cout<<EffectNum[i]<<" ";

    int oddnum=0;
    for (int i=0;i<N;i++)
        if(EffectNum[i]%2==1)
            oddnum++;

    bool mark[maxnum];
    for (int i=0;i<maxnum;i++)
        mark[i]=false;
    mark[0]=true;
    int Max;
    for (int num=1;num<maxnum;num++)
    {
        for (int j=0;j<N;j++)
        {
            if(num-EffectNum[j]>=0&&mark[num-EffectNum[j]])
                mark[num]=true;
        }
        if(!mark[num])Max=num;
    }

    if(N==1||oddnum==0)
    {
        Max=0;
    }
    else
    {
        int count=0;
        for(long long num=maxnum+1;num<2000000000;num++)
        {
            bool signal=false;
            for (int j=0;j<N;j++)
            {
                if(mark[(num-EffectNum[j]+maxnum)%maxnum])
                {
                    signal=true;
                    count++;
                    break;
                }
            }
            mark[num%maxnum]=signal;
            if(!mark[num%maxnum])
            {
                Max=num;
                count=0;
            }
            if (count>maxnum)break;
        }
    }
    cout<<Max<<endl;
    fout<<Max<<"\n";
//    for(int i=0;i<N;i++)
//        cout<<Number[i]<<" ";
    return 0;
}
