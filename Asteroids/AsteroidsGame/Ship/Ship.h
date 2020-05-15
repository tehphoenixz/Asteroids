#ifndef SHIP_H
#define SHIP_H

#include "Engine/Rectangle/GameObject/PolyShape/PolyShape.h"
#include "AsteroidsGame/Bullet/Bullet.h"
#include "Engine/ParticleSystem/ParticleSystem.h"
#include "Engine/Shader/Shader.h"

namespace Asteroids {
    class Ship : public Engine::PolyShape {
    private:
        Engine::ParticleSystem* particleSystem;
        int fullShield = 0;
        int shield = 0;
    public:
        Ship() = default;
        Ship(float x, float y, float angle, float dx, float dy, float dAngle, Engine::ParticleSystem* particleSystem);
        void Shield(int duration);
        int Ship::Shield();
        void Explode();
        void Accelerate(float power);
        void Update(float maxX, float maxY, bool wrap = true);
        void Draw(Engine::Shader& shader, float width, float height);
        Bullet Fire(float power);
    };
}

#endif