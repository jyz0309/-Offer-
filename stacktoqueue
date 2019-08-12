/*
题目要求：用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
解题思路：使用两个栈，在元素入队的时候，将其直接推入stack1中，在进行弹出操作的时候，将stack1的元素依次弹出并推入stack2中，
这时stack2的栈顶元素就是需要弹出的元素。在弹出元素之后，将stack2的栈中元素依次弹出并推入回去stack1中。
*/
class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        while(!stack1.empty()){
            stack2.push(stack1.top());
            stack1.pop();
        }
        int top = stack2.top();
        stack2.pop();
        while(!stack2.empty()){
            stack1.push(stack2.top());
            stack2.pop();
        }
        return top;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};
