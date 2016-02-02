#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

// Single responsibility principle

struct Journal {
    string title;
    vector<string> entries;

    explicit Journal(const string &title) : title{title} {

    }

    void add(const string &entry) {
        entries.push_back(entry);
    }
};

struct PersistenceManager {
    static void save(const Journal &j, const string &filename) {
        ofstream ofs(filename);
        for (auto &s : j.entries) {
            ofs << s << endl;
        }
    }
};

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}