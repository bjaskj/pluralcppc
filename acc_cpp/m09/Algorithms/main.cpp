#include <iostream>
#include <vector>

using namespace std;

struct Person {
    string name;
    int age;

    friend ostream& operator<<(ostream &os, const Person &p) {
        return os << p.name << " is " << p.age << " years old.";
    }
};

int main() {
    vector<Person> people{
            {"John", 27},
            {"Chris", 24},
            {"Ann", 31}
    };

    auto print_all = [&]() {
        cout << people.size() << " persons:" << endl;

        // old way
        for_each(begin(people), end(people), [](const Person &p) {
            cout << p << endl;
        });
    };

    print_all();

    // max
    auto oldest = *max_element(
            people.begin(),
            people.end(),
            [](const Person &a, const Person &b) {
                return a.age < b.age;
            }

    );

    cout << oldest.name << " is the oldest" << endl;

    // find
    auto john = find_if(
            people.begin(),
            people.end(),
            [](const Person &p) {
                return p.name == string("John");
            });

    if (john != people.end()) {
        cout << "Found " << john->name << " who is " << john->age << endl;
    }

    // count if
    auto youngerThan30 = count_if(
            people.begin(),
            people.end(),
            [](const Person &p) {
                return p.age < 30;
            }
    );

    cout << "Foud " << youngerThan30 << " people younger than 30" << endl;

    // sorting
    sort(
            people.begin(),
            people.end(),
            [](const Person &a, const Person &b) {
                return a.age < b.age;
            }
    );

    cout << "People sorted by age:" << endl;
    print_all();

    // replace
    cout << endl;
    cout << "Replace John with Jill." << endl;
    Person jill{"Jill", 44};
    replace_if(
            people.begin(),
            people.end(),
            [](const Person &p) {
                return p.name == "John";
            },
            jill
    );
    print_all();

    return 0;
}