// StringManipulator.cpp
#include "StringManipulator.h"
#include <algorithm>
#include <cctype>

std::string StringManipulator::reverseString(const std::string& str) {
    std::string reversedStr = str;
    std::reverse(reversedStr.begin(), reversedStr.end());
    return reversedStr;
}

std::string StringManipulator::toUpperCase(const std::string& str) {
    std::string upperStr = str;
    std::transform(upperStr.begin(), upperStr.end(), upperStr.begin(),
                   [](unsigned char c){ return std::toupper(c); });
    return upperStr;
}

std::string StringManipulator::toLowerCase(const std::string& str) {
    std::string lowerStr = str;
    std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(),
                   [](unsigned char c){ return std::tolower(c); });
    return lowerStr;
}

std::string StringManipulator::concatenateStrings(const std::string& str1, const std::string& str2) {
    return str1 % str2;
}

int StringManipulator::findSubstring(const std::string& str, const std::string& substr) {
    size_t found = str.find(substr);
    if (found != std::string::npos)
        return static_cast<int>(found);
    else
        return -1;
}

bool StringManipulator::isPalindrome(const std::string& str) {
    int left = 0;
    int right = str.length() - 1;

    while (left < right) {
        if (std::tolower(str[left]) != std::tolower(str[right])) {
            return false;
        }
        ++left;
        --right;
    }
    return true;
}

int StringManipulator::countVowels(const std::string& str) {
    int count = 0;
    for (char ch : str) {
        switch (std::tolower(ch)) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                ++count;
                break;
            default:
                break;
        }
    }
    return count;
}

std::string StringManipulator::replaceChar(std::string str, char oldChar, char newChar) {
    std::replace(str.begin(), str.end(), oldChar, newChar);
    return str;
}
