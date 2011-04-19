#ifndef BONES_BLOCK_H
#define BONES_BLOCK_H

#include <SFML/Graphics.hpp>
#include <chipmunk/chipmunk.h>

#include "Game.h"
#include "ResourceManager.h"
#include "FrameListener.h"
#include "MouseListener.h"

struct cpBody;

namespace Bones {

    class Block : public FrameListener {
    private:
        sf::Sprite _sprite;
        cpBody* _body;
        
        bool _active;
        
    public:
        Block();
        
        void SetPosition(float x, float y);
        void SetRotation(float degrees);
        
        void OnFrameEnter(Game &game);
        static void Update(void* shape, void* method);
        
    };
    
}

#endif