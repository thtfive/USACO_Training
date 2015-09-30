/*
ID:thtfive
LANG:C++
TASK:namenum
*/
#include<iostream>
using namespace std;
#include<fstream>
#include<string.h>


long num_array[12];
long get_the_digit(string strnum,long num_array[])
{

    long counter=strnum.length();

    for (long i=0;i<counter;i++)num_array[i]=strnum[i]-'0';
    return counter;
}

string convert(string str)
{
    char tmp;
    char num_tmp;
    int len=str.length();
    string return_ans="";
    for (int i=0;i<len;i++)
    {
        tmp=str[i];
        switch(tmp)
        {
            case 'A':num_tmp='2';break;
            case 'B':num_tmp='2';break;
            case 'C':num_tmp='2';break;
            case 'D':num_tmp='3';break;
            case 'E':num_tmp='3';break;
            case 'F':num_tmp='3';break;
            case 'G':num_tmp='4';break;
            case 'H':num_tmp='4';break;
            case 'I':num_tmp='4';break;
            case 'J':num_tmp='5';break;
            case 'K':num_tmp='5';break;
            case 'L':num_tmp='5';break;
            case 'M':num_tmp='6';break;
            case 'N':num_tmp='6';break;
            case 'O':num_tmp='6';break;
            case 'P':num_tmp='7';break;
            case 'R':num_tmp='7';break;
            case 'S':num_tmp='7';break;
            case 'T':num_tmp='8';break;
            case 'U':num_tmp='8';break;
            case 'V':num_tmp='8';break;
            case 'W':num_tmp='9';break;
            case 'X':num_tmp='9';break;
            case 'Y':num_tmp='9';break;
            default : num_tmp='0';break;
        }
        return_ans=return_ans+num_tmp;
    }
    return return_ans;
}

int main(){
    bool flag=false;
    ifstream fin("namenum.in");
    ifstream dictionary("dict.txt");
    ofstream fout("namenum.out");
    string strnum;
    string str_possible;
    string str_tmp;
    string str_store;
    string str_dict[5000];
    string num_dict[5000];
    fin>>strnum;

    int index=0;
    while(dictionary>>str_store)
    {

        str_dict[index]=str_store;
        index++;
    }
    for (int i=0;i<index;i++)
    {
        num_dict[i]=convert(str_dict[i]);
    }

    for (int i=0;i<index;i++)
    {
        if(strnum==num_dict[i])
        {
            fout<<str_dict[i];
            fout<<"\n";
            flag=true;
        }

    }
       // fout<<str_possible;fout<<"\n";

    if (!flag){fout<<"NONE";fout<<"\n";}
       // cout<<num_array[i]<<" ";
    //cout<<dict.search_data("GREG")<<endl;
return 0;
}


