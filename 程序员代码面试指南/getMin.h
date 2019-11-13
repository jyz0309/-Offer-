//
// Created by alkaid on 2019/11/13.
//
#include <iostream>
#include <stack>
using namespace std;

class MinStack{
public:
    stack<int> s;
    stack<int> min;
    void push(int data){
        s.push(data); // 直接入栈
        if(!min.empty()&&data<min.top()) min.push(data); //检测最小栈中是否有元素，如果有元素且栈顶元素大于data，则将data入栈
        else if(min.empty()) min.push(data); //如果无元素，则直接入栈
    }
    int pop(){
        int current = s.top(); //取出栈顶元素
        s.pop(); //弹出
        if(!min.empty()&&current==min.top()) min.pop(); //检测最小栈是否需要弹出元素
        return current;
    }
    int getMin(){
        return min.top();
    }
};