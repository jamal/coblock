#include "Bones/Game.h"

using namespace Bones;

Game* Game::_instance;

Game* Game::Instance() {
    if (_instance == 0) {
        _instance = new Game();
    }
    
    return _instance;
}

Game::Game() {
    _Init("A Game", 800, 600, sf::Color(0, 0, 0));
}

Game::~Game() {
    cpSpaceFreeChildren(_space);
    cpSpaceFree(_space);
}

void Game::_Init(const char* name, int width, int height, sf::Color color) {
    SetName(name);
	SetSize(width, height);
    
	_framerate = 0;
	_maxFramerate = 100;
    
    _color = color;
    
    // Initialize physics engine
    cpInitChipmunk();
    cp_collision_slop = 0.2f;
    
    _space = cpSpaceNew();
    _space->iterations = 10;
    _space->sleepTimeThreshold = 0.5f;
    _space->gravity = cpv(0, 500);  
    
    cpSpaceResizeActiveHash(_space, 30.0f, 1000);
    
    // Add edges
    cpBody* staticBody = &_space->staticBody;
    cpShape *shape;
    
    shape = cpSpaceAddShape(_space, cpSegmentShapeNew(staticBody, cpv(0, 0), cpv(0, 768), 0.0f));
    shape->e = 1.0f;
    shape->u = 1.0f;
    
    shape = cpSpaceAddShape(_space, cpSegmentShapeNew(staticBody, cpv(0, 768), cpv(1024, 768), 0.0f));
    shape->e = 1.0f;
    shape->u = 1.0f;
    
    shape = cpSpaceAddShape(_space, cpSegmentShapeNew(staticBody, cpv(1024, 0), cpv(1024, 768), 0.0f));
    shape->e = 1.0f;
    shape->u = 1.0f;
}

void Game::SetName(const char* name) {
	_name = (char*) malloc(sizeof(name) + 1);
	strcpy(_name, name);
}

void Game::SetSize(int width, int height) {
	_width = width;
	_height = height;
}

void Game::SetColor(int red, int green, int blue) {
    SetColor(sf::Color(red, green, blue));
}

void Game::SetColor(sf::Color color) {
    _color = color;
}

const char* Game::GetName() {
    return _name;
}

sf::Vector2f Game::GetSize() {
    return sf::Vector2f(_width, _height);
}

sf::Color Game::GetColor() {
    return _color;
}

sf::RenderWindow &Game::GetWindow() {
	return _window;
}

const sf::Input &Game::GetInput() {
    return _window.GetInput();
}

float Game::GetFramerate() {
	return _framerate;
}

float Game::GetFrameTime() {
    return _window.GetFrameTime();
}

cpSpace* Game::GetSpace() {
    return _space;
}

void Game::RegisterFrameListener(FrameListener* listener) {
	_frameListeners.push_back(listener);
}

void Game::RegisterMouseListener(MouseListener* listener) {
	_mouseListeners.push_back(listener);
}

void Game::Run() {
	// Create new window
	_window.Create(sf::VideoMode(_width, _height), _name);
	_window.SetFramerateLimit(_maxFramerate);
    
//    const sf::Input& input = _window.GetInput();

    sf::Event Event; 
    
	// Main loop
    while (_window.IsOpened()) {
		_framerate = 1.f / GetFrameTime();
        
        Signal::FrameEnter();
        
        // Process events
        while (_window.GetEvent(Event)) {
            
            if (Event.Type == sf::Event::Closed) {
                // TODO: Fire a game close event
                _window.Close();
			} else if (Event.Type == sf::Event::MouseButtonPressed) {
                Signal::MouseButtonPressed();
            } else if (Event.Type == sf::Event::MouseButtonReleased) {
                Signal::MouseButtonReleased();
            } else if (Event.Type == sf::Event::MouseMoved) {
                Signal::MouseMoved();
            } else if (Event.Type == sf::Event::MouseWheelMoved) {
                Signal::MouseWheelScrolled();
            }
        }
        
        // Render the frame
        cpSpaceStep(_space, GetFrameTime());
        
        Signal::Render();
        
        Signal::FrameExit();
    }
}

/*
 // Prototype code
 
 
 mousePoint = cpv(input.GetMouseX(), input.GetMouseY());
 if (Event.Type == sf::Event::MouseButtonPressed) {
 Signal::MouseButtonPressed();
 
 if (_mouseListeners.size() > 0) {
 std::vector<MouseListener*>::iterator it;
 
 for (it = _mouseListeners.begin(); it != _mouseListeners.end(); it++) {
 (*it)->OnMousePress();
 }
 }
 
 if (Event.MouseButton.Button == sf::Mouse::Left) {  
 printf("Pointer clicked: %.2d, %.2d\n", input.GetMouseX(), input.GetMouseY());
 
 activeShape = cpSpacePointQueryFirst(_space, mousePoint, CP_ALL_LAYERS, 0);
 
 if (activeShape) {
 printf("Found shape\n");
 cpBodySleep(activeShape->body);
 }
 }
 }
 
 if (Event.Type == sf::Event::MouseButtonReleased) {                if (Event.MouseButton.Button == sf::Mouse::Left && activeShape) {
 activeShape->body->v = cpvzero;
 cpBodyActivate(activeShape->body);
 activeShape = NULL;
 }
 }
 
 if (Event.Type == sf::Event::MouseMoved && activeShape) {
 activeShape->body->p = mousePoint;
 cpBodySlew(activeShape->body, mousePoint, GetFrameTime());
 cpBodyUpdatePosition(activeShape->body, GetFrameTime());
 }
 */
