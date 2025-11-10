
#ifndef FLUX_PL_DEFINES_HPP
#define FLUX_PL_DEFINES_HPP
#include <string>

struct Node {
    virtual ~Node() = default;
    virtual void print(int indent = 0) const = 0;
};
struct NumberNode : public Node {
    std::string value;
    NumberNode(std::string v) : value(v) {}

    void print(int indent = 0) const override {
        std::cout << std::string(indent, ' ') << "NumberNode(" << value << ")\n";
    }
};

struct IdentifierNode : public Node {
    std::string name;
    IdentifierNode(std::string n) : name(n) {}

    void print(int indent = 0) const override {
        std::cout << std::string(indent, ' ') << "IdentifierNode(" << name << ")\n";
    }
};

struct VarDeclNode : public Node
{
    std::string name;
    Node* value;
    VarDeclNode(std::string n, Node* v) : name(n), value(v) {}

    void print(int indent = 0) const override {
        std::cout << std::string(indent, ' ') << "VarDeclNode(name=" << name << ")\n";
        if (value) value->print(indent + 2);
    }
};
#endif //FLUX_PL_DEFINES_HPP