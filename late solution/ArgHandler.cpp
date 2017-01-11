/*
 * ArgHandler.cpp
 *
 *  Created on: Jan 11, 2017
 *      Author: robertwinke
 */

#include "ArgHandler.h"

ArgHandler::ArgHandler(int argc, char** argv)throw(const char *): argc(argc), argv(argv){
  outputFileName = "";
  switch(argc) {
  case 1:
    throw "No filename is provided\n";
    break;
  case 2:
    throw "No shift is provided\n";
    break;
  case 3:
    throw "No shift is provided\n";
    break;
  case 4:
    inputFileName = (string)argv[1];
    shift = atoi(argv[3]);
    if (inputFileName.substr(inputFileName.length() - 4) != ".txt") {
      throw "Invalid pathname\n";
    }
    else if(strcmp(argv[2], "-s") != 0) {
      throw "Invalid argument\n";
    }
    break;
  case 5:
    throw "No output file provided\n";
    break;
  case 6:
    if (strcmp(argv[2], "-s") == 0 && strcmp(argv[4], "-o") == 0) {
      inputFileName = (string)argv[1];
      shift = atoi(argv[3]);
      outputFileName = (string)argv[5];
    }
    else if((strcmp(argv[2], "-o") == 0 && strcmp(argv[4], "-s") == 0)) {
      inputFileName = (string)argv[1];
      shift = atoi(argv[5]);
      outputFileName = (string)argv[3];
    }
    else {
      throw "Messed up arguments\n";
    }
    break;
  }
}
int ArgHandler::getShift() {
  return shift;
}
string ArgHandler::getInputArg() {
  return inputFileName;
}
string ArgHandler::getOutputArg() {
  return outputFileName;
}
