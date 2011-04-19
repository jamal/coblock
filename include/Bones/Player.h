/*
 *  Player.h
 *  Starless
 *
 *  Created by Jamal Fanaian on 3/25/11.
 *  Copyright 2011 Nipat. All rights reserved.
 *
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "Game.h"

class Player : public FrameListener {
private:
	sf::Sprite _sprite;
	sf::Image _image;
	bool _hasInit;
    int _speed;
	
public:
	Player();
	~Player();
	
	void Init();
	void OnFrameEnter(Game &game);
	
};

#endif
