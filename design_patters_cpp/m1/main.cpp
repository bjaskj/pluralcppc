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

int main() {
    openClosedPrinciple();
    return 0;
}

