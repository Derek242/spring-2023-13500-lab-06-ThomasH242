#include <iostream>
#include <string>
#include <cctype>
#include "caeser.h"
#include "funcs.h"
#include "vigenere.h"
#include "decrypt.h"
int main()
{
  // std::cout << encryptCaesar("Way to Go!", 5) << std::endl;
  // std::cout << encryptCaesar("Hello, World!", 10) << std::endl;
  // std::cout << encryptVigenere("Hello, World!","cake") << std::endl;
  // std::cout << encryptVigenere("My name is Thomas!","fork") << std::endl;
  // std::cout << decryptCaesar("Bfd yt Lt!", 5)<< std::endl;
  // std::cout << decryptCaesar("Rovvy, Gybvn!", 10)<< std::endl;
  // std::cout << decryptVigenere("Jevpq, Wyvnd!","cake") << std::endl;
  // std::cout << decryptVigenere("Rm ekrs zc Yvfwfg!","fork") << std::endl;
  std::string testz = "ABCDefghIJklmnoPQRStuvwXY";
  std::string test0 = "Aopz pz qbza h alza."; // this is a test;
  std::string test1 = "Le tlt texq x qbpq";
  std::string test2 = "Rxewtgts pcs Strxewtgts";
  //std::cout << freq('a',test0);
  // std::vector<double> e = allf(test0);
  // for(int i =0; i <e.size();i++){
  //   std::cout << e[i] << " ";
  // }
  std::string solved = solve(test0);
  std::cout << solved << "\n";
  //std::cout << dist(allf(testz),allf(test0));
  return 0; 
}

