# Enigma-Machine
The Enigma machine is a famous encryption device used by the Germans, most notably during World War II, for securing military communications. The machine resembles a typewriter and operates by inputting letters through a keyboard, which are then encrypted based on the configuration of several rotors and a plugboard before being output as a different letter.<br/>
<br/>
This setup allowed for a vast number of possible settings, making the Enigma's encryption extremely difficult to break.
## Overview

## How it works?

* **Rotors:** Each Rotor have 26 inputs and outputs (for each letter), each input letter is connected to a output letter (for example: A->D, F->Z). 
  * **Rotor mechanism:** Each time key is pressed at least one rotor will turn (at most three), that means that for two presses on the same letter might extract two  different letters (!). Rotor 1 will move in each press and when it compelete a full spin - Rotor 2 will do one turn (the same for rotors 2 and 3). So we have Rotor 1 as the fast rotor, Rotor 2 as mid rotor and Rotor 3 as slow rotor. 
    
* **Reflector:** The reflector has 26 inputs, that connected as 13 pairs. when the reflector get a signal in some input, it reflects it's pair as an output (for example: A->F, F->A)   
* **Plugboard:** The plugboard takes a letter and might connect it to a other letter (as pair) but it can be stay as is. So the power of the plugboard that it can have at most 13 pairs (325 options) but also it can have 0 pairs - and all the options that are between. (for example: F->A, A->F, D->D, R->R, T->P, P->T,...)
* **Machine Settings:** The power of the Enigma machine is the large number of configurations it has. first when you start writing words into this machine you need to write down the configuration of the machine, send your message, and then the reciver should have the same configuration in order to decode the message you sent. The machine had some elements that you should concider when configing:
  * Rotor Order -  you need to choose 3 out of 5 rotors and you need to choose thier order (for example: 1. I,IV,II 2. II,III,I).
  * Ring setting - choose the start point for each Rotor (for example: 1.A, 2.T, 3.W).
  * Plugboard connections - configure the plugboard as you want.

## Combination
1. Rotors: 5 * 4 * 3 = 60.
2. Starting: 26^3 = 17,576.
3. Plugboard: 26! / (6! * 10! * 2^10) = 150,738,274,237,937,250.
4. Total: 158,962,555,217,826,360,000.

Means that there are more then **158 Quintillion** ways to set up the Enigma Machine!

## Sources
* [Enigma Machine](https://en.wikipedia.org/wiki/Enigma_machine)
* [How did the Enigma Machine work?](https://www.youtube.com/watch?v=ybkkiGtJmkM&ab_channel=JaredOwen)
* [(Enigma Machine) - Numberphile](https://www.youtube.com/watch?v=G2_Q9FoD-oQ&t=20s&ab_channel=Numberphile)


