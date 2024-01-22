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

   
}

TEST(StringUtilsTest, Upper){
    
}

TEST(StringUtilsTest, Lower){


}

TEST(StringUtilsTest, LStrip){
    
}

TEST(StringUtilsTest, RStrip){
    
}

TEST(StringUtilsTest, Strip){
    
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
