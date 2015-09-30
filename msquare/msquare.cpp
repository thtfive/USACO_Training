/*
ID:thtfive
LANG:C++
TASK:msquare
*/
#include<iostream>
#include<fstream>
#include<queue>
#include<cmath>
using namespace std;

bool mark[2100000];
int Findex;
int Iindex;
bool flag=false;


int Dmultiply(int num)
{
    int result=1;
    if(num==0)return 1;
    while(num!=0)
    {
        result*=8;
        num--;
    }
    return result;
}

int index_count(int (*array)[4])
{
    int num=0;
    int index=0;
    for (num=0;num<7;num++)
    {
        int x=num/4,y=num%4;
        index+=(array[x][y]-1)*Dmultiply(num);
    }
    return index;
}

void transformA(int (*array)[4],int (*dest)[4])
{
    for (int i=0;i<2;i++)
        for (int j=0;j<4;j++)
            dest[i][j]=array[(i+1)%2][j];
}
void transformB(int (*array)[4],int (*dest)[4])
{
    for (int i=0;i<2;i++)
        for (int j=0;j<4;j++)
            dest[i][j]=array[i][(j+3)%4];
}
void transformC(int (*array)[4],int (*dest)[4])
{
    for (int i=0;i<2;i++)
        for (int j=0;j<4;j++)
            dest[i][j]=array[i][j];
    dest[0][1]=array[1][1];
    dest[0][2]=array[0][1];
    dest[1][1]=array[1][2];
    dest[1][2]=array[0][2];
}



void retransformA(int (*array)[4],int (*dest)[4])
{
    for (int i=0;i<2;i++)
        for (int j=0;j<4;j++)
            dest[i][j]=array[(i+1)%2][j];
}
void retransformB(int (*array)[4],int (*dest)[4])
{
    for (int i=0;i<2;i++)
        for (int j=0;j<4;j++)
            dest[i][j]=array[i][(j+1)%4];
}
void retransformC(int (*array)[4],int (*dest)[4])
{
    for (int i=0;i<2;i++)
        for (int j=0;j<4;j++)
            dest[i][j]=array[i][j];
    dest[1][1]=array[0][1];
    dest[0][1]=array[0][2];
    dest[1][2]=array[1][1];
    dest[0][2]=array[1][2];
}


class Node
{
public:
    int data[2][4];
    int counter;
    string steps;
};

queue<Node>que;

int solution(int (*Iarray)[4],string &steps)
{
    Node start;
    for (int i=0;i<2;i++)
        for (int j=0;j<4;j++)
            start.data[i][j]=Iarray[i][j];
    start.counter=0;
    start.steps="";
    que.push(start);
    int index=index_count(start.data);
    if(index==Findex)
    {
        steps="";
        return 0;
    }
    mark[index]=true;
    int result;
    while(!que.empty())
    {
        Node poparray=que.front();
        que.pop();
        Node tmp;
        string strtmp=poparray.steps;
        tmp.counter=poparray.counter+1;

        transformA(poparray.data,tmp.data);
        index=index_count(tmp.data);
        if (index==Findex)
        {
            result=tmp.counter;
            steps=strtmp+"A";
            break;
        }
        if (mark[index]==false)
        {
            mark[index]=true;
            tmp.steps=strtmp+"A";
            que.push(tmp);
        }

        transformB(poparray.data,tmp.data);
        index=index_count(tmp.data);
        if (index==Findex)
        {
            result=tmp.counter;
            steps=strtmp+"B";
            break;
        }
        if (mark[index]==false)
        {
            mark[index]=true;
            tmp.steps=strtmp+"B";
            que.push(tmp);
        }

        transformC(poparray.data,tmp.data);
        index=index_count(tmp.data);
        if (index==Findex)
        {
            result=tmp.counter;
            steps=strtmp+"C";
            break;
        }
        if (mark[index]==false)
        {
            mark[index]=true;
            tmp.steps=strtmp+"C";
            que.push(tmp);
        }
    }
    return result;
}


int main()
{
    ifstream fin("msquare.in");
    ofstream fout("msquare.out");

    for (int i=0;i<2100000;i++)
    {
        mark[i]=false;
    }

    int Iarray[2][4];
    int Farray[2][4];
    int num=0;
    //Findex=index_count(Farray);

    for(int j=0;j<4;j++)
    {
        num++;
        Iarray[0][j]=num;
        fin>>Farray[0][j];
    }
    for(int j=3;j>=0;j--)
    {
        num++;
        Iarray[1][j]=num;
        fin>>Farray[1][j];
    }

    Iindex=index_count(Iarray);
    Findex=index_count(Farray);


    string steps="";
    int result=solution(Iarray,steps);

//    cout<<result<<": "<<steps<<endl;
//
//    int tmp1[2][4];
//    int tmp2[2][4];
//    int tmp3[2][4];
//    int tmp4[2][4];
//    int tmp5[2][4];
//    int tmp6[2][4];
//    int tmp7[2][4];
//    transformB(Iarray,tmp1);
//    transformC(tmp1,tmp2);
//    transformA(tmp2,tmp3);
//    transformB(tmp3,tmp4);
//    transformC(tmp4,tmp5);
//    transformC(tmp5,tmp6);
//    transformB(tmp6,tmp7);


//    for(int i=0;i<2;i++)
//    {
//        for(int j=0;j<4;j++)
//            cout<<Farray[i][j]<<" ";
//            cout<<endl;
//    }
//
//    for(int i=0;i<2;i++)
//    {
//        for(int j=0;j<4;j++)
//            cout<<tmp7[i][j]<<" ";
//            cout<<endl;
//    }
//
//
//    cout<<endl;

    fout<<result;
    int length=steps.length();
    int idx=0;
    while(idx<length)
    {
        if(idx%60==0)fout<<"\n";
        fout<<steps[idx];
        idx++;
    }
    if(length==0)fout<<"\n";
    fout<<"\n";


//    retransformA(Iarray,Farray);

//    cout<<endl;
//    retransformB(Iarray,Farray);
//    for(int i=0;i<2;i++)
//    {
//        for(int j=0;j<4;j++)
//            cout<<Farray[i][j]<<" ";
//            cout<<endl;
//    }
//    cout<<endl;
//    retransformC(Iarray,Farray);
//    for(int i=0;i<2;i++)
//    {
//        for(int j=0;j<4;j++)
//            cout<<Farray[i][j]<<" ";
//            cout<<endl;
//    }
//    int index=index_count(Farray);
//    mark[index]=0;

    //solution(Farray);


//    cout<<index_count(Farray)<<endl;


    return 0;

}
