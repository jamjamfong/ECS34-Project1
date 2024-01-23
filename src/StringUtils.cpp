#include "StringUtils.h"

namespace StringUtils{

std::string Slice(const std::string &str, ssize_t start, ssize_t end = 0) noexcept {
  // Handle negative indices
  if (start < 0) {
    start += str.length();
  }
  if (end < 0) {
    end += str.length();
  }

  // Clamp indices within string bounds
  start = std::max(0L, std::min(start, static_cast<ssize_t>(str.length())));
  end = std::max(0L, std::min(end, static_cast<ssize_t>(str.length())));

  // Ensure start is before end
  if (start > end) {
    return "";
  }

  // Recalculate length based on adjusted indices
  ssize_t length = end - start;  // Adjust calculation

  // Extract the sliced substring
  return str.substr(start, length);
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
    
    //
    size_t firstNonWhitespace =str.find_first_not_of(" \t\n\r\f\v");

    //
    if(firstNonWhitespace == std::string::npos){
        return "";
    }

    return str.substr(firstNonWhitespace);
}

std::string RStrip(const std::string &str) noexcept{

    size_t lastNonWhitespace = str.find_last_not_of(" \t\n\r\f\v");

    if(lastNonWhitespace == std::string::npos){
        return "";
    }

    return str.substr(0, lastNonWhitespace + 1);
}

std::string Strip(const std::string &str) noexcept{
    

    size_t firstNonWhitespace = str.find_first_not_of(" \t\n\r\f\v");
    size_t lastNonWhitespace = str.find_last_not_of(" \t\n\r\f\v");

      // Handle cases where the string is empty or only contains whitespace
    if (firstNonWhitespace == std::string::npos || lastNonWhitespace == std::string::npos) {
        return "";
    }

    // Extract the substring between the first and last non-whitespace characters
    return str.substr(firstNonWhitespace, lastNonWhitespace - firstNonWhitespace + 1);

}

std::string Center(const std::string &str, int width, char fill) noexcept{
    
    int space = std::max(0, width - static_cast<int>(str.length()));

    int leftSpace = space / 2;

    int rightSpace = space - leftSpace;

    return std::string(leftSpace, fill) + str + std::string(rightSpace, fill);
}

std::string LJust(const std::string &str, int width, char fill) noexcept{
    
    // Handle empty string case
    if (str.empty()) {
        return "";
    }

    // Calculate padding accurately, considering string length
    int space = std::max(0, width - static_cast<int>(str.length()));

    // Create padding string with the correct fill character
    std::string padding(space, (fill == '\0') ? ' ' : fill);

    // Prefix padding for left-justification
    return padding + str;
}
std::string RJust(const std::string &str, int width, char fill) noexcept{
 int space = std::max(0, width - static_cast<int>(str.length()));
    return std::string(space, fill) + str;
}

std::string Replace(const std::string &str, const std::string &old, const std::string &rep) noexcept{
    
    std::string result = str;

    size_t pos = 0;
    while ((pos = result.find(old,pos)) != std::string::npos){
        result.replace(pos,old.length(),rep);
        pos += rep.length();
    }
    return result;
}

std::vector< std::string > Split(const std::string &str, const std::string &splt) noexcept{
    
    std::vector<std::string>result;

    if(splt.empty()){
        size_t start = 0;
        size_t end = str.find_first_of(" \t\n\r\f\v");
        while (start < str.length()) {
            if (end == std::string::npos) {
                end = str.length();
            }
            result.push_back(str.substr(start, end - start));
            start = str.find_first_not_of(" \t\n\r\f\v", end);
            end = str.find_first_of(" \t\n\r\f\v", start);
        }
    } else {

        size_t start = 0;
        size_t end = str.find(splt);
        while (end != std::string::npos) {
            result.push_back(str.substr(start, end - start));
            start = end + splt.length();
            end = str.find(splt, start);
        }
        result.push_back(str.substr(start));
    }

    return result;
}

std::string Join(const std::string &str, const std::vector< std::string > &vect) noexcept{
    std::string result;

    for (size_t i = 0; i < vect.size(); ++i) {
        result += vect[i];

        if (i < vect.size() - 1) {
            result += str;  // Add the separator after each element except the last one
        }
    }

    return result;
}

std::string ExpandTabs(const std::string &str, int tabsize) noexcept{
    std::string result;
    size_t column = 0;

    for (char ch : str) {
        if (ch == '\t') {
            // Replace tab with spaces up to the next tab stop
            int spacesToAdd = tabsize - (column % tabsize);
            result += std::string(spacesToAdd, ' ');
            column += spacesToAdd;
        } else {
            result += ch;
            // Increment column for non-tab characters
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