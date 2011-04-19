#ifndef BONES_GAME_H
#define BONES_GAME_H

#include <vector>
#include <boost/bind.hpp>
#include <boost/signals2.hpp>
#include <SFML/Graphics.hpp>
#include <chipmunk/chipmunk.h>

#include "Signal.h"
#include "FrameListener.h"
#include "MouseListener.h"
#include "Block.h"

namespace Bones {

    class Game {
    private:
        static Game* _instance;
        
        sf::RenderWindow _window;
        
        cpSpace* _space;
        cpBody* _test;
        
        char* _name;
        int _width;
        int _height;
        float _framerate;
        float _maxFramerate;
        sf::Color _color;
        
        std::vector<FrameListener*> _frameListeners;
        std::vector<MouseListener*> _mouseListeners;
        
        void _Init(const char* name, int width, int height, sf::Color color);
        
        Game();
        ~Game();
        
    public:
        static const int VIEW_HUD = 1;
        static const int VIEW_WORLD = 2;
        static const int VIEW_BACKGROUND = 3;
        
        static Game* Instance();
        
        
        void SetName(const char* name);
        void SetSize(int width, int height);
        void SetColor(int red, int green, int blue);
        void SetColor(sf::Color color);
        
        const char* GetName();
        sf::Vector2f GetSize();
        sf::Color GetColor();
        
        sf::RenderWindow &GetWindow();
        const sf::Input &GetInput();
        float GetFramerate();
        float GetFrameTime();
        cpSpace* GetSpace();
        
        void RegisterFrameListener(FrameListener* listener);
        void RegisterMouseListener(MouseListener* listener);
        
        void Run();
        
    };
    
}

#endif
