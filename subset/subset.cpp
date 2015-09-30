/*
ID:thtfive
LANG:C++
TASK:subset
*/
#include<fstream>
#include<iostream>
using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int N;
    fin>>N;

    int total=N*(N+1)/2;

    if (1==total%2){fout<<0<<endl;return 0;}
    if (N<3){fout<<0<<endl;return 0;}

    int ave=total/2;

    total++;
    long long counter[total];

    bool flag[total];
    int idx=0;
    for (int i=0;i<total;i++){counter[i]=0;flag[i]=false;}

    flag[0]=true;
    flag[1]=true;
    flag[2]=true;
    flag[3]=true;
    counter[0]=1;
    counter[1]=1;
    counter[2]=1;
    counter[3]=1;

    for (int i=3;i<=N;i++)
    {
        flag[i]=true;
        int temp=(i*(i-1)/2);

        for (int j=temp;j>=0;j--)
            if(flag[j])
            {
                counter[i+j]+=counter[j];
                flag[i+j]=true;
            }
    }

    fout<<counter[ave]/2<<"\n";

    return 0;
}
