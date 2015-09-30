/*
ID:thtfive
LANG:C++
TASK:money
*/
#include<iostream>
#include<fstream>
//25 10000
//1 2 5 3 4 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
using namespace std;
void increase_sort(int *moneylib,int N)
{
    int tmp;
    for (int i=0;i<N;i++)
        for (int j=1;j<N-i;j++)
        {
            if (moneylib[j-1]>moneylib[j])
            {
                tmp=moneylib[j-1];
                moneylib[j-1]=moneylib[j];
                moneylib[j]=tmp;
            }
        }
}

bool greedy(int N,int n,int *moneylib)
{
    if (n<0)return false;
    if (N%moneylib[n]==0)return true;
    else
    {
        bool flag=false;
        int tmp=N%moneylib[n];
        while (!flag&&tmp<=N)
        {
            flag=flag||greedy(tmp,n-1,moneylib);
            tmp+=moneylib[n];
        }
        return flag;
    }
}

long long solve_recursive(int N,int n,int *moneylib,long long (*record)[26])
{
    if (record[N][n]!=-1)return record[N][n];

    ///greedy algorithm
    long long result=0;

    if (greedy(N,n,moneylib))
    {
        int num=N/moneylib[n];
        for (int i=0;i<=num;i++)
        {
            result+=solve_recursive(N-i*moneylib[n],n-1,moneylib,record);
        }
    }

    record[N][n]=result;
    return result;
}

int main()
{
    int V,N;
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    fin>>V>>N;
    int moneylib[V];
    for (int i=0;i<V;i++)
    {
        fin>>moneylib[i];
          //   cout<<moneylib[i]<<" "<<Num[i]<<"\n";
    }

    long long record[N+1][26];
    for (int i=0;i<=N;i++)
        for (int j=0;j<26;j++)
            record[i][j]=-1;

    increase_sort(moneylib,V);

    for (int i=0;i<=N;i++)
        if (i%moneylib[0]==0)record[i][0]=1;
        else record[i][0]=0;
    solve_recursive(N,V-1,moneylib,record);

    cout<<record[N][V-1];
    fout<<record[N][V-1]<<"\n";





//    long long result=0;
//   // long long record[N+1][26];
//    for (int i=0;i<N+1;i++)
//        for (int j=0;j<26;j++)
//            record[i][j]=-1;
//    for (int i=1;i<=N;i++)
//    {
//        if (i%moneylib[0]==0)
//            record[i][1]=1;
//        else
//            record[i][1]=0;
//    }
//    for (int j=0;j<26;j++)
//        record[0][j]=0;
  //  result=solve_recursive(N,V,Num,moneylib,record);


//    long long counter[N+1],counter_previous[N+1],tmp[N+1];
//    bool newflag[N+1];
//    int len=V;
//    int index[N+1];
//    int newindex[N+1];
//    for (int i=0;i<N+1;i++)///initialize
//    {
//        counter[i]=0;
//        counter_previous[i]=0;
//        tmp[i]=0;
//        newflag[i]=false;
//    }
//
//    for (int i=0;i<V;i++)
//    {
//        counter_previous[moneylib[i]]=1;
//        index[i]=moneylib[i];
//    }
//
//
//    int maxnum=N/moneylib[0];
//
//
//    for (int i=2;i<=maxnum;i++)
//    {
//        int newlen=0;
//        for (int i=1;i<=N;i++){tmp[i]=0;}
//
//        for (int k=0;k<len;k++)
//        {
//            for (int j=0;j<V;j++)
//            {
//                int place=index[k]+moneylib[j];
//                if (place<N+1)
//                {
//                    tmp[place]+=counter_previous[index[k]];
//                    if (!newflag[place])
//                    {
//                        newindex[newlen]=place;
//                        newlen++;
//                        newflag[place]=true;
//                    }
//                }
//            }
//        }
//
//        len=newlen;
//        for (int n=0;n<len;n++)index[n]=newindex[n];
//
////        cout<<"i: "<<i<<endl;
////        for (int i=1;i<=N;i++)cout<<tmp[i]<<" ";
////        cout<<endl;
//
//        for (int n=1;n<=N;n++)
//        {
//            newflag[n]=false;
//            counter[n]+=counter_previous[n];
//            counter_previous[n]=tmp[n];
//            tmp[n]=0;
//        }
//
//        cout<<"i: "<<i<<" "<<endl;
//        for (int ii=1;ii<=N;ii++)cout<<counter_previous[ii]<<" ";
//        cout<<endl;
//    }

 //   cout<<counter[N]<<"\n";


    return 0;
}
