#include "StringGood.h"
#include <iostream>
#include <cstring>
int StringGood:: strnum=0;

StringGood ::StringGood()
{
    strnum++;
    len=7;
    str=new char[len+1];
    std::strcpy(str,"default");
    str[len]='\0';
    std::cout<< "string #" << strnum << ": \"" << str << "\" created.\n";
}

StringGood:: StringGood(const char *s)
{
    strnum++;
    len=std::strlen(s);
    str=new char[len+1];
    std::strcpy(str,s);
    str[len]='\0';
    std::cout<<"string #"<<strnum<<": \""<<str <<"\" created.\n";
}
StringGood:: StringGood(const StringGood &obj)
{
    strnum++;
    len=obj.len;
    str=new char[len+1];
    std::strcpy(str,obj.str);
    str[len]='\0';
    std::cout<<"string #"<<strnum<<": \""<<str <<"\" created.\n";
}

std::ostream& operator<<(std::ostream &os,const StringGood &obj)
{
    os<<"string "<<": "<<obj.str<<"\n";
    return os;
}

StringGood& StringGood::operator=(const StringGood& obj)
{
    if(this==&obj)return *this;
    delete []str;
    len=obj.len;
    str=new char[len+1];
    std::strcpy(str,obj.str);
    return *this;
}
char & StringGood::operator[](int i)
{
    return *(str+i);
}
StringGood:: ~StringGood()
{
    std::cout<<"string #"<<strnum<<": \""<<str <<"\" destroyed.\n";
    strnum--;
    delete []str;
}

template <typename T>
Stk<T>& Stk<T>::operator=(const Stk& st)
{
    return st;
}
