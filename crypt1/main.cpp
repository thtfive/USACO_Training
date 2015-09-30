/*
ID:thtfive
LANG:C++
TASK:crypt1
*/
#include<iostream>
using namespace std;
#include<fstream>
#include<cstdlib>

string int_2_str(int num)
{
    string tmp;
    string strlib="0123456789";
    int index;
    string str="";
    if (num==0)str="0";
    while(num!=0)
    {
        index=num%10;
        tmp=strlib[index];
        str=tmp+str;
        num/=10;
    }
    return str;
}

bool check_digits(int number,int digits[],int Num)
{
    string str;
    string str_tmp;
    str=int_2_str(number);
    string str_lib[Num];
    for (int i=0;i<Num;i++)str_lib[i]=int_2_str(digits[i]);
    bool flag=true;
    bool flag2=false;
    int len=str.length();
    for(int i=0;i<len;i++)
    {
        flag2=false;
        for (int j=0;j<Num;j++)
        {
            str_tmp=str[i];
            if (str_tmp==str_lib[j])flag2=true;
        }
        if (flag2==false){flag=false;break;}
    }
    return flag;
}

int main()
{
    int Num;
    int counter=0;
    int top,low,top_ans,low_ans,ans;
    ifstream fin("crypt1.in");
    ofstream fout("crypt1.out");
    fin>>Num;
    int digits[Num];
    for (int i=0;i<Num;i++)fin>>digits[i];

    //for (int i=0;i<Num;i++)cout<<digits[i]<<" ";
    bool flag1,flag2,flag3;
    for (int i=0;i<Num;i++)
    {
        for (int j=0;j<Num;j++)
        {
            for (int k=0;k<Num;k++)
            {
                top=100*digits[i]+10*digits[j]+digits[k];
                for (int t=0;t<Num;t++)
                {
                    for (int l=0;l<Num;l++)
                    {
                        low=10*digits[t]+digits[l];
                        ans=top*low;
                        top_ans=top*digits[t];
                        low_ans=top*digits[l];
                        if (ans>=10000||top_ans>=1000||low_ans>=1000)continue;
                        flag1=check_digits(ans,digits,Num);
                        flag2=check_digits(top_ans,digits,Num);
                        flag3=check_digits(low_ans,digits,Num);
                        if(flag1&&flag2&&flag3){counter++;}
                    }
                }
            }
        }
    }
    fout<<counter<<"\n";

    return 0;
}
