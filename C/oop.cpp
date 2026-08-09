#include <iostream>
#include <exception>
using namespace std;


class InvalidAgeException : public exception {
public:
    const char* what() const noexcept {
        return "Age must be positive!";
    }
};

int main() {
    int age;
    
    cout << "Enter Age: ";
    cin >> age;

    try {
        if (age < 0)
            throw InvalidAgeException();

        cout << "Valid age: " << age;
    }
    catch (const exception &e) {
        cout << "Error: " << e.what();
    }

    return 0;
}