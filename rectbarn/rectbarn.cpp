/*
ID:thtfive
LANG:C++
TASK:rectbarn
*/
#include<iostream>
#include<fstream>
#include<stack>
#include<cstring>
#include<algorithm>

///����һ��ջ�洢ĳһ�е����ĸ߶�
///�������һ���µĸ߶�С��ջ���ĸ߶ȣ����ջ�������ݵ������������Ե���������߶�Ϊ�Ҳ�ߵľ������
///ע�⣺���εĿ�ȵļ��㣺
///    if(s.empty())
///        area=(c-index)*height[index];
///    else
///        area=(c-(s.top()+1))*height[index];

using namespace std;
ifstream fin("rectbarn.in");
ofstream fout("rectbarn.out");

int M,N,badNum;
int height[3010];
int broken[30010][2];
int result;

void init()
{
    fin>>M>>N>>badNum;
    memset(height,0,sizeof(height));
    for(int i=1;i<=badNum;i++)
        fin>>broken[i][0]>>broken[i][1];
}

int quickpart(int start,int finish)
{
    int mid=start-1;
    for(int idx=start;idx<finish;idx++)
    {
        if(broken[idx][0]<broken[finish][0]||(broken[idx][0]==broken[finish][0]&&broken[idx][1]<broken[finish][1]))
        {
            mid++;
            int tmp0=broken[idx][0];
            int tmp1=broken[idx][1];
            broken[idx][0]=broken[mid][0];
            broken[idx][1]=broken[mid][1];
            broken[mid][0]=tmp0;
            broken[mid][1]=tmp1;
        }
    }
    mid++;
    int tmp0=broken[finish][0];
    int tmp1=broken[finish][1];
    broken[finish][0]=broken[mid][0];
    broken[finish][1]=broken[mid][1];
    broken[mid][0]=tmp0;
    broken[mid][1]=tmp1;
    return mid;
}

void quicksort(int start,int finish)
{
    if(start<finish)
    {
        int mid=quickpart(start,finish);
        quicksort(start,mid-1);
        quicksort(mid+1,finish);
    }
}

void solution()
{
    quicksort(1,badNum);
    int index=1;

    height[N+1]=-1;

    for(int R=1;R<=M;R++)
    {
        for(int c=1;c<=N;c++)
            height[c]++;


        for(;broken[index][0]==R;index++)
        {
            height[broken[index][1]]=0;
        }
//        for(int c=1;c<=N;c++)
//            cout<<height[c]<<" ";
//        cout<<"\n";
        stack<int> s;
        for(int c=1;c<=N+1;c++)
        {
            if(s.empty())
            {
                s.push(c);
            }
            else
            {
                while(!s.empty()&&height[s.top()]>height[c])
                {
                    int index=s.top();
                    s.pop();
                    int area;
                    if(s.empty())
                        area=(c-index)*height[index];
                    else
                        area=(c-(s.top()+1))*height[index];///��������Ҫ�����ջ�л������ݣ������Ŀ����(c-(s.top()+1))������ȷ��s.top()+1..index-1�ĸ߶��Ǹ���height[index],�������Ƕ�������ջ��
                    result=max(result,area);
                }
                s.push(c);
            }
        }
    }
}

void print()
{
    cout<<result<<"\n";
    fout<<result<<"\n";
}
int main()
{
    init();
    solution();
    print();
}
