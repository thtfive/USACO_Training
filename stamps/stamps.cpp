/*
ID:thtfive
LANG:C++
TASK:stamps
*/
#include<iostream>
#include<fstream>
using namespace std;
#define max_num_of_stamps 201
int mark[max_num_of_stamps];


void decrease_sort(int *p,int N)
{
    for (int i=0;i<N;i++)
    {
        for (int j=1;j<N;j++)
        {
            if (p[j-1]<p[j])
            {
                int tmp=p[j-1];
                p[j-1]=p[j];
                p[j]=tmp;
            }
        }
    }
}


int main()
{
//    ifstream fin("input.txt");
//    ofstream fout("output.txt");
    ifstream fin("stamps.in");
    ofstream fout("stamps.out");

    int K,N;
    fin>>K>>N;
    int stamps[N];
    for (int i=0;i<N;i++)
        fin>>stamps[i];

    decrease_sort(stamps,N);

    bool flag[2000001];
    for (int i=0;i<=K*stamps[0];i++)flag[i]=false;

    flag[0]=true;

    mark[0]=0;///use for boundary

    for (int i=1;i<=K;i++)
    {
        for (int j=(i-1)*stamps[0];j>=mark[i-1]-stamps[0]&&j>=0;j--)
        {
            if (flag[j]==true)
            {
                 for (int k=0;k<N;k++)
                    {
                        int idx=j+stamps[k];
                        flag[idx]=true;
                    }
            }
//            for (int i=0;i<20;i++)
//                if(flag[i])cout<<i<<": true  ";
//            cout<<"\n";
        }

        int n;
        for (n=mark[i-1]+1;n<=i*stamps[0]&&flag[n];n++)
        {
        }
        mark[i]=n-1;
    }
//    for (int i=1;i<=K;i++)
//    for (int i=1;i<K*stamps[0];i++)
    int counter=0;

    cout<<mark[K]<<"\n";
    fout<<mark[K]<<"\n";


    return 0;
}
