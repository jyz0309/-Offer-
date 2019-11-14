//
// Created by alkaid on 2019/11/14.
//
#include <iostream>
#include <stack>

using namespace std;
/*
 * 以递归的方式逆序一个栈
 */
class ReverseStack{
public:
    int RemoveLast(stack<int> stack){
        // 函数作用：去除并返回栈的最底部元素
        int top = stack.top();
        stack.pop();
        if(stack.empty()) return top;
        else{
            int last = RemoveLast(stack);
            stack.push(top);
            return last;
        }
    }
    void Reverse(stack<int> stack){
        // 逆序
        if(stack.empty()) return;
        else{
            int i = RemoveLast(stack); //得到栈底元素
            Reverse(stack); //通过递归，将stack变为空，然后将原本处在栈顶的元素推入栈中
            stack.push(i);
        }
    }
};