/*
ID:thtfive
LANG:C++
TASK:comehome
*/
#include<fstream>
#include<iostream>
using namespace std;
int map[60][60];
bool flag[60];
bool mark[60];
int insideset[60];
int distant[60];
int total=0;
int insidecount;

int search_for_a_new_one()
{
    int result=-1;
    int value=999999999;
    for (int index=0;index<60;index++)
    {
        if (flag[index]&&mark[index]==false)
        {

            int valuetmp=999999999;
            for (int j=0;j<insidecount;j++)
            {
                if (map[insideset[j]][index]!=-1)
                {
                    if (valuetmp>map[insideset[j]][index]+distant[insideset[j]])
                    {
                        valuetmp=map[insideset[j]][index]+distant[insideset[j]];
                    }
                }
            }

            if(value>valuetmp)
            {
                value=valuetmp;
                result=index;
            }

        }
    }
    return result;
}

void addin(int index)
{
    if (index==-1)return;
    mark[index]=true;
    int idx;
    int mindistance=99999999;
    for (int i=0;i<insidecount;i++)
    {
        idx=insideset[i];
        if (map[idx][index]!=-1)
        {
            mindistance=mindistance<distant[idx]+map[idx][index]?mindistance:distant[idx]+map[idx][index];
        }
    }
    distant[index]=mindistance;
    insideset[insidecount]=index;
    insidecount++;
}

void addto()
{
    int index;
    while(1)
    {
        index=search_for_a_new_one();
        addin(index);
        if (index==-1)break;
    }
    return;
}

int main()
{
    ifstream fin("comehome.in");
    ofstream fout("comehome.out");

    int N;
    fin>>N;
    for (int i=0;i<60;i++)
        for (int j=0;j<60;j++)
            map[i][j]=-1;

    for (int i=0;i<60;i++)
    {
        flag[i]=false;
        mark[i]=false;
    }

    char ch1,ch2;
    int x,y;
    int length;
    for (int i=0;i<N;i++)
    {
        fin>>ch1>>ch2>>length;
        x=ch1-'A';
        y=ch2-'A';
        flag[x]=true;
        flag[y]=true;
        if (map[x][y]==-1)
        {
            map[x][y]=length;
            map[y][x]=length;
        }
        else
        {
            map[x][y]=map[x][y]<length?map[x][y]:length;
            map[y][x]=map[x][y];
        }
    }
    for (int i=0;i<60;i++)
    {
        distant[i]=0;
        if (flag[i]==true)total++;
    }

    insidecount=1;
    insideset[0]=25;///the place of barn
    mark[25]=true;

    int cow=0;
    int number=99999999;

    addto();

    for (int i=0;i<25;i++)
    {
        if (flag[i])
        {
            if(number>distant[i])
            {
                cow=i;
                number=distant[i];
            }
        }
    }



    string lib="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    cout<<lib[cow]<<" "<<number<<"\n";
    fout<<lib[cow]<<" "<<number<<"\n";


    return 0;
}
