rm output.txt
g++ -std=c++11 "UVa_$1.cpp" -o 1
./1 <input.txt >output.txt
open output.txt