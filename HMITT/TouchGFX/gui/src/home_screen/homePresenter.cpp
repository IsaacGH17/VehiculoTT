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
    view.setBatValue(value);
}

void homePresenter::updatePWM(int value)
{
    view.setPWMValue(value);
}

void homePresenter::updateDist(int value)
{
    view.setDistValue(value);
}
void homePresenter::updateRoll(float value)
{
	view.setRollValue(value);
}
void homePresenter::updatePitch(float value)
{
	view.setPitchValue(value);
}

void homePresenter::solicitarModoSemi()
{
    model->solicitarModoSemi();
}
