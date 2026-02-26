#pragma once
#include "interface/main/main_module.h"
namespace Arieo::Interface::Window
{
    class IWindowManager;
    class IWindow
    {
    public:
        virtual std::uint64_t getWindowHandle() = 0;
        virtual Base::Math::Rect<std::uint32_t> getWindowRect() = 0;
        virtual Base::Math::Vector<std::uint32_t, 2> getFramebufferSize() = 0;
        virtual bool isClosed() = 0;
        virtual Base::StringID getWindowPlatform() = 0;
    };

    class IWindowManager
        : public Arieo::Interface::Main::ITickable
    {
    public:
        virtual void* getDisplay() = 0;
        virtual Base::Interface<IWindow> createWindow(std::uint16_t pos_x, std::uint16_t pos_y, std::uint16_t width, std::uint16_t height) = 0;
        virtual void destroyWindow(Base::Interface<IWindow>) = 0;

        virtual Base::Interface<IWindow> getMainWindow() = 0;
    };
}