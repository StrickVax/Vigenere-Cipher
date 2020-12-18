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
        else
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
    cout << "\n\nInput: " << inputAction;
    cin >> inputText;
    string punctPreserve = inputText;

    // asks and takes the user's keyword
    cout << "\nWhat is the keyword: ";
    cin >> keyword;

    // declares an int vector called numerickeyword
    string numerickeyword;

    // Extends keyword to fit the plaintext
    for (int i = 0; i < inputText.length(); i++)
    {
        for (int i = 0; i < keyword.size(); i++)
        {
            numerickeyword.push_back(keyword[i]);
        }
    }

    // used to construct the output
    char y = ' ';

    // Encrypts
    if (userChoice == 1)
    {

        for (int i = 0; i < inputText.length(); i++)
        {

            y = char(int(toupper(inputText[i]) + toupper(numerickeyword[i])) % 26 + 65);

            outputText.push_back(y);
            cout << int(outputText[i]) << " ";
        }
    }

    // decrypts 
    else
    {
        for (int i = 0; i < inputText.length(); i++)
        {

            y = char(int(toupper(inputText[i]) - toupper(numerickeyword[i])) % 26 + 65);

            outputText.push_back(y);
            cout << int(outputText[i]) << " ";
        }
    }

    // Ensures punctuation is preserved
    for (int i = 0; i < inputText.length(); i++)
    {
        if (islower(punctPreserve[i]))
        {
            outputText[i] = tolower(outputText[i]);
        }
    }

    cout << "\nOutput: " << outputAction << outputText;
}
