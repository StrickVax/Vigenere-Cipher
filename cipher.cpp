#include <iostream>
#include <vector>

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
    // declares codeWord, key, and the cipherAction (encryption by default)
    string codeWord, userWord, key, cipherAction = "encrypt";

    // if the user chose to decrypt, the cipherAction is switched to decryption
    if (userChoice == 2)
        cipherAction = "decrypt";

    // asks and takes the user's plaintext/encypted word
    cout << "\n\nWhat would you like to " << cipherAction << ": ";
    cin >> userWord;

    // asks and takes the user's key
    cout << "\nWhat is the key: ";
    cin >> key;

    // declares an int vector called numericKey
    vector<int> numericKey;

    for (int i = 0; i < key.length(); i++)
    {
    }

    if (userChoice == 1)
    {
    }

    else
    {
    }

    cout << "\nPlaintext : " << userWord;
    cout << "\nKeyword : " << key;
    cout << "\nEncrypted : " << codeWord;
}
