#include <iostream>
#include "include/Rotor.hpp"
#include "include/Reflector.hpp"



int main(int argc, char const *argv[])
{
    Rotor r(2,12,0);
    int32_t output{0};

    std::cout << "- - - 0 Turns: - - -" << std::endl;
    output = r.step(0);
    std::cout << r << std::endl;
    std::cout << "Step Output: " << output << "\n";

    std::cout << "- - - 1 Turns: (last + 1)- - -" << std::endl;
    output = r.step(1);
    std::cout << r << std::endl;
    std::cout << "Step Output: " << output << "\n";

    std::cout << "- - - 6 Turns: (last + 5)- - -" << std::endl;
    output = r.step(5);
    std::cout << r << std::endl;
    std::cout << "Step Output: " << output << "\n";

    std::cout << "- - - 26 Turns: (last + 20)- - -" << std::endl;
    output = r.step(20);
    std::cout << r << std::endl;
    std::cout << "Step Output: " << output << "\n";


    Reflector ref;

    std::cout << ref;

    for(int i=0; i < 26; i++)
    {
        std::cout << "TEST " << i <<"\n";
        int num = ref.reflect(i);
        std::cout << "ref.at("<<i<<") = "<< num<<"\n";
        std::cout << "ref.at("<<num<<") = "<< ref.reflect(num)<<"\n";

        std::cout << std::endl;
    }
    return 0;
}
