#include <iostream>
#include <string>
#include "../include/Enigma.hpp"



// Function 1: Convert uppercase letter or space to lowercase
char toLowercase(char c) {
    // Check if the character is an uppercase letter
    if (c >= 'A' && c <= 'Z') {
        return c - 'A' + 'a'; // Convert to lowercase
    } else if (c == ' ') {
        return c; // Return space unchanged
    } else {
        // Invalid input, return the input character itself
        // Or handle the error as needed
        return c;
    }
}

// Function 2: Convert lowercase letter to its alphabetical index (0-25)
int letterToIndex(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a'; // Get index (0-25)
    } else {
        // Invalid input, return -1 or handle the error as needed
        return -1;
    }
}

// Function to convert a number (0-25) to its corresponding lowercase letter
char indexToLetter(int index) {
    if (index >= 0 && index <= 25) {
        return 'a' + index; // Convert index to lowercase letter
    } else {
        // Invalid input, return an error character or handle the error as needed
        return '?'; // Example error character
    }
}


int main(int argc, char const *argv[])
{
    Enigma em{1,2,3,0,0,0,10,0};

    std::string str = "nst ryypui loujhkp at j vbkgat ctpuoiglrv cufhjy bttr zb obr dcjweuk.";
    std::string ans = "";
    
    std::cout << "\nEnigma:\n";
    std::cout << "Input  : " << str << "\n";

    for(int i=0; i < str.size(); ++i)
    {
        char c = str.at(i);
        if(c < 65 || c > 122)
        {
            ans += c;
        }
        else if(c >90 && c<97)
        {
            ans += c;
        }
        else
        {
            char c_small = toLowercase(c);
            int index = letterToIndex(c_small);
            int32_t a = em.getPermute(index);
            ans += indexToLetter(a);
        }
    }

    std::cout << "Encoded: " << ans << std::endl;
    
    return 0;
}
