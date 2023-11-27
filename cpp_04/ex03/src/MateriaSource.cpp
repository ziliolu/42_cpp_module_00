#include "../includes/AMateria.hpp"
#include "../includes/MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    //std::cout << "[MATERIA SOURCE] Default constructor called" << std::endl;
    for(int i = 0; i < 4; i++)
        this->materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &src)
{
    //std::cout << "[MATERIA SOURCE] Copy constructor called" << std::endl;
    for(int i = 0; i < 4; i++)
    {
        if(src.materias[i] != NULL)
            this->materias[i] = src.materias[i]->clone();
        else
            this->materias[i] = NULL;
    }

}

MateriaSource::~MateriaSource()
{
    //std::cout << "[MATERIA SOURCE] Destructor called" << std::endl;
    for(int i = 0; i < 4; i++)
    {
        if(this->materias[i])
            delete this->materias[i];
    }
}
const MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
    //std::cout << "[MATERIA SOURCE] Assignment operator called" << std::endl;
    if(this != &other)
    {
        for (int i = 0; i < 4; i++)
        {
            if(materias[i] != NULL) 
                delete materias[i];
            materias[i] = NULL;
        }

        for (int i = 0; i < 4; i++)
        {
            if (other.materias[i] != NULL)
                materias[i] = other.materias[i]->clone();
            else
                materias[i] = NULL;
        }
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria *m)
{
    //std::cout << "[MATERIA SOURCE] Learning Materia..." << std::endl;
    for(int i = 0; i < 4; i++)
    {
        if(this->materias[i] == NULL)
        {
            this->materias[i] = m;
            return ;
        }
    }
}
AMateria* MateriaSource::createMateria(std::string const & type)
{
    //std::cout << "[MATERIA SOURCE] Creating Materia..." << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if(this->materias[i] && this->materias[i]->getType() == type)
            return (materias[i]->clone());
    }
    return NULL;
}
