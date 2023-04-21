#include <iostream>
#include "cipher.h"

// function body
void cipher(int userChoice)
{
    // declares outputText and keyword. inputAction and outputAction print the approriate menu
    std::string outputText = "", inputText, keyword, inputAction = "Plaintext: ", outputAction = "Ciphertext: ";
    char userInput[100];

    // if the user chose to decrypt, the input and output actions are switched
    if (userChoice == 2)
    {
        inputAction = "Ciphertext: ";
        outputAction = "Plaintext: ";
    }

    // asks and takes the user's inputText/encypted word
    std::cout << "\nInput: " << inputAction;
    // std::cin >> inputText;
    std::cin.clear();
    std::cin.sync();
    std::cin.getline(userInput, 100);
    inputString(userInput, inputText);

    // std::string used to reconstruct the capitalization of the inputText
    std::string punctPreserve = inputText;

    // asks and takes the user's keyword
    std::cout << "Keyword: ";
    std::cin >> keyword;

    std::string numerickeyword;
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
            std::cout << int(toupper(inputText[i])) - int(toupper(numerickeyword[i])) << std::endl;

            // ISSUE: Instead of looping back to the orginal letter, it will go into
            // ASCIIs that are lower than A [65] , such as @ [64]
            if (int(toupper(inputText[i])) - int(toupper(numerickeyword[i])) < 0)
            {
                y = char(int(toupper(inputText[i]) - toupper(numerickeyword[i])) % 26 + 91);
            }
            else
            {
                y = char(int(toupper(inputText[i]) - toupper(numerickeyword[i])) % 26 + 65);
            }
        }

        // y is added to the end of the output
        outputText.push_back(y);
    }

    textPreserver(punctPreserve, outputText);

    // outputs the de/ciphered text
    std::cout << "Output: " << outputAction << outputText << std::endl;
    std::cout << numerickeyword << std::endl
              << std::endl;
}

void inputString(char userInput[], std::string &inputText)
{
    for (int i = 0;; i++)
        if (userInput[i] != '\0')
            inputText.push_back(userInput[i]);
        else
            break;
}

// function tha
void keywordGenerator(std::string inputText, std::string keyword, std::string &numerickeyword)
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
void textPreserver(std::string punctPreserve, std::string &outputText)
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
