# Project-1


/* MAKEFILE CITATIONS */ 

1. Prompt: 
        "How to implement bin and obj directories in a makefile"
   ChatGPT Answer:
        "To implement bin and obj directories in a Makefile, you can include rules for creating these directories and specify them as targets. Here's an example Makefile that demonstrates how to create bin and obj directories:

        make
        Copy code
        # Makefile

        CXX = g++            # C++ compiler
        CXXFLAGS = -std=c++17 -Wall -I./include
        LIBS = -lgtest -lgtest_main -lpthread

        OBJ_DIR = ./obj
        BIN_DIR = ./bin
        SRC_DIR = ./src
        INC_DIR = ./include

        # List your source files
        SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)

        # List your object files based on source files
        OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

        # Main target
        all: directories runtests

        # Run tests after building executable
        runtests: $(BIN_DIR)/teststrutils
            $(BIN_DIR)/teststrutils

        # Target for teststrutils executable
        $(BIN_DIR)/teststrutils: $(OBJ_FILES)
            $(CXX) -o $@ $^ $(LIBS)

        # Build rule for object files
        $(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
            $(CXX) -o $@ -c $(CXXFLAGS) $<

        # Cleans up built directories
        clean:
            rm -rf $(OBJ_DIR)
            rm -rf $(BIN_DIR)

        # Creates directories if not existing
        directories:
            mkdir -p $(OBJ_DIR)
            mkdir -p $(BIN_DIR)
        In this example:

        $(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp is a pattern rule to build object files from corresponding source files.
        $(BIN_DIR)/teststrutils: $(OBJ_FILES) specifies that the teststrutils executable depends on all object files.
        clean target removes the obj and bin directories.
        You can customize this Makefile according to your project structure and requirements

    Why:
        - I was unsure how to create directories in a makefile


/*TEST CITATIONS*/

1. Prompt: 
    "how would I make test cases in Google Tests for a function that capitalizes letters"

    ChatGPT Answer:
    "To create test cases for a function that capitalizes letters using Google Test, you can follow these steps:

    Include Necessary Headers:
    Include the necessary headers for Google Test and the file containing yournstring manipulation functions.
    cpp
    Copy code
    #include <gtest/gtest.h>
    #include "StringUtils.h"  // Replace with the actual header file name
    Write Test Cases:
    Write individual test cases to cover different scenarios. Ensure that you cover edge cases, typical cases, and any special cases your function should handle.
    cpp
    Copy code
    TEST(StringUtilsTest, CapitalizeLetters) {
        // Standard test case
        std::string inputOne = "hello";
        std::string resultOne = StringUtils::CapitalizeLetters(inputOne);
        EXPECT_EQ(resultOne, "HELLO");

        // Test case with mixed case
        std::string inputTwo = "HeLLo";
        std::string resultTwo = StringUtils::CapitalizeLetters(inputTwo);
        EXPECT_EQ(resultTwo, "HELLO");

        // Test case with numbers and symbols
        std::string inputThree = "abc123!@#";
        std::string resultThree = StringUtils::CapitalizeLetters(inputThree);
        EXPECT_EQ(resultThree, "ABC123!@#");

        // Test case with an empty string
        std::string inputFour = "";
        std::string resultFour = StringUtils::CapitalizeLetters(inputFour);
        EXPECT_EQ(resultFour, "");

        // Test case with all uppercase letters
        std::string inputFive = "UPPERCASE";
        std::string resultFive = StringUtils::CapitalizeLetters(inputFive);
        EXPECT_EQ(resultFive, "UPPERCASE");
    }
    Compile and Run Tests:
    Ensure that your test file is compiled along with the source code containing the StringUtils::CapitalizeLetters function. Run the compiled test executable.
    Check Test Results:
    Verify that all the test cases pass. If any test case fails, investigate and fix the issues in your implementation.
    Remember to replace "StringUtils.h" with the actual header file that contains the declaration of your CapitalizeLetters function. Additionally, adjust the test cases based on the specific requirements of your function."

    Why:
    - I didn't really understand how to make test cases and need an example to figure out how I would do the captalize one and the rest 
    - I copied the functions given and made sure to understand how to use them for the future (EXPECT_EQ)

2. Prompt: 
    "How do I create test cases with vectors"

    Answer:
            "Certainly! Here's a generic example of creating test cases with vectors using Google Test:

    cpp
    Copy code
    #include <gtest/gtest.h>

    // Function to be tested
    std::vector<int> MultiplyByTwo(const std::vector<int>& input) {
        std::vector<int> result;
        for (int value : input) {
            result.push_back(value * 2);
        }
        return result;
    }

    // Test case for MultiplyByTwo function
    TEST(MyTestSuite, MultiplyByTwo) {
        // Test case with a non-empty vector
        std::vector<int> inputOne = {1, 2, 3};
        std::vector<int> resultOne = MultiplyByTwo(inputOne);
        std::vector<int> expectedOne = {2, 4, 6};
        EXPECT_EQ(resultOne, expectedOne);

        // Test case with an empty vector
        std::vector<int> inputTwo = {};
        std::vector<int> resultTwo = MultiplyByTwo(inputTwo);
        std::vector<int> expectedTwo = {};
        EXPECT_EQ(resultTwo, expectedTwo);

        // Test case with negative values
        std::vector<int> inputThree = {-1, -2, -3};
        std::vector<int> resultThree = MultiplyByTwo(inputThree);
        std::vector<int> expectedThree = {-2, -4, -6};
        EXPECT_EQ(resultThree, expectedThree);
    }

    int main(int argc, char** argv) {
        ::testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
    }
    In this example, the function MultiplyByTwo takes a vector of integers and multiplies each element by two. The test cases use the EXPECT_EQ macro to compare the actual results with the expected vectors. Adjust the example based on the specific functions you want to test and the types involved."

    Why:
    - I didn't know if EXPECT_EQ() could handle vector values 


/*FUNCTION CITATIONS*/

1. https://stackoverflow.com/questions/8530529 convert-first-letter-in-string-to-uppercase

2. Prompt: 

        " std::string RStrip(const std::string &str) noexcept{

            size_t lastNonWhitespace = str.find_last_not_of("\t\n\r\f\v");

            if(lastNonWhitespace == std::string::npos){
                return "";
            }

            return str.substr(0, lastNonWhitespace + 1);
        } fix this function so that it strips the whitespace on the right side"

    Bard Answer: 

        Key changes:

        Expanded whitespace definition: The find_last_not_of expression now includes a space character (" ") in addition to the other whitespace characters. This ensures that regular spaces are also stripped.
        Explanation:

        Finding last non-whitespace: The find_last_not_of method locates the index of the last character that's not within the specified set of whitespace characters.
        Handling whitespace-only string: If no non-whitespace character is found, the function returns an empty string.
        Extracting substring: The substr method extracts the substring from the beginning of the string up to the last non-whitespace character, effectively removing trailing whitespace.
        With this correction, the RStrip function will now correctly strip all types of whitespace characters, including spaces, from the right side of the input string.

    Why: 
        - was having problems getting it to work even though my LStrip function was working and they were generally the same idea 
        - just needed to add the spce in the .find_last_not_of()

3. Prompt: 
    "Adjust the LJust function so that if there is no fill character it would just be space"

   ChatGPT Answer: 
    "Certainly! Here's the modified `LJust` function:

    ```cpp
    std::string StringUtils::LJust(const std::string &str, int width, char fill) {
        if (width <= 0) {
            // Negative or zero width, return an empty string
            return "";
        }

        int space = std::max(0, width - static_cast<int>(str.length()));

        if (fill == '\0') {
            // If no fill character provided, use space by default
            fill = ' ';
        }

        return str + std::string(space, fill);
    }
    ```

    Now, this function will use a space as the default fill character if none is provided. Please try this adjusted function in your test cases." 

    Why:
     - my function couldn't handle when there wasn't a fill character inputted 
     - added a loop which accounted for if there was no fill 
     - changed the comparison to '\0' not "\0" which was giving me an error because fill is a character not a string 

4. Prompt: 
    "How do I find and replace the position of a string in C++ without adding other includes"

    ChatGPT Answer:
        "If you want to find and replace a substring within a string using only <string> and <vector> includes in C++, you can use the following approach. This involves iterating through the string and replacing occurrences of the target substring. Here's an example function:

    cpp
    Copy code
    #include <iostream>
    #include <string>
    #include <vector>

    std::string FindAndReplace(const std::string& input, const std::string& target, const std::string& replacement) {
        std::string result = input;
        std::vector<size_t> positions;

        // Find all occurrences of the target substring
        size_t pos = result.find(target);
        while (pos != std::string::npos) {
            positions.push_back(pos);
            pos = result.find(target, pos + 1);
        }

        // Replace occurrences in reverse order to avoid changing positions of subsequent replacements
        for (auto it = positions.rbegin(); it != positions.rend(); ++it) {
            result.replace(*it, target.length(), replacement);
        }

        return result;
    }

    int main() {
        std::string input = "Hello world! Hello universe!";
        std::string target = "Hello";
        std::string replacement = "Hi";

        std::string output = FindAndReplace(input, target, replacement);

        std::cout << "Original: " << input << std::endl;
        std::cout << "Replaced: " << output << std::endl;

        return 0;
    }
    This example defines a FindAndReplace function that uses a vector to store the positions of occurrences of the target substring. It then iterates through these positions and replaces the target substring with the replacement string in reverse order to avoid changing positions of subsequent replacements."

    4. https://www.geeksforgeeks.org/stringnpos-in-c-with-examples/