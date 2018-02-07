# ethvis
Quick n' dirty Ethereum Virtual Machine simulator

Ethvis integration/staging tree
===============================

What is EVM?
------------
The EVM is the Turing-complete stack machine that runs Ethereum's powerful scripting language, allowing developers to make
decentralized apps (Dapps). The EVM takes in bytecode, instructions with 0-2 operands and 1 operator that push and pop bytes
onto a stack for computation.

For more information, visit the Ethereum Yellow Paper for a detailed breakdown of the EVM's implementation.

Ethvis: a quick n' dirty EVM Simulator
--------------------------------------
The goal of Ethvis is to create a light but powerful simulator to easily toy with the EVM. It does this through implementing 
an interpreter for OPCODE values and their instructions. Some differences between the Ethvis interpreter and EVM specifics:
    - Ethvis casts everything onto 32-bit unsigned int's (for now)
    - Ethvis cannot handle CALL (for now)
    - Ethvis has limited contract functionality (for now)
  
Development Process
-------------------
This project is open to anyone who likes C and enjoys developing in the blockchain space. 
