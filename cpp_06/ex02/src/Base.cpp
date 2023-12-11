#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"
#include <ctime>
#include <cstdlib>

Base::~Base()
{

}

Base *generate()
{
    std::srand(std::time(0));
    int randomNumber = std::rand();
    switch (randomNumber % 3)
    {
    case 0:
        std::cout << "Class created: A" << std::endl;
        return (new A()); 
    case 1:
        std::cout << "Class created: B" << std::endl;
        return (new B());
    case 2:
        std::cout << "Class created: C" << std::endl;
        return (new C()); 
    }
    return NULL;
}

void identify(Base *p)
{
    Base *a = dynamic_cast<A*> (p);
    if(a)
        std::cout << "A" << std::endl;
    Base *b = dynamic_cast<B*> (p);
    if(b)
        std::cout << "B" << std::endl;
    Base *c = dynamic_cast<C*> (p);
    if(c)
        std::cout << "C" << std::endl;
}

void identify(Base& p)
{
    try 
    {
        Base &a = dynamic_cast<A&> (p);
        (void)a;
        std::cout << "A" << std::endl;
    }
    catch (std::exception &e){}
    try
    {
        Base &b = dynamic_cast<B&> (p);
        (void)b;
        std::cout << "B" << std::endl;
    } catch (std::exception &e){}
    try
    {
        Base &c = dynamic_cast<C&> (p);
        (void)c;
        std::cout << "C" << std::endl;
    } catch (std::exception &e) {}
}