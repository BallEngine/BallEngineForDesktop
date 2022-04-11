/*****************************************************************************
FileName:   QtInterface.cpp
Creater:    Xeler
Desc:       QtInterface code.
******************************************************************************/

#include "QtInterface.h"

BE_USE

QtInterface::QtInterface(int argc, char *argv[]) : qtApplication(argc, argv) {
    qtScreen.show();
}

QtInterface::~QtInterface() {

}

void QtInterface::updateFrame(BImage frame) {
    BImage localFrame = SystemInterface::pretreatmentFrame(frame);
    QPixmap qtFrame = QPixmap::fromImage(QImage::fromData(localFrame.getImageData(), localFrame.getImageDataSize()));

    qtScreen.setPixmap(qtFrame);
}

void QtInterface::processEvent(BEvent event) {

}

int QtInterface::execute() {
    return qtApplication.exec();
}
