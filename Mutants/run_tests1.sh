#!/bin/bash

# Array of test names from your DeepState test suite
declare -a tests=(
  "StringManipulator_Reverse"
  "StringManipulator_ToUpperCase"
  "StringManipulator_ToLowerCase"
  "StringManipulator_Replace"
  "StringManipulator_Remove"
  "StringManipulator_CountWords"
  "StringManipulator_IsPalindrome"
  "StringManipulator_FindSubstring"
  "StringManipulator_Shuffle"
  "StringManipulator_Join"
  "StringManipulator_NormalizeSpaces"
  "StringManipulator_CapitalizeWords"
  "StringManipulator_ReverseWords"
  "StringManipulator_EncodeHTML"
)

# Directory to output the test results
output_dir="d"

# Loop through each test and run it
for test in "${tests[@]}"
do
  echo "Running $test..."
  ./a.out --fuzz --output_test_dir $output_dir --timeout 30 --run_test $test
  echo "completed $test..."
done

echo "All tests completed!"
