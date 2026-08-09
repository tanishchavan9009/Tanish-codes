#include "wp.h"

int main()
{
    WhatsApp chat;

    int choice;

    string sender;
    string message;
    string oldMessage;
    string keyword;

    do
    {
        cout << "\n====== WhatsApp Chat ======\n";

        cout << "1. Send Message\n";
        cout << "2. Display Forward\n";
        cout << "3. Display Backward\n";
        cout << "4. Edit Message\n";
        cout << "5. Delete Message\n";
        cout << "6. Search by Keyword\n";
        cout << "7. Next Message\n";
        cout << "8. Previous Message\n";
        cout << "9. Chat Statistics\n";
        cout << "10. Exit\n";

        cout << "Enter Choice : ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            cout << "Sender (User1/User2): ";
            getline(cin, sender);

            cout << "Message : ";
            getline(cin, message);

            chat.sendMessage(sender, message);
            break;

        case 2:
            chat.displayForward();
            break;

        case 3:
            chat.displayBackward();
            break;

        case 4:
            cout << "Enter Old Message : ";
            getline(cin, oldMessage);

            cout << "Enter New Message : ";
            getline(cin, message);

            chat.editMessage(oldMessage, message);
            break;

        case 5:
            cout << "Enter Message to Delete : ";
            getline(cin, message);

            chat.deleteMessage(message);
            break;

        case 6:
            cout << "Enter Keyword : ";
            getline(cin, keyword);

            chat.searchByKeyword(keyword);
            break;

        case 7:
            chat.nextMessage();
            break;

        case 8:
            chat.previousMessage();
            break;

        case 9:
            chat.statistics();
            break;

        case 10:
            cout << "Thank You.\n";
            break;

        default:
            cout << "Invalid Choice.\n";
        }

    } while (choice != 10);

    return 0;
}