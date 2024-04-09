// Hello.cpp
// Created by Yu Houcheng on 4/9/24.

#include "Hello.h"
#include "globals.h"

namespace crow_app {

void setupHelloRoute(crow::SimpleApp &app, inja::Environment &env) {
  CROW_ROUTE(app, "/hello")([&env] {
    URLMap::instance().add_route("index", "/");

    nlohmann::json data;
    data["title"] = "index page";
    data["heading"] = "Index 485";
    data["message"] = "This is a message from Inja in C++.";

    // Render the template with the data
    std::string result = env.render_file(TEMPLATES_FOLDER + "hello.html", data);
    return crow::response(result);
  });
}

} // namespace crow_app
