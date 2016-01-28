#include <iostream>
#include <cmath>
#include <vector>
#include <complex>
#include <random>

using namespace std;

int main() {
    cout << "Maximum integer is " <<
            numeric_limits<int>::max() << endl;

    cout << sin(M_PI / 2) << endl;

    vector<int> v{1,2,3,4};
    next_permutation(
            v.begin(), v.end()
    );

    for (auto i : v) {
        cout << i << "\t";
    }
    cout << endl;

    // complex
    complex<float> f(0.4f, 0.5f);
    cout << f*f << endl;

    // random numbers
    // old way
    srand((unsigned)time(nullptr));
    for (int i = 0; i < 100; ++i) {
        cout << rand() % 10 << "\t";
    }
    cout << endl;

    // new way
    auto seed = chrono::system_clock::now()
            .time_since_epoch().count();

    mt19937 gen(seed);
    normal_distribution<float> nd;

    for (size_t i; i < 100; i++) {
        cout << nd(gen) << "\t";
    }
    cout << endl;

    return 0;
}