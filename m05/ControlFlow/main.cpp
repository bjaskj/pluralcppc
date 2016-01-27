#include <iostream>
#include <vector>

using namespace std;

void iteration() {
    int a[]{1, 2, 3, 4};

    for (int i = 0; i < 4; ++i) {
        cout << a[i] << "\t";
    }
    cout << endl;

    // pointer example
    for (int *p = a, *e = a + 4; p != e; ++p) {
        cout << *p << "\t";
    }
    cout << endl;

    //
    auto ba = begin(a);
    auto ea = end(a);

    for (; ba != ea; ba++) {
        cout << *ba << "\t";
    }
    cout << endl;

    // for
    for (auto value : a) {
        cout << value << "\t";
    }
    cout << endl;

    //
    vector<int> v{5, 6, 7, 8};

    auto bv = v.begin();
    auto cbv = v.cbegin();

    for (auto i = v.rbegin(); i != v.rend(); ++i) {
        cout << *i << "\t";
    }
    cout << endl;
}

void switching() {
    int i = 1;
    switch (i) {
        case 0:
            cout << "hello" << endl;
            break;
        case 1:
            cout << "world" << endl;
            break;
        default:
            cout << "!" << endl;
    }
}

void boolean_conversion() {
    char *s = "Pluralsight";

    while (*s) {
        putchar(*s);
        s++;
    }

    int *p = nullptr;
    if (p) {
        cout << "Wait a minute?!";
    }
}

int main() {
    boolean_conversion();
    return 0;
}