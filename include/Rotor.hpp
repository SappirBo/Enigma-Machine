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
public:
    Rotor(int32_t rotorNum, int32_t startPoint, int32_t turn);
    ~Rotor();
};

