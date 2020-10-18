#include "Expression.h"
using namespace std;

int main() {
    setlocale(0, "");
    Expression expr;
    cout << "Введите выражение: ";
    cin >> expr;
    cout << "Вывод справа налево:\n";
    expr.print();
    cout << "Вывод прямым обходом в глубину: ";
    cout << expr;
    return 0;
}
