#ifndef SIMULATIONSETTINGPANE_H
#define SIMULATIONSETTINGPANE_H

#include <QWidget>

namespace Ui {
class SimulationSettingPane;
}

class SimulationSettingPane : public QWidget
{
    Q_OBJECT

public:
    explicit SimulationSettingPane(QWidget *parent = 0);
    ~SimulationSettingPane();
    void emitDefaults();

signals:
    void forceChanged(float force);

private slots:
    void on_forceSlider_valueChanged(int value);

private:
    Ui::SimulationSettingPane *ui;
};

#endif // SIMULATIONSETTINGPANE_H
