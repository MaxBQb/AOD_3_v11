#include "Expression.h"

Expression::Node* Expression::readExpression(istream& in) {
    string t;
    in >> t;
    if (t[0] != '+' &&
        t[0] != '-' &&
        t[0] != '*' &&
        t[0] != '/')
        return new Expression::Node(stoi(t));
    return new Expression::Node((int)(t[0]),
                                true,
                                readExpression(in),
                                readExpression(in)
                               );
}

istream &operator>>(istream &in, Expression &expr) {
    delete expr.root;
    expr.root = Expression::readExpression(in);
    return in;
}

void Expression::printExpression(ostream &out, Expression::Node *root) {
    if (root == nullptr)
        return;

    if (root->is_operation)
        out << (char)(root->data);
    else
        out << root->data;
    out << ' ';

    printExpression(out, root->left);
    printExpression(out, root->right);
}

ostream &operator<<(ostream &out, const Expression &expr) {
    Expression::printExpression(out, expr.root);
    return out;
}

void Expression::print(Expression::Node* root, ostream &out, int level) {
    if (root == nullptr)
        return;

    print(root->right, out, level+1);
    for (int i = 0; i < (level<<1); i++)
        out << ' ';

    if (root->is_operation)
        out << (char)(root->data);
    else
        out << root->data;
    out << '\n';

    print(root->left, out, level+1);
}