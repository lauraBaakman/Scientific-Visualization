#ifndef SLICESTAB_H
#define SLICESTAB_H

#include <QWidget>

#include "settings/visualizationsettings.h"

namespace Ui {
    class SlicesTab;
}

class SlicesTab : public QWidget
{
   Q_OBJECT

   public:
      explicit SlicesTab(QWidget *parent = 0);
      ~SlicesTab();

   signals:
      void numberOfSlicesChanged(int newNumberOfSlices);

      void globalAlphaChanged(double newGlobalAlpha);

      void numberOfStatesPerSliceChanged(int newNumberOfStates);

      void combinationMethodChanged(Settings::visualization::Slices::CombinationMethod newMethod);

   public slots:

   private slots:

      void on_globalAlphaSpinBox_valueChanged(double arg1);

      void on_numberOfSlicesSpinBox_valueChanged(int arg1);

      void on_numberOfStatesSpinBox_valueChanged(int value);

      void on_combinationmethodComboBox_currentIndexChanged(int index);

   private:
      Ui::SlicesTab *ui;

      void connectToSettings();

      void initializeUI();

      void setUItoDefaults();
};

#endif // SLICESTAB_H
