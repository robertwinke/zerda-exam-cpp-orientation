/*
 * Decrypt.cpp
 *
 *  Created on: Jan 11, 2017
 *      Author: robertwinke
 */


#include "Decrypt.h"

Decrypt::Decrypt(string textToDecrypt, int shift): shift(shift) {
  int charCode;
  decryptedText = "";
  for (unsigned int i = 0; i < textToDecrypt.length(); i++) {
    if(isalpha(textToDecrypt[i])) {
      charCode = textToDecrypt[i] + shift;
      if (textToDecrypt[i] >= 'A' && textToDecrypt[i] <= 'Z') {
        if (charCode < 'A') {
          decryptedText += ('Z' - ('A' - charCode) + 1);
        }
        else if (charCode > 'Z') {
          decryptedText += ('A' + (charCode - 'Z') - 1);
        }
        else {
          decryptedText += charCode;
        }
      }
      else if (textToDecrypt[i] >= 'a' && textToDecrypt[i] <= 'z') {
        if (charCode < 'a') {
          decryptedText += ('z' - ('a' - charCode) + 1);
        }
        else if (charCode > 'z') {
          decryptedText += ('a' + (charCode - 'z') - 1);
        }
        else {
          decryptedText += charCode;
        }
      }
    }
    else {
      decryptedText += textToDecrypt[i];
    }
  }
}
string Decrypt::getText() {
  return decryptedText;
}
