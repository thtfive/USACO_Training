/*
ID:thtfive
LANG:C++
TASK:contact
*/

#include<fstream>
#include<iostream>
#include<cmath>
using namespace std;
class Node
{
public:
    int counter;
    Node *right,*left;
    Node()
    {
        right=NULL;
        left=NULL;
        counter=-1;
    }
};
class binarytree
{
public:
    bool flag;
    Node *root;
    binarytree()
    {
        root=NULL;
    }

    void insert(string str)
    {
        int length=str.length();
        if (root==NULL)root=new Node;
        Node *p=root;
        for (int i=0;i<length;i++)
        {
            switch(str[i]-'0')
            {
                case 0:if(p->left==NULL)p->left=new Node;p=p->left;break;
                case 1:if(p->right==NULL)p->right=new Node;p=p->right;break;
            }
        }
        p->counter=0;
    }

    bool count(string str)
    {
        int length=str.length();
        Node *p=root;
        for (int i=0;i<length;i++)
        {
            if (p==NULL){return false;}
            switch(str[i]-'0')
            {
                case 0:p=p->left;break;
                case 1:p=p->right;break;
            }
        }
        if(p==NULL)return false;
        else
        {
            p->counter++;
            return true;
        }
    }

    int search(string str)
    {
        int length=str.length();
        Node *p=root;
        for (int i=0;i<length;i++)
        {
            if (p==NULL){return false;}
            switch(str[i]-'0')
            {
                case 0:p=p->left;break;
                case 1:p=p->right;break;
            }
        }
        if(p==NULL)return false;
        else
        {
            return p->counter;
        }
    }

}Tree;

class doubleData
{
public:
    int counter;
    int key;
    string str;
    doubleData()
    {
        counter=0;
        key=0;
        str="";
    }
};


void create(int n,string str)
{
    if (n==0)
    {
        Tree.insert(str);
    }
    else
    {
        create(n-1,str+"0");
        create(n-1,str+"1");
    }
}


void solve(int A,int B,string contact_string)
{
    string str="";
    int length=contact_string.length();
    for (int start=0;start<length;start++)
    {
        str="";
        for (int idx=start;idx<start+A-1&&idx<length;idx++)
        {
            str+=contact_string[idx];
        }
        for (int idx=start+A-1;idx<start+B&&idx<length;idx++)
        {
            str+=contact_string[idx];
            Tree.count(str);
        }
    }
}

void recursive(int len,int index,int start,string str,doubleData *Data)
{
    if (len==0)
    {
        Data[start+index].str=str;
        Data[start+index].key=start+index;
    }
    else
    {
        recursive(len-1,2*index,start,str+"0",Data);
        recursive(len-1,2*index+1,start,str+"1",Data);
    }
}

void solution(int A,int B,string contact_string,doubleData *Data)
{
    int length=contact_string.length();

    for(int len=A;len<=B;len++)
    {
        int index=0;
        int tmp=pow(2,len)-2;
        int num=pow(2,len);

        for (int idx=0;idx<len-1&&idx<length;idx++)
        {
            index*=2;
            index+=contact_string[idx]-'0';
        }

        for (int finish=len-1;finish<length;finish++)
        {
            index*=2;
            index+=contact_string[finish]-'0';
            index%=num;
            Data[index+tmp].counter++;
        }
    }
}

void reorder(doubleData *Data,int maxN,int N)
{
    for (int i=0;i<maxN;i++)
    {
        for (int j=maxN-1;j>i;j--)
        {
            if (Data[j].counter>Data[j-1].counter)
            {
                int tmp=Data[j].counter;
                Data[j].counter=Data[j-1].counter;
                Data[j-1].counter=tmp;

                string strtmp=Data[j].str;
                Data[j].str=Data[j-1].str;
                Data[j-1].str=strtmp;
            }
        }
    }
}

int partition(doubleData *Data,int start,int finish)
{
    int counter=Data[finish].counter;
    int key=Data[finish].key;
    int j=start-1;
    for (int i=start;i<finish;i++)
    {
        if(Data[i].counter>counter||(Data[i].counter==counter&&Data[i].key<key))
        {
            j++;

            int tmp=Data[j].counter;
            Data[j].counter=Data[i].counter;
            Data[i].counter=tmp;

            string strtmp=Data[j].str;
            Data[j].str=Data[i].str;
            Data[i].str=strtmp;

            int keytmp=Data[j].key;
            Data[j].key=Data[i].key;
            Data[i].key=keytmp;
        }
    }

    int tmp=Data[j+1].counter;
    Data[j+1].counter=Data[finish].counter;
    Data[finish].counter=tmp;

    string strtmp=Data[j+1].str;
    Data[j+1].str=Data[finish].str;
    Data[finish].str=strtmp;

    int keytmp=Data[j+1].key;
    Data[j+1].key=Data[finish].key;
    Data[finish].key=keytmp;

    return j+1;
}

void quicksort(doubleData *Data,int start,int finish)
{
    if (start<finish)
    {
        int mid=partition(Data,start,finish);
        quicksort(Data,start,mid-1);
        quicksort(Data,mid+1,finish);
    }
}
int main()
{
//    ifstream fin("input.txt");
//    ofstream fout("output.txt");
    ifstream fin("contact.in");
    ofstream fout("contact.out");
    int A,B,N;
    fin>>A>>B>>N;
    string contact_string="";
    string strtmp;
    while(fin>>strtmp)contact_string+=strtmp;

    for (int n=A;n<=B;n++)
    {
        create(n,"");
    }

    solve(A,B,contact_string);
  //  cout<<Tree.search("1000");

    doubleData Data[10000];



    int maxN=pow(2,B+1)-2;
    for (int len=A;len<=B;len++)
    {
        int start=pow(2,len)-2;
        string str="";
        recursive(len,0,start,str,Data);
    }



    solution(A,B,contact_string,Data);


//    reorder(Data,maxN,N);
    int p=pow(2,A)-2;
    int q=pow(2,B+1)-3;
    quicksort(Data,p,q);

//    for (int i=0;i<100;i++)
//    cout<<Data[i].counter<<" "<<Data[i].str<<endl;

    int counter1=0;
    int counter2=0;
    int ind=p;
    int countertmp=-1;

    while(ind<=q)
    {
        if (Data[ind].counter==countertmp)
        {
            counter2++;
            if (counter2%6==0)fout<<" "<<Data[ind].str<<"\n";
            else
            {
                if (counter2%6==1)
                {
                    fout<<Data[ind].str;
                }
                else
                    fout<<" "<<Data[ind].str;
            }
        }
        else
        {
            counter1++;
            if(counter1==N+1)break;
            if(Data[ind].counter==0)break;
            if(ind!=p&&counter2%6!=0)fout<<"\n";
            countertmp=Data[ind].counter;
            fout<<Data[ind].counter<<"\n";
            fout<<Data[ind].str;
            counter2=1;
        }
        ind++;
    }
    if (counter2%6!=0)fout<<"\n";

    //cout<<Data[0].counter<<endl;

}
