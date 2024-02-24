#ifndef ROTOR_HPP
#define ROTOR_HPP

#include <iostream>
#include <vector>

#include "RotorData.hpp"

class Rotor
{
private:
    std::vector<int32_t> _inputRing;
    std::vector<int32_t> _outputRotor;
    int32_t _current;
    int32_t _ringTurn;
    RotorData _data;
public:
    Rotor();
    Rotor(int32_t rotorNum, int32_t startPoint, int32_t turn);
    ~Rotor();

    /**
     * Take the input rotor one step up
     * output: the current input.at(0) => start point
    */
    int32_t step(int32_t turns);

    /**
     * taking input in - return its permute. 
     * if False - from input ring to rotor ring
     * if True  - from rotor ring to input ring  
    */
    int32_t permute(int32_t input, bool in_out);
    
    friend std::ostream& operator<< (std::ostream& out, const Rotor& obj); 

private:
    int32_t oneStep();
    int32_t getIndex(int32_t intput, const std::vector<int32_t> vec);
};



#endif