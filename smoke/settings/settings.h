#ifndef SETTINGSNS_H
#define SETTINGSNS_H

#include "colormaps/colormapfactory.h"
#include "QSize"

namespace Settings {
    class Simulation;
    const Simulation& simulation();

    class Canvas;
    const Canvas& canvas();

    namespace visualization {
        QStringList getScalarVariableNames();
        QStringList getVectorVariableNames();

        class ColorMap;

        class Smoke;
        const Smoke& smoke();

        class Glyphs;
        const Glyphs& glyphs();
    }

    namespace sim {
        enum Scalar
        {
           fluidDensity,
           fluidVelocityMagnitude,
           forceFieldMagnitude
        };

        enum Vector
        {
            fluidVelocity,
            force,
        };
    }

    namespace defaults {
        namespace simulation {
            static const float valueRangeMin = 0.0f;
            static const float valueRangeMax = 10.0f;

            static const int forceMin = 1;
            static const int forceMax = 100;
        }
        namespace visualization {
            namespace colormap {
                static const ColorMapFactory::colorMaps colormap = ColorMapFactory::colorMaps::rainbow;
                static const float clampMin = 0.0f;
                static const float clampMax = 1.0f;
                static const bool clampingOn = false;
                static const float clampEpsilon = 0.01;
                static const Settings::sim::Scalar scalar = Settings::sim::fluidDensity;

                static const int numColors = 256;
                static const int minNumColors = 2;
                static const int maxNumColors = 256;
                static const float saturation = 1.0f;
                static const float minSaturation = 0.0f;
                static const float maxSaturation = 1.0f;
            }

            namespace glyphs {
                static const QSize gridSize = QSize(10, 15);
                static const Settings::sim::Vector vector = Settings::sim::Vector::fluidVelocity;
            }
        }
    }
}

#endif // SETTINGSNS_H
