#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <view/canvas.h>
#include "simulation/simulation.h"
#include "settings/settings.h"
#include "colormaplegend.h"
#include "view/simulationsettingpane.h"

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
    Settings *settings;
    ColorMapLegend *colorMapLegend;
    SimulationSettingPane *simulationSettingPane;

    void connectCanvasAndSimulation();
    void connectSettingsAndCanvas();
    void connectSimulationAndColorMapLegend();
    void connectSettingAndSimulationSettingPane();
};

#endif // MAINWINDOW_H
