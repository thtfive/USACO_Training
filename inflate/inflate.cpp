/*
ID:thtfive
LANG:C++
TASK:inflate
*/
#include<fstream>
#include<iostream>
#define max_time 10001
using namespace std;
bool flag=false;
int highest=0;
int mark[max_time];

class Node
{
    friend class tree;
    int score;
    Node *next[2];
    Node()
    {
        for (int i=0;i<2;i++)
            next[i]=NULL;
    }
};

class tree
{
    int socre;
    Node *root;
public:
    void insert(int M,int start,int score)
    {
        Node *p=root;
        if (p->next[M]==NULL)
        {
            p->next[M]=new Node;
            p=p->next[M];
            p->next[start]=new Node;
            p=p->next[start];
            p->score=score;
        }
        else
        {
            p=p->next[M];
            if (p->next[start]==NULL)
            {
                p->next[start]=new Node;
                p=p->next[start];
                p->score=score;
            }
        }
    }

    bool search(int M,int start,int &score)
    {
        Node *p=root;
        if (p->next[M]==NULL)
        {
            return false;
        }
        else
        {
            p=p->next[M];
            if (p->next[start]==NULL)
            {
                return false;
            }
            else
            {
                p=p->next[start];
                score=p->score;
                return true;
            }
        }
    }

    tree()
    {
        root=new Node;
    }

}T;




void decrease_sort(double *score,double *time,int &N)
{
    double tmp1,tmp2;
    for (int i=0;i<N;i++)
        for (int j=1;j<N;j++)
        {
            tmp1=time[j-1];
            tmp2=time[j];
            if (tmp1>tmp2)
            {
                tmp1=score[j-1];
                tmp2=time[j-1];
                score[j-1]=score[j];
                time[j-1]=time[j];
                score[j]=tmp1;
                time[j]=tmp2;
            }
        }

    int flag[N];
    int counter=0;
    for (int i=0;i<N;i++)flag[i]=true;
    for (int i=1;i<N;i++)
        for (int j=0;j<i;j++)
        {
            if (score[j]>=score[i])
            {
                flag[i]=false;
                break;
            }
        }

    double *s,*t;
    s=new double[N];
    t=new double[N];

    for (int i=0;i<N;i++)
    {
        if (flag[i])
        {
            s[counter]=score[i];
            t[counter]=time[i];
            counter++;
        }
    }
    for (int i=0;i<counter;i++)
    {
        score[i]=s[i];
        time[i]=t[i];
    }

    N=counter;
}

void adjust_greedy(int M,int N,int start,double *score,double *time,int *number)
{
    int miniute;
    miniute=M;
    for (int n=start;n<N;n++)///initial
        number[n]=0;

    for (int i=start;i<N;i++)
    {
        int tmp=time[i];
        number[i]=miniute/tmp;
        miniute%=tmp;
        if (miniute==0)
        {
            flag=true;
            break;
        }
    }
}

void search_recursive(int M,int N,int start,double *score,double *time,int *number)
{
//    int hightmp;
//    if (T.search(M,start,hightmp))
//    {
//        highest=highest>hightmp?highest:hightmp;
//        return;
//    }

    adjust_greedy(M,N,start,score,time,number);
    int tmp=0;

    for (int i=0;i<N;i++)
        tmp+=score[i]*number[i];
    highest=highest>tmp?highest:tmp;

    if (!flag)
    {
        int max_num=number[start];
        for (int i=max_num;i>=0&&start<N-1;i--)
        {
            number[start]=i;
            search_recursive(M-i*time[start],N,start+1,score,time,number);
        }
    }
//
//    T.insert(M,start,hightmp);
}

void another_way(int M,int N,double *score,double *time)
{
    mark[0]=0;
    for (int minuite=1;minuite<=M;minuite++)
    {
        int high=0;
        int temp;
        for (int j=0;j<N;j++)
        {
            if (time[j]<=minuite)
            {
                int idx=minuite-time[j];
                temp=mark[idx]+score[j];
                high=temp>high?temp:high;
            }
        }
        mark[minuite]=high;
    }

}

int main()
{
//    ifstream fin("input.txt");
//    ofstream fout("output.txt");
    ifstream fin("inflate.in");
    ofstream fout("inflate.out");
    int M,N;
    fin>>M>>N;
    double score[N],time[N];
    int number[N];
    for (int i=0;i<N;i++)
        fin>>score[i]>>time[i];
    decrease_sort(score,time,N);


 //   search_recursive(M,N,0,score,time,number);
    another_way(M,N,score,time);



    cout<<mark[M]<<"\n";
    fout<<mark[M]<<"\n";


    return 0;

}
