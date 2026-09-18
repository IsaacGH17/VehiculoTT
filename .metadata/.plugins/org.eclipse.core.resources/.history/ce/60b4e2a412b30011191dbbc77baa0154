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
    void setRollValue(float value);
    void setPitchValue(float value);

protected:
    touchgfx::Unicode::UnicodeChar batValueBuffer[10];
    touchgfx::Unicode::UnicodeChar pwmValueBuffer[10];
    touchgfx::Unicode::UnicodeChar distValueBuffer[10];
    touchgfx::Unicode::UnicodeChar rollValueBuffer[10];
    touchgfx::Unicode::UnicodeChar pitchValueBuffer[10];
    float lastBatValue;
    int lastPWMValue;
    int lastDistValue;
    float lastRollValue;
    float lastPitchValue;
};

#endif // CONTAINERTELE_HPP
