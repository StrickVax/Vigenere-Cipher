#include "cipher.cpp"

int main()
{
    int flag = 0;

    while (flag != 3)
    {
        // prints out the options the user has
        std::cout << "\nWhat would you like to do?"
                  << "\n1) Encrpyt"
                  << "\n2) Decrypt"
                  << "\n3) Exit program\n"
                  << std::endl;

        // takes user input and uses it to select a menu option
        std::cin >> flag;

        // if the user chose 1 or 2, the cipher function is called, along with what they wanted to do (encrypt or decrypt)
        if (flag == 1 || flag == 2)
        {
            cipher(flag);
        }

        // checks to see if user input is even a number
        else if (std::cin.fail())
        {
            std::cout << "\nERROR: CHOICE MUST BE A NUMBER";
            std::cin.clear();
            std::cin.ignore();
        }

        // if the user chose an invalid number
        else if (flag != 3)
        {
            std::cout << "\nERROR: INVALID NUMBER";
        }
    }

    return 0;
}