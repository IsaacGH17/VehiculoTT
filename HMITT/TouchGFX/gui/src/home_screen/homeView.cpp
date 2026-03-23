#include <gui/home_screen/homeView.hpp>

homeView::homeView()
{
    Unicode::strncpy(batValueBuffer, "0", 10);
    Unicode::strncpy(pwmValueBuffer, "0", 10);
    Unicode::strncpy(distValueBuffer, "0", 10);
}

void homeView::setupScreen()
{
    homeViewBase::setupScreen();
    baterry.setWildcard(batValueBuffer);
    baterry.invalidate();
    pwmval.setWildcard(pwmValueBuffer);
    pwmval.invalidate();
    dist.setWildcard(distValueBuffer);
    dist.invalidate();
}

void homeView::tearDownScreen()
{
    homeViewBase::tearDownScreen();
}
void homeView::setbatValue(float value)
{
    static int lastValue = -1;
    if (value != lastValue)
    {
        lastValue = value;
        int pct = (int)value;

        Unicode::snprintf(batValueBuffer, 10, "%d", pct);
        baterry.invalidate();
        
        imageProgress1.setValue(pct);
        imageProgress1.invalidate();
    }
}
void homeView::setPWMValue(int value)
{
    static int lastValue = -1;
    if (value != lastValue)
    {
        lastValue = value;
        Unicode::snprintf(pwmValueBuffer, 10, "%d", value);
        pwmval.invalidate();
    }
}
void homeView::setDistValue(int value)
{
    static int lastValue = -1;
    if (value != lastValue)
    {
        lastValue = value;
        Unicode::snprintf(distValueBuffer, 10, "%d", value);
        dist.invalidate();
    }
}

