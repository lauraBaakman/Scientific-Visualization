#include "airplane.h"
#include "utilities/vector.h"
#include "utilities/range.h"
#include "settings/visualizationsettings.h"

#include <QDebug>

#define SIN60    0.86602540378

const double Airplane::AirplaneBuilder::maxCellRatio = 2;

Airplane::Airplane(QVector3D position, QVector3D direction, float scalar) :
   AbstractGlyph(scalar)
{
   AirplaneBuilder builder = AirplaneBuilder(position, direction, computeNormalizedMagnitude(direction));

   addVertices(builder.getVertices(), builder.getNormals());
}

Airplane::AirplaneBuilder::AirplaneBuilder(QVector3D position, QVector3D direction, float normalizedMagnitude) :
   direction(direction.normalized()),
   orthogonalDirection(computeOrthogonalVector(direction)),
   position(position),
    normalizedMagnitude(normalizedMagnitude),
   mesh(4, 2)
{
   determineSizeRange();

   mesh::Vertex *tail = mesh.addVertex(computeBase());
   mesh::Vertex *nose = mesh.addVertex(computeNose());
   mesh::Vertex *rightWing = mesh.addVertex(computeRightWing());
   mesh::Vertex *leftWing = mesh.addVertex(computeLeftWing());

   mesh.addTriangle(leftWing, nose, tail);
   mesh.addTriangle(tail, nose, rightWing);
}

QVector<QVector3D> Airplane::AirplaneBuilder::getNormals()
{
   QVector<QVector3D> normals;
   for (auto triangle : mesh.getTriangles())
   {
      normals.append(triangle->getVertexNormals());
   }
   return normals;
}

QVector<QVector3D> Airplane::AirplaneBuilder::getVertices()
{
   QVector<QVector3D> vertices;
   for (auto triangle : mesh.getTriangles())
   {
      vertices.append(triangle->getVertexPositions());
   }
   return vertices;
}

float Airplane::AirplaneBuilder::baseEdgeLength()
{
   return this->baseSize;
}

QVector3D Airplane::AirplaneBuilder::computeNose()
{
   float height = this->baseEdgeLength() * SIN60;

   return this->position + height * this->direction * Settings::visualization::glyphs().scale * this->normalizedMagnitude;
}

QVector3D Airplane::AirplaneBuilder::computeBase()
{
   return this->position + this->normalizedMagnitude * this->baseSize * this->direction * Settings::visualization::glyphs().scale * this->normalizedMagnitude;
}

QVector3D Airplane::AirplaneBuilder::computeLeftWing()
{
   return this->computeWing(-1);
}

QVector3D Airplane::AirplaneBuilder::computeRightWing()
{
   return this->computeWing(+1);
}

QVector3D Airplane::AirplaneBuilder::computeWing(int direction)
{
   float scalingFactor = Settings::visualization::glyphs().scale * this->normalizedMagnitude;

   return position + 0.5 * baseEdgeLength() * orthogonalDirection * direction * scalingFactor + QVector3D(0.0, 0.0, scalingFactor);
}

void Airplane::AirplaneBuilder::determineSizeRange()
{
   QSizeF cellSize = Settings::visualization::glyphs().cellSize;

   this->baseSize = maxCellRatio * qMax(cellSize.width(), cellSize.height());
}