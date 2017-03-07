#ifndef COLORMAPTAB_H
#define COLORMAPTAB_H

#include <QWidget>
#include <QColor>
#include <QColorDialog>

#include "colormaps/colormapfactory.h"
#include "settings/visualizationsettings.h"

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
   void scalarVariableChanged(Settings::Visualization::ScalarVariable variable);
   void valueRangeChanged(float minimum, float maximum);

public slots:
   void onValueRangeChanged(float minimum, float maximum);
   void onForceChanged(float force);

private slots:
   void on_clampingCheckBox_clicked(bool checked);
   void on_clampingMaximumSlider_valueChanged(float value);
   void on_clampingMinimumSlider_valueChanged(float value);
   void on_numColorsSlider_valueChanged(int value);
   void on_colormapSelector_currentIndexChanged(int index);
   void on_saturationSlider_valueChanged(float value);
   void on_variableSelector_currentIndexChanged(int index);

   void on_colorPickerButton_clicked();

private:
   Ui::ColorMapTab *ui;

   void setUItoDefaults();
   void setUpConnections();

   void clampingUISetDisabled(bool disabled);
};

#endif // COLORMAPTAB_H
