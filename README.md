# ethvis
Quick n' dirty Ethereum Virtual Machine simulator

Ethvis integration/staging tree
===============================

What is EVM?
------------
The EVM is the Turing-complete stack machine that runs Ethereum's powerful scripting language, allowing developers to make
decentralized apps (Dapps). The EVM takes in bytecode, instructions with 0-2 operands and 1 operator that push and pop bytes
onto a stack for computation.

For more information, visit the [Ethereum Yellow Paper](https://ethereum.github.io/yellowpaper/paper.pdf) for a detailed breakdown of the EVM's implementation.

Ethvis: a quick n' dirty EVM Simulator
--------------------------------------
The goal of Ethvis is to create a light but powerful simulator to easily toy with the EVM. It does this through implementing 
an interpreter for OPCODE values and their functionality. Some differences between the Ethvis interpreter and EVM specifics:
    * Ethvis casts everything onto 32-bit unsigned int's -- DIRTY (for now)
    * Ethvis cannot handle CALL -- DIRTY (for now)
    * Ethvis has limited contract functionality -- DIRTY (for now)
    * Ethvis is written in ANSI C (2008) -- QUICK

There will be two available modes, each using the core interpreter: (1) a complete pre-configured machine with file parsing features, and (2) a more configurable interactive execution environment that stores console input.

For a complete listing of all the opcodes to be used, reference [this](https://ethereum.stackexchange.com/questions/119/what-opcodes-are-available-for-the-ethereum-evm) Stack Overflow post.
    
Development Process
-------------------
This project is open to anyone who likes C and enjoys developing in the blockchain space. 

Much of the control structure has been implemented, and therefore a major priority (as of February 6, 2018) is to implement all opcodes, and conversely make good tests.
