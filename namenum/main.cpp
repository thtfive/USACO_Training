/*
ID:thtfive
LANG:C++
TASK:namenum
*/
#include<iostream>
using namespace std;
#include<fstream>
#include<string.h>


class tree
{
public:
    class Node
    {
    public:
        Node(){
        A=NULL;B=NULL;C=NULL;D=NULL;E=NULL;
        F=NULL;G=NULL;H=NULL;I=NULL;J=NULL;
        K=NULL;L=NULL;M=NULL;N=NULL;O=NULL;
        P=NULL;Q=NULL;R=NULL;S=NULL;T=NULL;
        U=NULL;V=NULL;W=NULL;X=NULL;Y=NULL;
        Z=NULL;
        signn=false;
        }

        string data;
        bool signn;
        Node *A,*B,*C,*D,*E,*F,*G,*H,*I,*J,*K,*L,*M,*N;
        Node *O,*P,*Q,*R,*S,*T,*U,*V,*W,*X,*Y,*Z;
    };
    Node *root;

///构造函数
    bool insert_data(string data);
    bool search_data(string data);
    Node *get_root(){return root;}
    tree(){
        root=NULL;
    }
    virtual ~tree(){
    }

private:
    bool data_insert(string data,Node *&p,long index);
    bool data_search(string data,Node *p,long index);

};

bool tree::insert_data(string data)
{
    if (root==NULL&&data.length()>0)root=new Node;

    return data_insert(data,root,0);
}

bool tree::data_insert(string data,Node *&p,long index){
    long len=data.length();
    if (p==NULL){p=new Node;}
    if (index==len){p->signn=true; return true;}
    if (index<len){
        char tmp=data[index];
        switch (tmp)
        {
            case 'A': return data_insert(data,p->A,index+1);
                      break;
            case 'B': return data_insert(data,p->B,index+1);
                      break;
            case 'C': return data_insert(data,p->C,index+1);
                      break;
            case 'D': return data_insert(data,p->D,index+1);
                      break;
            case 'E': return data_insert(data,p->E,index+1);
                      break;
            case 'F': return data_insert(data,p->F,index+1);
                      break;
            case 'G': return data_insert(data,p->G,index+1);
                      break;
            case 'H': return data_insert(data,p->H,index+1);
                      break;
            case 'I': return data_insert(data,p->I,index+1);
                      break;
            case 'J': return data_insert(data,p->J,index+1);
                      break;
            case 'K': return data_insert(data,p->K,index+1);
                      break;
            case 'L': return data_insert(data,p->L,index+1);
                      break;
            case 'M': return data_insert(data,p->M,index+1);
                      break;
            case 'N': return data_insert(data,p->N,index+1);
                      break;
            case 'O': return data_insert(data,p->O,index+1);
                      break;
            case 'P': return data_insert(data,p->P,index+1);
                      break;
            case 'Q': return data_insert(data,p->Q,index+1);
                      break;
            case 'R': return data_insert(data,p->R,index+1);
                      break;
            case 'S': return data_insert(data,p->S,index+1);
                      break;
            case 'T': return data_insert(data,p->T,index+1);
                      break;
            case 'U': return data_insert(data,p->U,index+1);
                      break;
            case 'V': return data_insert(data,p->V,index+1);
                      break;
            case 'W': return data_insert(data,p->W,index+1);
                      break;
            case 'X': return data_insert(data,p->X,index+1);
                      break;
            case 'Y': return data_insert(data,p->Y,index+1);
                      break;
            case 'Z': return data_insert(data,p->Z,index+1);
                      break;
            default: return false; break;
        }
    }
    return false;
}

///查找函数实现函数
bool tree::search_data(string data){

    return data_search(data,root,0);
}

bool tree::data_search(string data,Node *p,long index){
    if (p==NULL){return false;}
    long num=data.length();
    if (index==num)
    {
        if (p->signn==true)return true;
        else return false;
    }

    if (index<num){
        char tmp=data[index];
        switch (tmp){
            case 'A': return data_search(data,p->A,index+1);
                      break;
            case 'B': return data_search(data,p->B,index+1);
                      break;
            case 'C': return data_search(data,p->C,index+1);
                      break;
            case 'D': return data_search(data,p->D,index+1);
                      break;
            case 'E': return data_search(data,p->E,index+1);
                      break;
            case 'F': return data_search(data,p->F,index+1);
                      break;
            case 'G': return data_search(data,p->G,index+1);
                      break;
            case 'H': return data_search(data,p->H,index+1);
                      break;
            case 'I': return data_search(data,p->I,index+1);
                      break;
            case 'J': return data_search(data,p->J,index+1);
                      break;
            case 'K': return data_search(data,p->K,index+1);
                      break;
            case 'L': return data_search(data,p->L,index+1);
                      break;
            case 'M': return data_search(data,p->M,index+1);
                      break;
            case 'N': return data_search(data,p->N,index+1);
                      break;
            case 'O': return data_search(data,p->O,index+1);
                      break;
            case 'P': return data_search(data,p->P,index+1);
                      break;
            case 'Q': return data_search(data,p->Q,index+1);
                      break;
            case 'R': return data_search(data,p->R,index+1);
                      break;
            case 'S': return data_search(data,p->S,index+1);
                      break;
            case 'T': return data_search(data,p->T,index+1);
                      break;
            case 'U': return data_search(data,p->U,index+1);
                      break;
            case 'V': return data_search(data,p->V,index+1);
                      break;
            case 'W': return data_search(data,p->W,index+1);
                      break;
            case 'X': return data_search(data,p->X,index+1);
                      break;
            case 'Y': return data_search(data,p->Y,index+1);
                      break;
            case 'Z': return data_search(data,p->Z,index+1);
                      break;
            default: break;
        }

    }
    return false;

}






long num_array[12];
long get_the_digit(string strnum,long num_array[])
{

    long counter=strnum.length();

    for (long i=0;i<counter;i++)num_array[i]=strnum[i]-'0';
    return counter;
}

string convert(long digit)
{
    switch(digit)
    {
        case 2:return "ABC";break;
        case 3:return "DEF";break;
        case 4:return "GHI";break;
        case 5:return "JKL";break;
        case 6:return "MNO";break;
        case 7:return "PRS";break;
        case 8:return "TUV";break;
        case 9:return "WXY";break;
        default : return "";break;
    }
    return "";
}

int main(){
    bool flag=false;
    ifstream fin("namenum.in");
    ifstream dictionary("dict.txt");
    ofstream fout("namenum.out");
   // stack a;
    long counter=0;
    string strnum;
    string str_possible;
    string str_tmp;
    string str_store;
    fin>>strnum;

    counter=get_the_digit(strnum,num_array);

    tree dict;
    while(dictionary>>str_store)
    {
        dict.insert_data(str_store);
    }

    long total_num=1;
    long digits[counter];
    for(long i=0;i<counter;i++){digits[i]=0;total_num*=3;}
    long temp_long;

    long cal=0;
    while (cal<total_num){
        temp_long=cal;
        for (long i=counter-1;i>=0;i--)
        {
            digits[i]=temp_long%3;
            temp_long/=3;
        }

        str_possible="";
        for (long j=0;j<counter;j++)
        {
            str_tmp=convert(num_array[j]);///
            str_possible=str_possible+str_tmp[digits[j]];
        }
       // fout<<str_possible;fout<<"\n";
        if(dict.search_data(str_possible)){fout<<str_possible;fout<<"\n";flag=true;}
        cal++;
    }
    if (!flag){fout<<"NONE";fout<<"\n";}
       // cout<<num_array[i]<<" ";
    //cout<<dict.search_data("GREG")<<endl;
return 0;
}


