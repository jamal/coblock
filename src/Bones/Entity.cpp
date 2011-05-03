#include "Bones/Entity.h"
#include "Bones/Game.h"

using namespace Bones;

Entity::Entity() {
    _width = 10;
    _height = 10;
    _x = 0;
    _y = 0;
    _rotation = 0;
    _mass = 10.f;
    _elasticity = 0.0f;
    _friction = 1.0f;
    
    cpBody* body;
    body = cpBodyNew(_mass, cpMomentForBox(_mass, _width, _height));
    body->p = cpv(_x, _y);
    
    cpSpaceAddBody(Game::Instance()->GetSpace(), body);
    
    _shape = cpBoxShapeNew(body, _width, _height);
    _shape->e = 0.0f;
    _shape->u = _friction;
    _shape->data = this;
    
    cpSpaceAddShape(Game::Instance()->GetSpace(), _shape);
}

Entity::~Entity() {}

void Entity::SetMass(float mass) {
    _mass = mass;
    _shape->body->m = mass;
    _shape->body->i = cpMomentForBox(_mass, _width, _height);
}

void Entity::SetSize(float width, float height) {
    _width = width;
    _height = height;
    _shape->body->m = cpMomentForBox(_mass, _width, _height);
    _shape->
}

void Entity::SetPosition(float x, float y) {
    _x = x;
    _y = y;
    _shape->body->p = cpv(_x, _y);
}

void Entity::SetPosition(Vector2f position) {
    SetPosition(position.x, position.y);
}

void Entity::SetCenter(float x, float y) {
    x = x - (_width/2);
    y = y - (_height/2);
    SetPosition(x, y);
}

void Entity::SetCenter(Vector2f center) {
    SetCenter(center.x, center.y);
}

Vector2f Entity::GetCenter() {
    Vector2f position = GetPosition();
    position.x = position.x + (_width/2);
    position.y = position.y + (_height/2);
    return position;
}

void Entity::SetRotation(float radians) {
    _rotation = radians;
    _shape->body->a = radians;
}

void Entity::SetRotationd(float radians) {
    SetRotation(radians);
}

void Entity::SetRotationr(float degrees) {
    SetRotation(degrees * (M_PI/180));
}

Vector2f Entity::GetPosition() {
    return Vector2f(_x, _y);
}

float Entity::GetRotation() {
    return _rotation;
}

float Entity::GetRotationr() {
    return GetRotation();
}

float Entity::GetRotationd() {
    return GetRotation() * (180/M_PI);
}