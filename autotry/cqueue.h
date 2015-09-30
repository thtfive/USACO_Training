#ifndef CQUEUE_H_INCLUDED
#define CQUEUE_H_INCLUDED
#include <iostream>
#include <stack>
#include <vector>
#include <fstream>
#include <cstring>
#include <exception>
using namespace std;
template <typename T>
class CQueue
{
private:
    stack<T> stack1;
    stack<T> stack2;
public:
    CQueue(){}
    ~CQueue(){}
    void appendTail(const T& node);
    T deleteHead();
};

template <typename T>
void CQueue<T>::appendTail(const T& node)
{
    stack1.push(node);
}

template <typename T>
T CQueue<T>::deleteHead()
{
    if(stack2.empty())
    {
        while(!stack1.empty())
        {
            T &data=stack1.top();
            stack2.push(data);
            stack1.pop();
        }
    }
    if(stack2.empty())
    {
    }
    T head=stack2.top();
    stack2.pop();
    return head;
}
#endif // CQUEUE_H_INCLUDED
