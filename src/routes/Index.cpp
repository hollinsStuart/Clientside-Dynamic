#include "Index.h"
#include "globals.h"

namespace crow_app {

/**
 * Sets up the index route for the web application.
 *
 * Configures the root route ("/") for the application, adds the route to the URLMap,
 * prepares JSON data for rendering, and then renders an HTML page using the Inja template engine.
 *
 * @param app Reference to the crow::SimpleApp object representing the web application.
 * @param env Reference to the inja::Environment object used for rendering HTML templates.
 */
void setupIndexRoute(crow::SimpleApp &app, inja::Environment &env, sqlite3 *db) {
  CROW_ROUTE(app, "/")
      ([&env, db]() -> crow::response {
        URLMap::instance().add_route("index", "/");

        nlohmann::json data;
        data["title"] = "index page";
        data["heading"] = "Index 485";
        data["message"] = "This is a message from Inja in C++.";

        const char *queryString = "SELECT fullname, username FROM users";
        sqlite3_stmt *statement;
        int rc = sqlite3_prepare_v2(db, queryString, -1, &statement, nullptr);
        if (rc != SQLITE_OK) {
          std::cerr << "Error preparing statement: " << sqlite3_errmsg(db) << std::endl;
        }
        std::vector<nlohmann::json> usernames;
        while (sqlite3_step(statement) == SQLITE_ROW) {
          std::string fullname = reinterpret_cast<const char *>(sqlite3_column_text(statement, 0));
          std::string username = reinterpret_cast<const char *>(sqlite3_column_text(statement, 1));
          nlohmann::json userObject = {
              {"username", username},
              {"fullname", fullname}
          };
          usernames.push_back(userObject);
        }
        data["usernames"] = usernames;
        data["style_path"] = STYLE_SHEET_PATH;

        // Render the template with the data
        std::string result = env.render_file(TEMPLATES_FOLDER + "index.html", data);
        return {result};
      });
}

} // namespace crow_app
