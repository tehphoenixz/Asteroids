#ifndef MENU_H
#define MENU_H

#include "Engine/HUD/HUDElement/Text/Text.h"
#include <string>
#include <vector>
#include <functional>
#include <tuple>
#include <variant>

namespace Engine {
    class Menu;

    typedef std::tuple<std::string, std::variant<
                                        std::monostate,
                                        std::tuple<int*, int*, int*>,
                                        std::function<void()>, Menu>> MenuItem;
    class Menu {
    public:
        Menu(std::vector<MenuItem> options, bool subMenu);
        void Show(GLFWwindow* window);

    private:
        std::vector<MenuItem> options;
    };
}

#endif
