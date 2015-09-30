/*
ID:thtfive
LANG:C++
*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void multiply(char &str1,char str2,int &sign)
{
    if(str1=='1')
    {
        str1=str2;
        return;
    }
    else if(str1=='i')
    {
        if(str2=='1')
        {
            return;
        }
        if(str2=='i')
        {
            str1='1';
            sign=(sign+1)%2;
            return;
        }
        if(str2=='j')
        {
            str1='k';
            return;
        }
        if(str2=='k')
        {
            str1='j';
            sign=(sign+1)%2;
            return;
        }
    }
    else if(str1=='j')
    {
        if(str2=='1')
        {
            return;
        }
        if(str2=='i')
        {
            str1='k';
            sign=(sign+1)%2;
            return;
        }
        if(str2=='j')
        {
            str1='1';
            sign=(sign+1)%2;
            return;
        }
        if(str2=='k')
        {
            str1='i';
            return;
        }
    }
    else if(str1=='k')
    {
        if(str2=='1')
        {
            return;
        }
        if(str2=='i')
        {
            str1='j';
            return;
        }
        if(str2=='j')
        {
            str1='i';
            sign=(sign+1)%2;
            return;
        }
        if(str2=='k')
        {
            str1='1';
            sign=(sign+1)%2;
            return;
        }
    }
}

int main()
{
    ifstream fin("C-small-attempt1.in");
    ofstream fout("C-small-attempt1.out");

    int T;
    int sign;
    fin>>T;
    cout<<T<<endl;
    for (int Test=1;Test<=T;Test++)
    {
        int L,X;
        bool result=false;
        string strtemp;
        string str="";
        fin>>L>>X>>strtemp;
        int length=L*X;
        for (int i=0;i<X;i++)str+=strtemp;

        int first,second;
        char strtmp=str[0];

        ///compare the prefix
        if (strtmp=='i')
        {
            first=0;
        }
        else
        {
            sign=0;
            for (first=1;first<length;first++)
            {

                multiply(strtmp,str[first],sign);
                if (strtmp=='i'&&sign==0)break;
            }
        }

        ///compare the tail part
        strtmp=str[length-1];
        if (strtmp=='k')
        {
            second=length-1;
        }
        else
        {
            sign=0;
            char tmp2;
            for (second=length-2;second>0;second--)
            {
                tmp2=strtmp;
                strtmp=str[second];
                multiply(strtmp,tmp2,sign);
                if (strtmp=='k'&&sign==0)break;
            }
        }

        if (first+1>second-1)
        {
            result=false;
        }
        else
        {
            strtmp=str[first+1];
            sign=0;

            for (int idx=first+2;idx<=second-1;idx++)
            {
                multiply(strtmp,str[idx],sign);
            }
            if(strtmp=='j'&&sign==0)result=true;
        }

//        string strlib="1ijk";
//        for (int i=0;i<4;i++)
//        {
//            for (int j=0;j<4;j++)
//            {
//                char ch=strlib[i];
//                char ch2=strlib[j];
//                int fuhao=0;
//                multiply(ch,ch2,fuhao);
//                if (fuhao==1)cout<<"-"<<ch<<" ";
//                else cout<<ch<<" ";
//            }
//            cout<<endl;
//        }

        if(result)
        fout<<"Case #"<<Test<<": "<<"YES"<<"\n";
        else
        fout<<"Case #"<<Test<<": "<<"NO"<<"\n";

    }

    return 0;
}
