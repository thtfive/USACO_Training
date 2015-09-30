/*
ID:thtfive
LANG:C++
TASK:milk3
*/
#include<iostream>
#include<fstream>
using namespace std;
#define max_num 21
int flag[21][21][21];///use flag to identify those status which are archieved before
int remain[max_num];
void exchange(int A,int B,int C,int A_remain,int B_remain,int C_remain)
{


    if(0==A_remain)
    {
        remain[C_remain]=1;
    }

    if (flag[A_remain][B_remain][C_remain]==1)return;
    flag[A_remain][B_remain][C_remain]=1;


    if(0!=A_remain)
    {
        if(A_remain>(B-B_remain))
        {
            int tmp=B-B_remain;
            int B_remain_tmp=B;
            int A_remain_tmp=A_remain-tmp;
            int C_remain_tmp=C_remain;
            exchange(A,B,C,A_remain_tmp,B_remain_tmp,C_remain_tmp);
        }
        else
        {
            int B_remain_tmp=B_remain+A_remain;
            int A_remain_tmp=0;
            int C_remain_tmp=C_remain;
            exchange(A,B,C,A_remain_tmp,B_remain_tmp,C_remain_tmp);
        }

        if(A_remain>(C-C_remain))
        {
            int tmp=C-C_remain;
            int C_remain_tmp=C;
            int A_remain_tmp=A_remain-tmp;
            int B_remain_tmp=B_remain;
            exchange(A,B,C,A_remain_tmp,B_remain_tmp,C_remain_tmp);
        }
        else
        {
            int C_remain_tmp=C_remain+A_remain;
            int A_remain_tmp=0;
            int B_remain_tmp=B_remain;
            exchange(A,B,C,A_remain_tmp,B_remain_tmp,C_remain_tmp);
        }

    }
    if(0!=B_remain)
    {
        if(B_remain>(A-A_remain))
        {
            int tmp=A-A_remain;
            int A_remain_tmp=A;
            int B_remain_tmp=B_remain-tmp;
            int C_remain_tmp=C_remain;
            exchange(A,B,C,A_remain_tmp,B_remain_tmp,C_remain_tmp);
        }
        else
        {
            int A_remain_tmp=A_remain+B_remain;
            int B_remain_tmp=0;
            int C_remain_tmp=C_remain;
            exchange(A,B,C,A_remain_tmp,B_remain_tmp,C_remain_tmp);
        }

        if(B_remain>(C-C_remain))
        {
            int tmp=C-C_remain;
            int C_remain_tmp=C;
            int B_remain_tmp=B_remain-tmp;
            int A_remain_tmp=A_remain;
            exchange(A,B,C,A_remain_tmp,B_remain_tmp,C_remain_tmp);
        }
        else
        {
            int C_remain_tmp=C_remain+B_remain;
            int B_remain_tmp=0;
            int A_remain_tmp=A_remain;
            exchange(A,B,C,A_remain_tmp,B_remain_tmp,C_remain_tmp);
        }
    }
    if(0!=C_remain)
    {
        if(C_remain>(A-A_remain))
        {
            int tmp=A-A_remain;
            int A_remain_tmp=A;
            int C_remain_tmp=C_remain-tmp;
            int B_remain_tmp=B_remain;
            exchange(A,B,C,A_remain_tmp,B_remain_tmp,C_remain_tmp);
        }
        else
        {
            int A_remain_tmp=A_remain+C_remain;
            int C_remain_tmp=0;
            int B_remain_tmp=B_remain;
            exchange(A,B,C,A_remain_tmp,B_remain_tmp,C_remain_tmp);
        }

        if(C_remain>(B-B_remain))
        {
            int tmp=B-B_remain;
            int B_remain_tmp=B;
            int C_remain_tmp=C_remain-tmp;
            int A_remain_tmp=A_remain;
            exchange(A,B,C,A_remain_tmp,B_remain_tmp,C_remain_tmp);
        }
        else
        {
            int B_remain_tmp=B_remain+C_remain;
            int C_remain_tmp=0;
            int A_remain_tmp=A_remain;
            exchange(A,B,C,A_remain_tmp,B_remain_tmp,C_remain_tmp);
        }
    }
}

int main()
{
    ifstream fin("milk3.in");
    ofstream fout("milk3.out");
    int A,B,C;
    fin>>A>>B>>C;

    for (int i=0;i<max_num;i++)remain[i]=-1;
    remain[C]=1;
    for (int i=0;i<=A;i++)
        for (int j=0;j<=B;j++)
            for (int k=0;k<=C;k++)
                flag[i][j][k]=0;


    exchange(A,B,C,0,0,C);

    int data[20];
    int counter=0;
    for (int i=0;i<max_num;i++)if(remain[i]==1){data[counter]=i;counter++;}

    for (int i=0;i<counter-1;i++){fout<<data[i]<<" ";}
    fout<<data[counter-1]<<"\n";

    for (int i=0;i<counter;i++){cout<<data[i]<<" ";}

    return 0;
}
