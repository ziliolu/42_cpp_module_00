#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

class Serializer
{
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
}

#endif
