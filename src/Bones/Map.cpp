//
//  Map.cpp
//  Rush
//
//  Created by Jamal Fanaian on 4/6/11.
//  Copyright 2011 N/A. All rights reserved.
//

#include "Map.h"

Map::Map() {
    image.LoadFromFile(ASSETS_DIR"/graphics/tile_dirt.png");
    image.SetSmooth(false);
    tile.SetImage(image);
    
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 20; j++) {
            if (i == 14) {
                _mapData[i][j] = 1;
            } else {
                _mapData[i][j] = 0;
            }
        }
    }
}

Map::~Map() {
    
}

void Map::OnFrameEnter(Game &game) {
}