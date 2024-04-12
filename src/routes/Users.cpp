// Users.cpp
// Created by Yu Houcheng on 4/11/24.

#include "Users.h"
#include "globals.h"

namespace crow_app {

/**
 * Sets up the user profile route in the web application.
 *
 * This route handles URLs of the form /users/<username> and renders a user profile
 * page using Inja templates with user-specific data.
 *
 * @param app Reference to the crow::SimpleApp object representing the web application.
 * @param env Reference to the inja::Environment object used for rendering HTML templates.
 * @param db Pointer to the database for queries.
 */
void setupUserProfileRoute(crow::SimpleApp &app, inja::Environment &env, sqlite3 *db) {
  CROW_ROUTE(app, "/users/<string>/")
      ([&env, db](const crow::request &req, const std::string &username) -> crow::response {
        std::cout << "Username: " << username << std::endl;
        const char *queryString = "SELECT * FROM users WHERE username=?";
        sqlite3_stmt *statement;
        int rc = sqlite3_prepare_v2(db, queryString, -1, &statement, nullptr);
        if (rc != SQLITE_OK) {
          std::cerr << "Error preparing statement: " << sqlite3_errmsg(db) << std::endl;
        }
        sqlite3_bind_text(statement, 1, username.c_str(), -1, SQLITE_STATIC);
        nlohmann::json data;
        // Execute the query and iterate over result rows
        while (sqlite3_step(statement) == SQLITE_ROW) {
          data["username"] = reinterpret_cast<const char *>(sqlite3_column_text(statement, 0));
          data["fullname"] =
              reinterpret_cast<const char *>(sqlite3_column_text(statement, 1));
          data["email"] =
              reinterpret_cast<const char *>(sqlite3_column_text(statement, 2));
          data["filename"] =
              reinterpret_cast<const char *>(sqlite3_column_text(statement, 3));
        }

        sqlite3_finalize(statement);
        // Render the HTML page using the Inja template engine
        std::string result = env.render_file(TEMPLATES_FOLDER + "user.html", data);
        return {result};
      });
}

} // namespace crow_app