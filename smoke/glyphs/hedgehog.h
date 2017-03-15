#ifndef HEDGEHOG_H
#define HEDGEHOG_H

#include "glyphs/abstractglyph.h"

class HedgeHog : public AbstractGlyph
{
   public:
      HedgeHog();
      HedgeHog(QVector3D position, QVector3D direction, float scalar);

   private:
      QVector3D computeOffSet(QVector3D direction);

      QVector3D computeNormal(QVector3D direction);

      static const double cellRatio;
};

#endif // HEDGEHOG_H
