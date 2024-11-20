#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


int main()
{
    Base *p = generate();
    Base *p1 = new A();
    Base *p2 = new B();
    Base *p3 = new C();
    identify(p1);
    identify(p2);
    identify(p3);
    std::cout << "\t--------" << std::endl;
    identify(p);
    std::cout << "\t--------" << std::endl;
    A a;
    identify(a);
    delete p1;
    delete p2;
    delete p3;
    delete p;
}
