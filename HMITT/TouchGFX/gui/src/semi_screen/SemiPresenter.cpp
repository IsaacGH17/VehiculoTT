#include <gui/semi_screen/SemiView.hpp>
#include <gui/semi_screen/SemiPresenter.hpp>

SemiPresenter::SemiPresenter(SemiView& v)
    : view(v)
{
}

void SemiPresenter::activate()
{
}

void SemiPresenter::deactivate()
{
}

void SemiPresenter::updateBat(float value)
{
    view.setBatValue(value);
}

void SemiPresenter::updatePWM(int value)
{
    view.setPWMValue(value);
}

void SemiPresenter::updateDist(int value)
{
    view.setDistValue(value);
}
void SemiPresenter::updateRoll(float value)
{
	view.setRollValue(value);
}
void SemiPresenter::updatePitch(float value)
{
	view.setPitchValue(value);
}
