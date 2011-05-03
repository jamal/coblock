#include "Bones/Block.h"

using namespace Bones;

Block::Block() {
    
    _sprite.SetImage(*ResourceManager::LoadImage("block.png"));
    
    cpFloat width = _sprite.GetSize().x;
    cpFloat height = _sprite.GetSize().y;
    `
    printf("Size: %.2f, %.2f\n", width, height);
    
    cpFloat mass = 10.0f;
    _body = cpBodyNew(mass, cpMomentForBox(mass, width, height));
    cpSpaceAddBody(Game::Instance()->GetSpace(), _body);
    _body->p = cpv(_sprite.GetPosition().x, _sprite.GetPosition().y);
    
    cpShape* shape = cpBoxShapeNew(_body, width, height);
    cpSpaceAddShape(Game::Instance()->GetSpace(), shape);
    shape->e = 0.0f;
    shape->u = 0.7f;
    shape->data = this;
}

void Block::SetPosition(float x, float y) {
    _sprite.SetPosition(x, y);
    _body->p = cpv(x, y);
}

void Block::SetRotation(float degrees) {
    _sprite.SetRotation(degrees);
}

void Block::OnFrameEnter(Game &game) {
    float r = -_body->a;
    float d = r * (180/M_PI);
    _sprite.SetPosition(_body->p.x - (_sprite.GetSize().x / 2), 
                        _body->p.y - (_sprite.GetSize().y / 2));
    _sprite.SetRotation(d);
    
	game.GetWindow().Draw(_sprite);
}

