#include <iostream>
#include <string>
#include <cctype>
// A helper function to shift one character by rshift
char shiftChar(char c, int rshift){
    if((c >= 97 and c <= 122)) 
        if(c + rshift < 123){ 
        return c + rshift;
    }
    else if(c + rshift > 122){
        return c + rshift- 122 + 96; 
    }
    else{
        return c;
    }
    if(c >= 65 and c <= 90)
        if(c + rshift <= 90){
            return c+rshift;
    }
    else if(c + rshift >= 89){
            return c+ rshift - 90 + 64;
        }
    else{
        return c;
    }
}

// Caesar cipher encryption
std::string encryptCaesar(std::string plaintext, int rshift){ 
    for(int i = 0;i< plaintext.length();i++){
        plaintext[i] = shiftChar((int)plaintext[i],rshift);
    }
    return plaintext;
}