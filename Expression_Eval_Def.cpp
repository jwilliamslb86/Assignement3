#ifndef _EXPRESSION_EVAL
#define _EXPRESSION_EVAL

#include"Expression_Eval_Head.h"
#include <iostream>
#include <stack>
#include<cstring>
#include <string>

using namespace std;

// function to check if a given symbol is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
}

// function to get the precedence of an operator
int getPrecedence(char c) {
    if (c == '+' || c == '-') {
        return 1;
    }
    else if (c == '*' || c == '/' || c == '%') {
        return 2;
    }
    else {
        return 0;
    }
}

// function to convert an infix expression to postfix expression
string infixToPostfix(string expression) {
    stack<char> s;
    string postfix = "";
    for (int i = 0; i < expression.length(); i++) {
        if (expression[i] == ' ' || expression[i] == '\t') {
            continue;
        }
        if (expression[i] >= '0' && expression[i] <= '9') {
            postfix += expression[i];
        }
        else if (isOperator(expression[i])) {
            while (!s.empty() && s.top() != '(' && getPrecedence(s.top()) >= getPrecedence(expression[i])) {
                postfix += s.top();
                s.pop();
            }
            s.push(expression[i]);
        }
        else if (expression[i] == '(') {
            s.push(expression[i]);
        }
        else if (expression[i] == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            if (!s.empty() && s.top() == '(') {
                s.pop();
            }
        }
        else {
            // invalid symbol
            cout << "Invalid symbol found: " << expression[i] << endl;
            postfix = "";
            break;
        }
    }
    while (!s.empty() && s.top() != '(') {
        postfix += s.top();
        s.pop();
    }
    return postfix;
}

// function to check if an expression has balanced parentheses
bool hasBalancedParentheses(string expression) {
    stack<char> s;
    for (int i = 0; i < expression.length(); i++) {
        if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[') {
            s.push(expression[i]);
        }
        else if (expression[i] == ')' || expression[i] == '}' || expression[i] == ']') {
            if (s.empty()) {
                return false;
            }
            char top = s.top();
            s.pop();
            if ((expression[i] == ')' && top != '(') || (expression[i] == '}' && top != '{') || (expression[i] == ']' && top != '[')) {
                return false;
            }
        }
    }
    return s.empty();
}

#endif