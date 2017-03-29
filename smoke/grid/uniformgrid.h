#ifndef UNIFORMGRID_H
#define UNIFORMGRID_H

#include "grid/grid.h"
#include <QSizeF>
#include "simulation/simulationrealization.h"
#include "streamobjects/streamline.h"
#include <QRectF>

class UniformGrid : public Grid
{
   public:
      QVector<QVector3D> const& getVertexPositions() const;

      virtual void changeGridArea(QSizeF newArea);

      virtual void changeGridArea(QSizeF newArea, QSizeF padding);

      static UniformGrid *createSimulationGrid(int dimension, QSizeF size, SimulationRealization *simulation);

      static UniformGrid *createVisualizationGrid(int dimension, QSizeF size, UniformGrid *simulationGrid);

      QSizeF const& getPadding() const;

      QSizeF getCellSize() const;

      int getDimension() const;

      bool inGridArea(QVector3D position) const;

      streamobject::Line computeStreamLine(QVector3D seedPoint,
                                           Vertex::scalarGetter textureCoordinateGetter,
                                           Vertex::vectorGetter vectorGetter);

      Triangulation getTriangulation();

   protected:
      UniformGrid(int dimension, QSizeF areaSize, bool hasPadding);
      UniformGrid(int dimension, QSizeF areaSize, QSizeF padding);
      UniformGrid(int dimension, QSizeF cellSize, bool hasPadding, QSizeF padding);

      static void createVertices(UniformGrid *grid, SimulationRealization *simulation);

      static void createVertices(UniformGrid *visualizationGrid, UniformGrid *simulationGrid);

      static void createCells(UniformGrid *grid);

      static void createTriangulation(UniformGrid *grid);

      virtual QVector3D computeVertexPosition(int i, int j);

      QVector3D boundToGrid(QVector3D position);

      int to1Dindex(int x, int y) const;
      int to1Dindex(Index2D idx) const;

      int dimension;
      QSizeF cellSize;
      QSizeF padding;
      QRectF coveredArea;

      Triangulation triangulation;

   private:

      void recomputeVertexPositions(QSizeF oldCellSize, QSizeF newCellSize);

      QSizeF computeCellSize(QSizeF area);

      QSizeF computeCellSize(QSizeF area, QSizeF padding);

      QRectF computeCoveredArea(QSizeF padding, QSizeF cellSize);

      StructuredCell *findCellContaining(QVector3D position);

      bool inGridArea(QVector3D position);

      Vertex *getVertexAt(int x, int y) const;

      QPair<int, int> findUpperLeftOfContainingCell(QVector3D position);

      class StreamLineBuilder;
};

#endif // UNIFORMGRID_H
