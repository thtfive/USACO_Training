/*
ID:thtfive
LANG:C++
TASK:humble
*/
#include<iostream>
#include<fstream>
using namespace std;
int lib[101];
int K;
int N;


void decrease_sort(int*p,int N)
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

int search_index_initial(int start,int finish,int &mid,int number,int *humble)
{
    mid=(start+finish)/2;
    int length=finish;
    int temp=humble[finish]/number;
    while(finish>start+1)
    {
        if (temp<humble[mid])
        {
            finish=mid;
        }
        else
        {
            start=mid;
        }
        mid=(start+finish)/2;
    }

//    cout<<number*humble[finish]<<"\n";
    int result=number*humble[start];
    if (result>humble[length])
    {
        return result;
    }
    else
    {
        return number*humble[finish];
    }
}


int search_index(int start,int finish,int current,int &mid,int number,int *humble)
{
    mid=(start+finish)/2;
    int temp=humble[current]/number;
    while(finish>start+1)
    {
        if (temp<humble[mid])
        {
            finish=mid;
        }
        else
        {
            start=mid;
        }
        mid=(start+finish)/2;
    }

//    cout<<number*humble[finish]<<"\n";
    mid=finish;
    return number*humble[finish];

}

int main()
{
//    ifstream fin("input.txt");
//    ofstream fout("output.txt");
    ifstream fin("humble.in");
    ofstream fout("humble.out");

    fin>>K>>N;


    for (int i=0;i<K;i++)
        fin>>lib[i];
    decrease_sort(lib,K);

//    int restrain[K];
//    for (int i=0;i<K;i++)restrain[i]=0;
//
//    for (int i=0;i<K;i++)
//    {
//        int tmp=lib[i];
//        while (tmp!=0)
//        {
//            tmp/=lib[0];
//            restrain[i]++;
//        }
//    }
//    restrain[0]=1;



//    for (int i=0;i<K;i++)cout<<restrain[i]<<" ";

    int humble[N+1];
//    for (int i=1;i<=N;i++)
//        humble[i]=0;
    humble[0]=1;


//    for(int i=1;i<=N;i++)
//    {
//        int number=humble[i-1];
//        int flag=false;
//        while (!flag)
//        {
//            number++;
//            flag=judge(number);
//        }
//        humble[i]=number;
//    }
    int first;
    for (first=1;first<=N;first++)
    {
        int min_num=2147483640;
        int start=0;
        int mid=start;
        int finish=first-1;
        int tmp;
        for (int j=K-1;j>=0;j--)///for lib
        {
            tmp=search_index_initial(start,finish,mid,lib[j],humble);
            min_num=min_num<tmp?min_num:tmp;
        }
        humble[first]=min_num;
        if(humble[first]==lib[0])
        {
            break;
        }
    }




    for (int current=first+1;current<=N;current++)
    {
        int min_num=2147483640;
        int start=0;
        int mid=start;
        int finish=current-1;
        int tmp;
        for (int j=K-1;j>=0;j--)///for lib
        {
            tmp=search_index(start,finish,current-1,mid,lib[j],humble);
            min_num=min_num<tmp?min_num:tmp;
            finish=mid;
            if (min_num==humble[current-1]+1)break;
        }
        humble[current]=min_num;
    }

//    for (int current=1;current<=N;current++)
//        cout<<humble[current]<<"\n";

//    for (int i=1;i<=N;i++)
//        cout<<humble[i]<<" ";
//    for (int i=0;i<=N;i++)
//    cout<<humble[i]<<"\n";
    cout<<humble[N]<<"\n";
    fout<<humble[N]<<"\n";

    return 0;
}
