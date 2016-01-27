#include <string>
#include <iostream>

namespace life {
    auto meaning = 42;
    auto* pm = &meaning;
    auto& rm = meaning;
}

void name_space_stuff() {
    std::cout << "Hello, World!" << std::endl;

    // using namespace life;
    // using life::meaning;

    std::cout << life::meaning << " takes up " << sizeof(life::meaning) << " bytes" << std::endl;

    *life::pm = 43;

    std::cout << life::meaning << std::endl;
    life::rm = 42;
    std::cout << life::meaning << std::endl;
}

// ================================

inline int add(int a, int b) {
    return a + b;
}

auto add2(int a, int b) -> int {
    return a + b;
}

void increase(int& a) { a++; }

// ================================

void string_stuff() {
    std::string s("hello");
    std::string* t = new std::string("world");

    delete t;

    int* values = new int[128];

    delete[] values;
}

// ================================

void lambda_functions() {
    int x = 4;

    auto doubleValue = [](int z) { return z * 2; };

    std::cout << x << "*2 = " << doubleValue(x) << std::endl;

    int y = 5;

    auto increaseByY = [&y](int z) { return y + z; };

    y = 100;

    std::cout << "The result of 4+y = " << increaseByY(x) << std::endl;
}

// ================================

enum Color {
    Red,
    Green,
    Blue
};

enum class GameState {
    Win,
    Lose
};

void enumerations() {
    Color c = Red;
    int i = c;

    GameState gs = GameState::Win;
}

// ================================

union Data {
    int integer;
    float fpnumber;
    char* text;
};

void unions() {
    Data d;
    d.fpnumber = 0.5f;
}

// ================================

struct Size {
    int width, height;
};

void structures() {
    Size s{15, 10};
}

int main(int argc, char* argv[]) {
    // std::cout << argv[0] << std::endl;
    structures();
    return 0;
}