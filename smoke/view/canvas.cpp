#include "canvas.h"
#include <QMouseEvent>
#include <QDebug>
#include <QImage>
#include "settings/simulationsettings.h"


Canvas::Canvas(QWidget* parent) :
    QOpenGLWidget(parent),
    timer(new QTimer(this))
{
    this->initiateIdleLoop();
}

Canvas::~Canvas()
{
    delete this->timer;
}

void Canvas::initiateIdleLoop()
{
   this->timer->start();
    connect(timer, SIGNAL(timeout()), this, SLOT(idleLoop()));
}

void Canvas::connectThisAndEngine(AbstractEngine* engine)
{
    connect(this, SIGNAL(windowResized(int,int)),
            engine, SLOT(onWindowChanged(int,int)));
}

void Canvas::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);

    this->vectorEngine = new VectorEngine();
    this->smokeEngine = new SmokeEngine();

    emit openGlReady();


    connectThisAndEngine(this->vectorEngine);
    connectThisAndEngine(this->smokeEngine);
}


void Canvas::idleLoop()
{
    if(!Settings::simulation().frozen)
    {
        this->simulation->step();
    }
    update();
}

void Canvas::setSimulation(Simulation *simulation)
{
    this->simulation = simulation;
}

void Canvas::mouseMoveEvent(QMouseEvent *event)
{
    if(!Settings::simulation().frozen){
        QPointF mousePosition = event->localPos();
        emit mouseMoved(QPoint(mousePosition.x(), mousePosition.y()));
    }
}

void Canvas::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);   
    smokeEngine->draw(this->simulation);
//    vectorEngine->draw(this->simulation);

}

void Canvas::resizeGL(int width, int height)
{
    glViewport(0.0f, 0.0f, (GLfloat) width, (GLfloat) height);

    emit windowResized(width, height);
}
