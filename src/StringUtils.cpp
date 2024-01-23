#include "StringUtils.h"

namespace StringUtils{

std::string Slice(const std::string &str, ssize_t start, ssize_t end = 0) noexcept {
    return "";
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

    // finds the position first nonwhitespace character in the string
    size_t firstNonWhitespace =str.find_first_not_of(" \t\n\r\f\v");

    // checks if string is empty 
    if(firstNonWhitespace == std::string::npos){
        return "";
    }

    // return substring starting from first nonwhitespace
    return str.substr(firstNonWhitespace);
}


std::string RStrip(const std::string &str) noexcept{
    
    // Finds position of last nonwhitespace characters 
    size_t lastNonWhitespace = str.find_last_not_of(" \t\n\r\f\v");

    //check if string is empty 
    if(lastNonWhitespace == std::string::npos){
        return "";
    }

    //return substring form beginning of string to last nonwhitespace
    return str.substr(0, lastNonWhitespace + 1);

}

std::string Strip(const std::string &str) noexcept{

    // finds position of the first and last nonwhitespace characters
    size_t firstNonWhitespace = str.find_first_not_of(" \t\n\r\f\v");
    size_t lastNonWhitespace = str.find_last_not_of(" \t\n\r\f\v");

      // checks if string is empty
    if (firstNonWhitespace == std::string::npos || lastNonWhitespace == std::string::npos) {
        return "";
    }

    // gets the substring between the nonwhitespace characters 
    return str.substr(firstNonWhitespace, lastNonWhitespace - firstNonWhitespace + 1);

}
    
}
std::string Center(const std::string &str, int width, char fill) noexcept{
    
    // finds amt of space needed on each side of the string 
    int space = std::max(0, width - static_cast<int>(str.length()));

    // find left space, if odd then it is less than the right space
    int leftSpace = space / 2;

    // find right space
    int rightSpace = space - leftSpace;

    // concatenate all the parts together
    return std::string(leftSpace, fill) + str + std::string(rightSpace, fill);
}

std::string LJust(const std::string &str, int width, char fill) noexcept{

}
std::string RJust(const std::string &str, int width, char fill) noexcept{

}

std::string Replace(const std::string &str, const std::string &old, const std::string &rep) noexcept{
    
 
}

std::vector< std::string > Split(const std::string &str, const std::string &splt) noexcept{
    

}

std::string Join(const std::string &str, const std::vector< std::string > &vect) noexcept{

}

std::string ExpandTabs(const std::string &str, int tabsize) noexcept{

}

int EditDistance(const std::string &left, const std::string &right, bool ignorecase) noexcept{
    // Replace code here
    return 0;
}

};