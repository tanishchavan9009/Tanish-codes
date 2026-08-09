#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int ItemCode;
    string ItemName;
    Node *next;
};

class ItemList
{
    Node *head;
    Node *tail;

public:

    ItemList()
    {
        head = NULL;
        tail = NULL;
    }

    void addItem(int code, string name)
    {
        Node *temp = new Node;

        temp->ItemCode = code;
        temp->ItemName = name;
        temp->next = NULL;

        if(head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }

    void Display()
    {
        if(head == NULL)
        {
            cout << "List is Empty" << endl;
            return;
        }

        Node *temp = head;

        while(temp != NULL)
        {
            cout << "Item Code : " << temp->ItemCode << endl;
            cout << "Item Name : " << temp->ItemName << endl;
            cout << endl;

            temp = temp->next;
        }
    }

    int search(int code)
    {
        Node *temp = head;

        while(temp != NULL)
        {
            if(temp->ItemCode == code)
                return 1;

            temp = temp->next;
        }

        return 0;
    }

    void remove(int code)
    {
        if(head == NULL)
        {
            cout << "List is Empty" << endl;
            return;
        }

        Node *temp = head;
        Node *prev = NULL;

        while(temp != NULL && temp->ItemCode != code)
        {
            prev = temp;
            temp = temp->next;
        }

        if(temp == NULL)
        {
            cout << "Item Not Found" << endl;
            return;
        }

        if(temp == head)
        {
            head = head->next;

            if(head == NULL)
                tail = NULL;
        }
        else
        {
            prev->next = temp->next;

            if(temp == tail)
                tail = prev;
        }

        delete temp;

        cout << "Item Deleted" << endl;
    }
};

int main()
{
    ItemList obj;

    obj.addItem(101, "Pen");
    obj.addItem(102, "Book");
    obj.addItem(103, "Pencil");

    cout << "Items in List" << endl;
    obj.Display();

    if(obj.search(102))
        cout << "Item Found" << endl;
    else
        cout << "Item Not Found" << endl;

    obj.remove(102);

    cout << "\nList After Deletion" << endl;
    obj.Display();

    return 0;
}