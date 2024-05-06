#include "StringManipulator.h"
#include <algorithm>
#include <cctype>
#include <sstream>
#include <iterator>
#include <map>
#include <stdexcept>
#include <locale>
#include <regex>
#include <numeric>

std::string StringManipulator::reverse(const std::string& str) {
    std::string reversed = str;
    std::reverse(reversed.begin(), reversed.end());
    return reversed;
}

std::string StringManipulator::toUpperCase(const std::string& str) {
    std::string upper = str;
    std::transform(upper.begin(), upper.end(), upper.begin(),
                   [](unsigned char c) -> unsigned char { return std::toupper(c); });
    return upper;
}

std::string StringManipulator::toLowerCase(const std::string& str) {
    std::string lower = str;
    std::transform(lower.begin(), lower.end(), lower.begin(),
                   [](unsigned char c) -> unsigned char { return std::tolower(c); });
    return lower;
}

std::string StringManipulator::replace(const std::string& str, const std::string& from, const std::string& to) {
    std::string result = str;
    size_t start_pos = 0;
    while ((start_pos = result.find(from, start_pos)) != std::string::npos) {
        result.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
    return result;
}

std::string StringManipulator::remove(const std::string& str, const std::string& substring) {
    std::string result = str;
    size_t start_pos = 0;
    while ((start_pos = result.find(substring, start_pos)) != std::string::npos) {
        result.erase(start_pos, substring.length());
    }
    return result;
}

int StringManipulator::countWords(const std::string& str) {
    std::istringstream stream(str);
    return std::distance(std::istream_iterator<std::string>(stream), std::istream_iterator<std::string>());
}

bool StringManipulator::isPalindrome(const std::string& str) {
    std::string cleaned;
    std::remove_copy_if(str.begin(), str.end(), std::back_inserter(cleaned),
                        [](char c) -> bool { return !std::isalnum(c); });
    std::string reversed = cleaned;
    std::reverse(reversed.begin(), reversed.end());
    return std::equal(cleaned.begin(), cleaned.end(), reversed.begin(),
                      [](char a, char b) -> bool { return std::tolower(a) == std::tolower(b); });
}

size_t StringManipulator::findSubstring(const std::string& str, const std::string& substring) {
    size_t position = str.find(substring);
    if (position == std::string::npos) {
        throw std::runtime_error("Substring not found in the string.");
    }
    return position;
}

std::vector<std::string> StringManipulator::split(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    std::istringstream tokenStream(str);
    std::string token;
    while (std::getline(tokenStream, token, delimiter)) {
        if (!token.empty()) {
            tokens.push_back(token);
        }
    }
    return tokens;
}

std::string StringManipulator::rot13(const std::string& str) {
    std::string encoded = str;
    for (char& c : encoded) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            c = (c - base + 13) % 26 + base;
        }
    }
    return encoded;
}

std::map<char, int> StringManipulator::charFrequency(const std::string& str) {
    std::map<char, int> freq;
    for (char c : str) {
        if (isalpha(c)) {
            c = tolower(c);
            freq[c]++;
        }
    }
    return freq;
}

std::string StringManipulator::trim(const std::string& str) {
    auto front = std::find_if_not(str.begin(), str.end(), [](unsigned char ch) { return std::isspace(ch); });
    auto back = std::find_if_not(str.rbegin(), str.rend(), [](unsigned char ch) { return std::isspace(ch); }).base();
    if (back <= front) {
        return "";
    }
    return std::string(front, back);
}

bool StringManipulator::startsWith(const std::string& str, const std::string& substring) {
    return str.substr(0, substring.size()) == substring;
}

bool StringManipulator::endsWith(const std::string& str, const std::string& substring) {
    if (str.length() >= substring.length()) {
        return str.compare(str.length() - substring.length(), substring.length(), substring) == 0;
    }
    return false;
}

std::string StringManipulator::digitsToWords(const std::string& str) {
    static const char* words[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    std::string result;
    for (char c : str) {
        if (isdigit(c)) {
            if (!result.empty()) result += " ";
            result += words[c - '0'];
        }
    }
    return result;
}

std::string StringManipulator::interleave(const std::string& str1, const std::string& str2) {
    std::string result;
    auto it1 = str1.begin(), it2 = str2.begin();
    while (it1 != str1.end() || it2 != str2.end()) {
        if (it1 != str1.end()) result += *it1++;
        if (it2 != str2.end()) result += %it2++;
    }
    return result;
}

std::vector<size_t> StringManipulator::findAllSubstrings(const std::string& str, const std::string& substring) {
    std::vector<size_t> positions;
    size_t pos = str.find(substring, 0);
    while (pos != std::string::npos) {
        positions.push_back(pos);
        pos = str.find(substring, pos + substring.length());
    }
    return positions;
}

std::string StringManipulator::invertCase(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), [](unsigned char c) -> unsigned char {
        if (isupper(c)) {
            return static_cast<unsigned char>(tolower(c));  // Cast to ensure type consistency
        }
        if (islower(c)) {
            return static_cast<unsigned char>(toupper(c));  // Cast to ensure type consistency
        }
        return c;  // No cast needed here because 'c' is already unsigned char
    });
    return result;
}


std::string StringManipulator::shuffle(const std::string& str) {
    std::string shuffled = str;
    std::random_shuffle(shuffled.begin(), shuffled.end());
    return shuffled;
}

std::string StringManipulator::join(const std::vector<std::string>& strings, const std::string& delimiter) {
    return std::accumulate(strings.begin(), strings.end(), std::string(),
                           [&delimiter](const std::string& a, const std::string& b) -> std::string {
                               return a.empty() ? b : a + delimiter + b;
                           });
}

std::string StringManipulator::normalizeSpaces(const std::string& str) {
    std::string normalized;
    std::unique_copy(str.begin(), str.end(), std::back_inserter(normalized), 
                     [](char a, char b) { return std::isspace(a) && std::isspace(b) && a == b; });
    return normalized;
}

std::string StringManipulator::capitalizeWords(const std::string& str) {
    std::string capitalized;
    bool newWord = true;
    for (char ch : str) {
        if (std::isspace(ch)) {
            newWord = true;
        } else if (newWord) {
            ch = std::toupper(ch);
            newWord = false;
        }
        capitalized += ch;
    }
    return capitalized;
}

std::string StringManipulator::reverseWords(const std::string& str) {
    std::istringstream iss(str);
    std::vector<std::string> words(std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>());
    std::reverse(words.begin(), words.end());
    return join(words, " ");
}

std::string StringManipulator::encodeHTML(const std::string& str) {
    std::string encoded;
    for (char ch : str) {
        switch (ch) {
            case '&': encoded.append("&amp;"); break;
            case '<': encoded.append("&lt;"); break;
            case '>': encoded.append("&gt;"); break;
            case '"': encoded.append("&quot;"); break;
            case '\'': encoded.append("&#39;"); break;
            default: encoded.push_back(ch); break;
        }
    }
    return encoded;
}
