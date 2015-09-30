/*
ID:thtfive
LANG:C++
TASK:milk4
*/
#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;
int record[20001][101];

int partition(int *array,int start,int finish)
{
    int mid=start-1;
    for(int idx=start;idx<finish;idx++)
    {
        if(array[idx]<array[finish])
        {
            mid++;
            int tmp=array[mid];
            array[mid]=array[idx];
            array[idx]=tmp;
        }
    }
    mid++;
    int tmp=array[mid];
    array[mid]=array[finish];
    array[finish]=tmp;
    return mid;
}

void quicksort(int *array,int start,int finish)
{
    if(start<finish)
    {
        int mid=partition(array,start,finish);
        quicksort(array,start,mid-1);
        quicksort(array,mid+1,finish);
    }
}

int main()
{
    int Q,P;
    ifstream fin("milk4.in");
    ofstream fout("milk4.out");
    fin>>Q>>P;
    int pails[P];
    for(int i=0;i<P;i++)
        fin>>pails[i];

    quicksort(pails,0,P-1);

    bool mark[Q+1];
    memset(mark,false,sizeof(mark));
    memset(record,0,sizeof(record));
    mark[0]=true;


    bool sign=false;
    for(int p=0;p<P&&!sign;p++)
    {
        for(int q=1;q<=Q&&!sign;q++)
        {
            int rest=q-pails[p];
            int numtmp=101;
            int place;
            while(rest>=0)
            {
                bool flag=false;
                if(mark[rest]&&record[rest][0]<numtmp)
                {
                    flag=true;
                }
                else
                {
                    if(record[rest][0]==numtmp)
                    {
                        for(int i=1;i<=numtmp;i++)
                        {
                            if(record[rest][i]<record[place][i])
                            {
                                flag=true;
                                break;
                            }
                            if(record[rest][i]>record[place][i])
                            {
                                flag=false;
                                break;
                            }
                        }
                    }
                }
                if(flag)
                {
                    numtmp=record[rest][0];
                    place=rest;
                }
                rest-=pails[p];
            }

            if(numtmp<101)
            {
                if(!mark[q])
                {
                    mark[q]=true;
                    record[q][0]=numtmp+1;
                    for(int i=1;i<=numtmp;i++)
                        record[q][i]=record[place][i];
                    record[q][numtmp+1]=pails[p];
                }
                else
                {
                    bool flag=false;
                    if(numtmp==record[q][0]-1)
                    {
                        for(int i=1;i<=numtmp;i++)
                        {
                            if(record[q][i]>record[place][i])
                            {
                                flag=true;
                                break;
                            }
                            if(record[q][i]<record[place][i])
                            {
                                flag=false;
                                break;
                            }
                        }
                        if(flag)
                        {
                            record[q][0]=numtmp+1;
                            for(int i=1;i<=numtmp;i++)
                                record[q][i]=record[place][i];
                            record[q][numtmp+1]=pails[p];
                        }
                    }


                }
            }
        }
    }


    fout<<record[Q][0];
    cout<<record[Q][0];

    for(int i=1;i<=record[Q][0];i++)
    {
        cout<<" "<<record[Q][i];
        fout<<" "<<record[Q][i];
    }

    fout<<"\n";
    return 0;
}
