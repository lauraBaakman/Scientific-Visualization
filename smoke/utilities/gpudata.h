#ifndef GPUDATA_H
#define GPUDATA_H

#include <QVector>
#include <QVector3D>

#include <QObject>
#ifdef __APPLE__
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif

class GPUData
{
   public:
      GPUData(GLint drawMode);

      void extend(GPUData data);

      int numElements() const ;

      GLint getDrawMode() const;

      void addElement(QVector3D vertex, QVector3D normal, float textureCoordinate);

      void addElements(QVector<QVector3D> vertices, QVector3D normal, float textureCoordinate);

      void addElements(QVector<QVector3D> vertices, QVector<QVector3D> normals, float textureCoordinate);

      void addElements(QVector<QVector3D> vertices, QVector<QVector3D> normals, QVector<float> textureCoordinates);

      void addElements(QVector<QVector3D> vertices, QVector3D normal, QVector<float> textureCoordinates);

      QVector<QVector3D> getVertices() const;

      QVector<float> getTextureCoordinates() const;

      QVector<QVector3D> getNormals() const;

   private:
      GLint drawMode;

      QVector<QVector3D> vertices;
      QVector<float> textureCoordinates;
      QVector<QVector3D> normals;

      void assertDrawModesAreEqual(GLint thisMode, GLint otherMode);
};

#endif // GPUDATA_H
