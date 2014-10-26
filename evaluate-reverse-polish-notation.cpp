class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> rpn_stack;
        for (string token: tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") { 
                int op2 = rpn_stack.top();
                rpn_stack.pop();
                int op1 = rpn_stack.top();
                rpn_stack.pop();
                if (token == "+") rpn_stack.push(op1 + op2);
                else if (token == "-") rpn_stack.push(op1 - op2);
                else if (token == "*") rpn_stack.push(op1 * op2);
                else /* "/" */ rpn_stack.push(op1 / op2);
            } else {
                rpn_stack.push(atoi(token.c_str()));
            }
        }
        return rpn_stack.top();
    }
};