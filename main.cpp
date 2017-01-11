/*
 * main.cpp
 *
 *  Created on: Jan 11, 2017
 *      Author: robertwinke
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <stdlib.h>

using namespace std;

bool isNumber(char letter) {
  string digits = "0123456789";
  for (int i = 0; i < 10; i++) {
    if (digits[i] == letter) {
      return true;
    }
  }
  return false;
}


int main(int argc, char *argv[]) {

  string inputFileName;
  char* shift;

  if (argc == 1) {
    cout << "No filename is provided.\n";
  }
  else if (argc < 4) {
    cout << "No shift is provided\n";
  }
  else if (argc == 4 && strcmp(argv[2], "-s")) {
    inputFileName = (string)argv[1];
    shift = argv[3];
  }
  cout << inputFileName;

  ifstream myFile(inputFileName.c_str());


  ofstream outputFile("output2.txt");
  string line;


  int shiftNum = atoi(shift);


  if (myFile.is_open()) {
    while(getline(myFile,line)) {
      for (unsigned int i = 0; i < line.length(); i++) {
        if(line[i] != ' ' && !isNumber(line[i])) {
          line[i] = line[i] + shiftNum;
        }
      }
      outputFile << line << "\n";
    }
    outputFile << "\n";
  }
  myFile.close();
  outputFile.close();


  return 0;
}
