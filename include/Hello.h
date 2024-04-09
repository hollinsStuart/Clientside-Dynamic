// Hello.h
// Created by Yu Houcheng on 4/9/24.

#ifndef CPP_SERVER_HELLO_H
#define CPP_SERVER_HELLO_H

#pragma once

#include "crow.h"
#include "inja/inja.hpp"
#include "nlohmann/json.hpp"
#include "URLMap.h"

// Declare a function to set up the home page route
namespace crow_app {

void setupHelloRoute(crow::SimpleApp &app, inja::Environment &env);

}

#endif //CPP_SERVER_HELLO_H
