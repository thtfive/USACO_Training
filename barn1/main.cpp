/*
ID:thtfive
LANG:C++
TASK:barn1
*/
#include<iostream>
using namespace std;
#include<fstream>


int main()
{
    int supply_num,total_num,need_num;
    int result;
    ifstream fin("barn1.in");
    ofstream fout("barn1.out");

    fin>>supply_num>>total_num>>need_num;
    int repair[need_num];
    for (int i=0;i<need_num;i++)fin>>repair[i];

    int temp;
    for (int i=0;i<need_num;i++)
    {
        for (int j=1;j<need_num;j++)
        {
            if (repair[j-1]>repair[j])
            {
                temp=repair[j-1];
                repair[j-1]=repair[j];
                repair[j]=temp;
            }
        }
    }

    if (supply_num>need_num)supply_num=need_num;


    result=repair[need_num-1]-repair[0]+1;


    for (int i=0;i<need_num-1;i++)repair[i]=repair[i+1]-repair[i];

    int num=need_num-1;
    int tmp;
    for (int i=0;i<num;i++)
    {
        for (int j=1;j<num;j++)
        {
            if (repair[j-1]<repair[j])
            {
                tmp=repair[j-1];
                repair[j-1]=repair[j];
                repair[j]=tmp;
            }
        }
    }

    for (int i=0;i<need_num-1;i++)cout<<repair[i]<<" ";
    cout<<endl<<result<<endl;

    for (int i=0;i<supply_num-1;i++)result=result-repair[i]+1;


    fout<<result<<"\n";

    return 0;
}
