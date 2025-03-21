# Monte Carlo Option Pricer

## Overview
This project implements a Monte Carlo simulation for pricing European options (calls and puts). The code uses object-oriented design to separate the option types and pricing mechanism.

## Components
- **Option**: Base class for different option types
- **EuropeanCall**: Class for European call options
- **EuropeanPut**: Class for European put options
- **MCPricer**: Monte Carlo pricing engine

## Main Program
The main program demonstrates pricing European call and put options with various simulation sizes:
- 10,000 simulations
- 100,000 simulations
- 1,000,000 simulations


## Usage
Compile and run the program to see price estimates for European call and put options with the parameters above. The program will calculate prices using increasingly accurate Monte Carlo simulations.

## Dependencies
- C++ standard library
- Custom headers for options and pricing (Option.h, EuropeanCall.h, EuropeanPut.h, MCPricer.h)

## Implementation Notes
The implementation follows object-oriented principles with inheritance for different option types. The Monte Carlo pricer is designed to work with any option type that inherits from the base Option class.

## Bug Fix Note
There appears to be an empty loop in the original code:
```cpp
for (int j = 0; j < M[i]; j++) {}
```
This loop doesn't perform any operations and may need to be removed or implemented properly depending on the intended functionality.
