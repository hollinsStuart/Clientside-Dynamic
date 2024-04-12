// Users.h
// Created by Yu Houcheng on 4/11/24.

#ifndef CPP_SERVER_INCLUDE_USERS_H_
#define CPP_SERVER_INCLUDE_USERS_H_

#include "crow.h"
#include "inja/inja.hpp"
#include "nlohmann/json.hpp"
#include "URLMap.h"

#include <sqlite3.h>

namespace crow_app {

void setupUserProfileRoute(crow::SimpleApp &app, inja::Environment &env, sqlite3 *db);

}

#endif //CPP_SERVER_INCLUDE_USERS_H_
