/*
 * FileHandler.h
 *
 *  Created on: Jan 11, 2017
 *      Author: robertwinke
 */
#include <string>
#include <fstream>

using namespace std;

#ifndef FILEHANDLER_H_
#define FILEHANDLER_H_

class FileHandler {
private:
  ifstream myFile;
  string buffer;
public:

  FileHandler(string fileName) throw (const char*);
  string copyTextFromFile();
  string getText();
  void saveTextToFile(string text, string destination);
  ~FileHandler();
};



#endif /* FILEHANDLER_H_ */
