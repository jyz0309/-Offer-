//
// Created by alkaid on 2019/11/13.
//

#include <iostream>
#include <stack>
using namespace std;
class TwoStacksQuque{
public:
    stack<int> stackPush;
    stack<int> stackPop;
    void push(int data){
        stackPush.push(data); //直接往Push栈中推入元素
    }
    int pop(){
        while(!stackPush.empty()){ //首先将Push栈中的元素全部推入Pop栈中
            stackPop.push(stackPush.top());
            stackPush.pop();
        }
        int _result = stackPop.top(); //将Pop栈中的栈首元素弹出
        stackPop.pop();
        while(!stackPop.empty()){ //重新入栈
            stackPush.push(stackPop.top());
            stackPop.pop();
        }
        return _result;
    }
};