#ifndef SIMULATIONDATA_H
#define SIMULATIONDATA_H

#include "rfftw.h"

class SimulationData
{
   public:
      SimulationData(int numSimulationVertices);

      fftw_real *vx, *vy;         //(vx,vy)   = velocity field at the current moment
      fftw_real *fx, *fy;         //(fx,fy)   = user-controlled simulation forces, steered with the mouse
      fftw_real *rho;             //smoke density at the current (rho) and previous (rho0) moment
};

#endif // SIMULATIONDATA_H
