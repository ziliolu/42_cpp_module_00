#ifndef MATERIA_SOURCE_HPP
#define MATERIA_SOURCE_HPP
#include <iostream>
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    protected:
        AMateria *materias[4];
    public: 
        MateriaSource();
        MateriaSource(const MateriaSource &other);
        ~MateriaSource();
        const MateriaSource& operator=(const MateriaSource& other);

        void learnMateria(AMateria *m);
        AMateria* createMateria(std::string const & type);
};

#endif