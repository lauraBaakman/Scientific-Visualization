#include "smokeslicesengine.h"
#include "grid/utilities/smokebuilder.h"

SmokeSlicesEngine::SmokeSlicesEngine(SimulationGrid *grid) :
   AbstractSliceEngine(AbstractEngine::lightModel::noLight,
                       Settings::engines::EnginesTypes::smokeSlices),
   simulation(grid)
{
   connectToSettings();
}

void SmokeSlicesEngine::updateCache()
{
   std::logic_error("SmokeSlicesEngine::updateCache() not yet implemented");
}

void SmokeSlicesEngine::draw()
{
   SmokeBuilder builder = SmokeBuilder(this->simulation, colorMap->textureGetter);
   GPUData data = builder.getGPUData();
   updateBuffersAndDraw(data);
}

void SmokeSlicesEngine::connectToSettings()
{
   qDebug() << "SmokeSlicesEngine::connectToSettings";
}
