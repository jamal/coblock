#ifndef BONES_SPRITE_ENTITY_H
#define BONES_SPRITE_ENTITY_H

#include <SFML/Graphics.hpp>
#include <chipmunk/chipmunk.h>

#include "Bones/Entity.h"

namespace Bones {
    
    class SpriteEntity : public Entity {
    private:
        bool _imageLoaded;
        const char* _filename;
        sf::Sprite* _sprite;
        
        void _LoadImage();
        
    public:
        SpriteEntity(const char* filename);
        ~SpriteEntity();
        
        void SetPosition(float x, float y);
        void SetRotation(float radians);
        
        void SetImage(const char* filename);
        
        void Render() const;
        
    };
    
}
#endif