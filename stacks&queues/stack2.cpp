/*_Application of stack data structures_
->function calls are executed in lefo(stack) order
->checking for balanced paranthesis
->reversing of set of items(store them in stack and then pop them out)
->infix and postfix expression
->**stocks pan problems easily solved by stack implementation
->Undo/redo operation  (in lefo order)
*/

//Stacks in C++STL
//c++ stl has predefined functions inside <stack> header file
//All the operation  of stack work in O(1)
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout<<s.size()<<endl;
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.push(5);
    cout<<s.top()<<endl;
    
    while(s.empty()==false){
        cout<<s.top()<<endl;
        s.pop();
    }
    return 0; 
}

//balanced paranthesis problem
//to check wheather given string of paranthesis is balanced (i.e. opened and closed properly)
bool isBalanced(string str){
      
    stack<char> s; 
    
    for (int i = 0; i < str.length(); i++)  
    { 
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')  
        {  
            s.push(str[i]); 
        } 
        else{
        if (s.empty()==true) 
            return false;
        else if(matching(s.top(),str[i])==false)
            return false;
        else
            s.pop();
        }
    }    
    return (s.empty()==true); 
}

//Infix,Postfix,Prefix implimentation
//Infix->Postfix-->firstly parathesis the expression then apply postfix from inner bracket to outer
//example- a+b*(c-d) --> (a+(b*(c-d)))--> (a+(b*(cd-)))-->(a+(bcd-*))-->abcd-*+

//efficent approach
bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
        return true;
    }
    else {
        return false;
    }
}
int precedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}
string InfixToPrefix(stack<char> s, string infix)
{
    string prefix;
    reverse(infix.begin(), infix.end());

    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
        }
        else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }
    for (int i = 0; i < infix.length(); i++) {
        if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z')) {
            prefix += infix[i];
        }
        else if (infix[i] == '(') {
            s.push(infix[i]);
        }
        else if (infix[i] == ')') {
            while ((s.top() != '(') && (!s.empty())) {
                prefix += s.top();
                s.pop();
            }

            if (s.top() == '(') {
                s.pop();
            }
        }
        else if (isOperator(infix[i])) {
            if (s.empty()) {
                s.push(infix[i]);
            }
            else {
                if (precedence(infix[i]) > precedence(s.top())) {
                    s.push(infix[i]);
                }
                else if ((precedence(infix[i]) == precedence(s.top()))
                    && (infix[i] == '^')) {
                    while ((precedence(infix[i]) == precedence(s.top()))
                        && (infix[i] == '^')) {
                        prefix += s.top();
                        s.pop();
                    }
                    s.push(infix[i]);
                }
                else if (precedence(infix[i]) == precedence(s.top())) {
                    s.push(infix[i]);
                }
                else {
                    while ((!s.empty()) && (precedence(infix[i]) < precedence(s.top()))) {
                        prefix += s.top();
                        s.pop();
                    }
                    s.push(infix[i]);
                }
            }
        }
    }





