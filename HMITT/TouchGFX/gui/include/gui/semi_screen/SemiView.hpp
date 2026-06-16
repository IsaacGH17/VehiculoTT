#ifndef SEMIVIEW_HPP
#define SEMIVIEW_HPP

#include <gui_generated/semi_screen/SemiViewBase.hpp>
#include <gui/semi_screen/SemiPresenter.hpp>

class SemiView : public SemiViewBase
{
public:
    SemiView();
    virtual ~SemiView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void setBatValue(float value);
    void setPWMValue(int value);
    void setDistValue(int value);
    virtual void setPitchValue(float value);
    virtual void setRollValue(float value);
    virtual void modoManual();
protected:
};

#endif // SEMIVIEW_HPP
