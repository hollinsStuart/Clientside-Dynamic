#include "Index.h"

namespace crow_app {
    void setupIndexRoute(crow::SimpleApp& app, inja::Environment& env) {
        CROW_ROUTE(app, "/")([&env]{
            URLMap::instance().add_route("index", "/");

            nlohmann::json data;
            data["title"] = "index page";
            data["heading"] = "Index 485";
            data["message"] = "This is a message from Inja in C++.";

            // Render the template with the data
            std::string result = env.render_file("../templates/index.html", data);
            return crow::response(result);
        });
    }
}

