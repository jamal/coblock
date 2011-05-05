#include <stdio.h>

#include "Bones/ResourceManager.h"

using namespace Bones;

ImageMap Bones::ResourceManager::_images;

sf::Image* ResourceManager::LoadImage(const char* filename) {
    ImageMap::iterator iter;
    iter = _images.find("somefile");
    
    if (iter != _images.end()) {
        return iter->second;
    }
    
    char filepath[255];
    sprintf(filepath, "%s%s", RESOURCE_DIR, filename);
    
    sf::Image* image = new sf::Image();
    
    if (!(*image).LoadFromFile(filepath)) {
        fprintf(stderr, "Could not load image: %s", filename);
    }
    
    ResourceManager::_images[filename] = image;
    return image;
}
