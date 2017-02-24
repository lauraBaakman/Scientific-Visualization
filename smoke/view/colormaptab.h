#ifndef COLORMAPTAB_H
#define COLORMAPTAB_H

#include <QWidget>
#include "colormaps/colormapfactory.h"

namespace Ui {
class ColorMapTab;
}

class ColorMapTab : public QWidget
{
    Q_OBJECT

public:
    explicit ColorMapTab(QWidget *parent = 0);
    ~ColorMapTab();

signals:
    void setClamping(bool clampingOn);
    void setClampingRange(float minimum, float maximum);
    void colorMapChanged(AbstractColorMap colormap);

public slots:

private slots:
    void on_clampingCheckBox_clicked(bool checked);
    void on_clampingMaximumSlider_valueChanged(float value);
    void on_clampingMinimumSlider_valueChanged(float value);

    void on_colormapSelector_currentIndexChanged(int index);

private:
    Ui::ColorMapTab *ui;

    void setUItoDefaults();
    void setUpConnections();

    void clampingUISetDisabled(bool disabled);
};

#endif // COLORMAPTAB_H
