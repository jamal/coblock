#ifndef BONES_ENTITY_H
#define BONES_ENTITY_H

#include <chipmunk/chipmunk.h>

#include "Bones/Vector2.h"

namespace Bones {
    
    class Entity {
    private:
        float _width;
        float _height;
        float _x;
        float _y;
        float _rotation;
        
        float _mass;
        float _elasticity;
        float _friction;
        
        cpShape* _shape;
    public:
        Entity();
        ~Entity();

        void SetMass(float mass);
        void SetSize(float width, float height);
        
        void SetPosition(float x, float y);
        void SetPosition(Vector2f position);
        void SetCenter(float x, float y);
        void SetCenter(Vector2f center);
        
        void SetRotation(float radians);
        void SetRotationd(float degrees);
        void SetRotationr(float radians);
        
        Vector2f GetPosition();
        Vector2f GetCenter();
        
        float GetRotation();
        float GetRotationr();
        float GetRotationd();
    };
    
}
#endif