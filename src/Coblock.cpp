#include "Coblock.h"

Coblock::Coblock() {
    _game = Game::Instance();
    
	_game->SetName("Coblock");
    _game->SetSize(1024, 768);
    _game->SetColor(255, 255, 255);
    
    Signal::FrameEnter.connect(boost::bind(&Coblock::OnFrameEnter, this));
    
//    _block1.SetPosition(200, 100);
	
    //	_game->RegisterFrameListener(this);
//    _game->RegisterFrameListener(&_block1);
}

Coblock::~Coblock() {
//    delete _game;
}

void Coblock::Run() {
	_game->Run();
}

void Coblock::OnFrameEnter() const {
    printf("enter framez\n");
}

//void Coblock::OnFrameEnter(Game &game) {
//	// Draw frameratex
//	char fpsStringContent[15];
//	sprintf(fpsStringContent, "FPS: %.2f", game.GetFramerate());
//	
//	sf::String fpsString;
//	fpsString.SetText(fpsStringContent);
//	fpsString.SetSize(12);
//	fpsString.SetFont(sf::Font::GetDefaultFont());
//    fpsString.SetPosition(0, 0);
//    fpsString.SetColor(sf::Color(0, 0, 0));
//	game.GetWindow().Draw(fpsString);
//}
