#ifndef ENIGMAAPP_HPP
#define ENIGMAAPP_HPP


#include "Enigma.hpp"
#include "Colors.hpp"
#include <ctime>
#include <iostream>

/**
 * Safer Enum class to habdle input states.
*/
enum class MenuOption {
    EncodeDecode = '1',
    ConfigSetting = '2',
    MachineStatus = '3',
    ClearScreen = '4',
    Exit = 27, // ESC key ASCII value
    InvalidInput = '0'
};

/**Enum Class to hold locations in the app (for the printing)*/
enum class AppLocations{
    Menu = 1,
    Encode = 2,
    EncodeBySequence = 3,
    EncodeBySingles = 4,
    MachineStat = 5,
    BadInput = 6
};


enum class EncodeOption{
    Single = 1,
    Sequence = 2,
    ReadFromFile = 3,
    Exit = 4,
    InvalidInput = 0
};

/**
 * Encapsulate the application state and behavior in class - EnigmaApp. 
 * This includes the Enigma machine instance, current user input, and flags like to_clear.
*/
class EnigmaApp
{

private:
    Enigma _em;
    bool to_clear {true};

    void encode();

    void encodeSingle();

    void encodeSequence();

    /* Convert uppercase letter or space to lowercase */
    char toLowercase(char c);

    /* Convert lowercase letter to its alphabetical index (0-25) */
    int32_t letterToIndex(char c);

    /*  Function to convert a number (0-25) to its corresponding lowercase letter */
    char indexToLetter(int32_t index);

    /** Function to handle the Enigma Machine */
    char useEnigma(char c);
    
    /* Clear the terminal screen */
    void clearScreen();

    /**Print out the machine current configuration*/
    void showMachineStatus();

    /*Showing all the first options*/
    void showMainMenu();
    
    /** Menu: Taking input (char) from user, and returns the prooper MenuOption*/
    MenuOption getMenuUserInput();

    /** Menu: Taking input (char) from user, and returns the prooper MenuOption*/
    EncodeOption getEncodeUserInput();
    
    void handleInvalidInput();

    /**return defined header to each print*/
    std::string getEnigmaSig(AppLocations location);
    
    void handleInput();
    void changeConfiguration();

public:
    EnigmaApp();
    ~EnigmaApp();
    void run();
};

#endif
