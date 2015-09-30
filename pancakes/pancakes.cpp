/*
ID:thtfive
LANG:C++
*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int partition(int *array,int p,int q)
{
    int i=p-1;
    for (int j=p;j<q;j++)
    {
        if(array[j]>array[q])
        {
            i++;
            int tmp=array[j];
            array[j]=array[i];
            array[i]=tmp;
        }
    }
    int tmp=array[q];
    array[q]=array[i+1];
    array[i+1]=tmp;
    return i+1;
}

void quick_sort(int *array,int start,int end)///descend sort
{
    if (start<end)
    {
        int mid=partition(array,start,end);
        quick_sort(array,start,mid-1);
        quick_sort(array,mid+1,end);
    }
}



int main()
{
    ifstream fin("B-small-attempt0.in");
    ofstream fout("B-small-attempt0.out");

    int T;
    fin>>T;
    for (int Test=1;Test<=T;Test++)
    {
        int D;
        fin>>D;
        int Pan[1001];
        int record[1001];
        for (int i=0;i<=1000;i++)
        {
            Pan[i]=0;
        }

        int tmp;
        int maxnum=0;
        for (int i=0;i<D;i++)
        {
            fin>>tmp;
            Pan[tmp]++;
            if(maxnum<tmp)maxnum=tmp;
        }


        int min_time=maxnum;///the upper bound of eating time is maxnum
        int punish_time=0;///punish_time initial is 0
        int idx=3;
        while(idx<maxnum)
        {
            punish_time+=Pan[maxnum];
            if(maxnum%2==0)
            {
                Pan[maxnum/2]+=Pan[maxnum]*2;
            }
            else
            {
                Pan[maxnum/2]+=Pan[maxnum];
                Pan[maxnum/2+1]+=Pan[maxnum];
            }
            Pan[maxnum]=0;
            while(Pan[maxnum]==0)maxnum--;
         //   cout<<"maxnum: "<<maxnum<<" punish_time:"<<punish_time<<"  min_time:"<<punish_time+maxnum<<endl;
           // cout<< "punish_time:"<<punish_time<<" maxnum: "<<maxnum<<endl;
            min_time=min_time<punish_time+maxnum?min_time:punish_time+maxnum;
        }
        cout<<"Case #"<<Test<<": "<<min_time<<"\n";
    }

    return 0;
}
