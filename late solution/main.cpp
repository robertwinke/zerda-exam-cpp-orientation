//============================================================================
// Name        : vizsga3otthon.cpp
// Author      : robertwinke
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "FileHandler.h"
#include "Decrypt.h"
#include "ArgHandler.h"

#include <iostream>
using namespace std;

int main(int argc, char** argv) {
  string inputFile;
  string outputFile;
  int shift;

  try {
    ArgHandler myArgHandler(argc, argv);

    inputFile = myArgHandler.getInputArg();
    outputFile = myArgHandler.getOutputArg();
    shift = myArgHandler.getShift() % 26;

    FileHandler myFileHandler(inputFile.c_str());

    Decrypt myDecrypter(myFileHandler.getText(), shift);

    if (outputFile == "") {
      cout << myDecrypter.getText();
    }
    else {
      myFileHandler.saveTextToFile(myDecrypter.getText(), outputFile);
    }
  }
  catch (const char* err) {
    cout << err;
  }

	return 0;
}

