#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const char Alphabet[] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','0','1','2','3','4','5','6','7','8','9' };
const int Alphabet_Size = sizeof(Alphabet) / sizeof(Alphabet[0]);

string caesar_cipher(string message, int shift);

int main() {
    int decision;
    string line;
    int shift;

    ifstream input_file("input.txt");
    if (!input_file) {
        cout << "Failed to open input file." << endl;
        return 1;
    }

    ofstream output_file("encrypted.txt");
    if (!output_file) {
        cout << "Failed to open encrypted file." << endl;
        return 1;
    }

    cout << "Welcome to Ceasar Cipher\nDo you want to encrypt(1), decrypt(2)" << endl;
    cin >> decision;
    if (decision == 1)
    {
        cout << "You choose encryption\nEnter the key of encription:";
        cin >> shift;
        while (getline(input_file, line)) {

            string encrypted_line = caesar_cipher(line, shift);
            output_file << encrypted_line << endl;

        }
        line = "";
    }
    if (decision == 2)
    {
        cout << "You choose decryption\nEnter the key of decryption:";
        cin >> shift;
        while (getline(input_file, line)) {

            string encrypted_line = caesar_cipher(line, -shift);
            output_file << encrypted_line << endl;
            
        }
        line = "";
    }
    else
    {
        return 0;
    }
    
    

    input_file.close();
    output_file.close();

    return 0;
}


string caesar_cipher(string message, int shift) {
    string result = "";
    int len = message.length();
    for (int i = 0; i < len; i++) {
        char c = toupper(message[i]); // Convert to uppercase to simplify indexing
        int index = -1;
        for (int j = 0; j < Alphabet_Size; j++) {
            if (Alphabet[j] == c) {
                index = j;
                break;
            }
        }
        if (index != -1) {
            index = (index + shift) % Alphabet_Size; // wrap if shift > Alphabet.Size
            result += islower(message[i]) ? tolower(Alphabet[index]) : Alphabet[index];
        }
        else {
            result += message[i];
        }
    }
    return result;
}