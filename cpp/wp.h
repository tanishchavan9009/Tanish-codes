#ifndef WHATSAPP_H
#define WHATSAPP_H

#include <iostream>
#include <string>

using namespace std;

struct Node
{
    string sender;
    string message;

    Node *prev;
    Node *next;

    Node(string s, string m)
    {
        sender = s;
        message = m;
        prev = NULL;
        next = NULL;
    }
};

class WhatsApp
{
private:
    Node *head;
    Node *tail;
    Node *current;

public:
    WhatsApp();

    void sendMessage(string sender, string msg);

    void displayForward();

    void displayBackward();

    void editMessage(string oldMsg, string newMsg);

    void deleteMessage(string msg);

    void searchByKeyword(string keyword);

    void nextMessage();

    void previousMessage();

    void statistics();
};

#endif