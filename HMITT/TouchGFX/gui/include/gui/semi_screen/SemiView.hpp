#ifndef SEMIVIEW_HPP
#define SEMIVIEW_HPP

#include <gui_generated/semi_screen/SemiViewBase.hpp>
#include <gui/semi_screen/SemiPresenter.hpp>

class SemiView : public SemiViewBase
{
public:
    SemiView();
    virtual ~SemiView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // SEMIVIEW_HPP
