#include <iostream>
using std::cout, std::endl, std::cerr;

#include "inja/inja.hpp"

int main()
{
    cout << "Hello, World!" << endl;
    inja::Environment env;
    inja::Template temp = env.parse("Hello, {{ name }}!");
    std::string result = env.render(temp, {{"name", "world"}});
    return 0;
}
