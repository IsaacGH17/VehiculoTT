#ifndef CONTAINERTELE_HPP
#define CONTAINERTELE_HPP

#include <gui_generated/containers/containerTeleBase.hpp>

class containerTele : public containerTeleBase
{
public:
    containerTele();
    virtual ~containerTele() {}

    virtual void initialize();

    void setBatValue(float value);
    void setPWMValue(int value);
    void setDistValue(int value);

protected:
    touchgfx::Unicode::UnicodeChar batValueBuffer[10];
    touchgfx::Unicode::UnicodeChar pwmValueBuffer[10];
    touchgfx::Unicode::UnicodeChar distValueBuffer[10];

    int lastBatValue;
    int lastPWMValue;
    int lastDistValue;
};

#endif // CONTAINERTELE_HPP
