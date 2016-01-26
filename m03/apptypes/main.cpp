#include <iostream>
#include <array>

using namespace std;

int main() {
    // pointers
    auto myInt = 10;
    auto *myPointedInt = &myInt;
    auto myDerefInt = *myPointedInt;

    cout << myDerefInt << endl;

    // References
    auto y = 123;
    auto &x = y;

    cout << y << endl;
    cout << x << endl;

    x = 321;

    cout << y << endl;

    // Arrays
    int numbers[] = { 1, 2, 3 };

    array<int, 3> values = { 1, 2, 3};

    cout << values.size() << endl;

    // char
    char c = 'c';

    // string
    auto text = u8"hello";

    cout << text << endl;

    cout << "Hello, World! Magic number: " << myDerefInt << endl;
    return 0;
}