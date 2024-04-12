// Index.h
// Created by Yu Houcheng on 4/7/24.

#ifndef CPP_SERVER_INDEX_H
#define CPP_SERVER_INDEX_H

#pragma once

#include "crow.h"
#include "inja/inja.hpp"
#include "nlohmann/json.hpp"
#include "URLMap.h"

#include <sqlite3.h>

// Declare a function to set up the home page route
namespace crow_app {

void setupIndexRoute(crow::SimpleApp &app, inja::Environment &env, sqlite3 *db);

}

#endif //CPP_SERVER_INDEX_H
