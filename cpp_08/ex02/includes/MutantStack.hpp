#include <iostream> 
#include <stack>
#include <deque>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
    public:

        typedef typename std::stack<T, Container>::container_type container_type;

        typename container_type::iterator begin() {
            return this->c.begin();
        }

        typename container_type::iterator end() {
            return this->c.end();
        }

        typename container_type::const_iterator cbegin() const {
            return this->c.cbegin();
        }

        typename container_type::const_iterator cend() const {
            return this->c.cend();
        }
};