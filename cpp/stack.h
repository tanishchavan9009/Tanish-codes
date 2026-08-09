#include<iostream>
#include<climits>
#include<cstdlib>

struct Node
{
    char data;
    Node *next;
};

class Stack
{
    Node *top;

public:
    Stack();

    void push(char value);
    char pop();
    char peek();
    bool isEmpty();
};

int priority(char ch);

void infixToPostfix(char infix[], char postfix[]);

int evaluatePostfix(char postfix[]);