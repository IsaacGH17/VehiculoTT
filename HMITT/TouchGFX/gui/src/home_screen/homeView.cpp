#include <gui/home_screen/homeView.hpp>

homeView::homeView()
{
}

void homeView::setupScreen()
{
    homeViewBase::setupScreen();
}

void homeView::tearDownScreen()
{
    homeViewBase::tearDownScreen();
}

void homeView::setBatValue(float value)
{
    containerTele1.setBatValue(value);
}

void homeView::setPWMValue(int value)
{
    containerTele1.setPWMValue(value);
}

void homeView::setDistValue(int value)
{
    containerTele1.setDistValue(value);
}
void homeView::setRollValue(float value)
{
    containerTele1.setRollValue(value);
}
void homeView::setPitchValue(float value)
{
    containerTele1.setPitchValue(value);
}
