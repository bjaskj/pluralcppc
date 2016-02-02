#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <memory>

// builder

class HtmlBuilder;

struct HtmlElement {
    std::string name;
    std::string text;
    std::vector<HtmlElement> elements;
    const size_t indent_size = 2;

    HtmlElement(){};

    HtmlElement(const std::string &name, const std::string &text)
            : name(name), text(text) { }

    std::string str(int indent = 0) const {
        std::ostringstream oss;
        std::string i(indent_size * indent, ' ');
        oss << i << "<" << name << ">" << std::endl;

        if (text.size() > 0) {
            oss << std::string(indent_size * (indent+1), ' ') << text << std::endl;
        }

        oss << "found " << elements.size() << " elements" << std::endl;

        for (const auto &e : elements) {
            oss << e.str(indent+1);
        }

        oss << i << "</" << name << ">" << std::endl;
        return oss.str();
    }

    static HtmlBuilder build(std::string root_name);
    static std::unique_ptr<HtmlBuilder> create(std::string root_name);
};

struct HtmlBuilder {
    HtmlBuilder(std::string root_name) {
        root.name = root_name;
    }

    HtmlBuilder & add_child(std::string child_name, std::string child_text) {
        HtmlElement e{child_name, child_text};
        root.elements.emplace_back(e);

        return *this;
    }

    HtmlBuilder * add_child2(std::string child_name, std::string child_text) {
        HtmlElement e{child_name, child_text};
        root.elements.emplace_back(e);

        return this;
    }

    std::string str() const {
        return root.str(0);
    }

    operator HtmlElement() { return root; }

    HtmlElement root;
};

HtmlBuilder HtmlElement::build(std::string root_name) {
    return HtmlBuilder {root_name};
};

std::unique_ptr<HtmlBuilder> HtmlElement::create(std::string root_name) {
    return std::make_unique<HtmlBuilder>(root_name);
};

int main() {
    HtmlBuilder builder{"ul"};
    builder.add_child("li", "hello")
            .add_child("li", "world");

    HtmlElement e = HtmlElement::build("ul")
            .add_child("li", "hello");

    HtmlBuilder *ee = HtmlElement::create("ul")
            ->add_child2("li", "hello")
            ->add_child2("li", "hello2");

    std::cout << ee->str() << std::endl; // does not work! Video instructions were not completed on this.

    return 0;
}

