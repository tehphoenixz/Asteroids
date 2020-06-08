#ifndef TEXT_H
#define TEXT_H

#include "Engine/Shader/Shader.h"
#include "Engine/Texture/Texture.h"

namespace Engine {
    namespace Text {
        enum class Anchor {
            TOP_LEFT,
            TOP_CENTER,
            TOP_RIGHT,
            MIDDLE_LEFT,
            MIDDLE_CENTER,
            MIDDLE_RIGHT,
            BOTTOM_LEFT,
            BOTTOM_CENTER,
            BOTTOM_RIGHT
        };
        void DrawString(Texture& texture, Shader& shader, Anchor anchor, float x, float y, int size, std::string str);
        void DrawCharacter(Texture& texture, Shader& shader, float x, float y, float w, float h, char c);
    }
}

#endif