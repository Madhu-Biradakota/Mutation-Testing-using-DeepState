#include <deepstate/DeepState.hpp>
using namespace deepstate;

//#include "StringManipulator.cpp"
#include "StringManipulator.h"

// Test for reversing strings
TEST(StringManipulator, ReverseString) {
  LOG(INFO) << "Testing reverseString function";
  const char* originalCStr = DeepState_CStr(10);  // Specifying string length
  std::string original(originalCStr);
  std::string reversed = StringManipulator::reverseString(original);
  std::string doubleReversed = StringManipulator::reverseString(reversed);
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
