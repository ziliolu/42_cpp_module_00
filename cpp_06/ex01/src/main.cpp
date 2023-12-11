#include "../includes/Serializer.hpp"
#include <iostream>

int main()
{
    Data data_set;
    data_set.name = "John";
    data_set.age = 26;
    data_set.job_position = "programmer";
    data_set.employed = true;

    std::cout << "Name: " << data_set.name << std::endl;
    std::cout << "Age: " << data_set.age << std::endl;
    std::cout << "Job position: " << data_set.job_position << std::endl;
    std::cout << "Employed: " << data_set.employed << std::endl;
    std::cout << "Ptr's address: " << &data_set << std::endl;
    std::cout << "Unsigned long ptr value: " << (unsigned long) &data_set << std::endl;
    
    std::cout << std::endl << "--- Serializing ptr ---"<< std::endl << std::endl;
    uintptr_t ux = Serializer::serialize(&data_set);
    std::cout << "Serialized value: " << ux << std::endl;

    std::cout << std::endl << "--- Deserializing ptr ---"<< std::endl << std::endl;
    Data *new_data_set = Serializer::deserialize(ux);
    std::cout << "Name: " << new_data_set->name << std::endl;
    std::cout << "Age: " << new_data_set->age << std::endl;
    std::cout << "Job position: " << new_data_set->job_position << std::endl;
    std::cout << "Employed: " << new_data_set->employed << std::endl;
    std::cout << "Ptr's address: " << &new_data_set<< std::endl;
    std::cout << "Unsigned long ptr value: " << (unsigned long) &new_data_set<< std::endl;
}   