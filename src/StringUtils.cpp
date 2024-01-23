#include "StringUtils.h"

namespace StringUtils{

std::string Slice(const std::string &str, ssize_t start, ssize_t end) noexcept {

}


std::string Capitalize(const std::string &str) noexcept{
    
    // if the string is empty return an empty string
    if(str.empty()){
        return "";
    }

    // converts first character to capital and stores it as the result
    std::string result = std::string(1, std::toupper(str[0]));

    //keeps the rest of the characters in the string lowercase 
    for(size_t i = 1; i < str.size(); ++i){
        result += std::tolower(str[i]);
    }

    return result;
}

std::string Upper(const std::string &str) noexcept{

    // if the string is empty return an empty string 

    if (str.empty()){
        return "";
    }

    // creates a string called result
    std::string result;

    // converts every character in the result string to uppercase
    for(char c : str){
        result += std::toupper(c);
    }

    return result;

}

std::string Lower(const std::string &str) noexcept{

    // if string is empty return an empty string 
    if(str.empty()){
        return "";
    }

    // creates result string
    std::string result;

    // converts every character in the string to lowercase
    for(char c: str){
        result+= std::tolower(c);
    }

    return result;
}
    

std::string LStrip(const std::string &str) noexcept{
    
 
}

std::string RStrip(const std::string &str) noexcept{
    
}

std::string Strip(const std::string &str) noexcept{
    // Replace code here
    return "";
}

std::string Center(const std::string &str, int width, char fill) noexcept{
    // Replace code here
    return "";
}

std::string LJust(const std::string &str, int width, char fill) noexcept{
    // Replace code here
    return "";
}

std::string RJust(const std::string &str, int width, char fill) noexcept{
    // Replace code here
    return "";
}

std::string Replace(const std::string &str, const std::string &old, const std::string &rep) noexcept{
    // Replace code here
    return "";
}

std::vector< std::string > Split(const std::string &str, const std::string &splt) noexcept{
    // Replace code here
    return {};
}

std::string Join(const std::string &str, const std::vector< std::string > &vect) noexcept{
    // Replace code here
    return "";
}

std::string ExpandTabs(const std::string &str, int tabsize) noexcept{
    // Replace code here
    return "";
}

int EditDistance(const std::string &left, const std::string &right, bool ignorecase) noexcept{
    // Replace code here
    return 0;
}

};