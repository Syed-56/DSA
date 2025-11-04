#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

int precedence(char op) {
    if(op=='^')  return 3;
    else if(op=='*' || op=='/')  return 2;
    else if(op=='+' || op=='-')  return 1;
    else return -1;
}

string infixToPostfix(string infix) {
    stack<char> s;
    string postfix = "";

    for(int i=0; i<infix.length(); i++) {
        char c = infix[i];
        if((c >= 'a' && c <='z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            postfix += c;
        }
        else if(c == '(')  s.push('(');
        else if(c==')') {
            while(!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            if(s.top()=='(')    s.pop();
        }
        else {
            while(!s.empty() && precedence(c) <= precedence(s.top())) {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }
    while(!s.empty()) {
        postfix += s.top();
        s.pop();
    }
    return postfix;
}

bool isOperator(char op) {
    return (op=='+' || op=='-' || op=='*' || op=='/' || op=='^');
}

string postfixToInfix(string postfix) {
    stack<string> s;
    string infix = "";
    for(int i=0; i<postfix.length(); i++) {
        char c = postfix[i];
        if((c >= 'a' && c <='z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            //cant directly do s.push(c) due to confict bw string and char
            string temp = "";
            temp += c;
            s.push(temp);
        }
        else if(isOperator(c)) {
            string op2 = s.top(); s.pop();
            string op1 = s.top(); s.pop();
            string expr = "(" + op1 + c + op2 + ")";
            s.push(expr);
        }
    }
    return s.top();
}

int evaluatePostfix(string postfix) {
    stack<int> s;
    for(int i=0; i<postfix.size(); i++) {
        char c = postfix[i];
        if(isdigit(c))  s.push(c-'0');
        else {
            int op2 = s.top(); s.pop();
            int op1 = s.top(); s.pop();
            int result = 0;

            switch (c) {
                case '+': result = op1+op2; break;
                case '-': result = op1-op2; break;
                case '*': result = op1*op2; break;
                case '/': result = op1/op2; break;
                case '^': result = pow(op1,op2); break;
                default: break;
            }
            s.push(result);
        }
    }
    return s.top();
}

int main() {
    string infix = "A+(B*C-D)/E";
    string postfix = infixToPostfix(infix);
    cout << postfix << endl;
    infix = postfixToInfix(postfix);
    cout << infix << endl;

    string infix2 = "1+(2*3-4)";
    cout << evaluatePostfix(infixToPostfix(infix2));
}