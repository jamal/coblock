#ifndef BONES_SIGNAL_H
#define BONES_SIGNAL_H

#include <boost/signals2.hpp>

namespace Bones {

    // TODO: Create an Event object that can be passed with the 
    // signal call, which will contain information such as which
    // button was clicked, the mouse position, frame time, etc.
    
    class Signal {
    public:
        static boost::signals2::signal<void ()> FrameEnter;
        static boost::signals2::signal<void ()> FrameExit;
        
        static boost::signals2::signal<void ()> Render;
        
        static boost::signals2::signal<void ()> MouseButtonPressed;
        static boost::signals2::signal<void ()> MouseButtonReleased;
        static boost::signals2::signal<void ()> MouseMoved;
        static boost::signals2::signal<void ()> MouseWheelScrolled;
    };
}

#endif