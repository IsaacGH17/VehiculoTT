#include <gui/home_screen/homeView.hpp>

homeView::homeView()
{
    // Inicializar el buffer con un valor por defecto
    Unicode::strncpy(batValueBuffer, "0", 10);
}

void homeView::setupScreen()
{
    homeViewBase::setupScreen();
    // CLAVE: conectar el buffer al widget antes del primer redraw
    baterry.setWildcard(batValueBuffer);
    baterry.invalidate();
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

        Unicode::snprintfFloat(batValueBuffer, 10, "%.3f", value);
        baterry.invalidate();
        int pct = (int) value % 101;
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

