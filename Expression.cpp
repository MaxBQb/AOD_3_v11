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

void Expression::print(Expression::Node *root, int level) {
    if (root == nullptr)
        return;

    print(root->right, level+1);
    for (int i = 0; i < (level<<1); i++)
        cout << ' ';

    if (root->is_operation)
        cout << (char)(root->data);
    else
        cout << root->data;
    cout << '\n';

    print(root->left, level+1);
}