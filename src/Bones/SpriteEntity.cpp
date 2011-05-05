#include "Bones/Game.h"
#include "Bones/Signal.h"
#include "Bones/SpriteEntity.h"
#include "Bones/ResourceManager.h"

using namespace Bones;

SpriteEntity::SpriteEntity(const char* filename) 
    : Entity() 
{
    _filename = filename;
    _imageLoaded = false;
    
    Signal::FrameRender.connect(boost::bind(&SpriteEntity::Render, this));
}

SpriteEntity::~SpriteEntity() {
    
}

void SpriteEntity::SetPosition(float x, float y) {
    Entity::SetPosition(x, y);
    _sprite->SetPosition(x, y);
}

void SpriteEntity::SetRotation(float radians) {
    Entity::SetRotation(radians);
    _sprite->SetRotation(radians);
}

void SpriteEntity::SetImage(const char* filename) {
    _filename = filename;
    _imageLoaded = false;
}

void SpriteEntity::_LoadImage() {
    sf::Image* img = ResourceManager::LoadImage(_filename);
    if (img) {
        _sprite->SetImage(*img);
        _imageLoaded = true;
    }
}

void SpriteEntity::Render() const {
    Game* game = Game::Instance();
    game->GetWindow().Draw(*_sprite);
}
