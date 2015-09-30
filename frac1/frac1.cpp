/*
ID:thtfive
LANG:C++
TASK:frac1
*/
#include<iostream>
#include<fstream>
using namespace std;
class Point
{
    public:
    long double x;
    long double y;
    Point *next;
    Point(){next=NULL;}
};

class orderque
{
    public:
        Point *root;
        orderque()
        {
            root=NULL;
        }
        bool insertdata(long double x,long double y)
        {
            if (root==NULL)
            {
                root=new Point;
                root->x=x;
                root->y=y;
            }
            else
            {
                Point *p=root;
                Point *previous=NULL;
                Point *tmp;
                if(p->x/p->y>x/y)
                {
                    tmp=new Point;
                    tmp->x=x;
                    tmp->y=y;
                    tmp->next=root;
                    root=tmp;
                }
                if(p->x/p->y==x/y)
                {
                    return false;
                }
                else
                {
                    while(p->x/p->y<x/y)
                    {
                        previous=p;
                        p=p->next;
                        if (p==NULL)
                        {
                            p=new Point;
                            p->x=x;
                            p->y=y;
                            previous->next=p;
                            return true;
                        }
                    }
                    if (p->x/p->y!=x/y)
                    {
                        tmp=new Point;
                        tmp->x=x;
                        tmp->y=y;
                        tmp->next=p;
                        previous->next=tmp;
                        return true;
                    }
                    else return false;
                }
                cout<<x<<" "<<y<<"\n";
                return true;
            }
        }

        void search()
        {
            Point *p=root;
            while(p!=NULL)
            {
                cout<<p->x<<" "<<p->y<<endl;
                p=p->next;
            }
        }

        Point front()
        {
            return *root;
        }

        void pop()
        {
            if(root!=NULL)
            {
                root=root->next;

            }
            else
                root=NULL;
        }
        bool isempty()
        {
            if(root==NULL)return true;
            return false;
        }
    private:
};
int main()
{
    ifstream fin("frac1.in");
    ofstream fout("frac1.out");
    int N;
    fin>>N;
    orderque que;

    for (long double i=1;i<=N;i++)
        for (long double j=0;j<=i;j++)
            que.insertdata(j,i);



   // que.search();


    while(!que.isempty())
    {
        fout<<que.front().x<<"/"<<que.front().y<<"\n";
        cout<<que.front().x<<"/"<<que.front().y<<"\n";
        que.pop();
    }




    return 0;
}
