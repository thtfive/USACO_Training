/*
ID:thtfive
LANG:C++
TASK:heritage
*/
#include<iostream>
#include<fstream>
#include<string>

using namespace std;
string In_order,Pre_order;
int TreeLength;


string recursive_classfy(int start,int finish)
{
    if (start==finish)
    {
        char *ch;
        ch=new char[1];
        ch[0]=In_order[start];
        return ch;
    }
    if (start>finish)return "";
    int ls,lf,rs,rf;
    char *chtmp;
    chtmp=new char[1];
    chtmp[0]=Pre_order[start];
    string Post_order=chtmp;
    for (int idx=start;idx<=finish;idx++)
    {
        if (Pre_order[start]==In_order[idx])
        {
            ls=start;
            lf=idx-1;
            rs=idx+1;
            rf=finish;
            char tmp=Pre_order[start];
            for(int i=start;i<idx;i++)
                Pre_order[i]=Pre_order[i+1];
            Pre_order[idx]=tmp;

            break;
        }
    }
    Post_order=recursive_classfy(ls,lf)+ recursive_classfy(rs,rf)+Post_order;
    return Post_order;
}

int main()
{
    ifstream fin("heritage.in");
    ofstream fout("heritage.out");

    fin>>In_order>>Pre_order;
    TreeLength=In_order.length();
    string Post_order=recursive_classfy(0,TreeLength-1);
    fout<<Post_order<<"\n";

}
