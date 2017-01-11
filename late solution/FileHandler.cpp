/*
 * FileHandler.cpp
 *
 *  Created on: Jan 11, 2017
 *      Author: robertwinke
 */


#include "FileHandler.h"

FileHandler::FileHandler(string fileName) throw (const char*) {
  myFile.open(fileName.c_str());
  if(!myFile.is_open()) {
    throw "couldn't open file\n";
  }
  buffer = copyTextFromFile();
}
string FileHandler::copyTextFromFile() {
  string line;
  string temp;
  while(getline(myFile, line)) {
    temp += line + "\n";
  }
  return temp;
}
string FileHandler::getText() {
  return buffer;
}
void FileHandler::saveTextToFile(string text, string destination) {
  ofstream outputFile(destination.c_str());
  for (unsigned int i = 0; i < text.length(); i++) {
    outputFile << text[i];
  }

  outputFile.close();
}

FileHandler::~FileHandler() {
  myFile.close();
}
