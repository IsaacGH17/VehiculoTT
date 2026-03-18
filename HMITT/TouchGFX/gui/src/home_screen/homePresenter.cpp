#include <gui/home_screen/homeView.hpp>
#include <gui/home_screen/homePresenter.hpp>

homePresenter::homePresenter(homeView& v)
    : view(v)
{

}

void homePresenter::activate()
{

}

void homePresenter::deactivate()
{

}
void homePresenter::updateBat(float value)
{
    view.setbatValue(value);
}
