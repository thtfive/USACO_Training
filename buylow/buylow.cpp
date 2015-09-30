/*
ID:thtfive
LANG:C++
TASK:buylow
*/
#include<iostream>
#include<fstream>
using namespace std;
///该题用动态规划的方法计算出最大的长度，并利用counter数组来记录相应的可能的方法数量
class llint///这个类用于储存长度较长的数字，一共有10位，大约可以储存长度为70位的数字
{
public:
    int data[10];
    llint()
    {
        for (int i=0;i<10;i++)data[i]=0;
    }
    llint &operator+(const llint &num1)///重载+ 操作
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

    llint &operator=(const llint num)///重载=
    {
        for(int i=0;i<10;i++)
            data[i]=num.data[i];
        return *this;
    }

};

ofstream & operator<<(ofstream &os,const llint &obj)///重载<<
{
    for (int i=9;i>0;i--)
    {
        if(obj.data[i]!=0)os<<obj.data[i];
    }
    os<<obj.data[0];
    return os;
}

ostream & operator<<(ostream &os,const llint &obj)///重载标准<<
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

    int maxnum=0;///maxnum 用于记录最大长度
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

        for (int j=i+1;j<N;j++)///对于两天相同的股价
        {
            if(stockprice[j]==stockprice[i]&&max+1==number[j])
                break;
            if(number[j]==max&&stockprice[j]<stockprice[i])
            {
                counter[i]=counter[i]+counter[j];
            }
        }

        if(max==0)///对于某一天的股价在它后面没有比它更小的股价，如果后面有相同的股价，则该天的股价的可能性记录置为0，否则1
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
