#include <iostream>

using std::string;
using std::cout;

//its not in c way of wri
int main(int argc, char **argv)
{    
    int j;
    int i;
    char c;
    
    i = 1;
    if(!argv[i])
        cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    while(argv[i])
    {
        j = 0;
        while(argv[i][j])
        {
            if(argv[i][j] >= 'a' && argv[i][j] <= 'z')
                c = argv[i][j] - 32;
            else
                c = argv[i][j];
            cout << c; 
            j++;
        }
        if(argv[i + 1])
            cout << " ";
        else
            cout << "\n";
        i++;
    }
}
