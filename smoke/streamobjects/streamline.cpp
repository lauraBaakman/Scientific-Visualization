#include "streamline.h"
#include <limits>

const double streamobject::Line::minimalEdgeSize = std::numeric_limits<double>::min();

streamobject::Line::Line(QVector3D seedPoint, float textureCoordinate, float alpha) :
   shapes::PolyLine(seedPoint)
{
   this->textureCoordinates.append(textureCoordinate);
   this->alphaValues.append(alpha);
}

streamobject::Line::Line(QPointF seedPoint, float textureCoordinate, float alpha) :
   shapes::PolyLine(QVector3D(seedPoint))
{
   this->textureCoordinates.append(textureCoordinate);
   this->alphaValues.append(alpha);
}

streamobject::Line::Line() :
   shapes::PolyLine()
{}

GPUData streamobject::Line::toGPUData() const
{
   GPUData data(drawMode);

   QVector3D normal = QVector3D(0.0, 0.0, 1.0);

   if (this->numVertices() <= 1) return data;

   for (int current = 0, next = 1; next < this->vertices.length(); current++, next++)
   {
      data.addElement(vertices[current], normal, textureCoordinates[current], alphaValues[current]);
      data.addElement(vertices[next], normal, textureCoordinates[next], alphaValues[next]);
   }
   return data;
}

int streamobject::Line::numVertices() const
{
   return this->vertices.length();
}

int streamobject::Line::getLength() const
{
   return shapes::PolyLine::getLength();
}

bool streamobject::Line::isEdgeAllowed(QVector3D vertex)
{
   if (this->vertices.isEmpty()) return true;

   QVector3D newEdge = vertex - this->vertices.last();
   return newEdge.length() > minimalEdgeSize;
}

void streamobject::Line::addVertex(QVector3D vertex, float textureCoordinate, float alpha)
{
   if (!isEdgeAllowed(vertex)) return;

   shapes::PolyLine::addVertex(vertex);
   textureCoordinates.append(textureCoordinate);
   alphaValues.append(alpha);
}

bool streamobject::Line::hasNoVertices()
{
   return this->numVertices() == 0;
}
