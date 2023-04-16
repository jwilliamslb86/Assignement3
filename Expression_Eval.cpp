/*  Using Stack, develop an Expression Manager that can do the following operations :
Infix to Postfix Conversion
• Read an infix expression from the user.
• Perform the Balanced Parentheses Check on the expression read.
•{ , }, (, ), [, ] are the only symbols considered for the check.All other characters can be ignored.
• If the expression fails the Balanced Parentheses Check, report a message to the user that the
expression is invalid.
• If the expression passes the Balanced Parentheses Check, convert the infix expression
• into a postfix expression and display it to the user.
• Operators to be considered are + , –, *, / , % .
*/


#include "Expression_Eval_Head.h"
#include <iostream>
#include <stack>
#include <string>
#include <cstring>



int main() {
    string expression;
    cout << "Enter an infix expression: ";
    getline(cin, expression);
    if (hasBalancedParentheses(expression)) {
        string postfix = infixToPostfix(expression);
        if (postfix == "") {
            cout << "Invalid expression" << endl;
        }
        else {
            cout << "Postfix expression: " << postfix << endl;
        }
    }
    else {
        cout << "Expression has unbalanced parentheses" << endl;
    }
    return 0;
}


