
#include <iostream>
#include <stack>
#include <cstring>



using namespace std;

// function to check if a given symbol is an operator
bool isOperator(char c);

// function to get the precedence of an operator
int getPrecedence(char c);

// function to convert an infix expression to postfix expression
string infixToPostfix(string expression);

// function to check if a given expression has balanced parentheses
bool hasBalancedParentheses(string expression);


