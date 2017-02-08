#include "canvas.h"

Canvas::Canvas(QWidget* parent) :
    QOpenGLWidget(parent)
{
    qDebug() << "Canvas" << &endl;

    this->vertices = QVector<QVector3D>();
    this->vertices.append(QVector3D(-0.8f, -0.8f, 0.0f));
    this->vertices.append(QVector3D(0.8f, -0.8f, 0.0f));
    this->vertices.append(QVector3D(0.0f, 0.8f, 0.0f));

    this->colors = QVector<QVector3D>();
    this->colors.append(QVector3D(1.0f, 0.0f, 0.0f));
    this->colors.append(QVector3D(0.0f, 1.0f, 0.0f));
    this->colors.append(QVector3D(0.0f, 0.0f, 1.0f));
}

Canvas::~Canvas()
{
    this->vertexBuffer->destroy();
    this->indexBuffer->destroy();
    this->vao.destroy();
    delete this->shaderProgram;
}

void Canvas::initializeGL()
{
    qDebug() << "initializeGL()" << &endl;

    initializeOpenGLFunctions();

    glEnable(GL_DEPTH_TEST);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    initializeShaders();
    initializeBuffers();
}

bool Canvas::isAllocated(QOpenGLBuffer *buffer)
{
    qDebug() << "isAllocated" << &endl;
    return buffer->size() != 0;
}

void Canvas::initializeShaders()
{
    qDebug() << "initializeShaders" << &endl;
    this->shaderProgram = new QOpenGLShaderProgram();
    this->shaderProgram->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/shaders/shaders/vertex.glsl");
    this->shaderProgram->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/shaders/shaders/fragment.glsl");
    this->shaderProgram->link();
}

void Canvas::initializeBuffers()
{
    qDebug() << "initializeBuffers" << &endl;

    this->vao.create();
    this->vao.bind();

    //Init vertex buffer
    this->vertexBuffer = new QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
    this->vertexBuffer->setUsagePattern(QOpenGLBuffer::DynamicDraw);
    this->vertexBuffer->create();
    this->vertexBuffer->bind();

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    //Init color buffer
    this->colorBuffer= new QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
    this->colorBuffer->setUsagePattern(QOpenGLBuffer::DynamicDraw);
    this->colorBuffer->create();
    this->colorBuffer->bind();

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);

    this->vao.release();

    //Fill buffers
    updateBuffer(this->vertexBuffer, this->vertices);
    updateBuffer(this->colorBuffer, this->colors);
}

void Canvas::updateBuffer(QOpenGLBuffer *buffer, QVector<QVector3D> data)
{
    qDebug() << "updateBuffer" << &endl;

    buffer->bind();
    buffer->allocate(data.data(), data.size() * sizeof(data[0]));
    buffer->release();
}

void Canvas::paintGL()
{
//    glClear(GL_COLOR_BUFFER_BIT);

    if (!isAllocated(this->vertexBuffer)) {
        qDebug() << "not allocated" << &endl;
        return;
    }

    this->shaderProgram->bind();
    this->vao.bind();

    //Should be placed in correct spot
    setUniforms();

    updateTransformationMatrix();

    glDrawArrays(GL_TRIANGLES, 0, 3 );

    this->vao.release();
    this->shaderProgram->release();
}

void Canvas::constructModelViewProjectionMatrix()
{
    qDebug() << "constructModelViewProjectionMatrix" << &endl;

    this->mvpMatrix.setToIdentity();
}

void Canvas::updateTransformationMatrix()
{
    qDebug() << "updateTransformationMatrix" << &endl;

    constructModelViewProjectionMatrix();
    this->shaderProgram->setUniformValue("mvpMatrix", this->mvpMatrix);
}

void Canvas::setUniforms()
{
    qDebug() << "setUniforms() does not do anything." << &endl;
}

