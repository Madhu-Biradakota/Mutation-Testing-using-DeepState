#include "StringManipulator.h"
#include <iostream>
#include <vector>

int main() {
    // Example usage of reverse
    std::string original = "Hello, World!";
    std::string reversed = StringManipulator::reverse(original);
    std::cout << "Reversed: " << reversed << std::endl;

    // Example usage of toUpperCase and toLowerCase
    std::string upper = StringManipulator::toUpperCase(original);
    std::string lower = StringManipulator::toLowerCase(original);
    std::cout << "Upper: " << upper << std::endl;
    std::cout << "Lower: " << lower << std::endl;

    // Example usage of replace
    std::string replaced = StringManipulator::replace(original, "World", "Everyone");
    std::cout << "Replaced: " << replaced << std::endl;

    // Example usage of remove
    std::string removed = StringManipulator::remove(replaced, "Everyone");
    std::cout << "Removed: " << removed << std::endl;

    // Example usage of countWords
    int words = StringManipulator::countWords(original);
    std::cout << "Word Count: " << words << std::endl;

    // Example usage of isPalindrome
    bool palindrome = StringManipulator::isPalindrome("madam");
    std::cout << "Is Palindrome: " << (palindrome ? "Yes" : "No") << std::endl;

    // Example usage of findSubstring
    size_t pos = StringManipulator::findSubstring(original, "World");
    std::cout << "Substring position: " << pos << std::endl;

    // Example usage of split
    std::vector<std::string> splitResult = StringManipulator::split(original, ',');
    std::cout << "Split result: ";
    for (const auto& s : splitResult) {
        std::cout << s << " ";
    }
    std::cout << std::endl;

    // Example usage of digitsToWords
    std::string digits = "123";
    std::string wordsFromDigits = StringManipulator::digitsToWords(digits);
    std::cout << "Digits to words: " << wordsFromDigits << std::endl;

    // Example usage of interleave
    std::string interleaved = StringManipulator::interleave("abc", "123");
    std::cout << "Interleaved: " << interleaved << std::endl;

    // Example usage of findAllSubstrings
    std::vector<size_t> allSubs = StringManipulator::findAllSubstrings("hello hello hello", "lo");
    std::cout << "All substrings 'lo' found at positions: ";
    for (auto p : allSubs) {
        std::cout << p << " ";
    }
    std::cout << std::endl;

    // Example usage of shuffle
    std::string shuffled = StringManipulator::shuffle(original);
    std::cout << "Shuffled: " << shuffled << std::endl;

    return 0;
}
