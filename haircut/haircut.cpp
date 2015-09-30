
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void heapfy(int *intarray,int start,int length,int *real_index)
{
   int left=start*2;
   int right=start*2+1;
   int smallest=start;
   if ((left<=length)&&((intarray[left]<intarray[smallest])||(intarray[left]==intarray[smallest]&&(real_index[left]<real_index[smallest]))))
        smallest=left;
   if((right<=length)&&((intarray[right]<intarray[smallest])||(intarray[right]==intarray[smallest]&&(real_index[right]<real_index[smallest]))))
        smallest=right;

   if(smallest!=start)
   {
       int tmp=intarray[start];
       intarray[start]=intarray[smallest];
       intarray[smallest]=tmp;
       tmp=real_index[smallest];
       real_index[smallest]=real_index[start];
       real_index[start]=tmp;

       heapfy(intarray,smallest,length,real_index);

   }
}

//int extra_min(int *heap,int &length,int &value,int *real_index,int *heap_index)
//{
//    int result=real_index[1];
//    value=heap[1];
//    int tmp=heap[length];
//    heap[1]=heap[length];
//    tmp=real_index[length];
//    real_index[length]=real_index[1];
//    real_index[1]=tmp;
//    heap_index[real_index[length]]=length;
//    heap_index[real_index[1]]=1;
//
//    heap[length]=tmp;
//    length--;
//    heapfy(heap,1,length,real_index);
//    return result;
//}

int main()
{
    ifstream fin("B-large.in");
    ofstream fout("B-large.out");

    int T;
    fin>>T;
    for (int Test=1;Test<=T;Test++)
    {
        int B,N;
        fin>>B>>N;
        int minuite[B+1];
        for (int i=1;i<=B;i++)
            fin>>minuite[i];

        int thequeue[B+1];
        int real_index[B+1];
        for (int i=1;i<=B;i++)
        {
            thequeue[i]=0;
            real_index[i]=i;
        }

//        cout<<B<<endl;
//        for (int i=1;i<=B;i++)
//            cout<<real_index[i]<<" ";
//        cout<<"\n";

        int baber;
//        bool flag[B+1];
//        for (int i=1;i<=B;i++)
//            flag[i]=false;
//        int counter=0;

        baber=real_index[1];
        thequeue[1]+=minuite[baber];
        heapfy(thequeue,1,B,real_index);
        bool flag=false;
        int maxnum=1;
        for(int i=2;i<=N;i++)
        {
            baber=real_index[1];

            if (baber==1)
            {
                for(int i=2;i<=B;i++)
                {
                    flag=true;
                    if (thequeue[i]!=thequeue[1])
                    {
                        flag=false;
                        break;
                    }
                }
            }
            if(flag==true)
            {
                maxnum=i-1;
                break;
            }
            thequeue[1]+=minuite[baber];
            heapfy(thequeue,1,B,real_index);
            if(thequeue[1]>20000000)
            {
                for(int i=1;i<=B;i++)
                    thequeue[i]-=20000000;
            }
        }

        if(flag)
        {
            int n=N%maxnum;
            if(n==0)n=maxnum;
            for (int i=1;i<=B;i++)
            {
                thequeue[i]=0;
                real_index[i]=i;
            }
            for(int i=1;i<=n;i++)
            {
                baber=real_index[1];
                thequeue[1]+=minuite[baber];
                heapfy(thequeue,1,B,real_index);
                if(thequeue[1]>20000000)
                {
                    for(int i=1;i<=B;i++)
                        thequeue[i]-=20000000;
                }
            }
        }
        fout<<"Case #"<<Test<<": "<<baber<<"\n";
    }

    return 0;
}
