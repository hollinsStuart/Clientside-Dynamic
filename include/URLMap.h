//
// Created by Yu Houcheng on 4/7/24.
//

#ifndef CPP_SERVER_URLMAP_H
#define CPP_SERVER_URLMAP_H

#pragma once
#include <unordered_map>
#include <string>

class URLMap {
public:
    static URLMap& instance() {
        static URLMap instance;
        return instance;
    }

    void add_route(const std::string& name, const std::string& path) {
        routes[name] = path;
    }

    std::string get_url(const std::string& name) const {
        auto it = routes.find(name);
        if (it != routes.end()) {
            return it->second;
        }
        return ""; // Return empty string or handle error as appropriate
    }

private:
    std::unordered_map<std::string, std::string> routes;
    URLMap() {} // Private constructor for singleton
};


#endif //CPP_SERVER_URLMAP_H
