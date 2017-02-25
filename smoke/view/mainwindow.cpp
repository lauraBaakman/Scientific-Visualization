#include "view/mainwindow.h"
#include "ui_mainwindow.h"

#include "settings/settings.h"
#include "settings/simulations.h"
#include "settings/canvass.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->simulation = new Simulation();

    this->canvas = ui->openGLWidget;
    this->canvas->setSimulation(this->simulation);
    this->colorMapLegend = ui->colorMapLegend;
    this->simulationTab = ui->simulationTab;
    this->colorMapTab = ui->colormapTab;

    connectCanvasAndSimulation();
    connectCanvasAndSettings();
    connectCanvasAndColorMapTab();

    connectSimulationTabAndSettings();

    connectColorMapTabAndColorMapLegend();
    connectColorMapTabAndSettings();

    connectColorMapLegendAndSettings();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete this->simulation;
}

void MainWindow::connectCanvasAndSimulation()
{
    connect(this->canvas, SIGNAL(mouseMoved(QPoint)),
            this->simulation, SLOT(onMouseMoved(QPoint)));
}

void MainWindow::connectCanvasAndSettings()
{
    connect(&Settings::simulation(),SIGNAL(valueRangeChanged(float,float)),
            this->canvas, SLOT(onValueRangeChanged(float,float)));

    connect(this->canvas, SIGNAL(windowResized(int, int)),
            &Settings::canvas(), SLOT(onWindowResized(int, int)));

    connect(this->canvas, SIGNAL(windowResized(int, int)),
            &Settings::simulation(), SLOT(onWindowResized(int, int)));
}

void MainWindow::connectColorMapLegendAndSettings()
{
    connect(&Settings::simulation(), SIGNAL(valueRangeChanged(float,float)),
            this->colorMapLegend, SLOT(onValueRangeChanged(float,float)));
}

void MainWindow::connectSimulationTabAndSettings()
{
    connect(this->simulationTab, SIGNAL(forceChanged(float)),
            &Settings::simulation(), SLOT(onForceChanged(float)));
}

void MainWindow::connectCanvasAndColorMapTab()
{
    connect(this->colorMapTab, SIGNAL(setClamping(bool)),
            this->canvas, SLOT(onSetClamping(bool)));
    connect(this->colorMapTab, SIGNAL(setClampingRange(float,float)),
            this->canvas, SLOT(onsetClampingRange(float,float)));
    connect(this->colorMapTab, SIGNAL(colorMapChanged(AbstractColorMap)),
            this->canvas, SLOT(onColorMapChanged(AbstractColorMap)));
}

void MainWindow::connectColorMapTabAndColorMapLegend()
{
    connect(this->colorMapTab, SIGNAL(setClampingRange(float,float)),
            this->colorMapLegend, SLOT(onClampRangeChanged(float,float)));
    connect(this->colorMapTab, SIGNAL(colorMapChanged(AbstractColorMap)),
            this->colorMapLegend, SLOT(onColorMapChanged(AbstractColorMap)));
}

void MainWindow::connectColorMapTabAndSettings()
{
    qDebug() << "void MainWindow::connectColorMapTabAndSettings()";
    connect(this->colorMapTab, SIGNAL(scalarVariableChanged(Settings::Visualization::ScalarVariable)),
            &Settings::visualization(), SLOT(onScalarVariableChanged(Settings::Visualization::ScalarVariable)));
}



