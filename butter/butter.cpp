/*
ID:thtfive
LANG:C++
TASK:butter
*/
#include<iostream>
#include<fstream>
using namespace std;
void min_heapfy(int *heap,int start,int length,int *heap_index,int *real_index)
{
    int l=2*start,r=2*start+1;
    int smallest=start;
    if(l<=length&&heap[l]<heap[start])
        smallest=l;
    if(r<=length&&heap[r]<heap[smallest])
        smallest=r;
    if(smallest!=start)
    {
        int tmp=heap[smallest];
        heap[smallest]=heap[start];
        heap[start]=tmp;

        tmp=real_index[smallest];
        real_index[smallest]=real_index[start];
        real_index[start]=tmp;

        heap_index[real_index[start]]=start;
        heap_index[real_index[smallest]]=smallest;

        min_heapfy(heap,smallest,length,heap_index,real_index);
    }

}
void extra_min(int *heap,int start,int &length,int *heap_index,int *real_index,int &index,int &mindistance)
{
    mindistance=heap[1];
    index=real_index[1];

    int tmp=real_index[1];
    real_index[1]=real_index[length];
    real_index[length]=tmp;

    heap_index[real_index[1]]=1;
    heap_index[real_index[length]]=length;

    heap[1]=heap[length];

    length--;
}


int main()
{
    ifstream fin("butter.in");
    ofstream fout("butter.out");
    int N,P,C;
    fin>>N>>P>>C;
    int map[P+1][P+1];
    int adjacent[P+1][P+1];
    int cow_num[P+1];
    for (int i=0;i<=P;i++)
        for (int j=0;j<=P;j++)
            {
                map[i][j]=1000000;
                adjacent[i][j]=0;
            }
    for(int i=0;i<=P;i++)
        cow_num[i]=0;
    int tmp1,tmp2,tmp3;
    for (int i=0;i<N;i++)
    {
        fin>>tmp1;
        cow_num[tmp1]++;
    }
    for (int i=0;i<C;i++)
    {
        fin>>tmp1>>tmp2>>tmp3;
        map[tmp1][tmp2]=tmp3;
        map[tmp2][tmp1]=tmp3;
        adjacent[tmp1][0]++;
        adjacent[tmp2][0]++;
        adjacent[tmp1][adjacent[tmp1][0]]=tmp2;
        adjacent[tmp2][adjacent[tmp2][0]]=tmp1;
    }
//    for (int i=1;i<=P;i++)
//        cout<<cow_num[i]<<" ";
//    cout<<endl;
    int Distance[P+1][P+1];
    for (int i=1;i<=P;i++)
        for (int j=1;j<=P;j++)
            Distance[i][j]=1000000;


    for(int p=1;p<=P;p++)
    {
        bool flag[P+1];
        int len=0;
        for (int i=1;i<=P;i++)flag[i]=false;

        int heap[P+1];
        int heap_index[P+1];
        int real_index[P+1];
        for (int i=1;i<=P;i++)
        {
            heap[i]=Distance[p][i];
            heap_index[i]=i;
            real_index[i]=i;
        }

        Distance[p][p]=0;
        real_index[1]=p;
        real_index[p]=1;
        heap_index[real_index[1]]=1;
        heap_index[real_index[p]]=p;
        heap[1]=0;

        int length=P;

        while(len<P)
        {
            int mindistance=1000000;
            int place_mark;

            extra_min(heap,1,length,heap_index,real_index,place_mark,mindistance);
            min_heapfy(heap,1,length,heap_index,real_index);
//
//            for(int outside=1;outside<=P;outside++)
//            {
//                if (!flag[outside])
//                {
//                    if(Distance[p][outside]<mindistance)
//                    {
//                        mindistance=Distance[p][outside];
//                        place_mark=outside;
//                    }
//                }
//            }

            len++;
            flag[place_mark]=true;
            Distance[p][place_mark]=mindistance;

            for(int adj=1;adj<=adjacent[place_mark][0];adj++)
            {
                int idx=adjacent[place_mark][adj];
                if (!flag[idx]&&Distance[p][place_mark]+map[place_mark][idx]<Distance[p][idx])
                {
                    Distance[p][idx]=Distance[p][place_mark]+map[place_mark][idx];
                    heap[heap_index[idx]]=Distance[p][idx];

                    for (int i=heap_index[idx];i>=1;i/=2)
                        min_heapfy(heap,i,length,heap_index,real_index);
                }
            }
            min_heapfy(heap,1,length,heap_index,real_index);
        }
    }

    int minDistance=0;
    for (int i=1;i<=P;i++)
    {
        minDistance+=cow_num[i]*Distance[1][i];
    }

    for (int finish=2;finish<=P;finish++)
    {
        int tmp=0;
        for (int j=1;j<=P;j++)
        {
            tmp+=cow_num[j]*Distance[finish][j];
        }
        minDistance=minDistance<tmp?minDistance:tmp;
    }

    cout<<minDistance<<endl;
    fout<<minDistance<<"\n";

    return 0;
}
