#include <application.h>

class Application : public IApplication
{
public:
    virtual bool Setup()
    {
        return true;
    }
    
    virtual void Render3d()
    {
    }
    
    virtual void Render2d()
    {
    }
};

extern IApplication* CreateApplication();

IApplication* CreateApplication()
{
    return new Application();
}
