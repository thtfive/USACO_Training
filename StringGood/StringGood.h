#ifndef STRINGGOOD_H_INCLUDED
#define STRINGGOOD_H_INCLUDED
#include<iostream>
class StringGood
{
    char *str;
    static int strnum;
    int len;
public:
    StringGood();
    StringGood(const char *s);
    StringGood(const StringGood &);
    friend std::ostream& operator<<(std::ostream &os,const StringGood& obj);
    StringGood & operator+(const StringGood &obj);
    StringGood & operator=(const StringGood &obj);
    char & operator[](int i);
    ~StringGood();
};

template <typename T>
class Stk
{
public:
    Stk &operator=(const Stk &st);
};


#endif // STRINGGOOD_H_INCLUDED
