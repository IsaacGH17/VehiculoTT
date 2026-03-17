#ifndef MANUALVIEW_HPP
#define MANUALVIEW_HPP

#include <gui_generated/manual_screen/ManualViewBase.hpp>
#include <gui/manual_screen/ManualPresenter.hpp>

class ManualView : public ManualViewBase
{
public:
    ManualView();
    virtual ~ManualView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // MANUALVIEW_HPP
