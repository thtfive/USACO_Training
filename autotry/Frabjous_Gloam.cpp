#include <iostream>
#include <cstring>
using namespace std;

class Frabjous{
    char fab[20];
public:
    Frabjous(const char * s="C++")
    {
        strncpy(fab,s,19);
        fab[19]='\0';
    }
    virtual void tell(){cout<<fab;}
};

class Gloam : private Frabjous {
private:
    int glip;
public:
    Gloam(int g =0,const char * s="C++"):Frabjous(s),glip(g){}
    Gloam(int g,const Frabjous &f):Frabjous(f),glip(g){}
    void tell();
};

void Gloam::tell()
{
    cout<<glip<<endl;
    Frabjous::tell();
    cout<<endl;
}

int main()
{
    Gloam a;
    Gloam b(81,"javascript");
    a.tell();
    b.tell();
    return 0;
}

