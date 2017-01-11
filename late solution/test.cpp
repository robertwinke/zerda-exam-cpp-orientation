/*
 * test.cpp
 *
 *  Created on: Jan 11, 2017
 *      Author: robertwinke
 */


#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "FileHandler.h"
#include <iostream>

using namespace std;

TEST_CASE( "get text from file") {

FileHandler myFileHandler("alma.txt");
REQUIRE(myFileHandler.getText() == "alma");

}
