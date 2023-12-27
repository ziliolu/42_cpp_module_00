/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 22:57:40 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/12/26 23:15:19 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream> 
#include <stack>
#include <deque>
#include "Colors.hpp"

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
            /* Orthodox Canonical Form*/
            MutantStack();
            MutantStack(const MutantStack &src);
            const MutantStack &operator=(const MutantStack &other);
            ~MutantStack();
            /*------------------------*/

            /* Iterators */
            typedef typename std::stack<T>::container_type::iterator iterator;
            typedef typename std::stack<T>::container_type::const_iterator const_iterator;

            iterator begin();
            iterator end();
            const_iterator cbegin() const;
            const_iterator cend() const;
            /*-------------*/
};

#include "../src/MutantStack.tpp" 
#endif