#ifndef ROTORDATA_HPP
#define ROTORDATA_HPP

#include <iostream>
#include <vector>

class RotorData
{
private:
    std::vector<int32_t> base;
    std::vector<int32_t> r1;
    std::vector<int32_t> r2;
    std::vector<int32_t> r3;
    std::vector<int32_t> r4;
    std::vector<int32_t> r5;
public:
    RotorData();
    ~RotorData();

    std::vector<int32_t> getRotorData (int32_t code);
};

#endif