//
//  Map.h
//  Rush
//
//  Created by Jamal Fanaian on 4/6/11.
//  Copyright 2011 N/A. All rights reserved.
//

#ifndef MAP_H
#define MAP_H

#include "Game.h"

class Map : public FrameListener {
private:
    static const int _tileWidth  = 100;
    static const int _tileHeight = 100;
    
    sf::Image image;
    sf::Sprite tile;
    
    std::vector<sf::Image
    
public:
    Map();
    ~Map();
    
	void OnFrameEnter(Game &game);
};

#endif