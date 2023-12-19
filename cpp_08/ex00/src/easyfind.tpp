#include "../includes/easyfind.hpp"

template <typename T>
int easyfind(const T &container, int number)
{
    typename T::const_iterator it;

    it = std::find(container.begin(), container.end(), number);
    if(it == container.end())
        throw std::out_of_range("number not found");
    return(std::distance(container.begin(), it));
}