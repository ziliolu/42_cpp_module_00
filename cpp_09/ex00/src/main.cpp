
#include "../includes/BitcoinExchange.hpp"
#include "../includes/Colors.hpp"

int main(int argc, char **argv)
{
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }
    std::cout << "Initializing program" << std::endl;
    BitcoinExchange bitcoinExchange(argv[1]);
}