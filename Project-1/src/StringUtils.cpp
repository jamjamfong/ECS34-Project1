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
    return "";
}
std::string RJust(const std::string &str, int width, char fill) noexcept{
    return "";
}

std::string Replace(const std::string &str, const std::string &old, const std::string &rep) noexcept{
    
    // store result 
    std::string result = str;

    size_t pos = 0;

    // iterates through string and replaces the old with the new
    while ((pos = result.find(old,pos)) != std::string::npos){
        result.replace(pos,old.length(),rep);
        pos += rep.length(); // moves the position pointed to keep searching 
    }
    return result;
 
}

std::vector< std::string > Split(const std::string &str, const std::string &splt) noexcept{
    
    // vector stores the result strings 
    std::vector<std::string>result;


    if(splt.empty()){
        // if split is empty, split on whitespace 
        size_t start = 0;
        size_t end = str.find_first_of(" \t\n\r\f\v");

        // iterate through string and split on whitespace
        while (start < str.length()) {
            // no whitespace
            if (end == std::string::npos) {
                end = str.length();
            }

            
            result.push_back(str.substr(start, end - start)); // add substring between start and end to result
            start = str.find_first_not_of(" \t\n\r\f\v", end); // update start position to next nonwhitespace
            end = str.find_first_of(" \t\n\r\f\v", start); //update end position to next white space
        }
    } else {

        // if not empty split on input
        size_t start = 0;
        size_t end = str.find(splt);

        // iterate through string and split 
        while (end != std::string::npos) {
            result.push_back(str.substr(start, end - start)); // add substring between start and end to result
            start = end + splt.length(); // update start position to next position
            end = str.find(splt, start); // update end psotion to next separator
        }

        // add remaining substring after last seperator 
        result.push_back(str.substr(start));
    }

    return result;

}

std::string Join(const std::string &str, const std::vector< std::string > &vect) noexcept{

    // store result
    std::string result;

    //iterate through vector elements 
    for (size_t i = 0; i < vect.size(); ++i) {
        result += vect[i]; // add current element to the result

        if (i < vect.size() - 1) {
            result += str;  // add the separator after each element except the last one
        }
    }

    return result;

}

std::string ExpandTabs(const std::string &str, int tabsize) noexcept{

    // stores result 
    std::string result;
    size_t column = 0; // tracks column position 


    // iterate through character in input string
    for (char c : str) {
        if (c == '\t') {
            // if tab replace with space
            int spacesToAdd = tabsize - (column % tabsize);
            result += std::string(spacesToAdd, ' '); // add to result 
            column += spacesToAdd; // update column position 
        } else {
            result += c; // if not a tab add to result 
            // increment column for non-tab characters
            column++;
        }
    }

    return result;
}


int EditDistance(const std::string &left, const std::string &right, bool ignorecase) noexcept{
    // Replace code here
    return 0;
}

};