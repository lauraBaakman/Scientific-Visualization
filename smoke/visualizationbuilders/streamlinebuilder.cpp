#include "streamlinebuilder.h"
#include "settings/visualizationsettings.h"

const float StreamLineBuilder::minimumMagnitude = 0.004;

StreamLineBuilder::StreamLineBuilder(const UniformGrid *grid, QVector3D seedPoint,
                                     Vertex::vectorGetter vectorGetter, Vertex::scalarGetter magnitudeGetter) :
   grid(grid),
   seedPoint(seedPoint),
   vectorGetter(vectorGetter),
   magnitudeGetter(magnitudeGetter),
   currentMagnitudeIsLargeEnough(true)
{
   this->timeStep = Settings::visualization::streamLines().timeStep;
   this->maximumTime = Settings::visualization::streamLines().maximumTime;

   this->edgeLength = Settings::visualization::streamLines().edgeLength;
   this->maximumTotalLength = Settings::visualization::streamLines().totalLength;
}

streamobject::Line StreamLineBuilder::getStreamLine()
{
   if (this->streamLine.hasNoVertices()) build(seedPoint);
   return this->streamLine;
}

void StreamLineBuilder::build(QVector3D seedPoint)
{
   double time = 0.0;
   QVector3D next, current = seedPoint;

   bool succes = tryAddingSeedPoint(current);

   while (continueBuilding(time) && succes)
   {
      next = integrate(current);
      succes = tryAddingEdge(current, next);

      current = next;
      time += this->timeStep;
   }
}

bool StreamLineBuilder::continueBuilding(double currentTime)
{
   return hasTimeLeftOver(currentTime) &&
          this->currentMagnitudeIsLargeEnough;
}

bool StreamLineBuilder::isEdgeAllowed(QVector3D origin, QVector3D destination)
{
   return this->isVertexAllowed(destination) &&
          this->isNewStreamLineLengthAllowed(origin, destination);
}

bool StreamLineBuilder::isVertexAllowed(QVector3D vertex)
{
   return this->grid->inGridArea(vertex);
}

bool StreamLineBuilder::isMagnitudeLargeEnoguh(float magnitude)
{
   return magnitude > StreamLineBuilder::minimumMagnitude;
}

bool StreamLineBuilder::hasTimeLeftOver(double currentTime)
{
   return currentTime <= this->maximumTime;
}

bool StreamLineBuilder::isNewStreamLineLengthAllowed(QVector3D origin, QVector3D destination)
{
   double edgeLength = (destination - origin).length();
   double potentialStreamLineLength = this->streamLine.getLength() + edgeLength;

   return potentialStreamLineLength < this->maximumTotalLength;
}

bool StreamLineBuilder::tryAddingVertex(QVector3D position)
{
   float magnitude = this->computeMagnitude(position);
   bool magnitudeAllowed = this->isMagnitudeLargeEnoguh(magnitude);

   if (magnitudeAllowed) this->streamLine.addVertex(position, magnitude);
   return magnitudeAllowed;
}

bool StreamLineBuilder::tryAddingEdge(QVector3D previousPosition, QVector3D position)
{
   if (!this->isEdgeAllowed(previousPosition, position)) return false;

   bool succes = this->tryAddingVertex(position);
   return succes;
}

bool StreamLineBuilder::tryAddingSeedPoint(QVector3D seedPoint)
{
   if (!this->isVertexAllowed(seedPoint)) return false;

   bool succes = this->tryAddingVertex(seedPoint);
   return succes;
}

float StreamLineBuilder::computeMagnitude(QVector3D position)
{
   StructuredCell *cell = this->grid->findCellContaining(position);
   float textureCoordinate = cell->interpolateScalar(position, this->magnitudeGetter);

   return textureCoordinate;
}

QVector3D StreamLineBuilder::integrate(QVector3D previousPosition)
{
   //Euler will do just fine for now
   QVector3D previousVector = this->grid->findCellContaining(previousPosition)->interpolate2DVector(previousPosition, this->vectorGetter);
   QVector3D currentPosition = previousPosition + previousVector.normalized() * this->edgeLength;

   return currentPosition;
}