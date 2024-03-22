#include <gui/main_screen/MainView.hpp>

MainView::MainView()
{
}

void MainView::setupScreen()
{
    tickCounter = 0;

    boxProgress.getRange(boxProgressMin, boxProgressMax);
    imageProgress1.getRange(imageProgress1Min, imageProgress1Max);
    imageProgress2.getRange(imageProgress2Min, imageProgress2Max);
    circleProgress.getRange(circleProgressMin, circleProgressMax);
    lineProgress.getRange(lineProgressMin, lineProgressMax);
    tiltedLineProgress.getRange(tiltedLineProgressMin, tiltedLineProgressMax);
    textProgress.getRange(textProgressMin, textProgressMax);
}

void MainView::tearDownScreen()
{

}

void MainView::updateProgress(uint16_t tick)
{
    boxProgress.setValue(tick % (boxProgressMax + 1));
    textProgress.setValue(tick % (textProgressMax + 1));
    imageProgress1.setValue(tick % (imageProgress1Max + 1));
    imageProgress2.setValue(tick % (imageProgress2Max + 1));
    circleProgress.setValue(tick % (circleProgressMax + 1));
    lineProgress.setValue(tick % (lineProgressMax + 1));
    tiltedLineProgress.setValue(tick % (tiltedLineProgressMax + 1));
}

void MainView::updateDirection(uint16_t tick)
{
    boxProgress.setMax((boxProgressMax + 1) * 4);
    boxProgress.setValue(tick % (boxProgressMax + 1));

    imageProgress1.setDirection((tick / (imageProgress1Max + 1)) % 2 == 0 ? AbstractDirectionProgress::RIGHT : AbstractDirectionProgress::LEFT);

    imageProgress2.setDirection((tick / (imageProgress2Max + 1)) % 2 == 0 ? AbstractDirectionProgress::RIGHT : AbstractDirectionProgress::LEFT);
}

void MainView::handleTickEvent()
{
    tickCounter++;
    updateProgress(tickCounter);
    updateDirection(tickCounter);
}
