/*
ID:thtfive
LANG:C++
TASK:hidden
*/
#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

string str;
int L;
int maxlen=100001;
int level=0;
int trank[200010];
int rank[200010];
int sa[200010];
int tsa[200010];
int sum[100001];
ifstream fin("hidden.in");
ofstream fout("hidden.out");

void init()
{
    fin>>L;
    string tmp;
    str="";
    while(fin>>tmp)
    {
        str+=tmp;
    }
}


void sorting(int len)
{
    memset(sum,0,sizeof(sum));
 	for (int i=0;i<L;i++)sum[rank[(i+len)%L]]++;
 	for (int i=1;i<=L;i++)sum[i]+=sum[i-1];
 	for (int i=L-1;i>=0;i--)
        tsa[sum[rank[(i+len)%L]]--]=i;

// 	for (int i=2;i<=L;i++)
// 	{
// 		if (trank[sa[i]]!=trank[sa[i-1]])p++;
// 		rank[sa[i]]=p;
// 	}

    ///�Եڶ��ؼ��ּ�������tsa����saΪ����Ϊi�ĺ�׺��tsa[i]

 	memset(sum,0,sizeof(sum));
 	for (int i=0;i<L;i++)sum[rank[i]]++;
 	for (int i=1;i<=maxlen;i++)sum[i]+=sum[i-1];
 	for (int i=L;i>0;i--)
        sa[sum[rank[tsa[i]]]--]=tsa[i];
        ///�Ե�һ�ؼ��ּ�������,���컥���ϵ
}

void get_sa()
{
    int p=1;
    memset(sum,0,sizeof(sum));
 	for(int i=0;i<L;i++){trank[i]=str[i]-'a';}///����ÿһ���ַ���Ӧ�����֣�0-25��������trank��
 	for(int i=0;i<L;i++){sum[trank[i]]++;}///����0-25ÿ�����ֵĸ���
 	for(int i=1;i<=26;i++)sum[i]+=sum[i-1];///���㵽��ǰλ�ø������ܺ�
 	for (int i=L-1;i>=0;i--)
    {
        sa[sum[trank[i]]--]=i;///�����׺����
    }
 	rank[sa[1]]=1;

 	p=1;
 	for (int i=2;i<=L;i++)
 	{
 		if (trank[sa[i]]!=trank[sa[i-1]])p++;
 		rank[sa[i]]=p;
 	}///��һ�ε�sa��rank�������,��������

 	for (int len=1;len<=L;len*=2)
 	{
 		sorting(len);
 		trank[sa[1]]=1;
 		p=1; ///��trank����rank
 		for (int i=2;i<=L;i++)
 		{
 			if ((rank[sa[i]]!=rank[sa[i-1]])||(rank[(sa[i]+len)%L]!=rank[(sa[i-1]+len)%L]))p++;
 			trank[sa[i]]=p;///
 		}
 		for (int i=0;i<L;i++)rank[i]=trank[i];
 	}

}

void print()
{
    cout<<"result: "<<sa[1]<<"\n";
    fout<<sa[1]<<"\n";
}

int main()
{
    init();
    get_sa();
    print();
    return 0;
}
