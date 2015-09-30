/*
ID:thtfive
LANG:C++
TASK:skidesign
*/
#include<iostream>
using namespace std;
#include<fstream>

int max_height(int p[],int num)///
{
    int tmp=p[0];
    for (int i=1;i<num;i++)
    {
        if(tmp<p[i])tmp=p[i];
    }
    return tmp;
}
int min_height(int p[],int num)///used for sort in ascend sequence
{
    int tmp=p[0];
    for (int i=1;i<num;i++)
    {
        if(tmp>p[i])tmp=p[i];
    }
    return tmp;
}

int MoneyCaculate(int p[],int min,int max,int num)
{
    int money=0;
    for (int i=0;i<num;i++)
    {
        if (p[i]<min)money+=(min-p[i])*(min-p[i]);
        if (p[i]>max)money+=(p[i]-max)*(p[i]-max);
    }
    return money;
}

int main()
{
    ifstream fin("skidesign.in");
    ofstream fout("skidesign.out");
    int NumOfHill;
    int Money=0;
    fin>>NumOfHill;
    int Height[NumOfHill];
    for(int i=0;i<NumOfHill;i++)fin>>Height[i];

    int maxHeight=max_height(Height,NumOfHill);
    int minHeight=min_height(Height,NumOfHill);

    cout<<maxHeight<<" "<<minHeight<<endl;

    if ((maxHeight-minHeight)>17)
    {
        int tmp;
        Money=MoneyCaculate(Height,minHeight,minHeight+17,NumOfHill);
        for (minHeight++;minHeight+17<=maxHeight;minHeight++)
        {
            tmp=MoneyCaculate(Height,minHeight,minHeight+17,NumOfHill);
            if (tmp<Money)Money=tmp;
        }
    }
    fout<<Money<<"\n";
    cout<<Money<<"\n";
    return 0;
}
