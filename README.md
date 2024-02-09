# Homework-02: Scientific Computing Toolbox
This is the project for Homework-02 of the Advanced Programming course.

## Modules
We chose to implement Module A and Module C.

## Build and Run
The build.sh files expect to find libraries boost and muparserx inside /urs/local.
To build each module's example, run the corresponding build.sh and then run the program with ./main

## Group
Our group consists of Camilla Giaccari (camillagiaccari97@gmail.com) and Lorenzo Giaccari (lorenzo.giaccari99@gmail.com).
We worked on the same machine with a pair programming approach, frequently swapping between who was writing and who was checking the code.

## Code organization
- SCToolbox/
    - Statistics/ (module A)
        - csv/
            - df_surf.csv
        - src/
            - main.cpp (contains some tests)
            - statistics.cpp
        - include/
            - fifo_map.hpp (header-only library)
            - statistics.hpp
        - build.sh
    - Numerical_integration/ (module C)
        - src/
            - main.cpp (contains some tests)
            - approximator.cpp (abstract base class)
            - midpoint_approximator.cpp
            - trapezoidal_approximator.cpp
            - simpson_approximator.cpp
        - include/
            - approximator.hpp (abstract base class)
            - midpoint_approximator.hpp
            - trapezoidal_approximator.hpp
            - simpson_approximator.hpp
        - build.sh
    - README.md

## Design choices
We decided to organize each module in its own directory, but they both share the same namespace 'sctoolbox'.  
All functionalities of Module A are inside a single class, with declaration and definition of the methods separated in two different files. Module C is organized into three different classes, each one implementing a different rule and deriving from the same abstract class. Declaration and definition of the methods are separated in two different files here too.  
### Module A:
The user can provide the Statistics constructor with valid paths to an input csv file and an output file or use the default ones. If it doesn't exist, the output file is created automatically at the first printing. The csv file is expected to have the name of the columns as the first row.  
Each function of statistics has two versions, one that returns the result (es. 'mean') and one that puts this result into the specified output file (es. 'write_mean').  
We implemented controls on the provided column name and on the type expected for the elements, throwing exceptions in case something is wrong. Missing values are identified as the empty string "" and so the methods handle them as needed, without throwing exceptions.  
We tested our application using the df_surf.csv file from https://www.kaggle.com/datasets/loureiro85/surfing/.
### Module C:
The methods work with any valid mathematical expression, and will throw an exception on non-valid ones.  
We heavily used the functionalities provided by the muParserX library.  
The user will call the approximate() method from the base class, and its implementation will change at runtime depending on the constructed deriving class. These classes provide the overridden method approximate_step() as private, since we don't expect the user to call it.  
The main file provides a way to calculate an integral provided by the user; when run using "./main demo", it prints a little demo with some pre-written examples.

## Libraries
Boost, muParserX and fifo-map libraries are used in this project.  
We had to use three different approaches when building and linking them, which was a bit time-consuming, but not excessively difficult. Boost required a single make command, fifo-map, as a header only library, just needed to be included in the project, and muParserX had to be built and installed using cmake.  

## Links
- the header only library fifo-map can be found at https://github.com/nlohmann/fifo_map.
- we found an useful check for double at https://stackoverflow.com/questions/29169153/how-do-i-verify-a-string-is-valid-double-even-if-it-has-a-point-in-it.
- we used the method 'visit' to print a variant as found at https://stackoverflow.com/questions/62707343/how-can-i-print-map-key-value-with-stdvariant.
- we skip missing elements in the correlation evaluation, as described in the "Complete Case Analysis" at https://dept.stat.lsa.umich.edu/~kshedden/Python-Workshop/correlation_missing_data.html#complete-case-analysis
- we found a way to assure user inputs as double at https://stackoverflow.com/questions/3273993/how-do-i-validate-user-input-as-a-double-in-c.

## Licenses
### Boost:  
Boost Software License - Version 1.0 - August 17th, 2003  
Permission is hereby granted, free of charge, to any person or organization
obtaining a copy of the software and accompanying documentation covered by
this license (the "Software") to use, reproduce, display, distribute,
execute, and transmit the Software, and to prepare derivative works of the
Software, and to permit third-parties to whom the Software is furnished to
do so, all subject to the following:  
The copyright notices in the Software and this entire statement, including
the above license grant, this restriction and the following disclaimer,
must be included in all copies of the Software, in whole or in part, and
all derivative works of the Software, unless such copies or derivative
works are solely in the form of machine-executable object code generated by
a source language processor.  
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.  
### muParserX:  
BSD 2-Clause License  
Copyright (c) 2023, Ingo Berg  
All rights reserved.  
Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:  
1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.  
2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  
### fifo-map:  
MIT License  
Copyright (c) 2015-2017 Niels Lohmann  
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:  
The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.  
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE. 
