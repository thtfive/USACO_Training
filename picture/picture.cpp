/*
ID:thtfive
LANG:C++
TASK:picture
*/
#include<iostream>
#include<fstream>
#include<string.h>
#include<queue>
#include<stack>
using namespace std;

ifstream fin("picture.in");
ofstream fout("picture.out");
int N;
int Xvalues[20001];
int Xnum;
int cnt[10001];
int result;

class SEG
{
public:
    int left,right;
    int y;
    int sign;
    SEG(){}
    SEG(int l,int r,int yvalue,int s):left(l),right(r),y(yvalue),sign(s){}
}segments[10001];

int partitioning(int *xvalues,int start,int finish)
{
    int mid=start-1;
    for(int idx=start;idx<finish;idx++)
    {
        if(xvalues[idx]<xvalues[finish])
        {
            mid++;
            int tmp=xvalues[idx];
            xvalues[idx]=xvalues[mid];
            xvalues[mid]=tmp;
        }
    }
    mid++;
    int tmp=xvalues[finish];
    xvalues[finish]=xvalues[mid];
    xvalues[mid]=tmp;
    return mid;
}

void quicksort(int *xvalues,int start,int finish)
{
    if(start<finish)
    {
        int mid=partitioning(xvalues,start,finish);
        quicksort(xvalues,start,mid-1);
        quicksort(xvalues,mid+1,finish);
    }
}

int segment_part(SEG *segment,int start,int finish)
{
    int mid=start-1;
    for(int idx=start;idx<finish;idx++)
    {
        if(segment[idx].y<segment[finish].y)
        {
            mid++;
            SEG tmp;
            tmp=segment[idx];
            segment[idx]=segment[mid];
            segment[mid]=tmp;
        }
    }
    mid++;
    SEG tmp;
    tmp=segment[finish];
    segment[finish]=segment[mid];
    segment[mid]=tmp;
    return mid;
}

void segment_sort(SEG *segment,int start,int finish)
{
    if(start<finish)
    {
        int mid=segment_part(segment,start,finish);
        segment_sort(segment,start,mid-1);
        segment_sort(segment,mid+1,finish);
    }
}

void init()
{
    fin>>N;
    for(int i=0;i<N;i++)
    {
        int lowy,upy,left,right;
        fin>>left>>lowy>>right>>upy;
        segments[2*i+1]=SEG(left,right,lowy,1);
        segments[2*i+2]=SEG(left,right,upy,-1);
        Xvalues[2*i+1]=left;
        Xvalues[2*i+2]=right;
    }
    memset(cnt,0,sizeof(cnt));
    quicksort(Xvalues,1,2*N);
    segment_sort(segments,1,2*N);

    Xnum=1;
    for(int i=2;i<=2*N;i++)
    {
        if(Xvalues[i]!=Xvalues[Xnum])
        {
            Xvalues[++Xnum]=Xvalues[i];
        }
    }

}

int findindex(int value)
{
    int start=1;
    int finish=Xnum;
    int mid=(start+finish)/2;
    while(Xvalues[mid]!=value)
    {
        if(Xvalues[mid]<value)
        {
            start=mid+1;
        }
        else
        {
            finish=mid;
        }
        mid=(start+finish)/2;
    }
    return mid;
}

int sidecount(SEG segment,int &length)
{
    length=0;
    int sidenum=0;
    int lidx=findindex(segment.left);
    int ridx=findindex(segment.right);
    for(int i=lidx;i<ridx;i++)
    {
        int pre=cnt[i];
        cnt[i]+=segment.sign;
        if((pre==0&&cnt[i]!=0)||(pre!=0&&cnt[i]==0))
        {
            length+=Xvalues[i+1]-Xvalues[i];
        }
    }

    for(int i=1;i<Xnum;i++)
    {
        if(cnt[i]!=0&&cnt[i-1]==0)
        {
            sidenum+=2;
        }
    }
    return sidenum;
}


void solution()
{
    result=0;
    int length=0;
    for(int i=1;i<2*N;i++)
    {
        int sidenum=sidecount(segments[i],length);
        result=result+length+sidenum*(segments[i+1].y-segments[i].y);
    }
    sidecount(segments[2*N],length);
    result+=length;
}

void print()
{
    cout<<result<<"\n";
    fout<<result<<"\n";
}
int main()
{
    init();
    solution();
    print();
    return 0;
}
