#include "Coblock.h"

int main()
{
    boost::shared_ptr<Coblock> game(new Coblock);
	game->Run();
    return 0;
}
