#include <iostream>
#include <string>
#include "include/Rotor.hpp"
#include "include/Reflector.hpp"
#include "include/Plugboard.hpp"



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


    Rotor r(2,12,0);
    Reflector ref;
    Plugboard pb{2};

    std::string str = "qxtxos luk xwvhjt ozsv";
    std::string ans = "";
    
    std::cout << "Hello, Lets Play a game ...\n";
    std::cout << "Input: " << str << "\n";

    for(int i=0; i < str.size(); ++i)
    {
        char c = str.at(i);
        if(c == ' ')
        {
            ans += " ";
        }
        else
        {
            char c_small = toLowercase(c);
            int index = letterToIndex(c_small);

            // std::cout << "Letter: " << c << ", Index:" << index << std::endl;

            int32_t a = r.permute(index,false);
            a = ref.reflect(a);
            a = r.permute(a,true);
            ans += indexToLetter(a);

            r.step(1);
        }
        

        // std::cout << "Letter: " << indexToLetter(a) << ", Index:" << a << std::endl;
    }

    std::cout << "Encoded: " << ans << std::endl;

    // std::cout << pb << std::endl;
    
    return 0;
}
