// arguments.h
// Created by Yu Houcheng on 4/20/24.

#ifndef CPP_SERVER_INCLUDE_ARGUMENTS_H_
#define CPP_SERVER_INCLUDE_ARGUMENTS_H_

#include <vector>
#include <iostream>
#include <string>
#include <cstdint>
#include <cstring>
#include "getopt.h"

using std::cout, std::string, std::cerr, std::vector;

enum class Mode {
  NONE, MST, FASTTSP, OPTTSP
};

struct Options {
  Mode mode = Mode::NONE;
  string host = "localhost";
  int port = 8000;
};  // Options{}

void printHelp() {
  cout << "Usage: ./Server [options]\n"
       << "--help             Show help message\n"
       << "--mode MODE        Set the program mode (MST, FASTTSP, OPTTSP)\n"
       << "--host HOST        Specify the host\n"
       << "--port PORT        Specify the port number\n";
}

void getMode(int argc, char *argv[], Options &options) {
  opterr = false; // Let us handle all error output for command line options
  int choice;
  int index = 0;
  option long_options[] = {
      {"mode", optional_argument, nullptr, 'm'},
      {"help", no_argument, nullptr, 'h'},
      {"host", optional_argument, nullptr, 'H'},
      {"port", optional_argument, nullptr, 'P'},
      {nullptr, 0, nullptr, '\0'},
  };  // long_options[]

  while ((choice = getopt_long(argc, argv, "m:H::P::", long_options, &index)) != -1) {
    switch (choice) {
      case 'h': {
        printHelp();
        exit(0);
      }
      case 'm': {
        break;
      }  // case 'm'
      case 'H': {
        if (optarg) options.host = optarg;
        break;
      }
      case 'P': {
        if (optarg) options.port = std::stoi(optarg);
        break;
      }
      default:cerr << "Error: invalid option!" << std::endl;
        exit(1);
    }  // switch ..choice
  }  // while
}

#endif //CPP_SERVER_INCLUDE_ARGUMENTS_H_
