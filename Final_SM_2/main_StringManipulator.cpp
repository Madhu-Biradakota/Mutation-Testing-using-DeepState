
#include "StringManipulator.h"
#include <iostream>
#include <vector>

int main() {
    std::string inputString;
    std::cout << "Enter a string: ";
    std::getline(std::cin, inputString);

    // Usage of all functions from StringManipulator
    std::string reversed = StringManipulator::reverse(inputString);
    std::cout << "Reversed: " << reversed << std::endl;

    std::string upper = StringManipulator::toUpperCase(inputString);
    std::cout << "Upper: " << upper << std::endl;

    std::string lower = StringManipulator::toLowerCase(inputString);
    std::cout << "Lower: " << lower << std::endl;

    std::string replaced = StringManipulator::replace(inputString, "a", "o");
    std::cout << "Replaced: " << replaced << std::endl;

    std::string removed = StringManipulator::remove(inputString, " ");
    std::cout << "Removed: " << removed << std::endl;

    int words = StringManipulator::countWords(inputString);
    std::cout << "Word Count: " << words << std::endl;

    bool palindrome = StringManipulator::isPalindrome(inputString);
    std::cout << "Is Palindrome: " << (palindrome ? "Yes" : "No") << std::endl;

    size_t pos = StringManipulator::findSubstring(inputString, "o");
    std::cout << "Substring position: " << pos << std::endl;

    std::vector<std::string> splitResult = StringManipulator::split(inputString, ' ');
    std::cout << "Split result: ";
    for (const auto& s : splitResult) {
        std::cout << s << " ";
    }
    std::cout << std::endl;

    std::string shuffled = StringManipulator::shuffle(inputString);
    std::cout << "Shuffled: " << shuffled << std::endl;

    std::string joined = StringManipulator::join(splitResult, "-");
    std::cout << "Joined: " << joined << std::endl;

    std::string normalized = StringManipulator::normalizeSpaces(inputString);
    std::cout << "Normalized Spaces: " << normalized << std::endl;

    std::string capitalized = StringManipulator::capitalizeWords(inputString);
    std::cout << "Capitalized Words: " << capitalized << std::endl;

    std::string reversedWords = StringManipulator::reverseWords(inputString);
    std::cout << "Reversed Words: " << reversedWords << std::endl;

    std::string encodedHTML = StringManipulator::encodeHTML(inputString);
    std::cout << "Encoded HTML: " << encodedHTML << std::endl;

    return 0;
}
