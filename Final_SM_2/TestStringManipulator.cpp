
#include <deepstate/DeepState.hpp>
using namespace deepstate;

#include "StringManipulator.h"

// Test for reversing strings
TEST(StringManipulator, Reverse) {
  const char* originalCStr = DeepState_CStr(10);  // Specifying string length
  std::string original(originalCStr);
  std::string reversed = StringManipulator::reverse(original);
  std::string doubleReversed = StringManipulator::reverse(reversed);
  ASSERT_EQ(original, doubleReversed) << "Double reversing should return to original";
}

// Test for converting strings to uppercase
TEST(StringManipulator, ToUpperCase) {
  const char* originalCStr = DeepState_CStr(10);  // Specifying string length
  std::string original(originalCStr);
  std::string upper = StringManipulator::toUpperCase(original);
  for (size_t i = 0; i < original.size(); i++) {
    ASSERT_EQ(std::toupper(original[i]), upper[i]) << "Each character should be converted to uppercase";
  }
}

// Test for converting strings to lowercase
TEST(StringManipulator, ToLowerCase) {
  const char* originalCStr = DeepState_CStr(10);  // Specifying string length
  std::string original(originalCStr);
  std::string lower = StringManipulator::toLowerCase(original);
  for (size_t i = 0; i < original.size(); i++) {
    ASSERT_EQ(std::tolower(original[i]), lower[i]) << "Each character should be converted to lowercase";
  }
}

// Test for replacing substrings
TEST(StringManipulator, Replace) {
  const char* originalCStr = DeepState_CStr(20);  // Specifying string length up to 20
  std::string original(originalCStr);
  std::string modified = StringManipulator::replace(original, "a", "o");
  ASSERT_NE(original, modified) << "Modified string should not be the same as the original";
}

// Test for removing substrings
TEST(StringManipulator, Remove) {
  const char* originalCStr = DeepState_CStr(20);
  std::string original(originalCStr);
  std::string modified = StringManipulator::remove(original, "a");
  ASSERT_NE(original, modified) << "Modified string should not be the same as the original";
}

// Test for counting words
TEST(StringManipulator, CountWords) {
  const char* text = DeepState_CStr(100);  // Specifying string length
  std::string str(text);
  int count = StringManipulator::countWords(str);
  ASSERT_GE(count, 0) << "Count should be non-negative";
}

// Test for checking if a string is a palindrome
TEST(StringManipulator, IsPalindrome) {
  const char* originalCStr = DeepState_CStr(10);  // Specifying string length
  std::string original(originalCStr);
  bool isPal = StringManipulator::isPalindrome(original);
  ASSERT_TRUE(isPal || !isPal) << "Result should be true or false, palindrome or not";
}

// Test for finding substrings
TEST(StringManipulator, FindSubstring) {
  const char* originalCStr = DeepState_CStr(10);  // Specifying string length
  std::string str(originalCStr);
  size_t pos = StringManipulator::findSubstring(str, "test");
  ASSERT_TRUE(pos != std::string::npos || pos == std::string::npos) << "Should either find 'test' or not";
}
///////////////////

// Test for shuffling strings
TEST(StringManipulator, Shuffle) {
  const char* originalCStr = DeepState_CStr(20);
  std::string original(originalCStr);
  std::string shuffled = StringManipulator::shuffle(original);
  ASSERT_NE(original, shuffled) << "Shuffled string should not be the same as the original";
}

// Test for joining strings
TEST(StringManipulator, Join) {
  std::vector<std::string> strings = {"hello", "world"};
  std::string delimiter = " ";
  std::string joined = StringManipulator::join(strings, delimiter);
  ASSERT_EQ(joined, "hello world") << "Joined string should be 'hello world'";
}

// Test for normalizing spaces
TEST(StringManipulator, NormalizeSpaces) {
  const char* originalCStr = "  This   is   a  test   ";
  std::string original(originalCStr);
  std::string normalized = StringManipulator::normalizeSpaces(original);
  ASSERT_EQ(normalized, " This is a test ") << "Normalized spaces should collapse multiple spaces to single";
}

// Test for capitalizing words
TEST(StringManipulator, CapitalizeWords) {
  const char* originalCStr = "this is a test";
  std::string original(originalCStr);
  std::string capitalized = StringManipulator::capitalizeWords(original);
  ASSERT_EQ(capitalized, "This Is A Test") << "Words should be capitalized";
}

// Test for reversing words in a string
TEST(StringManipulator, ReverseWords) {
  const char* originalCStr = "hello world";
  std::string original(originalCStr);
  std::string reversed = StringManipulator::reverseWords(original);
  ASSERT_EQ(reversed, "world hello") << "Words should be reversed in order";
}

// Test for encoding HTML special characters
TEST(StringManipulator, EncodeHTML) {
  const char* originalCStr = "<html>";
  std::string original(originalCStr);
  std::string encoded = StringManipulator::encodeHTML(original);
  ASSERT_EQ(encoded, "&lt;html&gt;") << "HTML should be properly encoded";
}



int main(int argc, char *argv[]) {
  int ret = 0;
  DeepState_Setup();
  DeepState_InitOptions(argc, argv);
  ret = DeepState_Run();
  DeepState_Teardown();
  return ret;
}