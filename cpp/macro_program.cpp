#include <iostream>
#include <cstring>
using namespace std;

#define SAME(a,b) ((a)==(b))

#define MAX3(a,b,c) (((a)>(b)) ? (((a)>(c)) ? (a) : (c)) : (((b)>(c)) ? (b) : (c)))

#define SWAP(a,b) { int temp = a; a = b; b = temp; }

#define LEFTSHIFT(num,n) ((num) << (n))

#define ODDONES(num) (__builtin_popcount(num) % 2)

#define CONCAT3(result,s1,s2,s3) \
    strcpy(result,s1); \
    strcat(result,s2); \
    strcat(result,s3);

int main()
{
    int a, b, c;

    cout << "Enter first number: ";
    cin >> a;

    cout << "Enter second number: ";
    cin >> b;

    if(SAME(a,b))
        cout << "Both numbers are same." << endl;
    else
        cout << "Both numbers are different." << endl;

    cout << "Enter third number: ";
    cin >> c;

    cout << "Maximum = " << MAX3(a,b,c) << endl;

    cout << "\nBefore Swap:" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    SWAP(a,b);

    cout << "After Swap:" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    int num, n;

    cout << "\nEnter number for left shift: ";
    cin >> num;

    cout << "Enter number of bits: ";
    cin >> n;

    cout << "Result = " << LEFTSHIFT(num,n) << endl;

    int x;

    cout << "\nEnter number to check odd number of 1's: ";
    cin >> x;

    if(ODDONES(x))
        cout << "Number has odd number of 1's." << endl;
    else
        cout << "Number has even number of 1's." << endl;

    char s1[50], s2[50], s3[50], result[150];

    cout << "\nEnter first string: ";
    cin >> s1;

    cout << "Enter second string: ";
    cin >> s2;

    cout << "Enter third string: ";
    cin >> s3;

    CONCAT3(result,s1,s2,s3);

    cout << "Concatenated String = " << result << endl;

    return 0;
}