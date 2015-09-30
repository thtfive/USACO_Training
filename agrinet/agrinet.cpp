/*
ID:thtfive
LANG:C++
TASK:agrinet
*/
#include<iostream>
#include<fstream>

using namespace std;
#define max_num 100
int map[max_num][max_num];

void Prim(int treesize,bool *intree,int *tree,int *distant,int graphsize)
{
    while(treesize<graphsize)
    {
        int mindistance=999999999;
        int place;
        for (int i=0;i<treesize;i++)
        {
            for (int j=1;j<graphsize;j++)
            {
                if (intree[j]==false)
                {
                    if (mindistance>map[tree[i]][j])
                    {
                        mindistance=map[tree[i]][j];
                        place=j;
                    }
                }

            }
        }
        intree[place]=true;
        tree[treesize]=place;
        distant[treesize]=mindistance;
        treesize++;
    }
}

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int N;
    fin>>N;
    for (int i=0;i<N;i++)
        for (int j=0;j<N;j++)
            fin>>map[i][j];

    bool intree[N];
    int tree[N];
    int treesize=0;
    int distant[N];
    for (int i=0;i<N;i++)
    {
        intree[i]=false;
        distant[i]=0;
    }

    tree[0]=0;///set 0 as the source
    treesize=1;
    intree[0]=true;

    Prim(treesize,intree,tree,distant,N);

    int mincount=0;
    for (int i=0;i<N;i++)
        mincount+=distant[i];
    cout<<mincount<<"\n";
    fout<<mincount<<"\n";
    return 0;
}
