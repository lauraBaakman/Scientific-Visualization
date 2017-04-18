#include "streamobject.h"
#include "settings/visualizationsettings.h"
#include "settings/canvassettings.h"
#include <QDebug>
#include <limits>

StreamObject::StreamObject(QObject *parent) :
   QObject(parent),
   timeStep(1.0),
   maximumTime(100),
   //Private
   edgeLengthFactor(0.33),
   totalLengthFactor(std::numeric_limits<double>::infinity())
{
   //Initial cellsize is -1, which doesn't make sense.
   this->edgeLength = 4.0;
   this->totalLength = 4.0;
}

void StreamObject::ontimeStepChanged(double newTimeStep)
{
   this->timeStep = newTimeStep;
   emit clearCache();
}

void StreamObject::onMaximumTimeChanged(double newMaximumTime)
{
   this->maximumTime = newMaximumTime;
   emit clearCache();
}

void StreamObject::onEdgeLengthFactorChanged(double newEdgeLengthFactor)
{
   this->edgeLength = computeEdgeLength(newEdgeLengthFactor, Settings::simulation().cellSize.width());
   this->edgeLengthFactor = newEdgeLengthFactor;
   emit clearCache();
}

void StreamObject::onMaximumTotalLengthFactorChanged(double newValue)
{
   this->totalLength = computeMaximumTotalLength(newValue, Settings::simulation().cellSize.width());
   this->totalLengthFactor = newValue;
   emit clearCache();
}

void StreamObject::onCellSizeChanged(QSizeF currentCellSize)
{
   this->edgeLength = computeEdgeLength(this->edgeLengthFactor, currentCellSize.width());
   this->totalLength = computeMaximumTotalLength(this->totalLengthFactor, currentCellSize.width());
   qDebug() << "StreamObject::onCellSizeChanged";
   qDebug() << "EdgeLength: " << edgeLength;
   qDebug() << "totalLength: " << totalLength;
}

double StreamObject::getTotalLengthFactor() const
{
   return totalLengthFactor;
}

double StreamObject::getEdgeLengthFactor() const
{
   return edgeLengthFactor;
}

double StreamObject::computeEdgeLength(double factor, double cellSize)
{
   return factor * cellSize;
}

double StreamObject::computeMaximumTotalLength(double factor, double cellSize)
{
   return factor * cellSize;
}
