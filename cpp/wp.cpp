#include "wp.h"

WhatsApp::WhatsApp()
{
    head = NULL;
    tail = NULL;
    current = NULL;
}

void WhatsApp::sendMessage(string sender, string msg)
{
    Node *newNode = new Node(sender, msg);

    if (head == NULL)
    {
        head = tail = current = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    cout << "Message Sent Successfully.\n";
}

void WhatsApp::displayForward()
{
    if (head == NULL)
    {
        cout << "No Messages.\n";
        return;
    }

    Node *temp = head;
    cout << "\nChat History (Forward)\n";

    while (temp != NULL)
    {
        cout << "Sender : " << temp->sender << endl;
        cout << "Message : " << temp->message << endl;
        cout << "-------------------------\n";

        temp = temp->next;
    }
}

void WhatsApp::displayBackward()
{
    if (tail == NULL)
    {
        cout << "No Messages.\n";
        return;
    }

    Node *temp = tail;
    cout << "\nChat History (Backward)\n";

    while (temp != NULL)
    {
        cout << "Sender : " << temp->sender << endl;
        cout << "Message : " << temp->message << endl;
        cout << "-------------------------\n";

        temp = temp->prev;
    }
}

void WhatsApp::editMessage(string oldMsg, string newMsg)
{
    Node *temp = head;

    while (temp != NULL)
    {
        if (temp->message == oldMsg)
        {
            temp->message = newMsg;
            cout << "Message Updated.\n";
            return;
        }

        temp = temp->next;
    }

    cout << "Message Not Found.\n";
}

void WhatsApp::deleteMessage(string msg)
{
    Node *temp = head;

    while (temp != NULL)
    {
        if (temp->message == msg)
        {
            if (temp == head && temp == tail)
            {
                head = tail = current = NULL;
            }
            else if (temp == head)
            {
                head = head->next;
                head->prev = NULL;

                if (current == temp)
                    current = head;
            }
            else if (temp == tail)
            {
                tail = tail->prev;
                tail->next = NULL;

                if (current == temp)
                    current = tail;
            }
            else
            {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;

                if (current == temp)
                    current = head;
            }

            delete temp;
            cout << "Message Deleted.\n";
            return;
        }

        temp = temp->next;
    }

    cout << "Message Not Found.\n";
}

void WhatsApp::searchByKeyword(string keyword)
{
    Node *temp = head;
    bool found = false;

    while (temp != NULL)
    {
        if (temp->message.find(keyword) != string::npos)
        {
            found = true;

            cout << "\nSender : " << temp->sender << endl;
            cout << "Message : " << temp->message << endl;
            cout << "----------------------\n";
        }

        temp = temp->next;
    }

    if (!found)
        cout << "Keyword Not Found.\n";
}

void WhatsApp::nextMessage()
{
    if (current == NULL)
    {
        cout << "No Messages.\n";
        return;
    }

    cout << "\nCurrent Message\n";
    cout << "Sender : " << current->sender << endl;
    cout << "Message : " << current->message << endl;

    if (current->next != NULL)
        current = current->next;
    else
        cout << "Reached Last Message.\n";
}

void WhatsApp::previousMessage()
{
    if (current == NULL)
    {
        cout << "No Messages.\n";
        return;
    }

    cout << "\nCurrent Message\n";
    cout << "Sender : " << current->sender << endl;
    cout << "Message : " << current->message << endl;

    if (current->prev != NULL)
        current = current->prev;
    else
        cout << "Reached First Message.\n";
}

void WhatsApp::statistics()
{
    if (head == NULL)
    {
        cout << "No Messages.\n";
        return;
    }

    int total = 0;
    int user1 = 0;
    int user2 = 0;

    Node *temp = head;

    while (temp != NULL)
    {
        total++;

        if (temp->sender == "User1")
            user1++;
        else if (temp->sender == "User2")
            user2++;

        temp = temp->next;
    }

    cout << "\nChat Statistics\n";
    cout << "Total Messages : " << total << endl;
    cout << "Messages by User1 : " << user1 << endl;
    cout << "Messages by User2 : " << user2 << endl;

    cout << "\nFirst Message\n";
    cout << head->message << endl;

    cout << "\nLast Message\n";
    cout << tail->message << endl;
}