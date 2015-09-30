/*
ID:thtfive
LANG:C++
TASK:lgame
*/
#include<iostream>
#include<fstream>
using namespace std;
string strlib[5041];
string longstrlib[35000];
int cut[35000];
int value(string str)
{
    int len=str.length();
    int result=0;
    for(int i=0;i<len;i++)
    {
        switch(str[i]-'a')
        {
            case 0:result+=2;break;
            case 1:result+=5;break;
            case 2:result+=4;break;
            case 3:result+=4;break;
            case 4:result+=1;break;
            case 5:result+=6;break;
            case 6:result+=5;break;
            case 7:result+=5;break;
            case 8:result+=1;break;
            case 9:result+=7;break;
            case 10:result+=6;break;
            case 11:result+=3;break;
            case 12:result+=5;break;
            case 13:result+=2;break;
            case 14:result+=3;break;
            case 15:result+=5;break;
            case 16:result+=7;break;
            case 17:result+=2;break;
            case 18:result+=1;break;
            case 19:result+=2;break;
            case 20:result+=4;break;
            case 21:result+=6;break;
            case 22:result+=6;break;
            case 23:result+=7;break;
            case 24:result+=5;break;
            case 25:result+=7;break;
        }
    }
    return result;
}

bool search(string strforcheck,string str,int &N)
{
    int length=strforcheck.length();
    int len=str.length();
    if(length>len)return false;
    bool mark=false;
    bool flag[len];
    for(int i=0;i<len;i++)
        flag[i]=false;

    for(int i=0;i<length;i++)
    {
        char ch=strforcheck[i];
        mark=false;
        for(int j=0;j<len;j++)
        {
            if(ch==str[j]&&!flag[j])
            {
                flag[j]=true;
                mark=true;
                break;
            }
        }
        if (!mark)break;
    }
    if(mark)
    {
        strlib[N++]=strforcheck;
    }
    return mark;
}

int assemble(string str,int N)
{
    int newN=0;
    int len=str.length();
    for(int i=0;i<N;i++)
    {
        int  length=strlib[i].length();
        if(length==len)
        {
            longstrlib[newN]=strlib[i];
            cut[newN]=0;
            newN++;
        }
        else
        {
            longstrlib[newN]=strlib[i];
            cut[newN]=0;
            newN++;
            for(int j=i;j<N;j++)
            {
                int newlen=strlib[j].length();
                if(newlen+length>len)continue;
                bool flag[len];
                for(int m=0;m<len;m++)
                    flag[m]=false;
                bool mark=false;
                string strtmp=strlib[i]+strlib[j];
                int l=strtmp.length();
                for(int k=0;k<l;k++)
                {
                    char ch=strtmp[k];
                    mark=false;
                    for(int n=0;n<len;n++)
                    {
                        if(ch==str[n]&&!flag[n])
                        {
                            flag[n]=true;
                            mark=true;
                            break;
                        }
                    }
                    if (!mark)break;
                }
                if(mark)
                {
                    longstrlib[newN]=strtmp;
                    cut[newN]=length;
                    newN++;
                }
            }
        }
    }
    return newN;
}
int partition(int *values,int start,int finish)
{
    int mid=start-1;
    for(int idx=start;idx<finish;idx++)
    {
        bool flag=false;
        if(values[idx]>values[finish])
        {
            flag=true;
        }
        else
        if(values[idx]==values[finish])
        {
            int len1=longstrlib[idx].length();
            int len2=longstrlib[finish].length();
            int len=len1<len2?len1:len2;
            for(int i=0;i<len;i++)
            {
                if((longstrlib[idx][i]-'a')<(longstrlib[finish][i]-'a'))
                {
                    flag=true;
                    break;
                }
            }
        }
        if(flag)
        {
            mid++;
            int tmp=values[mid];
            values[mid]=values[idx];
            values[idx]=tmp;
            string strtmp=longstrlib[mid];
            longstrlib[mid]=longstrlib[idx];
            longstrlib[idx]=strtmp;
            tmp=cut[mid];
            cut[mid]=cut[idx];
            cut[idx]=tmp;
        }
    }
    mid++;
    int tmp=values[mid];
    values[mid]=values[finish];
    values[finish]=tmp;
    string strtmp=longstrlib[mid];
    longstrlib[mid]=longstrlib[finish];
    longstrlib[finish]=strtmp;
    tmp=cut[mid];
    cut[mid]=cut[finish];
    cut[finish]=tmp;
    return mid;
}


void descendsort(int *values,int start,int finish)
{
    if(start<finish)
    {
        int mid=partition(values,start,finish);
        descendsort(values,start,mid-1);
        descendsort(values,mid+1,finish);
    }
}

int main()
{
    ifstream fin("lgame.in");
    ifstream dict("lgame.dict");
    ofstream fout("lgame.out");
    string str;
    string strdict[40001];
    int N=0;
    int dictN=0;
    fin>>str;
    string strtmp;

    while(true)
    {
        dict>>strtmp;
        if(strtmp==".")break;
        strdict[dictN++]=strtmp;
    }

    for(int i=0;i<dictN;i++)
    {
        search(strdict[i],str,N);
    }


    int newN=0;
    newN=assemble(str,N);

    int values[newN];
    for(int i=0;i<newN;i++)
    {
        values[i]=value(longstrlib[i]);
    }

    int len=str.length();
    descendsort(values,0,newN-1);
    int max=values[0];

    for(int i=0;i<newN;i++)
        cout<<values[i]<<" ";
        cout<<"\n";

    fout<<max<<"\n";
    for(int i=0;i<newN;i++)
    {
        if(values[i]==max)
        {
            if(cut[i]==0)
            {
                fout<<longstrlib[i]<<"\n";
            }
            else
            {
                int l=longstrlib[i].length();
                for(int k=0;k<cut[i];k++)
                    fout<<longstrlib[i][k];
                fout<<" ";
                for(int k=cut[i];k<l;k++)
                    fout<<longstrlib[i][k];
                fout<<"\n";
            }
        }
    }
    return 0;
}
