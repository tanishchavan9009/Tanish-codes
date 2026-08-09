#include "Stack.h"

using namespace std;

// Constructor
Stack::Stack()
{
    top = NULL;
}

// Push
void Stack::push(char value)
{
    Node *newNode = new Node;

    newNode->data = value;
    newNode->next = top;

    top = newNode;
}

// Pop
char Stack::pop()
{
    if (top == NULL)
    {
        cout << "Stack Underflow!" << endl;
        exit(1);
    }

    Node *temp = top;
    char value = top->data;

    top = top->next;

    delete temp;

    return value;
}

// Peek
char Stack::peek()
{
    if (top == NULL)
    {
        return CHAR_MIN;
    }

    return top->data;
}

// Check whether stack is empty
bool Stack::isEmpty()
{
    return top == NULL;
}

// Operator priority
int priority(char ch)
{
    if (ch == '^')
        return 3;

    if (ch == '*' || ch == '/')
        return 2;

    if (ch == '+' || ch == '-')
        return 1;

    return 0;
}

// Infix to Postfix
void infixToPostfix(char infix[], char postfix[])
{
    Stack s;

    int i = 0;
    int j = 0;

    while (infix[i] != '\0')
    {
        char ch = infix[i];

        // Operand
        if (ch >= '0' && ch <= '9')
        {
            postfix[j] = ch;
            j++;
        }

        // Opening bracket
        else if (ch == '(')
        {
            s.push(ch);
        }

        // Closing bracket
        else if (ch == ')')
        {
            while (!s.isEmpty() && s.peek() != '(')
            {
                postfix[j] = s.pop();
                j++;
            }

            if (!s.isEmpty())
            {
                s.pop();
            }
        }

        // Operator
        else
        {
            while (!s.isEmpty() &&
                   s.peek() != '(' &&
                   priority(s.peek()) >= priority(ch))
            {
                postfix[j] = s.pop();
                j++;
            }

            s.push(ch);
        }

        i++;
    }

    // Pop remaining operators
    while (!s.isEmpty())
    {
        postfix[j] = s.pop();
        j++;
    }

    postfix[j] = '\0';
}

// Evaluate Postfix
int evaluatePostfix(char postfix[])
{
    Stack s;

    int i = 0;

    while (postfix[i] != '\0')
    {
        char ch = postfix[i];

        // Operand
        if (ch >= '0' && ch <= '9')
        {
            int value = ch - '0';
            s.push(value);
        }

        // Operator
        else
        {
            int b = s.pop();
            int a = s.pop();

            int result;

            switch (ch)
            {
            case '+':
                result = a + b;
                break;

            case '-':
                result = a - b;
                break;

            case '*':
                result = a * b;
                break;

            case '/':
                if (b == 0)
                {
                    cout << "Division by zero!" << endl;
                    exit(1);
                }

                result = a / b;
                break;

            case '^':
                result = 1;

                for (int k = 0; k < b; k++)
                {
                    result = result * a;
                }

                break;

            default:
                cout << "Invalid operator!" << endl;
                exit(1);
            }

            s.push(result);
        }

        i++;
    }

    return s.pop();
}