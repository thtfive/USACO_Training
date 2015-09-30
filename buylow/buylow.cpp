/*
ID:thtfive
LANG:C++
TASK:buylow
*/
#include<iostream>
#include<fstream>
using namespace std;
///�����ö�̬�滮�ķ�����������ĳ��ȣ�������counter��������¼��Ӧ�Ŀ��ܵķ�������
class llint///��������ڴ��泤�Ƚϳ������֣�һ����10λ����Լ���Դ��泤��Ϊ70λ������
{
public:
    int data[10];
    llint()
    {
        for (int i=0;i<10;i++)data[i]=0;
    }
    llint &operator+(const llint &num1)///����+ ����
    {
        int flag=0;
        llint tmp;
        for(int i=0;i<10;i++)
        {
            tmp.data[i]=(data[i]+num1.data[i]+flag)%10000000;
            flag=(data[i]+num1.data[i]+flag)/10000000;
        }
        for(int i=0;i<10;i++)
            data[i]=tmp.data[i];
        return *this;
    }

    llint &operator=(const llint num)///����=
    {
        for(int i=0;i<10;i++)
            data[i]=num.data[i];
        return *this;
    }

};

ofstream & operator<<(ofstream &os,const llint &obj)///����<<
{
    for (int i=9;i>0;i--)
    {
        if(obj.data[i]!=0)os<<obj.data[i];
    }
    os<<obj.data[0];
    return os;
}

ostream & operator<<(ostream &os,const llint &obj)///���ر�׼<<
{
    for (int i=9;i>0;i--)
    {
        if(obj.data[i]!=0)os<<obj.data[i];
    }
    os<<obj.data[0];
    return os;
}

int main()
{
    ifstream fin("buylow.in");
    ofstream fout("buylow.out");
    int N;
    fin>>N;
    int stockprice[N];
    int number[N];
    llint counter[N];
    for(int i=0;i<N;i++)
        for(int j=0;j<10;j++)
            counter[i].data[j]=0;

    llint one,zero;
    one.data[0]=1;
    zero.data[0]=0;
    for(int i=0;i<N;i++)
    {
        fin>>stockprice[i];
        number[i]=1;
    }

    int maxnum=0;///maxnum ���ڼ�¼��󳤶�
    for (int i=N-1;i>=0;i--)
    {
        int max=0;
        for (int j=i+1;j<N;j++)
        {
            if(stockprice[i]>stockprice[j]&&max<number[j])
            {
                max=number[j];
            }
        }

        for (int j=i+1;j<N;j++)///����������ͬ�Ĺɼ�
        {
            if(stockprice[j]==stockprice[i]&&max+1==number[j])
                break;
            if(number[j]==max&&stockprice[j]<stockprice[i])
            {
                counter[i]=counter[i]+counter[j];
            }
        }

        if(max==0)///����ĳһ��Ĺɼ���������û�б�����С�Ĺɼۣ������������ͬ�Ĺɼۣ������Ĺɼ۵Ŀ����Լ�¼��Ϊ0������1
        {
            counter[i]=one;
            for(int j=i+1;j<N;j++)
            {
                if(stockprice[i]==stockprice[j])
                    counter[i]=zero;
            }
        }
        number[i]+=max;
        maxnum=maxnum>number[i]?maxnum:number[i];
    }

    llint result;
    for(int i=0;i<10;i++)
        result.data[i]=0;

    for(int i=0;i<N;i++)
    {
        if(number[i]==maxnum)result=result+counter[i];
    }

    cout<<maxnum<<" ";
    cout<<result<<"\n";

    fout<<maxnum<<" ";
    for(int i=9;i>0;i--)
        if(result.data[i]!=0)fout<<result.data[i];
    fout<<result.data[0]<<"\n";

    return 0;
}
