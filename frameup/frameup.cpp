/*
ID:thtfive
LANG:C++
TASK:frameup
*/
#include<iostream>
#include<fstream>
#include<string.h>
#include<cmath>
using namespace std;
ifstream fin("frameup.in");
ofstream fout("frameup.out");
char chlib[30];
string charlib[30];
int chnum=0;
int maxtop[30];
int maxbottom[30];
int maxleft[30];
int maxright[30];
int feasible;
string possible[20000];

string frames[30][30];
int H,W;

int index(char ch)
{
    if(ch=='.')return -1;
    for(int i=0;i<chnum;i++)
    {
        if(chlib[i]==ch)return i;
    }
    chlib[chnum++]=ch;
    return chnum-1;
}

void sort(char *ch)
{
    for(int i=0;i<chnum;i++)
    {
        for(int j=1;j<chnum;j++)
        {
            if(ch[j]-'A'<ch[j-1]-'A')
            {
                char tmp=ch[j];
                ch[j]=ch[j-1];
                ch[j-1]=tmp;
            }
        }
    }
}

void subsolution1(string *charlib)
{
    for(int i=0;i<H;i++)
    {
        for(int j=0;j<W;j++)
        {
            index(charlib[i][j]);
        }
    }
    sort(chlib);
    memset(maxtop,100,sizeof(maxtop));
    memset(maxbottom,0,sizeof(maxbottom));
    memset(maxleft,100,sizeof(maxleft));
    memset(maxright,0,sizeof(maxright));

    for(int i=0;i<H;i++)
    {
        for(int j=0;j<W;j++)
        {
            int place=index(charlib[i][j]);
            if(place!=-1)
            {
                maxbottom[place]=maxbottom[place]>i?maxbottom[place]:i;
                maxtop[place]=maxtop[place]<i?maxtop[place]:i;
                maxleft[place]=maxleft[place]<j?maxleft[place]:j;
                maxright[place]=maxright[place]>j?maxright[place]:j;

            }
        }
    }
}

void subsolution2()
{
    string emptystr="";
    for(int j=0;j<W;j++)
        emptystr+=".";

    for(int f=0;f<chnum;f++)
    {
        for(int i=0;i<H;i++)
        {
            frames[f][i]=emptystr;
        }
    }
    for(int f=0;f<chnum;f++)
    {
        for(int i=maxtop[f];i<=maxbottom[f];i++)
        {
            frames[f][i][maxleft[f]]=chlib[f];
            frames[f][i][maxright[f]]=chlib[f];
        }
        for(int j=maxleft[f];j<=maxright[f];j++)
        {
            frames[f][maxtop[f]][j]=chlib[f];
            frames[f][maxbottom[f]][j]=chlib[f];
        }
    }
}

void solution(string info,string *framestack)
{
    int len=info.length();
    if(len==chnum)
    {
        possible[feasible++]=info;
    }

//    if(len<chnum&&len>0)
//    {
//        for(int i=0;i<H;i++)
//        {
//            for(int j=0;j<W;j++)
//            {
//                if(framestack[i][j]!='.'&&framestack[i][j]!=charlib[i][j])
//                {
//                    return;
//                }
//            }
//        }
//    }


    for(int i=0;i<chnum;i++)
    {
        bool flag=true;
        for(int k=0;k<len;k++)
        {
            if(info[k]-'0'==i)
            {
                flag=false;
                break;
            }
        }
        char tmp='0'+i;
        if(flag)
        {
            string newstr[H];
            for(int m=0;m<H;m++)
                newstr[m]=framestack[m];
            bool jump=false;

            for(int n=maxleft[i];n<=maxright[i]&&!jump;n++)
            {
                if(framestack[maxtop[i]][n]=='.')
                {
                    newstr[maxtop[i]][n]=frames[i][maxtop[i]][n];
                    if(newstr[maxtop[i]][n]!=charlib[maxtop[i]][n])
                        jump=true;
                }
                if(framestack[maxbottom[i]][n]=='.')
                {
                    newstr[maxbottom[i]][n]=frames[i][maxbottom[i]][n];
                    if(newstr[maxbottom[i]][n]!=charlib[maxbottom[i]][n])
                        jump=true;
                }
            }

            for(int m=maxtop[i];m<=maxbottom[i]&&!jump;m++)
            {
                if(framestack[m][maxright[i]]=='.')
                {
                    newstr[m][maxright[i]]=frames[i][m][maxright[i]];
                    if(newstr[m][maxright[i]]!=charlib[m][maxright[i]])
                        jump=true;
                }
                if(framestack[m][maxleft[i]]=='.')
                {
                    newstr[m][maxleft[i]]=frames[i][m][maxleft[i]];
                    if(newstr[m][maxleft[i]]!=charlib[m][maxleft[i]])
                        jump=true;
                }
            }
            if(jump)continue;
            solution(tmp+info,newstr);
        }
    }
}

int partition(string *p,int start,int finish)
{
    int mid=start-1;
    for(int idx=start;idx<finish;idx++)
    {
        bool flag=false;
        for(int i=0;i<chnum;i++)
        {
            if(p[idx][i]-'0'<p[finish][i]-'0')
            {
                flag=true;
                break;
            }
            if(p[idx][i]-'0'>p[finish][i]-'0')
            {
                flag=false;
                break;
            }
        }
        if(flag)
        {
            mid++;
            string strtmp=p[idx];
            p[idx]=p[mid];
            p[mid]=strtmp;
        }
    }
    mid++;
    string strtmp=p[finish];
    p[finish]=p[mid];
    p[mid]=strtmp;
    return mid;
}

void quicksort(string *p,int start,int finish)
{
    if(start<finish)
    {
        int mid=partition(p,start,finish);
        quicksort(p,start,mid-1);
        quicksort(p,mid+1,finish);
    }
}
int main()
{
    fin>>H>>W;
    for(int i=0;i<=H;i++)
        fin>>charlib[i];
    subsolution1(charlib);
    subsolution2();

    string emptystr[H];
    string str1;
    for(int j=0;j<W;j++)
        str1+=".";
    for(int i=0;i<H;i++)
        emptystr[i]=str1;

    solution("",emptystr);

    quicksort(possible,0,feasible-1);

    for(int k=0;k<feasible;k++)
    {
        for(int i=0;i<chnum;i++)
            fout<<chlib[possible[k][i]-'0'];
        fout<<"\n";
    }

    return 0;
}
