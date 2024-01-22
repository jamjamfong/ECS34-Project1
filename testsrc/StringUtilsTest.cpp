#include <gtest/gtest.h>
#include "StringUtils.h"

TEST(StringUtilsTest, SliceTest){
    
    std::string inString = "Hello";

    // Positive start and end
    std::string resultOne = StringUtils::Slice(inString, 1, 4);
    EXPECT_EQ(resultOne, "el");

    // Negative start 
    std::string resultTwo = StringUtils::Slice(inString, -1, 0);
    EXPECT_EQ(resultTwo, "o");

    // Negative end 
    std::string resultThree = StringUtils::Slice(inString, 0, -1);
    EXPECT_EQ(resultThree, "Hell");

    // Negative start and end 
    std::string resultFour = StringUtils::Slice(inString, -1,-2);
    EXPECT_EQ(resultFour, "o"); 

    // Equal index
    std::string resultFive = StringUtils::Slice(inString, 2, 2);
    EXPECT_EQ(resultFive, "");

    // Index out of bounds
    std::string resultSix = StringUtils::Slice(inString, 0, 7);
    EXPECT_EQ(resultSix, "");

};

TEST(StringUtilsTest, Capitalize){
     // Standard test
    std::string inStringOne = "hello";
    std::string resultOne = StringUtils::Capitalize(inStringOne);
    EXPECT_EQ(resultOne, "Hello");

    // Input with a character other than a letter in front
    std::string inStringTwo = "3hello";
    std::string resultTwo = StringUtils::Capitalize(inStringTwo);
    EXPECT_EQ(resultTwo, "3hello");

    // Empty input
    std::string inStringThree = "";
    std::string resultThree = StringUtils::Capitalize(inStringThree);
    EXPECT_EQ(resultThree, "");

    // Already capitalized
    std::string inStringFour = "Hello";
    std::string resultFour = StringUtils::Capitalize(inStringFour);
    EXPECT_EQ(resultFour, "Hello");

    // Capitalized letters within the string
    std::string inStringFive= "HeLLO";
    std::string resultFive = StringUtils::Capitalize(inStringFive);
    EXPECT_EQ(resultFive, "Hello");

    // All letters capitalized
    std::string inStringSix = "HELLO";
    std::string resultSix = StringUtils::Capitalize(inStringSix);
    EXPECT_EQ(resultSix, "Hello");

};

TEST(StringUtilsTest, Upper){
    
    // Standard test
    std::string inStringOne = "hello";
    std::string resultOne = StringUtils::Upper(inStringOne);
    EXPECT_EQ(resultOne, "HELLO");

    // Some letters already capitalized
    std::string inStringTwo = "HeLLo";
    std::string resultTwo = StringUtils::Upper(inStringTwo);
    EXPECT_EQ(resultTwo, "HELLO");

    // Empty input
    std::string inStringThree = "";
    std::string resultThree = StringUtils::Upper(inStringThree);
    EXPECT_EQ(resultThree, "");

    // Other characters in string
    std::string inStringFour = "He45llo!?!";
    std::string resultFour = StringUtils::Upper(inStringFour);
    EXPECT_EQ(resultFour, "HE45LLO!?!");

}

TEST(StringUtilsTest, Lower){

    // Standard test
    std::string inStringOne = "Hello";
    std::string resultOne = StringUtils::Lower(inStringOne);
    EXPECT_EQ(resultOne, "hello");

    // Some letters lowercase 
    std::string inStringTwo = "HeLLo";
    std::string resultTwo = StringUtils::Lower(inStringTwo);
    EXPECT_EQ(resultTwo, "hello");

    // Empty input
    std::string inStringThree = "";
    std::string resultThree = StringUtils::Lower(inStringThree);
    EXPECT_EQ(resultThree, "");

    // Other characters in string
    std::string inStringFour = "He45LLo!?!";
    std::string resultFour = StringUtils::Lower(inStringFour);
    EXPECT_EQ(resultFour, "he45llo!?!");

}

TEST(StringUtilsTest, LStrip){

    // Standard test
    std::string inStringOne = "   hello";
    std::string resultOne = StringUtils::LStrip(inStringOne);
    EXPECT_EQ(resultOne, "hello");

    // No whitespaces 
    std::string inStringTwo = "hello";
    std::string resultTwo = StringUtils::LStrip(inStringTwo);
    EXPECT_EQ(resultTwo, "hello");

    // Empty string
    std::string inStringThree = "";
    std::string resultThree = StringUtils::LStrip(inStringThree);
    EXPECT_EQ(resultThree, "");

    // Only whitespaces
    std::string inStringFour = "   ";
    std::string resultFour = StringUtils::LStrip(inStringFour);
    EXPECT_EQ(resultFour, "");

    // Leading and trailing whitespace
    std::string inStringFive = "   hello   ";
    std::string resultFive = StringUtils::LStrip(inStringFive);
    EXPECT_EQ(resultFive, "hello   ");

    // Whitespace inbetween words
    std::string inStringSix = " hello Bob   ";
    std::string resultSix = StringUtils::LStrip(inStringSix);
    EXPECT_EQ(resultSix, "hello Bob   ");
    
}

TEST(StringUtilsTest, RStrip){

        // Standard test
    std::string inStringOne = "   hello";
    std::string resultOne = StringUtils::RStrip(inStringOne);
    EXPECT_EQ(resultOne, "hello");

    // No whitespaces 
    std::string inStringTwo = "hello";
    std::string resultTwo = StringUtils::RStrip(inStringTwo);
    EXPECT_EQ(resultTwo, "hello");

    // Empty string
    std::string inStringThree = "";
    std::string resultThree = StringUtils::RStrip(inStringThree);
    EXPECT_EQ(resultThree, "");

    // Only whitespaces
    std::string inStringFour = "   ";
    std::string resultFour = StringUtils::RStrip(inStringFour);
    EXPECT_EQ(resultFour, "");

    // Leading and trailing whitespace
    std::string inStringFive = "   hello   ";
    std::string resultFive = StringUtils::RStrip(inStringFive);
    EXPECT_EQ(resultFive, "   hello");

    // Whitespace inbetween words
    std::string inStringSix = "   hello Bob ";
    std::string resultSix = StringUtils::RStrip(inStringSix);
    EXPECT_EQ(resultSix, "   hello Bob");
  
}

TEST(StringUtilsTest, Strip){
    
    // Standard test 
    std::string inStringOne = " hello    ";
    std::string resultOne = StringUtils::Strip(inStringOne);
    EXPECT_EQ(resultOne, "hello");

    // No whitespaces
    std::string inStringTwo = "hello";
    std::string resultTwo = StringUtils::Strip(inStringTwo);
    EXPECT_EQ(resultTwo, "hello");

    // Only whitespace
    std::string inStringThree = "     ";
    std::string resultThree = StringUtils::Strip(inStringThree);
    EXPECT_EQ(resultThree, "");

    // Left whitespace
    std::string inStringFour = "     hello";
    std::string resultFour = StringUtils::Strip(inStringFour);
    EXPECT_EQ(resultFour, "hello");

    // Right whitespace
    std::string inStringFive = "hello     ";
    std::string resultFive = StringUtils::Strip(inStringFive);
    EXPECT_EQ(resultFive,"hello");

    // Whitespace in between words
    std::string inStringSix = "   hello Bob ";
    std::string resultSix = StringUtils::Strip(inStringSix);
    EXPECT_EQ(resultSix, "hello Bob");

    // Empty string 
    std::string inStringSeven = "";
    std::string resultSeven = StringUtils::Strip(inStringSeven);
    EXPECT_EQ(resultSeven, "");

}

TEST(StringUtilsTest, Center){
    
}

TEST(StringUtilsTest, LJust){
    
}

TEST(StringUtilsTest, RJust){
    
}

TEST(StringUtilsTest, Replace){
    
}

TEST(StringUtilsTest, Split){
    
}

TEST(StringUtilsTest, Join){
    
}

TEST(StringUtilsTest, ExpandTabs){
    
}

TEST(StringUtilsTest, EditDistance){
    
}
