#ifndef ACCUEIL_VIEW_HPP
#define ACCUEIL_VIEW_HPP

#include <QtCharts>
#include <QtWidgets>

#include "model.hpp"

class AccueilView {

    public:
        AccueilView(Model *model);
        void init();
        void setStyle();
        void addToWindow();
        QFrame* getFrame();

    private:
        Model *model;
        QLabel *labelDateBudget;
        QProgressBar *pgBarDepense;
        QPieSeries *valeurs;
        QChart *chart;
        QChartView *chartView;
        QFrame *frame;
        QVBoxLayout *layout;
};

#endif