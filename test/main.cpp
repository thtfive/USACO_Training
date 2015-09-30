

//class Node
//{
//public:
//    int UserId;
//    double Value=10;
//    int Task;
//
//    Node();
//};
//
//class ManagedQueue
//{
//public:
//    Node *array;
//    ManagedQueue()
//    {
//        size=0;
//        maxsize=100;
//        array=new Node[maxsize];
//    }
//
//    bool enqueue(int UserId,int task)
//    {
//        Node tmp;
//        tmp.UserId=UserId;
//        tmp.Task=task;
//        array[size++]=tmp;
//    }
//
//    int Dequeue()
//    {
//        reorder();
//        return array[size--].Task;
//    }
//private:
//    int size;
//    int maxsize;
//
//    void reorder()
//    {
//         for (int i=0;i<size;i++)
//         {
//            switch(array[i].UserId)
//            {
//                case 1:array[i].Value+=1.2;break;
//                case 2:array[i].Value+=1.3;break;
//                case 3:array[i].Value+=1.5;break;
//                default:break;
//            }
//         }
//        Node tmp;
//        for (int i=0;i<size;i++)
//            for (int j=1;j<size;j++)
//            {
//                if (array[j-1].Value>array[j].Value)
//                {
//                    tmp=array[j-1];
//                    array[j-1]=array[j];
//                    array[j]=tmp;
//                }
//            }
//    }
//};

#include<iostream>
#include<fstream>
using namespace std;

#define max_N 100
int main()
{
    ifstream fin("input.in");
    ofstream fout("output.out");

    int array[max_N];
    int N=0;
    int tmp;
    while (fin>>tmp)array[N++]=tmp;

    int newarray[N];
    int current=1;
    int length=0;

    for (int i=0;i<N;i++)
    {
        if (array[i]==current)
        {
            fout<<current<<" ";
            current++;
            while(length>0&&current==newarray[length-1])
            {
                fout<<current<<" ";
                length--;
                current++;
            }
            fout<<"\n";


        }
        else
        {
            newarray[length++]=array[i];
            int idx=length-1;
            int temp;
            while (idx>0&&newarray[idx]>newarray[idx-1])
            {
                temp=newarray[idx];
                newarray[idx]=newarray[idx-1];
                newarray[idx-1]=temp;
            }
        }
        while (newarray[length-1]==current)
        {
            fout<<current<<"\n";
            current++;
        }


    }

    while (length>0)
    {
        fout<<newarray[length-1]<<"\n";
        length--;
    }

    return 0;
}
