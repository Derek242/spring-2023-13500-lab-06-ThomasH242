#include <iostream>
#include <string>
#include <cctype>
#include "caeser.h"
#include "vigenere.h"
#include <vector>
#include <cmath>
std::string decryptCaesar(std::string ciphertext, int rshift){
    return encryptCaesar(ciphertext,26-rshift);
}
std::string decryptVigenere(std::string ciphertext, std::string keyword){
    for(int i=0; i<keyword.length(); i++){
        keyword[i] = 122 - (keyword[i]-97)+1;
    }
    return encryptVigenere(ciphertext,keyword);
}   
/*
freq a letter
*/
double freq(char l, std::string s){
    std::string news;
    for(int j =0; j < s.length();j++){
        news += tolower(s[j]);
    }
    double count = 0.0;
    for(int i = 0 ; i < s.length();i++){
        if (news[i] == l){
            count++;
        }
    }
    count = count/news.length();
    return count;
}
/* 
Make a 26 space vector with the frequencies of all the letters based on encrypted_string. Note
     that entries will be 0 for letters that don’t appear in the input string. Calculate the distance
    between this vector and the vector of letter frequencies for English. The rotation with the
    smallest distance should be the solution.
*/
std::vector<double> allf(std::string s){
    std::string newstring;
    for(int j = 0;j < s.length();j++){
        newstring += tolower(s[j]);
    }

    std::vector<double> list;
    for(int i =97; i<=122 ;i++){
        if(newstring.find(i) < 0){
            list.push_back(0.0);
        }
        else{
            list.push_back(freq(i,newstring));
        }
    }
    return list;
}
//A function to calculate the distance using the distance formula between 2 arrays of 26 elements.
double dist(std::vector<double> list,std::vector<double> list2){
    double distance;
    for(int i =0; i < 26;i++){  
        distance += pow((list[i] - list2[i]),2.0);
    }
    return sqrt(distance);//important
}
std::string solve(std::string encrypted_string){
    //Common Letters for English
    std::vector<double> cle = {8.2, 1.5, 2.8, 4.3, 13, 2.2, 2, 6.1, 7, 0.15, 0.77, 4, 2.4, 6.7, 7.5, 1.9, 0.095, 6, 6.3, 9.1, 2.8, 0.98, 2.4, 0.15, 2, 0.074};
    std::vector<double> list;
    //decrypted strings
    std::string dstring;
    std::string newdstring;
    //distance  between cle and the frequencies of the dstring
    double currdist;
    double mindist = 1000.0;
    int shift;
    //
    for(int i=0;i<26;i++){

        dstring = encryptCaesar(encrypted_string,i);
        list = allf(dstring);
        currdist = dist(cle,list);
        if(currdist < mindist){
            newdstring = dstring;
            mindist = currdist;
        }
    }
    return newdstring;
}