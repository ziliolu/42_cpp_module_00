#include <iostream> 
#include "../includes/Array.hpp"
#include "Array.tpp"

int main()
{
    std::cout << std::endl << "===== ARRAYS TESTS =====" << std::endl;
    try
    {
		/* declaration */
        Array<double>       		arr_1(10);
        Array<double>				arr_2(20);
        Array<double>       		arr_3(arr_1); //copy assignment operator called
		Array<double>				arr_4;
		Array< Array<double> >		arrays(4);

		arr_4 = arr_2;

		arrays[0] = arr_1;
		arrays[1] = arr_2;
		arrays[2] = arr_3;
		arrays[3] = arr_4;
		
		/* filling arrays */
		for(int i = 0; i < 4; i++)
		{
			for(unsigned int j = 0; j < arrays[i].size(); j++)
				arrays[i][j] = (j + 1) + 0.5;
		}

		/* printing arrays */
		std::cout << std::endl << "=== DOUBLES ===" << std::endl << std::endl; 
		for(int i = 0; i < 4; i++)
		{
			std::cout << "Array " << i << " == " << std::endl;
			for(unsigned int j = 0; j < arrays[i].size(); j++)
				std::cout << "- " << arrays[i][j] << std::endl;
		}
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << '\n';
    }

	try
    {
		/* declaration */
        Array<char>       		arr_1(10);
        Array<char>				arr_2(20);
        Array<char>       		arr_3(arr_1); //copy assignment operator called
		Array<char>				arr_4;
		Array< Array<char> >		arrays(4);

		arr_4 = arr_2;

		arrays[0] = arr_1;
		arrays[1] = arr_2;
		arrays[2] = arr_3;
		arrays[3] = arr_4;
		
		/* filling arrays */
		for(int i = 0; i < 4; i++)
		{
			for(unsigned int j = 0; j < arrays[i].size(); j++)
				arrays[i][j] = j + '0';
		}

		/* printing arrays */
		std::cout << std::endl << "=== CHARS ===" << std::endl << std::endl; 
		for(int i = 0; i < 4; i++)
		{
			std::cout << "Array " << i << " == " << std::endl;
			for(unsigned int j = 0; j < arrays[i].size(); j++)
				std::cout << "- " << arrays[i][j] << std::endl;
		}
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << '\n';
    }
}