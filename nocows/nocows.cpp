/*
ID:thtfive
LANG:C++
TASK:nocows
*/
#include<iostream>
#include<fstream>



using namespace std;

int pow(int num,int index)
{
    int result=num;
    for (int i=1;i<index;i++)result*=num;
    return result;
}

int recursive_record(int N,int K,int (*recorder)[100])
{
    if(recorder[N][K]!=-1) return recorder[N][K];
    if(N==1)return 1;

    int counter=0;
    int tmp=0;

    for (int n=1;n<=N-1;n=n+2)
    {
        for (int h=1;h<K-1;h++)
        {
            tmp+=recursive_record(N-n-1,K-1,recorder)*recursive_record(n,h,recorder);
            tmp%=9901;
        }
    }

    for (int n=1;n<=N-1;n=n+2)
    {
        counter+=recursive_record(N-n-1,K-1,recorder)*recursive_record(n,K-1,recorder);
        counter%=9901;
    }

    counter+=tmp*2;
    recorder[N][K]=counter%9901;
    return recorder[N][K];
}


int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int N,K;
    fin>>N>>K;
    cout<<"N: "<<N<<" K: "<<K<<"\n";
    int recorder[N+1][100];
    for (int i=0;i<=N;i++)
        for (int j=0;j<100;j++)
            {
                int maxnum=0;
                if (j<10)maxnum=pow(2,j);
                else maxnum=1000;
                if (i<(2*j-1)||i>=maxnum)recorder[i][j]=0;
                else
                    {
                        if (i==maxnum-1)recorder[i][j]=1;
                        else recorder[i][j]=-1;
                    }
                if (i==0||j==0)recorder[i][j]=0;
            }


//    for (int i=0;i<=N;i++)
//    {
//          for (int j=0;j<=K;j++)
//          {
//              cout<<recorder[i][j]<<" ";
//          }
//          cout<<"\n";
//    }


    recursive_record(N,K,recorder);
    fout<<recorder[N][K]<<endl;


//            for (int i=0;i<=N;i++)
//        {
//              for (int j=0;j<K;j++)
//              {
//                  cout<<recorder[i][j]<<" ";
//              }
//              cout<<"\n";
//        }



    return 0;
}
