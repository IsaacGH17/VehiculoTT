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
    // Solo redibujar si el valor cambió
    static int lastValue = -1;
    if (value != lastValue)
    {
        lastValue = value;

        // Actualizar el label de texto
        Unicode::snprintfFloat(batValueBuffer, 10, "%.3f", value);
        baterry.invalidate();

        // Actualizar el progress bar (rango 0-100)
        int pct = (int) value % 101; // cicla entre 0 y 100
        imageProgress1.setValue(pct);
        imageProgress1.invalidate();
    }
}
