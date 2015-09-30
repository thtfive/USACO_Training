/*
ID:thtfive
LANG:C++
TASK:fc
*/
#include<iostream>
#include<fstream>
#include<cmath>
#include<string.h>
#include<iomanip>
#define pi 3.1415926
using namespace std;

double anglecaculate(double x,double y,double midx,double midy)
{
    double angle=0;
    if(x-midx==0&&y-midy>0)
    {
        angle=pi/2;
        return angle;
    }
    if(x-midx==0&&y-midy<0)
    {
        angle=3*pi/2;
        return angle;
    }
    if(y-midy==0&&x-midx>0)
    {
        angle=0;
        return angle;
    }
    if(y-midy==0&&x-midx<0)
    {
        angle=pi;
        return angle;
    }

    if((y-midy)>0&&(x-midx)>0)
    {
        angle=atan(abs((y-midy)/(x-midx)));
        return angle;
    }
    if((y-midy)>0&&(x-midx)<0)
    {
        angle=pi-atan(abs((y-midy)/(x-midx)));
        return angle;
    }
    if((y-midy)<0&&(x-midx)<0)
    {
        angle=pi+atan(abs((y-midy)/(x-midx)));
        return angle;
    }
    if((y-midy)<0&&(x-midx)>0)
    {
        angle=2*pi-atan(abs((y-midy)/(x-midx)));
        return angle;
    }
    return angle;
}

int partition(double *angle,int start,int finish,int *index)
{
    int mid=start-1;
    for(int i=start;i<finish;i++)
    {
        if(angle[i]<angle[finish])
        {
            mid++;
            double tmp1=angle[mid];
            angle[mid]=angle[i];
            angle[i]=tmp1;
            int tmp2=index[mid];
            index[mid]=index[i];
            index[i]=tmp2;
        }
    }
    mid++;
    double tmp1=angle[mid];
    angle[mid]=angle[finish];
    angle[finish]=tmp1;
    int tmp2=index[mid];
    index[mid]=index[finish];
    index[finish]=tmp2;
    return mid;
}

void sort(double *angle,int start,int finish,int *index)
{
    if(start<finish)
    {
        int mid=partition(angle,start,finish,index);
        sort(angle,start,mid-1,index);
        sort(angle,mid+1,finish,index);
    }
}

int main()
{
    ifstream fin("fc.in");
    ofstream fout("fc.out");
    int N;
    fin>>N;
    double x[N],y[N],angles[N];
    int record[N];
    int recordnum=0;
    int index[N];
    for(int i=0;i<N;i++)
    {
        fin>>x[i]>>y[i];
        index[i]=i;
    }
    double midx=0;
    double midy=0;
    for(int i=0;i<N;i++)
    {
        midx+=x[i]/N;
        midy+=y[i]/N;
        angles[i]=anglecaculate(x[i],y[i],midx,midy);
    }

    for(int i=0;i<N;i++)
    {
        angles[i]=anglecaculate(x[i],y[i],midx,midy);
    }

    sort(angles,0,N-1,index);

//    for(int i=0;i<N;i++)
//        cout<<angles[i]<<" "<<index[i]<<" "<<x[index[i]]<<" "<<y[index[i]]<<endl;

    for(int i=0;i<N;i++)
    {
        if(i>0&&angles[i]==angles[i-1]&&x[index[i]]==x[index[i-1]])
        continue;
        recordnum++;
        record[recordnum-1]=index[i];
        bool flag=true;
        while(recordnum>2&&flag)
        {
            flag=false;
            double angle1=anglecaculate(x[record[recordnum-2]],y[record[recordnum-2]],x[record[recordnum-3]],y[record[recordnum-3]]);
            double angle2=anglecaculate(x[record[recordnum-1]],y[record[recordnum-1]],x[record[recordnum-2]],y[record[recordnum-2]]);
            double min;
            double max;
            if(angle1<=pi)
            {
                min=angle1;
                max=angle1+pi;
                if(!(angle2>min&&angle2<max))
                {
                    recordnum--;
                    record[recordnum-1]=index[i];
                    flag=true;
                }
            }
            else
            {
                max=angle1;
                min=angle1-pi;
                if(!(angle2>max||angle2<min))
                {
                    recordnum--;
                    record[recordnum-1]=index[i];
                    flag=true;
                }
            }
        }
    }

    bool flag=true;
    int start=0;
    while(flag)
    {

        double angle1=anglecaculate(x[record[recordnum-1]],y[record[recordnum-1]],x[record[recordnum-2]],y[record[recordnum-2]]);
        double angle2=anglecaculate(x[record[start]],y[record[start]],x[record[recordnum-1]],y[record[recordnum-1]]);
        double min;
        double max;
        flag=false;

        if(angle1<=pi)
        {
            min=angle1;
            max=angle1+pi;
            if(!(angle2>min&&angle2<max))
            {
                recordnum--;
                flag=true;
            }
        }
        else
        {
            max=angle1;
            min=angle1-pi;
            if(!(angle2>max||angle2<min))
            {
                recordnum--;
                flag=true;
            }
        }
        if(flag)continue;

        angle1=anglecaculate(x[record[start]],y[record[start]],x[record[recordnum-1]],y[record[recordnum-1]]);
        angle2=anglecaculate(x[record[start+1]],y[record[start+1]],x[record[start]],y[record[start]]);
        if(angle1<=pi)
        {
            min=angle1;
            max=angle1+pi;
            if(!(angle2>min&&angle2<max))
            {
                start++;
                flag=true;
            }
        }
        else
        {
            max=angle1;
            min=angle1-pi;
            if(!(angle2>max||angle2<min))
            {
                start++;
                flag=true;
            }
        }
    }

    double result=0;
    for(int i=start+1;i<recordnum;i++)
    {
        result+=sqrt((x[record[i]]-x[record[i-1]])*(x[record[i]]-x[record[i-1]])+(y[record[i]]-y[record[i-1]])*(y[record[i]]-y[record[i-1]]));
    }
    result+=sqrt((x[record[start]]-x[record[recordnum-1]])*(x[record[start]]-x[record[recordnum-1]])+(y[record[start]]-y[record[recordnum-1]])*(y[record[start]]-y[record[recordnum-1]]));
    cout<<setiosflags(ios::fixed)<<setprecision(2);
    cout<<result<<endl;

    fout<<setiosflags(ios::fixed)<<setprecision(2);
    fout<<result<<endl;
    return 0;
}
