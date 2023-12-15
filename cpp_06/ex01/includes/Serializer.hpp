#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP
#include <stdint.h>
#include <iostream>

struct Data
{
    std::string name;
    std::string job_position;
    bool employed;
    int age;
};

class Serializer
{
    /* Orthodox Canonical Form ---------------------------*/
    private: 
        Serializer();
        ~Serializer();
        Serializer(Serializer &src);
        Serializer& operator=(const Serializer &other);
    /* --------------------------------------------------*/
    public: 
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif
