/*
 *  Player.cpp
 *  Starless
 *
 *  Created by Jamal Fanaian on 3/25/11.
 *  Copyright 2011 Nipat. All rights reserved.
 *
 */

#include "Player.h"

Player::Player() {
    _speed = 250;

    if (!_image.LoadFromFile(ASSETS_DIR"/graphics/character_player.png")) {
        fprintf(stderr, "Failed to load image");
        exit(1);
    }

    _sprite.SetImage(_image);
    _sprite.SetCenter(_sprite.GetSize().x/2, _sprite.GetSize().y/2);

    _sprite.SetPosition(100, 475);
}

Player::~Player() {}

void Player::OnFrameEnter(Game &game) {

    float frameTime = game.GetWindow().GetFrameTime();
    
    sf::Vector2f camPos = game.GetCamera().GetCenter();
    sf::Vector2f playerPos = _sprite.GetPosition();

    if (game.GetWindow().GetInput().IsKeyDown(sf::Key::Left)
        && playerPos.x >= (_sprite.GetSize().x/2)) {
        _sprite.Move(-_speed * frameTime, 0);
    }

    if (game.GetWindow().GetInput().IsKeyDown(sf::Key::Right)) {
        _sprite.Move(_speed * frameTime, 0);
    }

//    if (game.GetWindow().GetInput().IsKeyDown(sf::Key::Down)) {
//        _sprite.Move(0, _speed * frameTime);
//    }
//
//    if (game.GetWindow().GetInput().IsKeyDown(sf::Key::Up)) {
//        _sprite.Move(0, -_speed * frameTime);
//    }
    
    // Move camera right
    if (playerPos.x > camPos.x) {
        game.GetCamera().SetCenter(playerPos.x, camPos.y);
    
    // Move camera left
    } else if (playerPos.x < camPos.x && camPos.x > (game.GetCamera().GetHalfSize().x)) {
        game.GetCamera().SetCenter(playerPos.x, camPos.y);
        
    }
    
    game.GetWindow().Draw(_sprite);
}
