#ifndef BONES_FRAME_LISTENER_H
#define BONES_FRAME_LISTENER_H

// Let FrameListener know that Game exists somewhere
namespace Bones {

    class Game;

    class FrameListener {
    public:
        virtual ~FrameListener() {}
        
        virtual void OnFrameEnter(Game &game) {}

    };

}

#endif