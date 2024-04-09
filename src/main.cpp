// Main function for the server.
// Created by Yu Houcheng on 4/7/24.

#include "Index.h"
#include "Hello.h"

#include <iostream>
using std::cout, std::endl, std::cerr;
#include <string>
using std::string;
#include <filesystem>

#include <sqlite3.h>

#include "crow/crow.h"
#include "inja/inja.hpp"

#include "globals.h"

int main() {
  crow::SimpleApp app;
  inja::Environment env;

  sqlite3 *db;
  std::filesystem::path dbPath(DATABASE_PATH);
  // Open database
  cout << "Opening database: " << dbPath << endl;
  if (sqlite3_open(dbPath.c_str(), &db)) {
    std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
    return 0;
  } else {
    std::cout << "Opened database successfully" << std::endl;
  }

  crow_app::setupIndexRoute(app, env);
  crow_app::setupHelloRoute(app, env);

  app.port(8000).multithreaded().run();

  sqlite3_close(db);
  cout << "Closed server and database." << endl;
  return 0;
}
