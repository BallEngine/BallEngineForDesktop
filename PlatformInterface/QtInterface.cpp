/*****************************************************************************
FileName:   QtInterface.cpp
Creater:    Xeler
Desc:       QtInterface code.
Version:    0.1
******************************************************************************/

#include "QtInterface.h"

BE_USE

QtInterface::QtInterface() {

}

QtInterface::~QtInterface() {

}

void QtInterface::updateFrame(BImage frame) {
    BImage localFrame = SystemInterface::pretreatmentFrame(frame);
    QImage qtFrame = QImage::fromData(localFrame.getImageData(),localFrame.getImageDataSize());
}

void QtInterface::processEvent(BEvent event) {

}