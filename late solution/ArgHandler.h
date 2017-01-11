/*
 * ArgHandler.h
 *
 *  Created on: Jan 11, 2017
 *      Author: robertwinke
 */

#include <string>
#include <cstring>
#include <stdlib.h>
using namespace std;

#ifndef ARGHANDLER_H_
#define ARGHANDLER_H_

class ArgHandler {
  int argc;
  char** argv;
  string inputFileName;
  string outputFileName;
  int shift;

public:
  ArgHandler(int argc, char** argv) throw(const char *);
  int getShift();
  string getInputArg();
  string getOutputArg();
};



#endif /* ARGHANDLER_H_ */
