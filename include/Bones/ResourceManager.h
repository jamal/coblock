#ifndef BONES_RESOURCE_MANAGER_H
#define BONES_RESOURCE_MANAGER_H

#include <map>
#include <SFML/Graphics.hpp>

namespace Bones {
    #define RESOURCE_DIR "/Users/jamal/Development/nipat/Coblock/resources/"

    typedef std::map<std::string, sf::Image*> ImageMap;

    class ResourceManager {
    private:
        static ImageMap _images;
        
    public:
        static sf::Image* LoadImage(const char* filename);
        
    };
    
}

#endif
