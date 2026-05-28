#ifndef MANUALPRESENTER_HPP
#define MANUALPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class ManualView;

class ManualPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    ManualPresenter(ManualView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual void updateBat(float value);
    virtual void updatePWM(int value);
    virtual void updateDist(int value);

    virtual ~ManualPresenter() {}

private:
    ManualPresenter();

    ManualView& view;
};

#endif // MANUALPRESENTER_HPP
