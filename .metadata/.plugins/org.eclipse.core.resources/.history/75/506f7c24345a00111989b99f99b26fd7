#ifndef MANUALVIEW_HPP
#define MANUALVIEW_HPP

#include <gui_generated/manual_screen/ManualViewBase.hpp>
#include <gui/manual_screen/ManualPresenter.hpp>
#include <touchgfx/Color.hpp>

class ManualView : public ManualViewBase
{
public:
    ManualView();
    virtual ~ManualView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void setBatValue(float value);
    void setPWMValue(int value);
    void setDistValue(int value);

protected:
    // Toggle states for the 4 buttons
    bool btn1State;  // buttonWithLabel1 (top-left)
    bool btn2State;  // buttonWithLabel1_2 (top-right)
    bool btn3State;  // buttonWithLabel1_1 (bottom-left)
    bool btn4State;  // buttonWithLabel1_1_1 (bottom-right)

    void updateButtonAppearance(touchgfx::ButtonWithLabel& btn, bool isOn);

    // Our own callback for the toggle buttons
    touchgfx::Callback<ManualView, const touchgfx::AbstractButton&> toggleCallback;
    void toggleCallbackHandler(const touchgfx::AbstractButton& src);
};

#endif // MANUALVIEW_HPP
