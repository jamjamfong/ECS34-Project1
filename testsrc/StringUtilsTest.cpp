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

};

TEST(StringUtilsTest, Center){
    
    // Standard test
    std::string inStringOne = "Hello";
    std::string resultOne = StringUtils::Center(inStringOne, 20);
    EXPECT_EQ(resultOne, "       Hello       ");

    // Empty string 
    std::string inStringTwo = "";
    std::string resultTwo = StringUtils::Center(inStringOne, 5);
    EXPECT_EQ(resultOne, "     ");

    // String with longer width
    std::string inStringThree = "Hello my name is Jamie";
    std::string resultThree = StringUtils::Center(inStringThree, 5);
    EXPECT_EQ(resultThree, "Hello my name is Jamie"); 

    // Equal to string length
    std::string inStringFour = "Hello";
    std::string resultFour = StringUtils::Center(inStringFour,5);
    EXPECT_EQ(resultFour, "Hello");

    // Negative width 
    std::string inStringFive = "Hello";
    std::string resultFive = StringUtils::Center(inStringFive, -4);
    EXPECT_THROW(resultFive, std::invalid_argument);


    // Fill characters 
    std::string inStringSix = "Hello";
    std::string resultSix = StringUtils::Center(inStringSix, 10, '!');
    EXPECT_EQ(resultSix, "!!!!Hello!!!!");
}

TEST(StringUtilsTest, LJust){
    
    // Standard test 
    std::string inStringOne = "Hello";
    std::string resultOne = StringUtils::LJust(inStringOne, 20);
    EXPECT_EQ(resultOne, "Hello               ");

    // Empty string
    std::string inStringTwo = "";
    std::string resultTwo = StringUtils::RJust(inStringTwo, 4);
    EXPECT_EQ(resultTwo, ""); 


    // Fill character
    std::string inStringThree = "Hello";
    std::string resultThree = StringUtils::LJust(inStringThree,20);
    EXPECT_EQ(resultThree, "Hello!!!!!!!!!!!!!!!");

    // Negative width 
    std::string inStringFour = "Hello";
    std::string resultFour = StringUtils::LJust(inStringFour, -4);
    EXPECT_THROW(resultFour, std::invalid_argument);

    // String longer than width 
    std::string inStringFive = "Hello my name is Jamie";
    std::string resultFive = StringUtils::LJust(inStringFive, 4);
    EXPECT_EQ(resultFive, inStringFive);
}

TEST(StringUtilsTest, RJust){
    
}

TEST(StringUtilsTest, Replace){
    
    // Standard Test 
    std::string inStringOne = "pizza pie moon";
    std::string resultOne = StringUtils::Replace(inStringOne, "moon", "cheese");
    EXPECT_EQ(resultOne, "pizza pie cheese");

    // Replace with empty 
    std::string inStringTwo = "pizza pie moon";
    std::string resultTwo = StringUtils::Replace(inStringTwo, " ", "");
    EXPECT_EQ(resultTwo, "pizzapiemoon");

    // Replace an empty string 
    std::string inStringThree = "";
    std::string resultThree = StringUtils::Replace(inStringThree, "pizza", "pie");
    EXPECT_EQ(resultThree, "");

    // Replace repetition
    std::string inStringFour = "pizza pizza pizza pie pie pie";
    std::string resultFour = StringUtils::Replace(inStringFour, "pizza", "moon");
    EXPECT_EQ(resultFour, "moon moon moon pie pie pie");

    // Nothing to replace 
    std::string inStringFive = "pizza pie moon";
    std::string resultFive = StringUtils::Replace(inStringThree, "cheese", "pickle");
    EXPECT_EQ(resultThree, "pizza pie moon");
}


TEST(StringUtilsTest, Split) {
    
    // Standard test 
    std::string inStringOne = "pizza.pie.moon";
    std::vector<std::string> resultOne = StringUtils::Split(inStringOne, ".");
    std::vector<std::string> expectedOne = {"pizza", "pie", "moon"};
    EXPECT_EQ(resultOne, expectedOne);

    // No split parameter 
    std::string inStringTwo = "Hello my name is Jamie";
    std::vector<std::string> resultTwo = StringUtils::Split(inStringTwo);
    std::vector<std::string> expectedTwo = {"Hello", "my", "name", "is", "Jamie"};
    EXPECT_EQ(resultTwo, expectedTwo);

    // Empty string 
    std::string inStringThree = "";
    std::vector<std::string> resultThree = StringUtils::Split(inStringThree);
    std::vector<std::string> expectedThree = {};
    EXPECT_EQ(resultThree, expectedThree);

    // Empty separator
    std::string inStringFour = "pizza";
    std::vector<std::string> resultFour = StringUtils::Split(inStringFour);
    std::vector<std::string> expectedFour = {"pizza"};
    EXPECT_EQ(resultFour, expectedFour);
}


TEST(StringUtilsTest, Join){
    
    // Standard test 
    std::vector<std::string>setOne = {"pizza", "pie", "moon"};
    std::string resultOne = StringUtils::Join(" ", setOne);
    EXPECT_EQ(resultOne, "pizza pie moon");

    // Empty vector 
    std::vector<std::string>setTwo;
    std::string resultTwo = StringUtils::Join(" ", setTwo);
    EXPECT_EQ(resultTwo, "");

    // One element 
    std::vector<std::string>setThree = {"pizza"};
    std::string resultThree = StringUtils::Join(".", setThree);
    EXPECT_EQ(resultThree, "pizza"); 

    // Empty seperator 
    std::vector<std::string>setFour = {"pizza", "pie", "moon"};
    std::string resultFour = StringUtils::Join("", setFour);
    EXPECT_EQ(resultFour, "pizzapiemoon");

    // Different/longer seperator
    std::vector<std::string>setFive = {"pizza", "pie", "moon"};
    std::string resultFive = StringUtils::Join("$$$", setFive);
    EXPECT_EQ(resultFive, "pizza$$$pie$$$moon");

}

TEST(StringUtilsTest, ExpandTabs){
    
    // Standard test
    std::string inStringOne = "Hello\tmy\tname\tis\tJamie";
    std::string resultOne = StringUtils::ExpandTabs(inStringOne);
    EXPECT_EQ(resultOne, "Hello   my name    is   Jamie");

    // Different tab size 
    std::string inStringTwo = "Hello\tmy\tname\tis\tJamie";
    std::string resultTwo = StringUtils::ExpandTabs(inStringTwo, 2);
    EXPECT_EQ(resultTwo, "Hello my name is Jamie");

   // Empty string
    std::string inStringThree = "";
    std::string resultThree = StringUtils::ExpandTabs(inStringThree);
    EXPECT_EQ(resultThree, "");

    // No tabs
    std::string inStringFour = "Hello my name is Jamie";
    std::string resultFour = StringUtils::ExpandTabs(inStringFour);
    EXPECT_EQ(resultFour, "Hello my name is Jamie");
}

TEST(StringUtilsTest, EditDistance){
    
    // Standard test

}

