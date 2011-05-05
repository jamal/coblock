#ifndef COBLOCK_H
#define COBLOCK_H

#include <boost/bind.hpp>
#include <boost/signals2.hpp>
#include <boost/shared_ptr.hpp>

#include "Bones/Game.h"
#include "Bones/Signal.h"
#include "Bones/FrameListener.h"
#include "Bones/Block.h"

using namespace Bones;

class Coblock : public FrameListener {
private:
	Game* _game;
    //Block _block1;
    //Block _block2;
	
public:
	Coblock();
	~Coblock();
	
	void Run();
	void OnFrameEnter() const;
};

#endif
