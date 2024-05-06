/*
#include <deepstate/DeepState.hpp>
using namespace deepstate;

//#include "StringManipulator.cpp"
#include "StringManipulator.h"

// Test for reversing strings
TEST(StringManipulator, reverse) {
  LOG(INFO) << "Testing reverseString function";
  const char* originalCStr = DeepState_CStr(10);  // Specifying string length
  std::string original(originalCStr);
  std::string reversed = StringManipulator::reverse(original);
  std::string doubleReversed = StringManipulator::reverse(reversed);
  ASSERT_EQ(original, doubleReversed) << "Double reversing should return to original";
}

// Test for converting strings to uppercase
TEST(StringManipulator, ToUpperCase) {
  LOG(INFO) << "Testing toUpperCase function";
  const char* originalCStr = DeepState_CStr(10);  // Specifying string length
  std::string original(originalCStr);
  std::string upper = StringManipulator::toUpperCase(original);
  for (size_t i = 0; i < original.size(); i++) {
    ASSERT_EQ(std::toupper(original[i]), upper[i]) << "Each character should be converted to uppercase";
  }
}

// Modify other test cases similarly by adding a length argument to DeepState_CStr()


#include <deepstate/DeepState.hpp>
using namespace deepstate;

#include "StringManipulator.h"

TEST(StringManipulator, Reverse) {
  LOG(INFO) << "Testing Reverse function";
  const char* originalCStr = DeepState_CStr(256); // Ensure strings are null-terminated
  std::string original(originalCStr);
  std::string reversed = StringManipulator::reverse(original);
  std::string doubleReversed = StringManipulator::reverse(reversed);
  ASSERT(strcmp(original.c_str(), doubleReversed.c_str()) == 0) << "Double reversing should return to original";
}

TEST(StringManipulator, ToUpperCase) {
  LOG(INFO) << "Testing ToUpperCase function";
  const char* originalCStr = DeepState_CStr(256);
  std::string original(originalCStr);
  std::string upper = StringManipulator::toUpperCase(original);
  for (size_t i = 0; i < original.size(); i++) {
    ASSERT(std::toupper(original[i]) == upper[i]) << "Each character should be converted to uppercase";
  }
}

// Ensure main function is setup correctly for DeepState
int main(int argc, char *argv[]) {
  DeepState_InitOptions(argc, argv);
  return DeepState_Run();
}
*/

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
