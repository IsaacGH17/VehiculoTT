#ifndef SEMIPRESENTER_HPP
#define SEMIPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class SemiView;

class SemiPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    SemiPresenter(SemiView& v);

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
    virtual void updatePitch(float value);
    virtual void updateRoll(float value);
    void solicitarModoManual();
    virtual ~SemiPresenter() {}

private:
    SemiPresenter();

    SemiView& view;
};

#endif // SEMIPRESENTER_HPP
