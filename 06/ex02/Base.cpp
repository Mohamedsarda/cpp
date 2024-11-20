#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {}

Base * generate(void) {
    std::srand(time(0));
    switch (std::rand() % 3)
    {
        case 0:
            return (new A());
        case 1:
            return (new B());
        case 2:
            return (new C());
    }
    return (NULL);
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "The Type Of *P Is A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "The Type Of *P Is B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "The Type Of *P Is C" << std::endl;
    else
        std::cout << "The Type Of *P is Undefined" << std::endl;
}

void identify(Base& p) {
    try {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "The Type Of &P Is A" << std::endl;
        return ;
    } catch (...) {}
    try {
        B& b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "The Type Of &P Is B" << std::endl;
        return ;
    } catch (...) {}
    try {
        C& c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "The Type Of &P Is C" << std::endl;
        return ;
    } catch (...) {}
    std::cout << "The Type Of &P is Undefined" << std::endl;
}
