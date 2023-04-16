# Assignement3
Infix to Postfix Function and Queue implementation

1. Expression Evaluation function takes user input requesting an infix expression.
2. The boolean function "hasBalancedParentheses" takes string value from user input and iterates over the length of the string and ensures matching parenths.
3. It does this by placing left parentheses into a Stack and popping the top element when the match is found returning the value of s.empty().
4. If false, "Expression has unbalanced parentheses" is returned.
5. If true, the returned value of "infixToPostfix" function is returned via "postfix" string variable in main function.
6. The "infixToPostfix" function iterates over the length of the expression ignoring spaces and adding digits 0-9 and operators (+,-,*,/,%).
7. Adds characters directly to postfix string varibale.
8. Pushes parentheses and operators to a stack in order of precedence. 
9. Pops matching parentheses when the right hand match is compared to it's left hand.
10. If an invalid symbol is in the string, postfix variable becomes an empty string and the loop is broken.
11. 11. If the postfix variable is an empty string, "Invalid expression is returned.
