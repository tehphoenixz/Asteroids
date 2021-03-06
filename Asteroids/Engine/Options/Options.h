#ifndef OPTIONS_H
#define OPTIONS_H

#include <vector>
#include "Engine/HUD/HUDElement/Text/Menu/Menu.h"

namespace Engine {
    class Options {
    public:
        typedef std::pair<int, int> ScreenSize;

    private:
        static std::vector<ScreenSize> screenSizes;
        static int screenSizeIndex;
        static bool fullscreen;

    public:
        static ScreenSize screenSize;
        static int volume;
        static int minVolume;
        static int maxVolume;
        static bool drawBounds;
        static bool drawParticles;

        static Menu GetOptionsMenu();
        static void ChangeResolution(int change);
        static void ToggleFullscreen();

        static void SaveConfig();
        static void LoadConfig();
    };
}
#endif