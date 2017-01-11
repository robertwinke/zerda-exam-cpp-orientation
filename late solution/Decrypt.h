/*
 * Decrypt.h
 *
 *  Created on: Jan 11, 2017
 *      Author: robertwinke
 */
#include <string>
#include <stdlib.h>
using namespace std;

#ifndef DECRYPT_H_
#define DECRYPT_H_


class Decrypt {
private:
  string decryptedText;
  int shift;
public:
  Decrypt(string textToDecrypt, int shift);
  string getText();
};


#endif /* DECRYPT_H_ */
