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

// ====================================================================
// Open-closed principle

enum class Color {Red, Green, Blue};
enum class Size {Small, Medium, Large};

struct Product {
    string name;
    Color color;
    Size size;
};

// bad filter

struct ProductFilter {
    typedef vector<Product*> Items;

    static Items by_color(Items items, Color color) {
        Items results;
        for (auto &i : items) {
            if (i->color == color) {
                results.push_back(i);
            }
        }

        return results;
    }

    static Items by_size(Items items, Size size) {
        Items results;
        for (auto &i : items) {
            if (i->size == size) {
                results.push_back(i);
            }
        }

        return results;
    }

    static Items by_color_and_size(Items items, Color color, Size size) {
        Items results;
        for (auto &i : items) {
            if (i->size == size && i->color == color) {
                results.push_back(i);
            }
        }

        return results;
    }
};

// Better filter

template <typename T> struct ISpecification {
    virtual bool is_satisfied(T* item) = 0;
};

template <typename T> struct IFilter {
    virtual vector<T*> filter(vector<T*> items, ISpecification<T> &spec) = 0;
};

struct BetterFilter : IFilter<Product> {
    typedef vector<Product*> Items;

    virtual Items filter(Items items, ISpecification<Product> &spec) override {
        Items result;
        for (auto &p : items) {
            if (spec.is_satisfied(p)) {
                result.push_back(p);
            }
        }

        return result;
    }
};

struct ColorSpecification : ISpecification<Product> {
    Color color;

    explicit ColorSpecification(const Color color)
            : color{color} {
    }

    bool is_satisfied(Product *item) override {
        return item->color == color;
    }
};

struct SizeSpecification : ISpecification<Product> {
    Size size;

    explicit SizeSpecification(const Size size)
            : size{size} {
    }

    bool is_satisfied(Product *item) override {
        return item->size == size;
    }
};

template <typename T> struct AndSpecification : ISpecification<T> {
    ISpecification<T> &first;
    ISpecification<T> &second;

    AndSpecification(ISpecification<T> &first, ISpecification<T> &second)
            : first(first), second(second) {

    }

    bool is_satisfied(T *item) override {
        return first.is_satisfied(item) && second.is_satisfied(item);
    }
};


void openClosedPrinciple() {
    Product apple{"Apple", Color::Green, Size::Small};
    Product tree{"Tree", Color::Green, Size::Large};
    Product house{"House", Color::Blue, Size::Large};

    vector<Product*> all{&apple, &tree, &house};

    BetterFilter bf;
    ColorSpecification green_spec(Color::Green);

    auto green_things = bf.filter(all, green_spec);
    for (auto &x : green_things) {
        cout << x->name << " is green." << endl;
    }

    SizeSpecification big_spec(Size::Large);
    AndSpecification<Product> green_and_big{ big_spec, green_spec };

    auto green_big_things = bf.filter(all, green_and_big);
    for (auto &x : green_big_things) {
        cout << x->name << " is green and large." << endl;
    }
}

// ====================================================================
// Liskov Substituion Principle

class Rectangle {
protected:
    int width, height;
public:

    Rectangle(int width, int height) : width(width), height(height) { }

    virtual int getWidth() const {
        return width;
    }

    virtual void setWidth(int width) {
        Rectangle::width = width;
    }

    virtual int getHeight() const {
        return height;
    }

    virtual void setHeight(int height) {
        Rectangle::height = height;
    }

    int Area() const {
        return width*height;
    }
};

class Square : public Rectangle {
public:
    Square(int size) : Rectangle{size, size} {}

    virtual void setWidth(int width) override {
        this->width = height = width;
    }

    virtual void setHeight(int height) override {
        this->height = width = height;
    }
};

void process(Rectangle &r) {
    int w = r.getWidth();
    r.setHeight(10);

    cout << "Expect area = " << (w*10) << ", got " << r.Area() << endl;
}

void liskov() {
    Rectangle r{5, 5};
    process(r);

    Square s{5};
    process(s);
}

// ====================================================================
// Interface Segregation Principle

struct Document;
/* bad:
struct IMachine {
    virtual void print(vector<Document*> docs) = 0;
    virtual void scan(vector<Document*> docs) = 0;
    virtual void fax(vector<Document*> docs) = 0;
};

struct MFP : IMachine {
    void print(vector<Document *> docs) override {}
    void scan(vector<Document *> docs) override {};
    void fax(vector<Document *> docs) override {};
};
*/

struct IPrinter {
    virtual void print(vector<Document*> docs) = 0;
};

struct IScanner {
    virtual void scan(vector<Document*> docs) = 0;
};

struct Printer : IPrinter {
    void print(vector<Document *> docs) override {

    }
};

struct Scanner : IScanner {
    void scan(vector<Document *> docs) override {

    }
};

struct IMachine : IPrinter, IScanner {};

struct Machine : IMachine {
    IPrinter &printer;
    IScanner &scanner;


    Machine(IPrinter &printer, IScanner &scanner)
            : printer(printer),
              scanner(scanner) { }

    void print(vector<Document *> docs) override {
        printer.print(docs);
    }

    void scan(vector<Document *> docs) override {
        scanner.scan(docs);
    }
};


void interfaceSegregationPrinciple() {

}

// ====================================================================
// Dependency Injection with Boost.DI

#include "di.hpp"

struct Engine {
    float volume = 5;
    int horse_power = 400;

    friend ostream&operator<<(ostream &os, const Engine &obj) {
        return os
               << "volume: " << obj.volume
               << "horse_power: " << obj.horse_power;
    }
};

struct Car {
    shared_ptr<Engine> engine;

    friend ostream&operator<<(ostream &os, const Car &obj) {
        return os
               << "car with engie: " << *obj.engine;
    }

    Car(const shared_ptr<Engine> &engine) : engine(engine) {
    }
};

void dep_inject_boost() {
    auto e = make_shared<Engine>();
    auto car = make_shared<Car>(e);

    cout << *car << endl;
}

int main() {
    dep_inject_boost();
    return 0;
}
