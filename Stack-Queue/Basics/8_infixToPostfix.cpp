#include <iostream>
#include <stack>
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
        if((c >= 'a' && c <='z') || (c >= 'A' && c <= 'Z')) {
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

int main() {
    string infix = "A+(B*C-D)/E";
    string postfix = infixToPostfix(infix);
    cout << postfix;
}