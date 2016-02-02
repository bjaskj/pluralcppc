#include <iostream>

using namespace std;

template <typename T> struct Maybe;

template <typename T> Maybe<T> maybe(T* context) {
    return Maybe<T>(context);
}

template <typename T> struct Maybe {
    T* context;

    explicit Maybe(T *context) : context {context} {
    }

    template <typename Func>
    auto With(Func evaluator) {
        if (context == nullptr) {
            return Maybe<typename remove_pointer<decltype(evaluator(context))>::type>(nullptr);
        } else {
            return maybe(evaluator(context));
        }
    }

    template <typename Func>
    auto Do(Func action) {
        if (context != nullptr) {
            action(context);
        }
        return *this;
    }
};

struct Address {
    string *houseName = nullptr;
};

struct Person {
    Address *address = nullptr;
};

void printHouseName(Person *p) {
    /* bad, unsafe:
    if (p != nullptr && p->address != nullptr && p->address->houseName != nullptr) {
        cout << *p->address->houseName << endl;
    }
    */

    // safe
    maybe(p)
            .With([](auto x) { return x->address; })
            .With([](auto x) { return x->houseName; })
            .Do([](auto x) { cout << *x << endl; });
}

int main() {
    Person p;
    p.address = new Address();
    p.address->houseName = new string("name");
    printHouseName(&p);
    delete p.address->houseName;
    delete p.address;

    return 0;
}