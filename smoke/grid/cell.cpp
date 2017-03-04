#include "cell.h"
#include "utilities.h"

Cell::Cell()
{}

Cell::~Cell()
{}

StructuredCell::StructuredCell(Vertex *upperLeft, Vertex *upperRight, Vertex *lowerLeft, Vertex *lowerRight):
    Cell(),
    upperLeft(upperLeft),
    upperRight(upperRight),
    lowerLeft(lowerLeft),
    lowerRight(lowerRight)
{}

Triangulation StructuredCell::triangulate()
{
    Triangulation triangulation(6);
    triangulation.extend(lowerLeftTriangle());
    triangulation.extend(upperRightTriangle());
    return triangulation;
}

float StructuredCell::interpolateScalar(QVector3D position, Vertex::scalarGetter getter)
{
    QVector3D normalizedPosition = normalizePosition(position);
    return interpolateBilinearly(normalizedPosition,
                          (upperLeft->*getter)(),
                          (upperRight->*getter)(),
                          (lowerLeft->*getter)(),
                          (lowerRight->*getter)());
}

QVector3D StructuredCell::interpolate3DVector(QVector3D position, Vertex::vectorGetter getter)
{
    qDebug() << "StructuredCell::interpolate3DVector not yet implemented";
}

QSizeF StructuredCell::getSize() const
{
    float width = upperRight->getPosition()->x() - upperLeft->getPosition()->x();
    float height = lowerLeft->getPosition()->y() - upperLeft->getPosition()->y();
    return QSizeF(width, height);
}

QVector3D StructuredCell::normalizePosition(const QVector3D position)
{
    float x = (position.x() - upperLeft->getPosition()->x()) / getSize().width();
    float y = (position.y() - upperLeft->getPosition()->y()) / getSize().height();
    return QVector3D(x, y, 0.0);
}

Triangulation StructuredCell::lowerLeftTriangle()
{
    Triangulation triangulation(3);
    triangulation.addVertex(upperLeft);
    triangulation.addVertex(lowerLeft);
    triangulation.addVertex(lowerRight);
    return triangulation;
}

Triangulation StructuredCell::upperRightTriangle()
{
    Triangulation triangulation(3);
    triangulation.addVertex(upperLeft);
    triangulation.addVertex(lowerRight);
    triangulation.addVertex(upperRight);
    return triangulation;
}

QDebug operator<<(QDebug stream, const StructuredCell &cell)
{
    stream << "StructuredCell ["
           << " upperLeft: "    << *cell.upperLeft->getPosition()
           << " upperRight: "    << *cell.upperRight->getPosition()
           << " lowerLeft: "    << *cell.lowerLeft->getPosition()
           << " lowerRight: "    << *cell.lowerRight->getPosition()
           << "]";
    return stream;
}

QDebug operator<<(QDebug stream, StructuredCell *cell)
{
    stream << *cell;
    return stream;
}
