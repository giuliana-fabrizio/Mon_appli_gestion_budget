#include "../Fichiers_hpp/accueil_view.hpp"

AccueilView::AccueilView(Model *model) {
    this->model = model;
    labelDateBudget = new QLabel("Début : - Fin : " /* + model->getUser()->getHistoriqueBudget().size()-1].date_debut.toString() */ /* + model->getUser()->getHistoriqueBudget().size()-1].date_fin.toString() */);
    pgBarDepense = new QProgressBar();
    valeurs = new QPieSeries;
    chart = new QChart;
    chartView = new QChartView(chart);
    frame = new QFrame();
    layout = new QVBoxLayout(frame);
    init();
    addToWindow();
}

void AccueilView::init() {
    double total = 0;
    for (Depense depense : model->getUser()->listerHistoriqueDepense(
        model->getUser()->getHistoriqueBudget()[model->getUser()->getHistoriqueBudget().size()-1].date_debut,
        model->getUser()->getHistoriqueBudget()[model->getUser()->getHistoriqueBudget().size()-1].date_fin
    )) {
            valeurs->append(QString::fromStdString(depense.category), depense.montant_depense);
            total += depense.montant_depense;
    }
    pgBarDepense->setValue(model->getUser()->getHistoriqueBudget()[model->getUser()->getHistoriqueBudget().size()-1].montant/total);
    chart->addSeries(valeurs);
    chart->setTitle("Détail de mes dépenses");
}

void AccueilView::setStyle() {
    // labelDateBudget->setStyleSheet("color: pink;");
    pgBarDepense->setFixedSize(250, 30);
    pgBarDepense->setStyleSheet(
        "QProgressBar {"
            "border: 1px solid gray;"
            "border-radius: 10px;"
            "text-align: center;"
        "}"
    );
    chartView->setFixedSize(800, 800);
}

void AccueilView::addToWindow() {
    layout->addWidget(labelDateBudget);
    layout->addWidget(pgBarDepense);
    layout->addWidget(chartView);
}

QFrame* AccueilView::getFrame() {
    return frame;
}