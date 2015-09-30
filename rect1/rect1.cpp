/*
ID:thtfive
LANG:C++
TASK:rect1
*/
#include<iostream>
#include<fstream>
using namespace std;
class Edge
{
public:
    int x;
    int y;
    Edge *next;
    Edge()
    {
        next=NULL;
    }
};

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int A,B,N;
    fin>>A>>B>>N;
    int color[N+2];
    for (int i=0;i<N+2;i++)
        color[i]=0;

    int rects[N][5];
    for (int i=0;i<N;i++)
    {
        for (int j=0;j<5;j++)
            fin>>rects[i][j];
    }



    for (int i=N-1;i>=0;i--)
    {
        int rect[5];
        for (int j=0;j<5;j++)///for every rectangle
            rect[j]=rects[i][j];

        Edge *ll,*lh,*rl,*rh;
        ll=NULL;
        lh=NULL;
        rl=NULL;
        rh=NULL;

        for (int k=i+1;k<N;k++)
        {


        }

    }




}
