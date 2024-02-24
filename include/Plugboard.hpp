#ifndef PLUGBOARD_HPP
#define PLUGBOARD_HPP

#include <iostream>
#include <vector>

class Plugboard
{
private:
    std::vector<int32_t> _plugVec;

public:
    Plugboard();
    Plugboard(size_t code);
    Plugboard(std::vector<int32_t> config);
    ~Plugboard();
    
    int32_t getPlug(int32_t input);

    friend std::ostream& operator<< (std::ostream& out, const Plugboard& obj); 
};



#endif
