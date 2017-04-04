#ifndef TRANSLUCENTGLYPHBUILDER_H
#define TRANSLUCENTGLYPHBUILDER_H

#include "abstracttranslucentbuilder.h"
#include "glyphbuilder.h"

class TranslucentGlyphBuilder :
   private AbstractTranslucentBuilder,
   public GlyphBuilder
{
   public:
      TranslucentGlyphBuilder(UniformGrid *grid,
                              Settings::sim::GlyphsType glyphThype,
                              Vertex::scalarGetter getTextureCoordinate,
                              Vertex::vectorGetter directionGetter,
                              Range magnitudeRange);

   protected:
      float computeAlpha(QVector3D vector) const;

   private:

      GPUData buildHedgeHog(Vertex *vertex) const;

      GPUData buildTriangle(Vertex *vertex) const;

      GPUData buildAirplane(Vertex *vertex) const;

      GPUData buildCone(Vertex *vertex) const;
};

#endif // TRANSLUCENTGLYPHBUILDER_H
