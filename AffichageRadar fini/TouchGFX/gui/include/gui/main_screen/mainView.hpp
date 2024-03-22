#ifndef MAIN_VIEW_HPP
#define MAIN_VIEW_HPP

#include <gui_generated/main_screen/MainViewBase.hpp>
#include <gui/main_screen/MainPresenter.hpp>

class MainView : public MainViewBase
{
public:
    MainView();
    virtual ~MainView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void handleTickEvent();

    void updateProgress(uint16_t tick);
    void updateDirection(uint16_t tick);

protected:
    uint16_t tickCounter;

    int boxProgressMax;
    int boxProgressMin;

    int imageProgress1Max;
    int imageProgress1Min;

    int imageProgress2Max;
    int imageProgress2Min;

    int circleProgressMax;
    int circleProgressMin;

    int lineProgressMax;
    int lineProgressMin;

    int tiltedLineProgressMax;
    int tiltedLineProgressMin;

    int textProgressMax;
    int textProgressMin;
};

#endif // MAIN_VIEW_HPP
