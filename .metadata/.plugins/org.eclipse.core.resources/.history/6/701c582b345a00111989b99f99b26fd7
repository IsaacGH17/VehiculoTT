#include <gui/manual_screen/ManualView.hpp>

ManualView::ManualView()
    : btn1State(false), btn2State(false), btn3State(false), btn4State(false),
      toggleCallback(this, &ManualView::toggleCallbackHandler)
{
}

void ManualView::setupScreen()
{
    ManualViewBase::setupScreen();

    // Set all buttons to OFF appearance initially
    updateButtonAppearance(buttonWithLabel1, false);
    updateButtonAppearance(buttonWithLabel1_2, false);
    updateButtonAppearance(buttonWithLabel1_1, false);
    updateButtonAppearance(buttonWithLabel1_1_1, false);

    // Assign our toggle callback to the 4 buttons
    // (overrides the default buttonCallback set by the generated base)
    buttonWithLabel1.setAction(toggleCallback);
    buttonWithLabel1_1.setAction(toggleCallback);
    buttonWithLabel1_1_1.setAction(toggleCallback);
    buttonWithLabel1_2.setAction(toggleCallback);
}

void ManualView::tearDownScreen()
{
    ManualViewBase::tearDownScreen();
}

void ManualView::toggleCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &buttonWithLabel1)
    {
        btn1State = !btn1State;
        updateButtonAppearance(buttonWithLabel1, btn1State);
        // TODO: Send command to vehicle
    }
    else if (&src == &buttonWithLabel1_2)
    {
        btn2State = !btn2State;
        updateButtonAppearance(buttonWithLabel1_2, btn2State);
        // TODO: Send command to vehicle
    }
    else if (&src == &buttonWithLabel1_1)
    {
        btn3State = !btn3State;
        updateButtonAppearance(buttonWithLabel1_1, btn3State);
        // TODO: Send command to vehicle
    }
    else if (&src == &buttonWithLabel1_1_1)
    {
        btn4State = !btn4State;
        updateButtonAppearance(buttonWithLabel1_1_1, btn4State);
        // TODO: Send command to vehicle
    }
}

void ManualView::updateButtonAppearance(touchgfx::ButtonWithLabel& btn, bool isOn)
{
    if (isOn)
    {
        // ON state: green text
        btn.setLabelColor(touchgfx::Color::getColorFromRGB(0, 255, 100));
        btn.setLabelColorPressed(touchgfx::Color::getColorFromRGB(0, 255, 100));
    }
    else
    {
        // OFF state: white text
        btn.setLabelColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
        btn.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    }
    btn.invalidate();
}

void ManualView::setBatValue(float value)
{
    containerTele1.setBatValue(value);
}

void ManualView::setPWMValue(int value)
{
    containerTele1.setPWMValue(value);
}

void ManualView::setDistValue(int value)
{
    containerTele1.setDistValue(value);
}
