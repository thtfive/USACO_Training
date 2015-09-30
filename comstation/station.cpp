#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
int Customers[1001][2];
int Company[101][2];
int N,M,A,B;

int caculate1(int xsum,int ysum,int placex,int placey)
{
    int tmpx=floor((2*xsum-1)/(2*A));
    int tmpy=floor((2*ysum-1)/(2*A));
    int ansx=placex>tmpx?placex:tmpx;
    int ansy=placey>tmpy?placey:tmpy;

    long long tmp;
    long long result=pow(10,18);
    for (int i=ansx;i<=ansx+1;i++)
    {
        for(int j=ansy;j<=ansy+1;j++)
        {
            tmp=0;
            if(i>=placex&&i<=N&&j>=placey&&j<=M)
            {
                for (int k=0;k<A;k++)
                {
                    tmp+=pow(Customers[k][0]-i,2)+pow(Customers[k][1]-j,2);
                }
                tmp+=(i+j-placex-placey);
                result=result<tmp?result:tmp;
            }
        }
    }
    return result;
}

int caculate2(int xsum,int ysum,int placex,int placey)
{
    int tmpx=floor((2*xsum+1)/(2*A));
    int tmpy=floor((2*ysum-1)/(2*A));
    int ansx=placex<tmpx?placex:tmpx;
    int ansy=placey>tmpy?placey:tmpy;

    long long tmp=0;
    long long result=pow(10,18);
    for (int i=ansx;i<=ansx+1;i++)
    {
        for(int j=ansy;j<=ansy+1;j++)
        {
            tmp=0;
            if(i<=placex&&i>=0&&j>=placey&&j<=M)
            {
                for (int k=0;k<A;k++)
                {
                    tmp+=pow(Customers[k][0]-i,2)+pow(Customers[k][1]-j,2);
                }
                tmp+=(placex-i+j-placey);
                result=result<tmp?result:tmp;
            }
        }
    }
    return result;
}

long long caculate3(int xsum,int ysum,int placex,int placey)
{
    int tmpx=floor((2*xsum+1)/(2*A));
    int tmpy=floor((2*ysum+1)/(2*A));
    int ansx=placex<tmpx?placex:tmpx;
    int ansy=placey<tmpy?placey:tmpy;

    long long tmp=0;
    long long result=pow(10,18);
    for (int i=ansx;i<=ansx+1;i++)
    {
        for(int j=ansy;j<=ansy+1;j++)
        {
            tmp=0;
            if(i<=placex&&i>=0&&j<=placey&&j>=0)
            {
                for (int k=0;k<A;k++)
                {
                    tmp+=pow(Customers[k][0]-i,2)+pow(Customers[k][1]-j,2);
                }
                tmp+=(placex+placey-i-j);
                result=result<tmp?result:tmp;
            }
        }
    }
    return result;
}

long long caculate4(int xsum,int ysum,int placex,int placey)
{
    int tmpx=floor((2*xsum-1)/(2*A));
    int tmpy=floor((2*ysum+1)/(2*A));
    int ansx=placex>tmpx?placex:tmpx;
    int ansy=placey<tmpy?placey:tmpy;

    long long tmp=0;
    long long result=pow(10,18);
    for (int i=ansx;i<=ansx+1;i++)
    {
        for(int j=ansy;j<=ansy+1;j++)
        {
            tmp=0;
            if(i<=placex&&i>=0&&j<=placey&&j>=0)
            {
                for (int k=0;k<A;k++)
                {
                    tmp+=pow(Customers[k][0]-i,2)+pow(Customers[k][1]-j,2);
                }
                tmp+=(i-placex+placey-j);
                result=result<tmp?result:tmp;
            }
        }
    }
    return result;
}

int main()
{
    int Test;
//    ifstream fin("input.txt");
    cin>>Test;
    for (int T=1;T<=Test;T++)
    {
        int x,y;
        cin>>N>>M>>A>>B;

        double xsum=0;
        double ysum=0;
        for(int i=0;i<A;i++)
        {
            cin>>x>>y;
            Customers[i][0]=x;
            xsum+=x;
            Customers[i][1]=y;
            ysum+=y;
        }
        for(int i=0;i<B;i++)
        {
            cin>>x>>y;
            Company[i][0]=x;
            Company[i][1]=y;
        }
        long long result=pow(10,18);

        for(int i=0;i<B;i++)
        {
            int placex=Company[i][0];
            int placey=Company[i][1];
            long long tmp;

            tmp=caculate1(xsum,ysum,placex,placey);
            result=result<tmp?result:tmp;

            caculate2(xsum,ysum,placex,placey);
            result=result<tmp?result:tmp;

            caculate3(xsum,ysum,placex,placey);
            result=result<tmp?result:tmp;

            caculate4(xsum,ysum,placex,placey);
            result=result<tmp?result:tmp;
        }

        cout<<"Case #"<<T<<": "<<result<<"\n";
    }
    return 0;
}
