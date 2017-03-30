#include "slices.h"

Settings::visualization::Slices::Slices(QObject *parent) :
   QObject(parent),
   globalAlpha(1.0),
   numberOfSlices(10)
{
   connectToOtherSettings();
}

void Settings::visualization::Slices::connectToOtherSettings()
{}

const Settings::visualization::Slices& Settings::visualization::Slices::instance()
{
   static Slices instance;

   return instance;
}

void Settings::visualization::Slices::onGlobalAlphaChanged(double newGlobalAlpha)
{
   qDebug() << "Settings::visualization::Slices::onGlobalAlphaChanged: " << newGlobalAlpha;
   this->globalAlpha = newGlobalAlpha;
}

void Settings::visualization::Slices::onNumberOfSlicesChanged(int newNumberOfSlices)
{
   qDebug() << "Settings::visualization::Slices::onNumberOfSlicesChanged: " << newNumberOfSlices;
   this->numberOfSlices = newNumberOfSlices;
   emit numberOfSlicesChanged(newNumberOfSlices);
}
