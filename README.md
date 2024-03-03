# Enigma-Machine
The Enigma machine is a famous encryption device used by the Germans, most notably during World War II, for securing military communications. The machine resembles a typewriter and operates by inputting letters through a keyboard, which are then encrypted based on the configuration of several rotors and a plugboard before being output as a different letter.<br/>
<br/>
This setup allowed for a vast number of possible settings, making the Enigma's encryption extremely difficult to break.

## Overview: Enigma Machine Implementation in C++

This project is a modern reinterpretation of the classic Enigma machine, adapted to run on modern computers. Unlike the original Enigma, which encrypted alphabetic characters, our version works by performing permutations on numbers corresponding to letters of the alphabet (0 for 'A', 1 for 'B', ..., 25 for 'Z'). This digital version of the Enigma machine is implemented in C++ and compiled using CMake, making it easily portable and scalable across different platforms.

### Key Features

- **Class-Based Representation:** Each component of the Enigma machine is represented as a class, encapsulating the functionality of rotors, the plugboard, and the reflector into modular, easy-to-understand code blocks.
  
- **Main Enigma Class:** The core of the implementation, the `Enigma` class, packages all individual components together, providing a unified interface for encryption and decryption operations.
  
- **Number-Based Permutations:** In a unique twist, our implementation uses number-based permutations for encryption, requiring users to convert letters to their corresponding numeric representations before encryption can occur. This approach provides an interesting perspective on the encryption process, emphasizing the mathematical underpinnings of the Enigma machine.

### Getting Started

To get started with this project, you'll need to have CMake and a C++ compiler installed on your system. Clone this repository to your local machine, navigate to the project directory, and follow the build instructions provided below to compile the project:

```bash
git clone <repository-url>
cd <repository-name>
mkdir build && cd build
cmake ..
make
````

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


