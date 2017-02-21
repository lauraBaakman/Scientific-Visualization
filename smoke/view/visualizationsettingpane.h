#ifndef VISUALIZATIONSETTINGSPANE_H
#define VISUALIZATIONSETTINGSPANE_H

#include <QWidget>

namespace Ui {
class VisualizationSettingsPane;
}

class VisualizationSettingPane : public QWidget
{
    Q_OBJECT

public:
    explicit VisualizationSettingPane(QWidget *parent = 0);
    ~VisualizationSettingPane();

signals:
    void setClamping(bool clampingOn);
    void setClampingRange(float minimum, float maximum);

private slots:
    void on_clampingCheckBox_clicked(bool checked);

    void on_clampingMinimumSlider_sliderMoved(int intValue);

    void on_clampingMaximumSlider_sliderMoved(int position);

private:
    Ui::VisualizationSettingsPane *ui;

    void setUItoDefaults();

};

#endif // VISUALIZATIONSETTINGSPANE_H
