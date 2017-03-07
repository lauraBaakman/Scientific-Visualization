#ifndef VECTORENGINE_H
#define VECTORENGINE_H

#include <QObject>
#include "abstractengine.h"

class VectorEngine : public AbstractEngine {
   Q_OBJECT

public:

   VectorEngine(UniformGrid *simulationGrid);

   void draw(Simulation *simulation);

public slots:

   void onRecomputeVertexPositions(QSizeF cellSize);
   void onGridDimensionChanged(int width, int height);

private:

   int updateBuffers(Simulation *simulation);

   Grid *visualizationGrid;
};

#endif // VECTORENGINE_H
