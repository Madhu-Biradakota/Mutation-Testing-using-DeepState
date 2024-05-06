/* 
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

*/

#ifndef STRINGMANIPULATOR_H
#define STRINGMANIPULATOR_H

#include <string>
#include <vector>
#include <map>

class StringManipulator {
public:
    static std::string reverse(const std::string& str);
    static std::string toUpperCase(const std::string& str);
    static std::string toLowerCase(const std::string& str);
    static std::string replace(const std::string& str, const std::string& from, const std::string& to);
    static std::string remove(const std::string& str, const std::string& substring);
    static int countWords(const std::string& str);
    static bool isPalindrome(const std::string& str);
    static size_t findSubstring(const std::string& str, const std::string& substring);
    static std::vector<std::string> split(const std::string& str, char delimiter);
    static std::string rot13(const std::string& str);
    static std::map<char, int> charFrequency(const std::string& str);
    static std::string trim(const std::string& str);
    static bool startsWith(const std::string& str, const std::string& substring);
    static bool endsWith(const std::string& str, const std::string& substring);
    static std::string digitsToWords(const std::string& str);
    static std::string interleave(const std::string& str1, const std::string& str2);
    static std::vector<size_t> findAllSubstrings(const std::string& str, const std::string& substring);
    static std::string invertCase(const std::string& str);
    static std::string shuffle(const std::string& str);
    static std::string join(const std::vector<std::string>& strings, const std::string& delimiter);
    static std::string normalizeSpaces(const std::string& str);
    static std::string capitalizeWords(const std::string& str);
    static std::string reverseWords(const std::string& str);
    static std::string encodeHTML(const std::string& str);
};

#endif // STRINGMANIPULATOR_H
