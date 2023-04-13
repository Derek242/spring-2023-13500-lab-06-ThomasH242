#include <iostream>
#include <vector>
std::string decryptCaesar(std::string ciphertext, int rshift);
std::string decryptVigenere(std::string ciphertext, std::string keyword);
double freq(char l, std::string s);
std::vector<double> allf(std::string s);
double dist(std::vector<double> list);
std::string solve(std::string encrypted_string);