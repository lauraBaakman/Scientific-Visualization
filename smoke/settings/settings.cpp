#include "settings.h"
#include "settingsns.h"
#include "settings/simulations.h"
#include <QDebug>

Settings::Settings(QObject *parent) : QObject(parent)
{
    this->canvas = new Canvas();
    this->grid  = new Grid();
    this->visualization = new Visualization();
}

Settings::~Settings()
{
    delete canvas;
    delete grid;
    delete visualization;
}


void Settings::onWindowResized(int width, int height)
{
    this->canvas->width = width;
    this->canvas->height = height;

    this->updateGridCellSize();
}

void Settings::updateGridCellSize()
{
    this->grid->cellHeight = (fftw_real) this->canvas->height / (fftw_real)(settingsns::simulation().dimension + 1);
    this->grid->cellWidth = (fftw_real) this->canvas->width / (fftw_real)(settingsns::simulation().dimension + 1);
}

void Settings::onForceChanged(float newForce)
{
//    this->simulation->force = newForce;
//    emit rangeChanged(0.0,newForce);
}
