/*
ID:thtfive
LANG:C++
TASK:fence
*/
#include<iostream>
#include<fstream>
#include<stack>
using namespace std;
int flag[501][501];
int adjacent[501][501];
stack <int> st;
int circuit_position;

void find_circuit(int start)
{
  //  cout<<start<<endl;
    bool have_neighbor=false;
    for (int idx=1;idx<=adjacent[start][0];idx++)
    {
        int place=adjacent[start][idx];
        if (flag[start][place]>0)
        {
            have_neighbor=true;
            break;
        }
    }
    if(!have_neighbor)
    {
        circuit_position++;
        st.push(start);
    }
    else
    {
        int idx=1;
        while(idx<=adjacent[start][0])
        {
            int place=adjacent[start][idx];
            if(flag[start][place]>0)
            {
                flag[start][place]--;
                flag[place][start]--;
                find_circuit(place);
            }
            idx++;
        }
        st.push(start);
        circuit_position++;
    }
}

int partition(int *array,int p,int q)
{
    int i=p-1;
    for (int j=p;j<q;j++)
    {
        if(array[j]<array[q])
        {
            i++;
            int tmp=array[j];
            array[j]=array[i];
            array[i]=tmp;
        }
    }
    int tmp=array[q];
    array[q]=array[i+1];
    array[i+1]=tmp;
    return i+1;
}


void quick_sort(int *array,int start,int end)
{
    if (start<end)
    {
        int mid=partition(array,start,end);
        quick_sort(array,start,mid-1);
        quick_sort(array,mid+1,end);
    }
}

int main()
{
    circuit_position=0;
    for(int i=0;i<=500;i++)
        for (int j=0;j<=500;j++)
        {
            adjacent[i][j]=0;
            flag[i][j]=0;
        }


    ifstream fin("fence.in");
    ofstream fout("fence.out");
    int F;
    int tmp1,tmp2;
    fin>>F;

    for (int i=1;i<=F;i++)
    {
        fin>>tmp1>>tmp2;
        adjacent[tmp1][0]++;
        adjacent[tmp2][0]++;
        adjacent[tmp1][adjacent[tmp1][0]]=tmp2;
        adjacent[tmp2][adjacent[tmp2][0]]=tmp1;
        flag[tmp1][tmp2]++;
        flag[tmp2][tmp1]++;
    }
///find the start point
    int start=0;
    for (int i=1;i<=500;i++)
    {
        if (adjacent[i][0]>1&&start==0)start=i;
        if (adjacent[i][0]%2==1){start=i;break;}
    }
    for (int i=1;i<=500;i++)
    {
        quick_sort(adjacent[i],1,adjacent[i][0]);
    }


    find_circuit(start);
    while(!st.empty())
    {
        fout<<st.top()<<"\n";
        st.pop();
    }



//    int data[4];
//    data[0]=3;data[1]=5;data[2]=0;data[3]=1;
////    quick_sort(data,0,3);
////    for(int i=0;i<=3;i++)cout<<data[i]<<"   data\n";
   // cout<<start<<"\n";




    return 0;
}
