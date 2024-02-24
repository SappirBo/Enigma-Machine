#ifndef REFLECTOR_HPP
#define REFLECTOR_HPP

#include <iostream>
#include <vector>

class Reflector
{
private:
    std::vector<int32_t> _reflectVector;

public:
    Reflector();
    ~Reflector();
    
    int32_t reflect(int32_t input);

    friend std::ostream& operator<< (std::ostream& out, const Reflector& obj); 
};



#endif
