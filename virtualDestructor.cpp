#include <iostream>

using namespace std;

class A
{
public:
    A() { cout << " A"; }
    virtual ~A() { cout << " ~A"; }
};
class AA : public A
{
public:
    AA() { cout << " AA"; }
    ~AA() { cout << " ~AA"; }
};
int main()
{
    A *pa = new AA;
    delete pa;
    return 0;
}
// 출력 : A AA ~A