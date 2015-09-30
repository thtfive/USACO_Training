/*
ID:thtfive
LANG:C++
TASK:maze1
*/
#include<iostream>
#include<fstream>
#include<queue>

using namespace std;
class Node
{
public:
    int x;
    int y;
    int len;
};

int main()
{
//    ifstream fin("maze1.in");
//    ofstream fout("maze1.out");
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    queue<Node>que;
    queue<Node>store;
    int W,H;
    fin>>W>>H;
    int width=2*W+1;
    int height=2*H+1;

    bool mark[H][W][4];
    int result[H][W][2];
    for (int i=0;i<H;i++)
        for (int j=0;j<W;j++)
        {
            result[i][j][0]=999999;
            result[i][j][1]=999999;
        }

    char map[height][width];

    fin>>noskipws;
    char str;

    int index_i=0,index_j=-1;

    while(!fin.eof())
    {
        fin>>str;
        if (str!='\n')
        {
             index_j++;
             if (index_j==width)
             {
                 index_j=0;
                 index_i++;
                 if (index_i>=height)break;
             }
             map[index_i][index_j]=str;
//             cout<<index_i<<" "<<index_j<<" "<<map[index_i][index_j]-'!'<<"\n";
        }
    }
    for (int i=0;i<H;i++)
        for (int j=0;j<W;j++)
            for (int k=0;k<4;k++)
                mark[i][j][k]=false;

    for (int i=0;i<H;i++)
        for (int j=0;j<W;j++)
        {
            if (map[2*i+1][j*2]==' ')
            {
                mark[i][j][0]=true;///to west
                if (j==0)
                {
                    Node tmp;
                    tmp.x=i;
                    tmp.y=j;
                    tmp.len=1;
                    store.push(tmp);
                }
            }
            if (map[2*i][j*2+1]==' ')
            {
                mark[i][j][1]=true;///to north
                if (i==0)
                {
                    Node tmp;
                    tmp.x=i;
                    tmp.y=j;
                    tmp.len=1;
                    store.push(tmp);
                }
            }
            if (map[2*i+1][j*2+2]==' ')
            {
                mark[i][j][2]=true;
                if (j==W-1)
                {
                    Node tmp;
                    tmp.x=i;
                    tmp.y=j;
                    tmp.len=1;
                    store.push(tmp);
                }
            }
            if (map[2*i+2][j*2+1]==' ')
            {
                mark[i][j][3]=true;
                if (i==H-1)
                {
                    Node tmp;
                    tmp.x=i;
                    tmp.y=j;
                    tmp.len=1;
                    store.push(tmp);
                }
            }
        }

    bool record[H][W];

    int index=-1;

    while (!store.empty())
    {
        index++;
        Node node=store.front();
        store.pop();

        que.push(node);

        int xtmp,ytmp,lentmp;
        Node nodetmp;


        for (int i=0;i<H;i++)
        for (int j=0;j<W;j++)
            record[i][j]=0;   ///used to identify those have been in the que
        record[node.x][node.y]=1;
        while(!que.empty())
        {
            nodetmp=que.front();
            que.pop();
            xtmp=nodetmp.x;
            ytmp=nodetmp.y;
            lentmp=nodetmp.len;
            result[xtmp][ytmp][index]=lentmp;

            if (mark[xtmp][ytmp][0])
            {
                if (ytmp-1>=0&&record[xtmp][ytmp-1]==0)
                {
                    Node ins;
                    ins.x=xtmp;
                    ins.y=ytmp-1;
                    ins.len=lentmp+1;
                    record[ins.x][ins.y]=1;
                    que.push(ins);
                }
            }

            if (mark[xtmp][ytmp][1])
            {
                if (xtmp-1>=0&&record[xtmp-1][ytmp]==0)
                {
                    Node ins;
                    ins.x=xtmp-1;
                    ins.y=ytmp;
                    ins.len=lentmp+1;
                    record[ins.x][ins.y]=1;
                    que.push(ins);

                }
            }

            if (mark[xtmp][ytmp][2])
            {
                if (ytmp+1<W&&record[xtmp][ytmp+1]==0)
                {
                    Node ins;
                    ins.x=xtmp;
                    ins.y=ytmp+1;
                    ins.len=lentmp+1;
                    record[ins.x][ins.y]=1;
                    que.push(ins);
                }

            }
            if (mark[xtmp][ytmp][3])
            {
                if (xtmp+1<H&&record[xtmp+1][ytmp]==0)
                {
                    result[xtmp][ytmp][index]=lentmp;
                    Node ins;
                    ins.x=xtmp+1;
                    ins.y=ytmp;
                    ins.len=lentmp+1;
                    record[ins.x][ins.y]=1;
                    que.push(ins);
                }
            }
        }
    }

    int minlen=99999;
    int worst=0;
    for (int i=0;i<H;i++)
    {
        for (int j=0;j<W;j++)
        {
            minlen=result[i][j][0]<result[i][j][1]?result[i][j][0]:result[i][j][1];
            worst=worst>minlen?worst:minlen;
        }
    }


    cout<<worst<<endl;
    fout<<worst<<endl;


    return 0;
}
