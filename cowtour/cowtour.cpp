/*
ID:thtfive
LANG:C++
TASK:cowtour
*/
#include<fstream>
#include<iostream>
#include<queue>
#include<cmath>
#include<iomanip>
using namespace std;

#define max_N 150
int mtx[max_N][max_N];

int region[max_N][max_N];
long double cowregion[max_N][2];
bool flag[max_N];
int regionnum=0;


int regioncount[max_N];

void regionselect(int N)
{
    queue <int>que;
    for (int i=0;i<N;i++)
    {
        if (flag[i]==false)
        {
            flag[i]=true;
            que.push(i);
            while(!que.empty())
            {
                int first=que.front();
                region[regionnum][regioncount[regionnum]++]=first;
                que.pop();
                for (int i=0;i<N;i++)
                {
                    if (mtx[first][i]==1&&!flag[i])
                    {
                        flag[i]=true;
                        que.push(i);
                    }
                }
            }
            regionnum++;
        }
    }
}

long double Distance(int i,int j)
{
    long double a=cowregion[i][0]-cowregion[j][0];
    long double b=cowregion[i][1]-cowregion[j][1];
    long double result=sqrt(a*a+b*b);
    return result;
}

long double distantcount(int order,int index,int regioncounter,int N)
{
    bool flagtmp[N];
    for (int i=0;i<N;i++)
        flagtmp[i]=false;

    int insideset[N];
    long double distanttmp[N];
    insideset[0]=region[order][index];///the initial status
    distanttmp[0]=0;
    flagtmp[region[order][index]]=true;
    int insidecount=1;
    int place;
    long double distmp;
    int finalplace;

    while (insidecount<regioncounter)
    {
        distmp=999999990;
        for (int i=0;i<regioncounter;i++)///find a feazible i
        {
            long double mindistant=999999998;///make mindistant big enough

            place=region[order][i];
            bool mark=false;
            for (int n=0;n<insidecount;n++)///if i is connect to inside
            {
                if (mtx[place][insideset[n]]==1)
                {
                    mark=true;
                    break;
                }
            }
            if(mark&&flagtmp[place]==false)///if region[order][i] is outside and connect to inside
            {
                for (int k=0;k<insidecount;k++)
                {
                    if (mtx[place][insideset[k]]==1)///region[i] is the new member inside
                    {
                        long double D=Distance(place,insideset[k]);
                        long double tmp=D+distanttmp[k];
                        if (mindistant>tmp)
                        {
                            mindistant=tmp;
                        }
                    }
                }
            }

            if (distmp>mindistant)
            {
                finalplace=place;
                distmp=mindistant;
            }
        }

        flagtmp[finalplace]=true;
        insideset[insidecount]=finalplace;///add region[i] to insideset
        distanttmp[insidecount]=distmp;
        insidecount++;
    }

    long double maxdistant=0;
    for (int i=0;i<regioncounter;i++)
    {
        maxdistant=maxdistant>distanttmp[i]?maxdistant:distanttmp[i];
    }
    return maxdistant;
}

long double maxD(int order,long double *distant)
{
    int num=regioncount[order];
    long double result=0;
    for (int i=0;i<num;i++)
    {
        result=result>distant[region[order][i]]?result:distant[region[order][i]];
    }
    return result;
}

long double mindistant(long double *distant)
{
    long double result=999999997;
    long double D1,D2,Dtmp;
    long double d;
    for (int i=0;i<regionnum;i++)
    {
        for (int j=i+1;j<regionnum;j++)
        {
            long double D=999999999;
            for (int k=0;k<regioncount[i];k++)
            {
                for (int n=0;n<regioncount[j];n++)
                {

                    d=Distance(region[i][k],region[j][n])+distant[region[i][k]]+distant[region[j][n]];
                    D=D<d?D:d;
                }
            }

            D1=maxD(i,distant);
            D2=maxD(j,distant);
            if (D1>D2)Dtmp=D1>D?D1:D;
            else Dtmp=D2>D?D2:D;
            if (result>Dtmp)
            {
//                cout<<"i: "<<i<<" j: "<<j<<endl;
//                cout<<"D1:     "<<D1<<endl;
//                cout<<"D2:     "<<D2<<endl;
//                cout<<"D:      "<<D<<endl;
//                cout<<"result: "<<result<<endl;
                result=Dtmp;
            }
        }
    }
    return result;
}

int main()
{
    int N;
    ifstream fin;
    ofstream fout;
    fin.open("input.txt");
    fout.open("output.txt");
//    fin.open("cowtour.in");
//    fout.open("cowtour.out");
    long double distant[max_N];

    fin>>N;


    for (int i=0;i<N;i++)///initialize
    {
        flag[i]=false;
        distant[i]=0;
        regioncount[i]=0;
    }

    for (int i=0;i<N;i++)
        fin>>cowregion[i][0]>>cowregion[i][1];

    string str;
    for (int i=0;i<N;i++)
    {
        fin>>str;
        for (int j=0;j<N;j++)
            mtx[i][j]=str[j]-'0';
    }


    regionselect(N);///right


    for (int i=0;i<regionnum;i++)
    {
        for (int j=0;j<regioncount[i];j++)
        {
            distant[region[i][j]]=distantcount(i,j,regioncount[i],N);
        }
    }


    long double result=mindistant(distant);


    fout<<setiosflags(ios::fixed)<<setprecision(6);
    cout<<setiosflags(ios::fixed)<<setprecision(6);
    cout<<result<<"\n";
    fout<<result<<"\n";




    return 0;
}
