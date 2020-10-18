#pragma once
#include <iostream>
#include <string>
using namespace std;

class Expression {
    struct Node{
        Node* left;
        Node* right;
        int data;
        bool is_operation;

        Node(int data = 0,
             bool is_operation = false,
             Node* left = nullptr,
             Node* right = nullptr):
             data(data),
             is_operation(is_operation),
             left(left),
             right(right)
             {}

        ~Node() {
            delete left;
            delete right;
        }
    };
    Node* root;
    static Node* readExpression(istream& in);
    static void printExpression(ostream& out, Node* root, int level = 0);
public:
    explicit Expression(Node* root = nullptr): root(root) {}
    friend istream& operator >>(istream& in, Expression& expr);
    friend ostream& operator <<(ostream& out, const Expression& expr);
    ~Expression() { delete root; }
};
