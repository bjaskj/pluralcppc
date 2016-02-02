#include <iostream>
#include <array>
#include <vector>
#include <set>
#include <map>

using namespace std;

template <typename array>
int sum_array(array values) {
    int result = 0;
    for (int value : values) {
        result += value;
    }

    return result;
}

void containers_array() {
    array<int, 5> numbers = {{1, 2, 3, 4, 5}};
    array<int, 3> otherNumbers = {{1, 2, 3}};
    cout << sum_array(numbers) << endl;
    cout << sum_array(otherNumbers) << endl;

    vector<float> values{1, 2, 3};
    values.push_back(4.5f);
    values.push_back(5);
    values.pop_back();

    // float v = values[5];

    try {
        float u = values.at(5);
    }
    catch (const std::out_of_range &e) {
        cout << e.what() << endl;
    }


    cout << "There are " << values.size() << " values" << endl;
    for (auto value : values) {
        cout << value << "\t";
    }
    cout << endl;

    // set
    string speech("to be, or not to be, that is the question");
    set<char> letters;
    for (char c : speech) {
        if (isalpha(c)) {
            letters.insert(c);
        }
    }

    for (char c : letters) {
        cout << c << "\t";
    }
    cout << endl;

    // map
    cout << endl;
    cout << "Mapping:" << endl;
    map<char, int> histogram;

    for (char c : speech) {
        if (isalpha(c)) {
            histogram[c]++; // no need to init
        }
    }

    for (auto u : histogram) {
        cout << u.first << " - " << u.second << endl;
    }
}

int main() {
    containers_array();
    return 0;
}