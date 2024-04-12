// Hello.cpp
// Created by Yu Houcheng on 4/9/24.

#include "Hello.h"
#include "globals.h"

namespace crow_app {

/**
 * Sets up the hello route for the web application.
 *
 * Configures the hello route ("/") for the application, adds the route to the URLMap,
 * prepares JSON data for rendering, and then renders an HTML page using the Inja template engine.
 *
 * @param app Reference to the crow::SimpleApp object representing the web application.
 * @param env Reference to the inja::Environment object used for rendering HTML templates.
 */
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
