/*
ID:thtfive
LANG:C++
TASK:window
*/
#include<iostream>
#include<fstream>
#include<string.h>
#include<iomanip>
using namespace std;
int xnum=0;
int segnum=0;
double Xvalues[10000];
///利用线段树的思想，再从下往上进行扫描，计算面积
class node
{
public:
    char mark;
    node *next;
    node()
    {
        next=NULL;
    }
};


struct SEG
{
public:
    double left,right,y_value;///左侧端点和右侧端点位置,y坐标
    int sign;///用于标记上边和下边，下边用1表示，上边用-1表示
    double area;
    char mark;
    SEG(double l,double r,double y,int s,char m,double a)
    {
        left=l;
        right=r;
        y_value=y;
        sign=s;
        mark=m;
        area=a;
    }
    SEG(){}
}segment[10000];

int part(SEG *segments,int start,int finish)
{
    int mid=start-1;
    for(int idx=start;idx<finish;idx++)
    {
        if(segments[idx].y_value<segments[finish].y_value)
        {
            mid++;
            SEG tmp=segments[idx];
            segments[idx]=segments[mid];
            segments[mid]=tmp;
        }
    }
    mid++;
    SEG tmp=segments[finish];
    segments[finish]=segments[mid];
    segments[mid]=tmp;
    return mid;
}

void segsort(SEG *segments,int start,int finish)
{
    if(start<finish)
    {
        int mid=part(segments,start,finish);
        segsort(segments,start,mid-1);
        segsort(segments,mid+1,finish);
    }
}

int partitioning(double *xvalues,int start,int finish)
{
    int mid=start-1;
    for(int idx=start;idx<finish;idx++)
    {
        if(xvalues[idx]<xvalues[finish])
        {
            mid++;
            double tmp=xvalues[idx];
            xvalues[idx]=xvalues[mid];
            xvalues[mid]=tmp;
        }
    }
    mid++;
    double tmp=xvalues[finish];
    xvalues[finish]=xvalues[mid];
    xvalues[mid]=tmp;
    return mid;
}

void quicksort(double *xvalues,int start,int finish)
{
    if(start<finish)
    {
        int mid=partitioning(xvalues,start,finish);
        quicksort(xvalues,start,mid-1);
        quicksort(xvalues,mid+1,finish);
    }
}

void reduce(double *xvalues,int &xnum)
{
    int cp=1;
    for(int i=1;i<xnum;i++)
    {
        if(xvalues[cp-1]!=xvalues[i])
            xvalues[cp++]=xvalues[i];
    }
    xnum=cp;
}

int indexcal(int start,int finish,double key,double *xvalues)
{
    int mid;
    while(start<finish)
    {
        mid=(start+finish)/2;
        if(xvalues[mid]<key)start=mid+1;
        else finish=mid;
    }
    return start;
}

void update(int lidx,int ridx,SEG segment,char mark,int *cnt)
{
    if(segment.mark==mark)
    {
        if(lidx==ridx)return;
        cnt[lidx]-=segment.sign;
        update(lidx+1,ridx,segment,mark,cnt);
    }
    else
    {
        if(lidx==ridx)return;
        cnt[lidx]+=segment.sign;
        update(lidx+1,ridx,segment,mark,cnt);
    }
}

double lengthcal(int *cnt)
{
    double result=0;
    for(int i=0;i<xnum-1;i++)
    {
        if(cnt[i]>0)result+=Xvalues[i+1]-Xvalues[i];
    }
    return result;
}

int main()
{
    ifstream fin("window.in");
    ofstream fout("window.out");

    string op;
    node *link=NULL;
    while(fin>>op)
    {
        int right,left,top,bottom;
        char mark;
        mark=op[2];
        if(op[0]=='w')
        {
            int num[4];
            bool ifexist=false;
            node *p=link;
            while(p!=NULL)
            {
                if(p->mark==mark)
                {
                    ifexist=true;
                    break;
                }
                p=p->next;
            }

            memset(num,0,sizeof(num));
            int len=op.length();
            int index=0;
            for(int i=4;i<len;i++)
            {
                if(op[i]==','||op[i]==')')
                {
                    index++;
                    continue;
                }
                num[index]=num[index]*10+op[i]-'0';
            }
            right=num[0]>num[2]?num[0]:num[2];
            left=num[0]<num[2]?num[0]:num[2];
            top=num[1]>num[3]?num[1]:num[3];
            bottom=num[1]<num[3]?num[1]:num[3];

            if(!ifexist)
            {
                node *tmp=link;
                link=new node;
                link->mark=mark;
                link->next=tmp;
                segment[segnum++]=SEG(left,right,top,1,mark,(top-bottom)*(right-left));
                segment[segnum++]=SEG(left,right,bottom,-1,mark,(top-bottom)*(right-left));
                Xvalues[xnum++]=left;
                Xvalues[xnum++]=right;
            }
        }
        if(op[0]=='t')
        {
            node *p=link;
            node *previous=NULL;
            node *tmp=link;
            while(p!=NULL)
            {
                if(p->mark==mark)
                {
                    if(previous==NULL)
                        break;
                    link=p;
                    previous->next=p->next;
                    link->next=tmp;
                    break;
                }
                previous=p;
                p=p->next;
            }
        }
        if(op[0]=='b')
        {
            node *p=link;
            node *previous=NULL;
            node *last;
            while(p!=NULL)
            {
                last=p;
                p=p->next;
            }

            p=link;
            while(p!=NULL)
            {
                if(p->mark==mark)
                {
                    if(last!=p)
                    {
                        if(previous==NULL)
                        {
                            link=link->next;
                            last->next=p;
                            p->next=NULL;
                            break;
                        }
                        else
                        {
                            previous->next=p->next;
                            last->next=p;
                            p->next=NULL;
                            break;
                        }

                    }
                    else
                    {
                        break;
                    }
                }
                previous=p;
                p=p->next;
            }
        }
        if(op[0]=='d')
        {
            node *p=link;
            node *previous=NULL;
            while(p!=NULL)
            {
                if(p->mark==mark)
                {
                    if(previous==NULL)
                    {
                        link=link->next;
                        break;
                    }
                    previous->next=p->next;
                    break;
                }
                previous=p;
                p=p->next;
            }
            bool sign[segnum];
            memset(sign,true,sizeof(sign));
            for(int i=0;i<segnum;i++)
            {
                if(segment[i].mark==mark)sign[i]=false;
            }

            int IDX=0;
            for(int i=0;i<segnum;i++)
                if(sign[i])segment[IDX++]=segment[i];
            segnum=IDX;
        }
        if(op[0]=='s')
        {
            quicksort(Xvalues,0,xnum-1);
            reduce(Xvalues,xnum);
            segsort(segment,0,segnum-1);
            int cnt[xnum];
            memset(cnt,0,sizeof(cnt));
            double ret=0;
            double total=0;

            for(int i=0;i<segnum-1;i++)
            {
                int lidx=indexcal(0,xnum,segment[i].left,Xvalues);
                int ridx=indexcal(0,xnum,segment[i].right,Xvalues);
                bool flag=false;
                node *p=link;

                while(p!=NULL)
                {
                    if(p->mark==segment[i].mark)
                    {
                        flag=true;
                        break;
                    }
                    if(p->mark==mark)break;
                    p=p->next;
                }
                if(segment[i].mark==mark)total=segment[i].area;

                if(flag)
                {
                    update(lidx,ridx,segment[i],mark,cnt);
                }
                double length=lengthcal(cnt);
                ret+=length*(segment[i+1].y_value-segment[i].y_value);


            }
            fout<<setiosflags(ios::fixed)<<setprecision(3);
            fout<<ret/total*100<<"\n";
            cout<<setiosflags(ios::fixed)<<setprecision(3);
            cout<<ret/total*100<<"\n";
        }

    }
    return 0;
}
