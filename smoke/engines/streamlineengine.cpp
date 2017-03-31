#include "streamlineengine.h"
#include "utilities/gpudata.h"
#include "streamobjects/streamline.h"

StreamLineEngine::StreamLineEngine(UniformGrid *simulationGrid) :
   AbstractEngine(AbstractEngine::lightModel::noLight,
                  Settings::engines::EnginesTypes::streamLines),
   grid(simulationGrid)
{}

int StreamLineEngine::fillBuffers()
{
   GPUData data = buildStreamLines();

   updateBuffers(data);
   return data.numElements();
}

GPUData StreamLineEngine::buildStreamLines()
{
   GPUData data(streamobject::Line::drawMode);

   for (QPointF seedpoint : Settings::visualization::streamLines().seedPoints)
   {
      GPUData streamLine = buildStreamLine(seedpoint);
      data.extend(streamLine);
   }
   return data;
}

GPUData StreamLineEngine::buildStreamLine(QPointF seedPoint)
{
   streamobject::Line streamLine = grid->computeStreamLine(QVector3D(seedPoint),
                                                           Settings::visualization::streamLines().colorMap->textureGetter,
                                                           Settings::visualization::streamLines().vectorField);
   return streamLine.toGPUData();
}

void StreamLineEngine::draw(Simulation *UNUSED(simulation))
{
   int bufferLength = this->fillBuffers();

   drawWithMode(this->drawMode, bufferLength);
}