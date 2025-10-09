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

string infixToPrefix(string infix) {
    for(int i=0; i<(infix.size()/2); i++)   swap(infix[i], infix[infix.size()-i-1]);
    for(int i=0; i<(infix.size()); i++) {
        if(infix[i]=='(')  infix[i] = ')';
        else if(infix[i]==')')    infix[i] = '(';
    }

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
    string prefix = postfix;
    for(int i=0; i<(prefix.size()/2); i++)   swap(prefix[i], prefix[prefix.size()-i-1]);
    return prefix;
}

bool isOperator(char op) {
    return (op=='+' || op=='-' || op=='*' || op=='/' || op=='^');
}

string prefixToInfix(string prefix) {
    stack<string> s;
    string infix = "";
    for(int i=prefix.length()-1; i>=0; i--) {
        char c = prefix[i];
        if((c >= 'a' && c <='z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            //cant directly do s.push(c) due to confict bw string and char
            string temp = "";
            temp += c;
            s.push(temp);
        }
        else if(isOperator(c)) {
            string op1 = s.top(); s.pop();
            string op2 = s.top(); s.pop();
            string expr = "(" + op1 + c + op2 + ")";
            s.push(expr);
        }
    }
    return s.top();    
}

int evaluatePrefix(string prefix) {
    stack<int> s;
    for(int i=prefix.length()-1; i>=0; i--) {
        char c = prefix[i];
        if(isdigit(c))  s.push(c-'0');
        else {
            int op1 = s.top(); s.pop();
            int op2 = s.top(); s.pop();
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
    string prefix = infixToPrefix(infix);
    cout << prefix << endl;
    infix = prefixToInfix(prefix);
    cout << infix << endl;

    string infix2 = "1+(2*3-4)";
    cout << evaluatePrefix(infixToPrefix(infix2));
}