#include "Stack.h"

using namespace std;

int main()
{
    char infix[100];
    char postfix[100];

    cout << "Enter infix expression: ";
    cin >> infix;

    infixToPostfix(infix, postfix);

    cout << "Postfix expression: " << postfix << endl;

    int result = evaluatePostfix(postfix);

    cout << "Result: " << result << endl;

    return 0;
}