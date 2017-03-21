#include "settings.h"
#include "settings/simulationsettings.h"
#include "settings/canvassettings.h"
#include "settings/visualizationsettings.h"

const Settings::Simulation& Settings::simulation()
{
   return Simulation::instance();
}

const Settings::Canvas& Settings::canvas()
{
   return Canvas::instance();
}

const Settings::visualization::Smoke& Settings::visualization::smoke()
{
   return Settings::visualization::Smoke::instance();
}

const Settings::visualization::Glyphs& Settings::visualization::glyphs()
{
   return Settings::visualization::Glyphs::instance();
}

QStringList Settings::visualization::getScalarVariableNames()
{
   QStringList scalarVariableNames;

   scalarVariableNames << "Fluid density"
                       << "Fluid velocity magnitude"
                       << "Force field magnitude";
   return scalarVariableNames;
}

QStringList Settings::visualization::getVectorVariableNames()
{
   QStringList vectorVariableNames;

   vectorVariableNames << "Fluid velocity"
                       << "Force"
                       << "Fluid density gradient"
                       << "Fluid velocity magnitude gradient";

      return vectorVariableNames;
}
