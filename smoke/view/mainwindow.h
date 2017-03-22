#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <view/canvas.h>
#include "simulation/simulation.h"
#include "colormaplegend.h"
#include "view/simulationtab.h"
#include "view/colormaptab.h"
#include "view/glyphstab.h"
#include "view/streamlinestab.h"
#include "keyboardhandler.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
   Q_OBJECT

   public:
      explicit MainWindow(QWidget *parent = 0);
      ~MainWindow();

      KeyboardHandler *keyboardHandler;

   public slots:
      void onOpenGLReady();

   private:
      Ui::MainWindow *ui;

      Canvas *canvas;
      Simulation *simulation;
      SimulationSettingPane *simulationTab;

      ColorMapTab *smokeColorMapTab;

      GlyphsTab *glyphsTab;
      StreamLinesTab *streamLinesTab;

      void setUpConnections();

      //Canvas
      void connectCanvasAndThis();

      void connectCanvasAndSimulation();

      void connectCanvasAndSettings();

      void connectCanvasAndTabs();


      //Engines - Vector
      void connectVectorEngineAndGlyphTab();

      void connectVectorEngineAndSettings();


      void connectSmokeEngineAndSettings();


      void connectStreamLineEngineAndStreamLinesTab();

      void connectStreamLineEngineAndSettings();


      void connectEngineAndSettings(AbstractEngine *currentEngine);

      void connectEngineAndColorMapTab(AbstractEngine *currentEngine, ColorMapTab *colormap);


      //Tabs
      void connectSimulationTabAndSettings();

      void connectSimulationTabAndSimulation();

      void connectGlyphTabAndSettings();

      void connectSmokeTabAndSettings();

      void connectStreamLinesTabAndSettings();


      //Other IO
      void connectKeyBoardHandlerAndSimulation();
};

#endif // MAINWINDOW_H
