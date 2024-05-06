/*
#include "StringManipulator.h"
#include <iostream>

int main() {
    // Example string
    std::string example = "Hello World";
    
    // Using the static methods of StringManipulator
    std::string reversed = StringManipulator::reverseString(example);
    std::string upper = StringManipulator::toUpperCase(example);
    std::string lower = StringManipulator::toLowerCase(example);
    bool isPalindrome = StringManipulator::isPalindrome(example);
    int vowelCount = StringManipulator::countVowels(example);
    std::string replaced = StringManipulator::replaceChar(example, 'o', 'a');

    // Displaying results
    std::cout << "Original: " << example << std::endl;
    std::cout << "Reversed: " << reversed << std::endl;
    std::cout << "Uppercase: " << upper << std::endl;
    std::cout << "Lowercase: " << lower << std::endl;
    std::cout << "Is Palindrome: " << (isPalindrome ? "Yes" : "No") << std::endl;
    std::cout << "Vowel Count: " << vowelCount << std::endl;
    std::cout << "Replaced 'o' with 'a': " << replaced << std::endl;

    return 0;
}
*/

#include "StringManipulator.h"
#include <iostream>
#include <string>

int main() {
    std::string input;
    int choice;

    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    std::cout << "Choose an operation to perform on the string:\n";
    std::cout << "1 - Reverse the string\n";
    std::cout << "2 - Convert to uppercase\n";
    std::cout << "3 - Convert to lowercase\n";
    std::cout << "4 - Replace substring\n";
    std::cout << "5 - Remove substring\n";
    std::cout << "6 - Count words\n";
    std::cout << "7 - Check if palindrome\n";
    std::cout << "8 - Find substring\n";
    std::cout << "9 - Split by delimiter\n";
    std::cout << "10 - Encode with ROT13\n";
    std::cout << "11 - Count character frequency\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    std::cin.ignore();  // Clear newline character from the buffer after reading integer

    switch (choice) {
        case 1:
            std::cout << "Reversed string: " << StringManipulator::reverse(input) << std::endl;
            break;
        case 2:
            std::cout << "Uppercase string: " << StringManipulator::toUpperCase(input) << std::endl;
            break;
        case 3:
            std::cout << "Lowercase string: " << StringManipulator::toLowerCase(input) << std::endl;
            break;
        case 4: {
            std::string from, to;
            std::cout << "Enter the substring to replace: ";
            std::getline(std::cin, from);
            std::cout << "Enter the replacement string: ";
            std::getline(std::cin, to);
            std::cout << "Resulting string: " << StringManipulator::replace(input, from, to) << std::endl;
            break;
        }
        case 5: {
            std::string substring;
            std::cout << "Enter the substring to remove: ";
            std::getline(std::cin, substring);
            std::cout << "Resulting string: " << StringManipulator::remove(input, substring) << std::endl;
            break;
        }
        case 6:
            std::cout << "Number of words: " << StringManipulator::countWords(input) << std::endl;
            break;
        case 7:
            std::cout << "Is palindrome: " << (StringManipulator::isPalindrome(input) ? "Yes" : "No") << std::endl;
            break;
        case 8: {
            std::string substring;
            std::cout << "Enter the substring to find: ";
            std::getline(std::cin, substring);
            size_t pos = StringManipulator::findSubstring(input, substring);
            if (pos != std::string::npos)
                std::cout << "Substring found at position: " << pos << std::endl;
            else
                std::cout << "Substring not found." << std::endl;
            break;
        }
        case 9: {
            char delimiter;
            std::cout << "Enter a single character delimiter: ";
            std::cin >> delimiter;
            std::vector<std::string> parts = StringManipulator::split(input, delimiter);
            std::cout << "Split parts:\n";
            for (const auto& part : parts) {
                std::cout << part << std::endl;
            }
            break;
        }
        case 10:
            std::cout << "ROT13 encoded string: " << StringManipulator::rot13(input) << std::endl;
            break;

        return 0;
        
    }
}


//         case 11: {
//             auto frequencies = StringManipulator::charFrequency(input);
//             std::cout << "Character frequencies:\n";
//             for (const auto& [char, freq] : frequencies) {
//                 std::cout << char << ": " << freq << std::endl;
//             }
//             break;
//         }
//         default:
//             std::cout << "Invalid option selected." << std::endl;
//             break;
//     }

//     return 0;
// }