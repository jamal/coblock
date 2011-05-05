#include "Bones/Signal.h"

using namespace Bones;

boost::signals2::signal<void ()> Signal::FrameEnter;
boost::signals2::signal<void ()> Signal::FrameExit;
boost::signals2::signal<void ()> Signal::FrameRender;

boost::signals2::signal<void ()> Signal::MouseButtonPressed;
boost::signals2::signal<void ()> Signal::MouseButtonReleased;
boost::signals2::signal<void ()> Signal::MouseMoved;
boost::signals2::signal<void ()> Signal::MouseWheelScrolled;
