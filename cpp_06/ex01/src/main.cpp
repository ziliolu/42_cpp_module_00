#include <cstdint>

int main()
{
    int *ptr;
    int x = 10;

    ptr = &x; 
    uintptr_t uptr = static_cast<uintptr_t>(ptr);

    std::cout << uptr << std::endl;
}   