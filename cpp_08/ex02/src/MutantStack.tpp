/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 22:50:55 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/12/26 23:31:58 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MutantStack.hpp"

/* Orthodox Canonical Form */
template <typename T>
MutantStack<T>::MutantStack(){}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &src)
{
    (void)src;
}

template <typename T>
const MutantStack<T> &MutantStack<T>::operator=(const MutantStack &other)
{
    (void)other;
    return (*this);
}
/*--------------------------*/

template <typename T>
MutantStack<T>::~MutantStack(){};
/*------------------------*/

/* Iterators */
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
    return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
    return this->c.end();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::cbegin() const{
    return this->c.cbegin();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::cend() const{
    return this->c.cend();
}
/*-------------*/