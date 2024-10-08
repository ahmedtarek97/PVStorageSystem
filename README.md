# PV Storage System
a simulation for a PV storage system and applying energy mangment algorithm

### Dependencies
Dependancies of this project are:
* g++
* cmake
* gtest [for testing]
* doxgen [for documintaion]

### Building
* Use the command `./build.sh` to build the c++ development and testing files also the script will generate doxgen documintation 
* Use the command `./test.sh` to run the provided test cases

## File Structure

- **Project Root** (This is the main project folder)
  - **build** : This folder is used by `build.sh` script to generate files during compilation
  - **docs**: This folder includes  generated doxgen documentation for the prject
    - **index.html**: The most relevant file in the folder it contains the documintation in html format
  - **include** This folder contains the header files of the used classes
  - **src**: This folder contains the implementation files of the used classes
  - **test** This folder the unit test files for some classes

## Future Work:
  - Imporove Unit test coverage as not all classes are covered
  - Rechecking the design and avoid violating the dependancy inversion design principle
  - Add Error handling and use the unsed values(for example: checking if a PV and a house have the same frequancy and voltage)
  - Add Error handling in `build.sh` and `test.sh` scripts
  - Integrate real-world data or simulate dynamic changes in PV production and house consumption over time.

