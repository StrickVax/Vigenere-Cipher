#include <iostream>

using namespace std;

// function headers
void cipher(int);
void inputString(char[], string &);
void keywordGenerator(string, string, string &);
void textPreserver(string, string &);

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
             << "\n3) Exit program\n"
             << endl;

        // takes user input and uses it to select a menu option
        cin >> flag;

        // if the user chose 1 or 2, the cipher function is called, along with what they wanted to do (encrypt or decrypt)
        if (flag == 1 || flag == 2)
        {
            cipher(flag);
        }

        // checks to see if user input is even a number
        else if (cin.fail())
        {
            cout << "\nERROR: CHOICE MUST BE A NUMBER";
            cin.clear();
            cin.ignore();
        }

        // if the user chose an invalid number
        else if (flag != 3)
        {
            cout << "\nERROR: INVALID NUMBER";
        }

        // ends the do-while menu when the flag is set to 3
    } while (flag != 3);

    return 0;
}

// function body
void cipher(int userChoice)
{
    // declares outputText and keyword. inputAction and outputAction print the approriate menu
    string outputText = "", inputText, keyword, inputAction = "Plaintext: ", outputAction = "Ciphertext: ";
    char userInput[100];

    // if the user chose to decrypt, the input and output actions are switched
    if (userChoice == 2)
    {
        inputAction = "Ciphertext: ";
        outputAction = "Plaintext: ";
    }

    // asks and takes the user's inputText/encypted word
    cout << "\nInput: " << inputAction;
    // cin >> inputText;
    cin.clear();
    cin.sync();
    cin.getline(userInput, 100);
    inputString(userInput, inputText);

    // string used to reconstruct the capitalization of the inputText
    string punctPreserve = inputText;

    // asks and takes the user's keyword
    cout << "Keyword: ";
    cin >> keyword;

    string numerickeyword;
    keywordGenerator(inputText, keyword, numerickeyword);

    // used to push the calculated letter to the output;
    char y = ' ';

    // Encrypts the plaintext

    for (int i = 0; i < inputText.length(); i++)
    {
        if (inputText[i] == ' ')
        {
            continue;
        }
        if (userChoice == 1)
        {
            // converts the two letters to uppercases and adds the calculated value to y
            y = char(int(toupper(inputText[i]) + toupper(numerickeyword[i])) % 26 + 65);
        }
        else
        {
            cout << int(toupper(inputText[i])) - int(toupper(numerickeyword[i])) << endl;

            // ISSUE: Instead of looping back to the orginal letter, it will go into
            // ASCIIs that are lower than A [65] , such as @ [64]
            y = char(int(toupper(inputText[i]) - toupper(numerickeyword[i])) % 26 + 65);
        }

        // y is added to the end of the output
        outputText.push_back(y);
    }

    textPreserver(punctPreserve, outputText);

    // outputs the de/ciphered text
    cout << "Output: " << outputAction << outputText << endl;
    cout << numerickeyword << endl
         << endl;
}

void inputString(char userInput[], string &inputText)
{
    for (int i = 0;; i++)
        if (userInput[i] != '\0')
            inputText.push_back(userInput[i]);
        else
            break;
}

// function tha
void keywordGenerator(string inputText, string keyword, string &numerickeyword)
{
    // Extends keyword to fit the plaintext by repeating the keyword for every letter in the plaintext. This guarantees the new
    // keyword will be as long as the inputted text
    for (int i = 0; i < inputText.length(); i++)
    {
        for (int i = 0; i < keyword.size(); i++)
        {
            numerickeyword.push_back(keyword[i]);
        }
    }
}

// function that preserves the capitals of the original text
void textPreserver(string punctPreserve, string &outputText)
{
    // Ensures punctuation is preserved
    for (int i = 0; i < punctPreserve.length(); i++)
    {
        // if the pre-cipher letter is lowercase, the outputted letter is converted into a lowercase
        if (islower(punctPreserve[i]))
        {
            outputText[i] = tolower(outputText[i]);
        }
    }
}
