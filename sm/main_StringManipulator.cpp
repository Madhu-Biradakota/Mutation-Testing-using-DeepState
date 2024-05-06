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
