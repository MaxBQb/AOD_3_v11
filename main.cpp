#include "Expression.h"
using namespace std;

int main() {
    setlocale(0, "");
    Expression expr;
    cout << "������� ���������: ";
    cin >> expr;
    cout << "����� ������ ������:\n";
    expr.print();
    cout << "����� ������ ������� � �������: ";
    cout << expr;
    return 0;
}
