// StringManipulator.h
#ifndef STRINGMANIPULATOR_H
#define STRINGMANIPULATOR_H

#include <string>

class StringManipulator {
public:
    static std::string reverseString(const std::string& str);
    static std::string toUpperCase(const std::string& str);
    static std::string toLowerCase(const std::string& str);
    static std::string concatenateStrings(const std::string& str1, const std::string& str2);
    static int findSubstring(const std::string& str, const std::string& substr);
    static bool isPalindrome(const std::string& str);
    static int countVowels(const std::string& str);
    static std::string replaceChar(std::string str, char oldChar, char newChar);
};

#endif // STRINGMANIPULATOR_H


