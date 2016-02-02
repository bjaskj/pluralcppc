#include <iostream>
#include <cassert>
//#include "libtest_project/test.h"

using namespace std;

#if DEBUG
void foo() {}
#endif

#define MUL(a,b) a * b

int main() {
    assert(MUL(2, 4) == 8);

    //cout << add(1, 2) << endl;

    cout << "Hello, C++" << endl;
    cout << "Something else" << endl;

    return 0;
}

