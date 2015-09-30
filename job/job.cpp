/*
ID:thtfive
LANG:C++
TASK:job
*/
#include<fstream>
#include<iostream>
using namespace std;
///该算法的时间复杂度为N*max(M1,M2)
void sort(int *Machinetime,int length)
{
    for (int i=0;i<length;i++)
    {
        for(int j=1;j<length-i;j++)
        {
            if(Machinetime[j]<Machinetime[j-1])
            {
                int tmp=Machinetime[j];
                Machinetime[j]=Machinetime[j-1];
                Machinetime[j-1]=tmp;
            }
        }
    }
}

int main()
{
    int N,M1,M2;
    ifstream fin("job.in");
    ofstream fout("job.out");
    fin>>N>>M1>>M2;
    int processtime1[N];
    int processtime2[N];
    int machine1[N];
    int machine2[N];
    for(int i=0;i<N;i++)
    {
        processtime1[i]=0;
        processtime2[i]=0;
        machine1[i]=0;
        machine2[i]=0;
    }

    int Machine1Time[M1];
    int Machine2Time[M2];
    for(int i=0;i<M1;i++)
        fin>>Machine1Time[i];
    for(int i=0;i<M2;i++)
        fin>>Machine2Time[i];

    for (int i=0;i<N;i++)
    {
        int pt=999999999;
        int ma;
        for (int j=0;j<M1;j++)
        {
            if(machine1[j]+Machine1Time[j]<pt)
            {
                pt=machine1[j]+Machine1Time[j];
                ma=j;
            }
        }
        processtime1[i]=pt;
        machine1[ma]=machine1[ma]+Machine1Time[ma];
    }

    for (int i=0;i<N;i++)
    {
        int pt=999999999;
        int ma;
        for (int j=0;j<M2;j++)
        {
            if(machine2[j]+Machine2Time[j]<pt)
            {
                pt=machine2[j]+Machine2Time[j];
                ma=j;
            }
        }
        processtime2[i]=pt;
        machine2[ma]=machine2[ma]+Machine2Time[ma];
    }


    int max=0;

    for(int i=0;i<N;i++)
    {
        if(max<processtime1[i]+processtime2[N-i-1])
        {
            max=processtime1[i]+processtime2[N-i-1];
        }
    }
    fout<<processtime1[N-1]<<" "<<max<<"\n";


}
