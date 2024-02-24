#include "../include/Rotor.hpp"
#include "../include/RotorData.hpp"

Rotor::Rotor()
{
    this->_data = RotorData();
    this->_inputRing = this->_data.getRotorData(0);
    this->_outputRotor = this->_data.getRotorData(1);

    this->_ringTurn = 25;
    this->_current = 0;
}

Rotor::Rotor(int32_t rotorNum, int32_t startPoint, int32_t turn)
{
    this->_data = RotorData();
    this->_inputRing = this->_data.getRotorData(0);
    this->_outputRotor = this->_data.getRotorData(rotorNum);

    this->_ringTurn = turn;
    this->_current = startPoint;
}

Rotor::~Rotor()
{
}

int32_t Rotor::step(int32_t turns)
{
    int32_t ans(0);
    while (turns > 0)
    {
        ans = this->oneStep();
        turns -= 1;
    }
    return ans;
}

int32_t Rotor::oneStep()
{
    int32_t lastElement = 25;
    int32_t firstElement = 0;

    int32_t turn = 0;
    int32_t prevNum = 0;
    int32_t newNum = 0;
    newNum =  this->_inputRing.at(lastElement);

    while(turn < 26)
    {
        prevNum = this->_inputRing.at(turn);
        this->_inputRing.at(turn) = newNum;
        newNum = prevNum;
        
        turn++;
    }
    return this->_inputRing.at(firstElement);
}






std::ostream& operator<< (std::ostream& out, const Rotor& obj)
{
    int32_t ring_size = obj._inputRing.size();
    out << "Rotor" << ":\n" ;
    out << "Input ring : {";
    for(int32_t i=0; i < ring_size; ++i){
        out << obj._inputRing.at(i);
        if(i != ring_size-1)
        {
            out <<", ";
        }
    }
    out << "}\n";

    out << "Output ring: {";
    for(int32_t i=0; i < ring_size; ++i){
        out << obj._outputRotor.at(i);
        if(i != ring_size-1)
        {
            out <<", ";
        }
    }
    out << "}\n";
    return out;

}





