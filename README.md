# Mutation-Testing-using-DeepState
String Manipulation Library Testing with DeepState


Abstract
This report presents the results from testing the String Manipulation Library using the DeepState test harness, particularly emphasizing ‘DeepState_CStr’. This project uses fuzzing, mutation testing, and code coverage assessment to verify the library's robustness and error-resilience. The information gathered from these tests confirms the library's general dependability—achieved through thorough and methodical testing—and points out important areas that require improvement.
Codes Github Link:
 https://github.com/Madhu-Biradakota/Mutation-Testing-using-DeepState
1.	Introduction 
To assure functionality and security, string manipulation is a vital component of software development that requires extensive testing. The DeepState framework has been used to conduct extensive testing on the String Manipulation Library, which is intended to offer a range of string operations. This project describes the techniques and resources used to assess the fault tolerance and performance of the library, including mutation testing, code coverage analysis, and fuzzing with ‘DeepState_CStr’.
About the Code: The code includes functions for manipulating and examining strings, such as reversing, counting words, cutting, dividing, checking for substrings, checking for palindromes, and converting from uppercase to lowercase.
2.	Testing Environment Setup
Hardware and Software: Tests were conducted on a MacBook Air with a 2.0 GHz Quad-Core Intel Core i5, 16 GB RAM, running macOS Mojave.
Tools Used:
•	DeepState: Utilized for fuzz testing, particularly with ‘DeepState_CStr’ for generating string inputs. A Docker image containing DeepState was employed, pulled from Docker using the commands ‘docker pull agroce/deepstate_examples_aflpp’ and executed with ‘docker run -it agroce/deepstate_examples_aflpp’.
•	Mutation Testing Tools: Custom scripts facilitated by commands such as ‘sudo mutate’.
•	Code Coverage: Implemented using ‘Clang++’ and ‘llvm-cov’

3.	Methodology:
Fuzz Testing with DeepState:
•	Setup involved configuring DeepState to generate test cases targeting string manipulation functions using ‘DeepState_CStr’.
•	Execution command: ‘./a.out --fuzz --output_test_dir d --timeout 30’.
Mutation Testing:
•	Mutation testing introduced faults into the library to assess the test suite's ability to detect them.
•	Commands:
o	Create mutants: sudo mutate StringManipulator.cpp.
o	Analyze mutants: ‘sudo analyze_mutants StringManipulator.cpp Final_SM_2’.
Code Coverage:
•	Code coverage measured the extent to which the source code was executed during tests.
•	Execution commands: ‘clang++ --coverage -o output_SM main_StringManipulator.cpp StringManipulator.cpp’, followed by ‘llvm-cov gcov StringManipulator.cpp’.
4.	String Library Functions:
The String Manipulation Library consists of the following 24 functions:
•	reverse: Reverses the given string.
•	toUpperCase: Converts all characters in the string to uppercase.
•	toLowerCase: Converts all characters in the string to lowercase.
•	replace: Replaces occurrences of a substring with another substring in the given string.
•	remove: Removes all occurrences of a substring from the string.
•	countWords: Counts the number of words in the string.
•	isPalindrome: Checks if the string is a palindrome, ignoring non-alphanumeric characters and case.
•	findSubstring: Finds the starting index of the first occurrence of a substring.
•	shuffle: Randomly shuffles the characters in the string.
•	join: Joins elements of a vector of strings into a single string separated by a delimiter.
•	normalizeSpaces: Normalizes consecutive spaces to a single space in the string.
•	capitalizeWords: Capitalizes the first letter of each word in the string.
•	reverseWords: Reverses the order of words in the string.
•	encodeHTML: Encodes special HTML characters in the string.
•	trim: Removes leading and trailing spaces from the string.
•	trimLeft: Removes leading spaces from the string.
•	trimRight: Removes trailing spaces from the string.
•	compare: Compares two strings for equality, ignoring case.
•	split: Splits the string into a vector of strings based on a delimiter.
•	contains: Checks if the string contains a specified substring.
•	countCharacter: Counts occurrences of a specific character in the string.
•	findFirstNotOf: Finds the first character in the string that does not match any character specified in the argument.
•	findFirstOf: Finds the first character in the string that matches any character specified in the argument.
•	countDistinctWords: Counts the number of distinct words in the string.

5.	Code Metrics:
StringManipulator.cpp:
•	This file contains the library’s implementation of 24 different string manipulation functions, which shows the library's robustness and versatility.
•	Using CLOC command, ‘StringManipulator.cpp’ comprises a total of 205 lines of code. 
 
TestStringManipulator.cpp:
•	This file has test functions for StringManipulator.cpp through the DeepState framework. It notably uses DeepState_CStr to generate test inputs, ensuring each function is thoroughly evaluated.
•	The TestStringManipulator.cpp file consists of 100 lines of code, primarily made up of test cases.
 
StringManipulator.h:
•	The StringManipulator.h file acts as the header for the StringManipulator.cpp, containing all the function declarations.
 
main_StringManipulator.cpp:
•	It contains the ‘main’ function.
 
The total number of lines of code combined is 381.
 

6.	Transferring Files to Docker Container:
I transferred essential project files from my local machine to the Docker container to facilitate testing within a controlled environment. Here’s a summary of the transfer process:
Command: docker cp <local_path> <container_id>:<container_path>
 
7.	Execution Process and Results:
I conducted a series of commands within a Docker environment to test the String Manipulation Library using DeepState. Here’s the process:
i.	Starting the Docker Container:
•	Command: docker exec -it 40f3da57eaff bash
•	Purpose: This command launches the Docker container(container id: 40f3da57eaff).
ii.	Compiling the Code:
•	Command: clang++ StringManipulator.cpp TestStringManipulator.cpp -ldeepstate
•	Purpose: This command compiles StringManipulator.cpp and TestStringManipulator.cpp using Clang++, linking the DeepState library for fuzz testing.
iii.	Executing the Tests:
•	Command: ./a.out
•	Purpose: Executes the compiled code to run the test funtions specified in TestStringManipulator.cpp
 
iv.	Outcomes: 
The test results shown in the screenshot demonstrate the execution of various string manipulation functions:
•	Functions like StringManipulator_Reverse, StringManipulator_ToUpperCase, and StringManipulator_CountWords passed, confirming their operational integrity.
•	However, some functions, like StringManipulator_Replace and StringManipulator_Shuffle failing the tests.
I.	Fuzz Testing Process and Results:
I carried out a series of fuzz tests using the run_tests.sh shell script. This script is designed to automate the fuzz testing process for each function listed in its test array.
i.	Script Execution Details:
•	Command: To start fuzz testing for each specified function, the script executes the following command:
•	./a.out --fuzz --output_test_dir $output_dir --timeout 30 --run_test $test
•	This command runs each test with a 30 sec timeout.
 
ii.	Execution of Script:
•	Starting the Script: The shell script was executed using: ./run_tests.sh
•	This command triggers a series of fuzz tests, executing them sequentially for each function listed in the script.

iii.	Outcome:
•	The screenshots below show how the script executed fuzz testing on string manipulation functions.
•	The outcomes of these tests varied, with some functions completed successfully. 
 
 
II.	Mutation Testing and Analysis:
I conducted mutation testing on the String Manipulator Library. This process has in two parts:
i.	Creating Mutants:
•	Command: sudo mutate StringManipulator.cpp --cmd "clang++ -std=c++11 -c -o SM_mutants StringManipulator.cpp" --mutantDir mutants
•	Outcome: This command successfully produced over 1,313 mutants of the StringManipulator.cpp file mutants. Out of 1313 mutants, 444 valid mutants and 869 invalid mutants with a valid percentage of 33.81%. 
 
 
 
ii.	Analyzing Mutants:
•	Command: analyze_mutants StringManipulator.cpp "clang++ -std=c++11 StringManipulator.cpp TestStringManipulator.cpp -ldeepstate -o a.out; ./a.out --fuzz --abort_on_fail --timeout 3" --timeout 10 --verbose --mutantDir mutants 
•	Execution: The analysis involved running the generated mutants to see if the tests could eliminate the mutants, like "killing" them.
 
Outcome: The test achieved a mutation score of 0.532252, indicating that approximately 53% of the mutants were detected.  
III.	Code Coverage Assessment
I performed a code coverage analysis on the String Manipulation Library. This involved compiling the code with coverage and then executing it to collect relevant data.
i.	Compiling with Coverage Options:
•	Command: clang++ --coverage -o output_SM main_StringManipulator.cpp StringManipulator.cpp
•	Purpose: This command compiles the source files with coverage instrumentation, enabling the generation of data on which parts of the code are executed during tests.
ii.	Executing the Compiled Program:
•	Command: ./output_SM
•	Outcome: Running the output executable allows us to test the library's functionalities.
 
iii.	Analyzing Coverage Data :
•	Command: llvm-cov gcov StringManipulator.cpp
•	Result: This tool examines the coverage data collected during test runs. 
 
Achieved a code coverage metric of 56.50%, indicating that more than half of the code was successfully executed and tested during the analysis.
 
References
[1] 	LLVM, “llvm-cov - emit coverage information,” [Online]. Available: https://llvm.org/docs/CommandGuide/llvm-cov.ht.

[2] 	Springer, “Mutation testing in the wild: findings from GitHub,” [Online]. Available: https://link.springer.com/article/10.1007/s10664-022-10177-8.






