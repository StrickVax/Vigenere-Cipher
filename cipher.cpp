#include <iostream>

using namespace std;

// function header
void cipher(int);

int main()
{
    // declares a do-while sentry
    int flag;

    // do-while menu
    do
    {
        // prints out the options the user has
        cout << "\nWhat would you like to do?"
             << "\n1) Encrpyt"
             << "\n2) Decrypt"
             << "\n3) Exit program\n";

        // takes user input and uses it to select a menu option
        cin >> flag;

        // if the user chose 1 or 2, the cipher function is called, along with what they wanted to do (encrypt or decrypt)
        if (flag == 1 || flag == 2)
            cipher(flag);

        // if the user chose an invalid number
        else if (flag != 3)
            cout << "\nERROR: INVALID CHOICE";

        // ends the do-while menu when the flag is set to 3
    } while (flag != 3);

    return 0;
}

// function body
void cipher(int userChoice)
{
    // declares outputText and keyword. inputAction and outputAction print the approriate menu
    string outputText = "", inputText, keyword, inputAction = "Plaintext: ", outputAction = "Ciphertext: ";

    // if the user chose to decrypt, the input and output actions are switched
    if (userChoice == 2)
    {
        inputAction = "Ciphertext: ";
        outputAction = "Plaintext: ";
    }

    // asks and takes the user's inputText/encypted word
    cout << "\nInput: " << inputAction;
    cin >> inputText;

    // string used to reconstruct the capitalization of the inputText
    string punctPreserve = inputText;

    // asks and takes the user's keyword
    cout << "Keyword: ";
    cin >> keyword;

    // declares a string to be used as the program's new keyword
    string numerickeyword;

    // Extends keyword to fit the plaintext by repeating the keyword for every letter in the plaintext. This guarantees the new
    //keyword will be as long as the inputted text
    for (int i = 0; i < inputText.length(); i++)
    {
        for (int i = 0; i < keyword.size(); i++)
        {
            numerickeyword.push_back(keyword[i]);
        }
    }

    // used to push the calculated letter to the output;
    char y = ' ';

    // Encrypts the plaintext
    if (userChoice == 1)
    {

        for (int i = 0; i < inputText.length(); i++)
        {
            // converts the two letters to uppercases and adds the calculated value to y
            y = char(int(toupper(inputText[i]) + toupper(numerickeyword[i])) % 26 + 65);

            // y is added to the end of the output
            outputText.push_back(y);
        }
    }

    // decrypts the encrypted text
    else
    {
        for (int i = 0; i < inputText.length(); i++)
        {
            // converts the two letters to uppercases and subtracts them to calculate the original letter
            y = char(int(toupper(inputText[i]) - toupper(numerickeyword[i]) - 26) % 26 + 91);

            // y is added to the end of output
            outputText.push_back(y);
        }
    }

    // Ensures punctuation is preserved
    for (int i = 0; i < inputText.length(); i++)
    {
        // if the pre-cipher letter is lowercase, the outputted letter is converted into a lowercase
        if (islower(punctPreserve[i]))
        {
            outputText[i] = tolower(outputText[i]);
        }
    }

    // outputs the de/ciphered text
    cout << "Output: " << outputAction << outputText << endl;
}
