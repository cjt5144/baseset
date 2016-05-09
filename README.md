# Number Base Conversion

## Overview

The class provides methods to convert a number of baseX to a number of baseY using the 
Baseset class.

The ct namespace provides...
* integer to character conversion.
* character to integer conversion.
* the number of digits in a number of a given base.
* the Baseset class.

The Baseset class provides...
* string representation for a number of a given base.
* reverse string representation for a number of a given base.
* iterator and const\_iterator types.
* reverse\_iterator and const\_reverse\_iterator types.
* modifiable access to individual digits for non-const Baseset objects.
* comparison operators to compare to Baseset objects.

## Examples

## Compile Shared Object

Compile shared object in shell using `g++ -std=c++11 -o baseset.o -c baseset.cpp`.

## Test

Test written in basesettest.cpp.

Compile baseset library and run test in shell using `g++ -std=c++11 basesettest.cpp baseset.cpp -o test`.

Run Test with `./test`.

## License

This work is licensed under The MIT License. See LICENSE file for more details.
