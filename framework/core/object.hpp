#ifndef __FRAMEWORK_CORE_OBJECT__
#define __FRAMEWORK_CORE_OBJECT__

class IObject
{
public:
    virtual ~IObject() = default;
    virtual bool isActive() = 0;
    virtual void render() = 0;
};

#endif
