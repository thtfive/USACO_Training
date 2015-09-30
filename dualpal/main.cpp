/*
ID:thtfive
LANG:C++
TASK:dualpal
*/
#include<iostream>
using namespace std;
#include<fstream>

bool isPal(int num,int base)
{
    int num_tmp;
    int len;
    bool flag=true;
    string stringmap="0123456789";
    string str_tmp;
    string str="";
    while(num!=0)
    {
        num_tmp=num%base;
        str_tmp=stringmap[num_tmp];
        num=num/base;
        str=str_tmp+str;
    }

    len=str.length();
    for (int i=0;i<len;i++)
    {
        if (str[i]!=str[len-1-i])
        {
            flag=false;
            break;
        }
    }
    return flag;

}

bool isDualpal(int num)
{
    int counter=0;
    for (int i=2;i<11;i++)
    {
        if(isPal(num,i))counter++;
        if (counter==2)return true;
    }
    return false;
}

int main(){
    ifstream filein("dualpal.in");
    ofstream fileout("dualpal.out");
    int N,S,num;
    int counter=0;
    filein>>N>>S;
    num=S+1;
    while(counter<N)
    {
        if(isDualpal(num))
        {
            fileout<<num<<"\n";
            counter++;
        }
        num++;
    }


    return 0;
}
