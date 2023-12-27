/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpicoli- <lpicoli-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 22:56:48 by lpicoli-          #+#    #+#             */
/*   Updated: 2023/12/26 23:28:36 by lpicoli-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MutantStack.hpp"
#include <list>

int main()
{
    {
        std::cout << GREEN_TEXT << "== Test: stacks ==" << RESET_COLOR << std::endl;
        MutantStack<int> mutant;

        mutant.push(1);
        mutant.push(5);
        mutant.push(10);
        std::cout << "[Mutant] Top: " << mutant.top() << std::endl;
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << "[Mstack] Top: " << mstack.top() << std::endl;
        mstack.pop();
        std::cout << "[Mstack] Size: " << mstack.size() << std::endl;
        mstack.push(3); 
        mstack.push(5); 
        mstack.push(737);
        mstack.push(0);
        
        MutantStack<int>::iterator it = mstack.begin(); 
        MutantStack<int>::iterator ite = mstack.end();

        ++it;
        --it; 
        std::cout << "Stack: [";
        while (it != ite) 
        {
            std::cout << *it;
            if(++it != ite)
                std::cout << ", ";   
        }
        std::cout << "]" << std::endl;
    }
    std::cout << std::endl;
    {
        std::cout << GREEN_TEXT << "== Test: lists ==" << RESET_COLOR << std::endl;
        std::list<int> mutant;

        mutant.push_back(1);
        mutant.push_back(5);
        mutant.push_back(10);
        std::cout << "[Mutant] Top: " << mutant.back() << std::endl;
        std::list<int> mstack;
        mstack.push_back(5);
        mstack.push_back(17);
        std::cout << "[Mstack] Top: " << mstack.back() << std::endl;
        mstack.pop_back();
        std::cout << "[Mstack] Size: " << mstack.size() << std::endl;
        mstack.push_back(3); 
        mstack.push_back(5); 
        mstack.push_back(737);
        mstack.push_back(0);
        
        std::list<int>::iterator it = mstack.begin(); 
        std::list<int>::iterator ite = mstack.end();

        ++it;
        --it;
        std::cout << "List: [";
        while (it != ite) 
        {
            std::cout << *it;
            if(++it != ite)
                std::cout << ", ";   
        }
        std::cout << "]" << std::endl;
    }
    return 0;
}