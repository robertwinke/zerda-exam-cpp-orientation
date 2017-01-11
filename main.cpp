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



void decrypt (string inputFileName, string outputFileName, int shiftNum) {
  ifstream myFile(inputFileName.c_str());
  ofstream outputFile(outputFileName.c_str());
  string line;

  if (myFile.is_open()) {
    while(getline(myFile,line)) {
      for (unsigned int i = 0; i < line.length(); i++) {
        if(isalpha(line[i])) {
          if (line[i] > 64 && line[i] < 91) {
            if (line[i] + shiftNum < 65) {
              line[i] = 90 - (65 - (line[i] + shiftNum));
            }
            else if (line[i] + shiftNum > 90) {
              line[i] = 65 + (line[i] + shiftNum - 90);
            }
            else {
              line[i] = line[i] + shiftNum;
            }
          }
          if (line[i] > 96 && line[i] < 123) {
            if (line[i] + shiftNum < 97) {
              line[i] = 122 - (97 -(line[i] + shiftNum));
            }
            else if (line[i] + shiftNum > 122) {
              line[i] = 97 + (line[i] + shiftNum - 122);
            }
            else {
              line[i] = line[i] + shiftNum;
            }
          }
        }
      }
      outputFile << line << "\n";
    }
    outputFile << "\n";
  }
  myFile.close();
  outputFile.close();
}

int main(int argc, char *argv[]) {

  string inputFileName;
  string outputFileName;
  char* shift;
  int shiftNum;
  if (argc == 1) {
    cout << "No filename is provided.\n";
  }
  else if (argc < 4) {
    cout << "No shift is provided\n";
  }
  else if (argc == 4 && strcmp(argv[2], "-s") == 0) {
    inputFileName = (string)argv[1];
    shift = argv[3];
    shiftNum = atoi(shift);
    outputFileName = "output2.txt";
  }
  else if (argc == 6 && strcmp(argv[4], "-o") == 0) {
    inputFileName = (string)argv[1];
    shift = argv[3];
    shiftNum = atoi(shift);
    outputFileName = (string)argv[5];
  }


  decrypt(inputFileName, outputFileName, shiftNum);

  return 0;
}
