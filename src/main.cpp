#include <iostream>
using std::cout, std::endl, std::cerr;
#include <sqlite3.h>
#include <string>
using std::string;

#include "crow/crow.h"
#include "inja/inja.hpp"
#include "nlohmann/json.hpp"

#include "Index.h"
#include "URLMap.h"


int main()
{
    crow::SimpleApp app;
    inja::Environment env;

    sqlite3* db;
    int rc;

    // Open database
    rc = sqlite3_open("../var/database.sqlite3", &db);
    if (rc) {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
        return 0;
    } else {
        std::cout << "Opened database successfully" << std::endl;
    }

    crow_app::setupIndexRoute(app, env);

    app.port(8000).multithreaded().run();

    sqlite3_close(db);
    return 0;
}
