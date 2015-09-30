/*
ID:thtfive
LANG:C++
TASK:sort3
*/

#include<fstream>
#include<iostream>
using namespace std;
void ascend_sort(int *num,int N)
{
    int tmp;
    for (int i=0;i<N;i++)
        for (int j=1;j<N-i;j++)
        {
            if(num[j-1]>num[j])
            {
                tmp=num[j-1];
                num[j-1]=num[j];
                num[j]=tmp;
            }
        }
}

int main()
{
    ifstream fin("sort3.in");
    ofstream fout("sort3.out");
    int N,counter=0;
    fin>>N;
    int num[N],num2[N];
    for (int i=0;i<N;i++)
    {
        fin>>num[i];
        num2[i]=num[i];
    }

    ascend_sort(num2,N);
    int counter1=0,counter2=0,counter3=0;

    for (int i=0;i<N;i++)
    {
        if(num[i]==3)num[i]=4;
        if(num2[i]==3)num2[i]=4;
    }

    for (int i=0;i<N;i++)
    {
        if(num[i]!=num2[i])counter++;
        switch(num[i])
        {
            case 1: counter1++;break;
            case 2: counter2++;break;
            case 3: counter3++;break;
        }
    }

    int tmp[N];
    for (int i=0;i<N;i++)
    {
        tmp[i]=num[i]-num2[i];
    }
    int counter_1=0,counter_2=0,counter_3=0,counterp1=0,counter0=0,counterp2=0,counterp3=0;
    for (int i=0;i<N;i++)
    {
         switch(tmp[i])
        {
            case -1:counter_1++;break;
            case -2:counter_2++;break;
            case -3:counter_3++;break;
            case 0:counter0++;break;
            case 1: counterp1++;break;
            case 2: counterp2++;break;
            case 3: counterp3++;break;
        }
    }
    int reg1,reg2,reg3;
    if(counterp1-counter_1>0)reg1=counterp1-counter_1;
    else reg1=counter_1-counterp1;
    if(counterp2-counter_2>0)reg2=counterp2-counter_2;
    else reg2=counter_2-counterp2;

    if(counterp3-counter_3>0)reg3=counterp3-counter_3;
    else reg3=counter_3-counterp3;

    counter=(counter+1)/2;
    cout<<reg1<<" "<<reg2<<" "<<reg3<<endl;
    if (reg1==2&&reg2==2&&reg3==2)counter++;


    fout<<counter<<"\n";

    return 0;
}
