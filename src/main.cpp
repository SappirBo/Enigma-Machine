#include <iostream>
#include <string>
#include <ctime>
#include <sstream>
#include <fstream>
#include <filesystem>
#include "../include/Enigma.hpp"
#include "../include/EnigmaApp.hpp"

namespace strings{

    const std::string RED = "\033[31m";      // Red color
    const std::string GREEN = "\033[32m";    // Green color
    const std::string YELLOW = "\033[33m";   // Yellow color
    const std::string BLUE = "\033[34m";  // Blue color
    const std::string RESET = "\033[0m";     // Reset to default color

    std::string enigma{YELLOW + "Enigma:" + RESET};

    std::string root_instructions{enigma + "\n     1. Encode/Decode\n     2. Config Setting\n     3. Machine Status\n     4. Clear Screen\n     esc. Exit.\n"};
    std::string bad_input{enigma + RED +" Bad Input, follow the keywords\n" + RESET};
    std::string char_or_seq{enigma + "\n     1. One Letter At Time\n     2. Full Sequence\n     3. Read From File\n     4. Back\n"};
    std::string enter_full_seq{enigma + "\n     1. Enter Seq:\n     2. Back:\n     esc. Enter 'esc' to quit.\n"};
    std::string enter_one_char{enigma + "     - Add Char (Enter 'esc' to quit.)\n"};
    std::string not_working_yet{enigma + RED +" Not WORKING YET !!!!!\n" + RESET};
    std::string please_add_txt_path{enigma +" Please add path to the txt file:\n"};
    std::string path_entered{enigma +" Path you entered: "};
}

// Convert uppercase letter or space to lowercase
char toLowercase(char c) {
    // Check if the character is an uppercase letter
    if (c >= 'A' && c <= 'Z') {
        return c - 'A' + 'a'; // Convert to lowercase
    } else {
        return c;
    }
}

// Convert lowercase letter to its alphabetical index (0-25)
int32_t letterToIndex(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a'; // Get index (0-25)
    } else {
        // Invalid input, return -1
        return -1;
    }
}

// Function to convert a number (0-25) to its corresponding lowercase letter
char indexToLetter(int32_t index) {
    if (index >= 0 && index <= 25) {
        return 'a' + index; // Convert index to lowercase letter
    } else {
        // Invalid input, return an error character or handle the error as needed
        return ' '; 
    }
}

char useEnigma(Enigma &em, char c)
{
    if(c < 65 || c > 122)
    {
        return c;
    }
    else if(c >90 && c<97)
    {
        return c;
    }
    else
    {
        char c_small = toLowercase(c);
        int32_t index = letterToIndex(c_small);
        int32_t a = em.getPermute(index);
        return indexToLetter(a);
    }

    return ' ';
}

void main_loop()
{
    // as long as run equals 1 - the program will run
    int32_t run{1};
    Enigma em{};
    bool to_clear{true};
    
    while(run)
    {
        if(to_clear)
        {
            std::system("clear");
            to_clear = false;
        }

        char input{' '};
        std::string input_str{""};
        std::string output_str{""};

        // First input from the user
        std::cout << strings::root_instructions;
        std::cin >> input;


        while(input != '1' && input != '2' && input != '3' && input != '4' && input != 27)
        {
            std::cout << strings::bad_input;
            std::cout << strings::root_instructions;
            std::cin >> input;
        }

        // Exit - esc
        if(input == 27)
        {
            run = 0;
        }

        // Encode Decode mechanism
        if(input == '1')
        {
            
            std::cout << strings::char_or_seq;
            std::cin >> input;

            if(input == '1')
            {
                while(input != 27)
                {
                    std::cout << strings::enter_one_char;
                    std::cin >> input;
                    if(input != 27)
                    {
                        input_str  += input;
                        output_str += useEnigma(em, input);
                        std::cout <<"\nEnigma: input  - "<<input_str <<"\n        output - " <<output_str<<"\n";
                    }
                }
                input = '4';
            }
            else if (input == '2')
            {
                bool back_not_esc {false};
                bool break_full_seq_loop{false};
                while(!break_full_seq_loop)
                {
                    input == 27;
                    std::cout << strings::enter_full_seq;
                    std::cin >> input;
                    if(input == '1')
                    {
                        std::cin >> input;
                        std::string temp_str{""};
                        std::getline(std::cin, temp_str);

                        input_str = input + temp_str;
                        
                        for(size_t i = 0; i< input_str.size(); ++i)
                        {
                            output_str += useEnigma(em, input_str.at(i));
                        }
                        std::cout <<"\nEnigma: input  - "<<input_str <<"\n        output - " <<output_str<<"\n";

                        input_str.clear();
                        output_str.clear();
                    }
                    else if(input == '2')
                    {
                        break_full_seq_loop = true;
                        back_not_esc = true;
                    }
                    else{
                        break_full_seq_loop = true;
                    }
                }
                if(back_not_esc)
                {
                    input = '4';
                }

            }
            else if (input == '3')
            {
                std::cout << strings::not_working_yet;
                std::cout << strings::please_add_txt_path;

                std::cin >> input;
                std::string temp_str{""};
                std::getline(std::cin, temp_str);

                std::string path_to_data{input + temp_str};

                std::cout << strings::path_entered << path_to_data << std::endl;
                /**
                 * 
                 * 1. encode decode as a seq 
                 * 2. encode decode as data base: origin Enigma(origin) machine_config
                 * 
                 * All The Data will be written to enigma.txt
                */

                std::ifstream inputFile(path_to_data);
    
                if (!inputFile.is_open()) {
                    std::cerr << "Could not open the input file." << std::endl;
                    break;
                }

                // Extracting filename from path
                std::filesystem::path p{path_to_data};
                std::string filename = p.stem().string();

                // Getting the current date
                auto t = std::time(nullptr);
                auto tm = *std::localtime(&t);
                std::ostringstream oss;
                oss << std::put_time(&tm, "%Y-%m-%d");
                std::string currentDate = oss.str();

                std::filesystem::path outputPath = "/home/sappirb/code/Enigma-Machine/output";
                if (!std::filesystem::exists(outputPath)) {
                    std::filesystem::create_directories(outputPath);
                }

                // Construct the full path for the output file
                outputPath /= filename + "_" + currentDate + ".txt";

                std::ofstream outputFile(outputPath);
                if (!outputFile.is_open()) {
                    std::cerr << "Could not open the output file." << std::endl;
                    inputFile.close();
                    break;
                }

                // Processing each word
                std::string word;
                while (inputFile >> word) {
                    for(size_t i=0; i<word.size(); ++i)
                    {
                        char transformed_letter = useEnigma(em, word.at(i));
                        outputFile << transformed_letter ;
                    }
                    outputFile << " ";
                }

                inputFile.close();
                outputFile.close();
                

            }
            if(input != '1' && input != '2' && input != '3'  && input != '4')
            {
                input = '5';
                //Clean Cin:
                std::getline(std::cin, input_str);
                input_str.clear();
            }
        }

        // Chage Configuration
        else if(input == '2')
        {
            std::cout << em << std::endl;
        }

        // Machine Status
        else if(input == '3')
        {
            std::system("clear");
            std::cout << em << std::endl;
        }

        // Clear Screen
        else if(input == '4')
        {
            to_clear = true;
        }
    }

}

int32_t main(int32_t argc, char const *argv[])
{   
    EnigmaApp enigma_app;

    enigma_app.run();
    
    return 0;
}


