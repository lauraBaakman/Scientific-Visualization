#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <view/canvas.h>
#include "simulation/simulation.h"
#include "colormaplegend.h"
#include "view/simulationtab.h"
#include "view/colormaptab.h"
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

private:
    Ui::MainWindow *ui;

    Canvas *canvas;
    Simulation *simulation;
    ColorMapLegend *colorMapLegend;
    SimulationSettingPane *simulationTab;
    ColorMapTab *colorMapTab;
    KeyboardHandler* keyboardHandler;

    void setUpConnections();

    void connectCanvasAndSimulation();
    void connectCanvasAndSettings();
    void connectCanvasAndColorMapTab();

    void connectColorMapLegendAndSettings();

    void connectSimulationTabAndSettings();
    void connectSimulationTabAndSimulation();

    void connectColorMapTabAndColorMapLegend();
    void connectColorMapTabAndSettings();
};

#endif // MAINWINDOW_H
