#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

// Morse Code Mappings
unordered_map<char, string> morseEncodeMap = {
    {'A', ".-"},   {'B', "-..."}, {'C', "-.-."}, {'D', "-.."},  {'E', "."},
    {'F', "..-."}, {'G', "--."},  {'H', "...."}, {'I', ".."},   {'J', ".---"},
    {'K', "-.-"},  {'L', ".-.."}, {'M', "--"},   {'N', "-."},   {'O', "---"},
    {'P', ".--."},{'Q', "--.-"}, {'R', ".-."},  {'S', "..."},  {'T', "-"},
    {'U', "..-"},  {'V', "...-"}, {'W', ".--"},  {'X', "-..-"},{'Y', "-.--"},
    {'Z', "--.."}, {'1', ".----"},{'2', "..---"},{'3', "...--"},{'4', "....-"},
    {'5', "....."},{'6', "-...."},{'7', "--..."},{'8', "---.."},{'9', "----."},
    {'0', "-----"},{' ', " / "}
};

unordered_map<string, char> morseDecodeMap = {
    {".-", 'A'},   {"-...", 'B'}, {"-.-.", 'C'}, {"-..", 'D'},  {".", 'E'},
    {"..-.", 'F'}, {"--.", 'G'},  {"....", 'H'}, {"..", 'I'},   {".---", 'J'},
    {"-.-", 'K'},  {".-..", 'L'}, {"--", 'M'},   {"-.", 'N'},   {"---", 'O'},
    {".--.", 'P'}, {"--.-", 'Q'}, {".-.", 'R'},  {"...", 'S'},  {"-", 'T'},
    {"..-", 'U'},  {"...-", 'V'}, {".--", 'W'},  {"-..-", 'X'}, {"-.--", 'Y'},
    {"--..", 'Z'}, {".----", '1'},{"..---", '2'},{"...--", '3'},{"....-", '4'},
    {".....", '5'},{"-....", '6'},{"--...", '7'},{"---..", '8'},{"----.", '9'},
    {"-----", '0'},{" / ", ' '}
};

// Function to encode text to Morse code
string encodeToMorse(const string &text) {
    stringstream morseStream;
    for (const char &ch : text) {
        char upperChar = toupper(ch);
        if (morseEncodeMap.find(upperChar) != morseEncodeMap.end()) {
            morseStream << morseEncodeMap[upperChar] << " ";
        } else {
            morseStream << "? "; // Unknown character
        }
    }
    return morseStream.str();
}

// Function to decode Morse code to text
string decodeFromMorse(const string &morseCode) {
    stringstream textStream;
    stringstream morseStream(morseCode);
    string morseChar;
    while (morseStream >> morseChar) {
        if (morseDecodeMap.find(morseChar) != morseDecodeMap.end()) {
            textStream << morseDecodeMap[morseChar];
        } else {
            textStream << "?"; // Unknown Morse code
        }
    }
    return textStream.str();
}

// Main function
int main() {
    string input;
    int choice;

    cout << "Morse Code Encoder/Decoder\n";
    cout << "1. Encode to Morse Code\n";
    cout << "2. Decode from Morse Code\n";
    cout << "Choose an option (1 or 2): ";
    cin >> choice;
    cin.ignore(); // Ignore the newline character after choice

    if (choice == 1) {
        cout << "Enter text to encode: ";
        getline(cin, input);
        string morseCode = encodeToMorse(input);
        cout << "Encoded Morse Code: " << morseCode << "\n";
    } else if (choice == 2) {
        cout << "Enter Morse Code to decode (use space between characters and '/' for space between words): ";
        getline(cin, input);
        string decodedText = decodeFromMorse(input);
        cout << "Decoded Text: " << decodedText << "\n";
    } else {
        cout << "Invalid choice.\n";
    }

    return 0;
}
