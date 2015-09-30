/*
ID:thtfive
LANG:C++
TASK:palsquare
*/
#include<iostream>
#include<fstream>
using namespace std;



string num_str(int num,int base){
    string str_a="";
    string str_tmp;
    int left;
    while(num!=0)
    {
        left=num%base;
        switch(left)
        {
            case 0:str_tmp='0';break;
            case 1:str_tmp='1';break;
            case 2:str_tmp='2';break;
            case 3:str_tmp='3';break;
            case 4:str_tmp='4';break;
            case 5:str_tmp='5';break;
            case 6:str_tmp='6';break;
            case 7:str_tmp='7';break;
            case 8:str_tmp='8';break;
            case 9:str_tmp='9';break;
            case 10:str_tmp='A';break;
            case 11:str_tmp='B';break;
            case 12:str_tmp='C';break;
            case 13:str_tmp='D';break;
            case 14:str_tmp='E';break;
            case 15:str_tmp='F';break;
            case 16:str_tmp='G';break;
            case 17:str_tmp='H';break;
            case 18:str_tmp='I';break;
            case 19:str_tmp='J';break;
            case 20:str_tmp='K';break;
            default:break;
        }
        str_a=str_tmp+str_a;
        num=num/base;
    }
    return str_a;
}

bool palcheck(string str){
    int len=str.length();
    bool flag=true;
    for (int i=0;i<len;i++)
    {
        if (str[i]!=str[len-i-1])flag=false;
    }
    return flag;
}

main(){
    ifstream filein("palsquare.in");
    ofstream fileout("palsquare.out");
    int basenum;
    int squarenum;
    string number_str,square_number_str;
    filein>>basenum;
    for (int i=1;i<301;i++)
    {
        number_str=num_str(i,basenum);
        squarenum=i*i;
        square_number_str=num_str(squarenum,basenum);
        if (palcheck(square_number_str))
        {
            fileout<<number_str<<" "<<square_number_str<<"\n";
        }
      //  str=palcompare(squarenum,basenum);
    }



    return 0;
}
