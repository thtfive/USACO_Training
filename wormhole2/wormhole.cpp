/*
ID:thtfive
LANG:C++
TASK:wormhole
*/
#include<iostream>
using namespace std;
#include<fstream>
///利用回溯法列出所有可能，然后对所有可能进行测试
///此种方法可行性有待商榷


int main()
{
    ifstream fin("wormhole.in");
    ofstream fout("wormhole.out");
    int Num;
    int counter=0;
    int y_level=1;
    int result=0;
    fin>>Num;
    int Hole[Num][2];
    for (int i=0;i<Num;i++)fin>>Hole[i][0]>>Hole[i][1];

    int y[Num];
    int same_y[Num];
    y[0]=Hole[0][1];
    same_y[0]=1;
    for (int i=1;i<Num;i++)
    {
        bool add_y_flag=true;
        for (int j=0;j<y_level;j++)
        {
            if (Hole[i][1]==y[j])
            {
                same_y[j]++;
                add_y_flag=false;
            }
        }
        if (add_y_flag)
        {
            y[y_level]=Hole[i][1];
            same_y[y_level]=1;
            y_level++;
        }
    }
    cout<<y_level<<"\n";
    for (int i=0;i<y_level;i++)cout<<y[i]<<":"<<same_y[i]<<" ; ";

   // int it=0;


    fout<<result<<"\n";
    //cout<<result;

    return 0;
}
