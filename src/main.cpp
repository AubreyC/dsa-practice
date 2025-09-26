

#include <chrono>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <thread>
#include <unistd.h>
#include <vector>

#include "dsa_practice.hpp"

using namespace std;

int main(int argc, char *argv[])
{
  const char *daz = "this is a sentence";

  size_t idx = 0;
  while (daz[idx] != '\0')
  {
    std::cout << daz[idx];
    idx++;
  }
  std::cout << "" << std::endl;
}
