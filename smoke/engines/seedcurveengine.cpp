#include "seedcurveengine.h"

SeedCurveEngine::SeedCurveEngine() :
   AbstractEngine(AbstractEngine::lightModel::noLight,
                  Settings::engines::EnginesTypes::seedCurves)
{}

void SeedCurveEngine::draw()
{
   int resolution = Settings::visualization::streamSurfaces().resolution;
   GPUData data = Settings::visualization::streamSurfaces().seedCurve->toGPUData(resolution);
   updateBuffersAndDraw(data);
}

void SeedCurveEngine::setColorMapClampingTo(bool UNUSED(clampingOn))
{
   AbstractEngine::setColorMapClampingTo(false);
}

void SeedCurveEngine::setColorMapValueRange(float UNUSED(min), float UNUSED(max))
{
   AbstractEngine::setColorMapValueRange(0.0, 1.0);
}
