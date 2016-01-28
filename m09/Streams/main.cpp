#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

void input() {
    // boolean
    cout << "text " << 42 << " " << false << endl;
    cout << boolalpha;
    cout << true << " " << false << endl;

    // input
    int width;
    float height;
    cout << "Enter width: ";
    cin >> width;
    cout << "Enter height: ";
    cin >> height;

    auto area = width * height;
    cout << "Area = " << area << endl;

    // string
    ostringstream oss;
    oss << "Width is " << width << ", ";
    oss << "Height is " << height << ", ";
    oss << "Area is " << area << ", ";

    string text = oss.str();
    cout << text << endl;

    // file
    ofstream ofs("info.txt");
    string s;

    while ((cin >> s) && (s != "q")) {
        ofs << s << endl;
    }
}

int main() {
    input();

    return 0;
}