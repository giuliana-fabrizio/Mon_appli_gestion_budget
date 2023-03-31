#include "../Fichiers_hpp/accueil_view.hpp"


AccueilView::AccueilView(Utilisateur *user) {
    this->user = user;

    labelDateBudget = new QLabel("Début : - Fin : " /* + user->getHistoriqueBudget().size()-1].date_debut.toString() */ /* + user->getHistoriqueBudget().size()-1].date_fin.toString() */);
    labelRevenu = new QLabel(QString::fromStdString(Data::composants_budget[0]));
    labelFixes = new QLabel(QString::fromStdString(Data::composants_budget[1]));
    labelVariables = new QLabel(QString::fromStdString(Data::composants_budget[2]));
    labelAutres = new QLabel(QString::fromStdString(Data::composants_budget[3]));

    pgBarDepense = new QProgressBar();

    valeurs_depenses_fixes = new QPieSeries();
    valeurs_depenses_variables = new QPieSeries();
    valeurs_autres_depenses = new QPieSeries();

    chart_depenses_fixes = new QChart();
    chart_depenses_variables = new QChart();
    chart_autres_depenses = new QChart();

    chartView_depenses_fixes = new QChartView(chart_depenses_fixes);
    chartView_depenses_variables = new QChartView(chart_depenses_variables);
    chartView_autres_depenses = new QChartView(chart_autres_depenses);

    tableWidget_revenus = new QTableWidget(5, 2);
    tableWidget_depenses_fixes = new QTableWidget(6, 3);
    tableWidget_depenses_variables = new QTableWidget(3, 3);
    tableWidget_autres_depenses = new QTableWidget(2, 3);

    frame = new QFrame();

    hBox_revenus = new QHBoxLayout();
    hBox_depenses_fixes = new QHBoxLayout();
    hBox_depenses_variables = new QHBoxLayout();
    hBox_autres_depenses = new QHBoxLayout();

    layout = new QGridLayout(frame);

    init();
    setStyle();
    addToWindow();
}

void AccueilView::init() {
    int cpt = 0;
    double montant = 0, total_depense = 0, total_revenu = 0;

    if ((int) user->getHistoriqueBudget().size() >= 1) {

        // ====================================================================================================== graph autres_depenses
        for (Enveloppe enveloppe : user->getLastBudget().depenses_fixes) {
            montant = 0;

            for (Depense depense : enveloppe.list_depense) montant += depense.montant_depense;
            total_depense += montant;
            valeurs_depenses_fixes->append(QString::fromStdString(enveloppe.libelle_enveloppe), montant);

            QLabel *labelMontantDepense = new QLabel(QString::fromStdString(std::to_string(montant)));

            if (montant > enveloppe.budget_prevu)
                labelMontantDepense->setStyleSheet("color: red;");

            tableWidget_depenses_fixes->setCellWidget(cpt, 0, new QLabel(QString::fromStdString(enveloppe.libelle_enveloppe)));
            tableWidget_depenses_fixes->setCellWidget(cpt, 1, labelMontantDepense);
            tableWidget_depenses_fixes->setCellWidget(cpt, 2, new QLabel(QString::fromStdString(std::to_string(enveloppe.budget_prevu))));

            cpt += 1;
        }

        // ====================================================================================================== graph depenses_variables
        cpt = 0;
        for (Enveloppe enveloppe : user->getLastBudget().depenses_variables) {
            montant = 0;

            for (Depense depense : enveloppe.list_depense) montant += depense.montant_depense;
            total_depense += montant;
            valeurs_depenses_variables->append(QString::fromStdString(enveloppe.libelle_enveloppe), montant);

            QLabel *labelMontantDepense = new QLabel(QString::fromStdString(std::to_string(montant)));

            if (montant > enveloppe.budget_prevu)
                labelMontantDepense->setStyleSheet("color: red;");

            tableWidget_depenses_variables->setCellWidget(cpt, 0, new QLabel(QString::fromStdString(enveloppe.libelle_enveloppe)));
            tableWidget_depenses_variables->setCellWidget(cpt, 1, labelMontantDepense);
            tableWidget_depenses_variables->setCellWidget(cpt, 2, new QLabel(QString::fromStdString(std::to_string(enveloppe.budget_prevu))));

            cpt += 1;
        }

        // ====================================================================================================== graph autres_depenses
        cpt = 0;
        for (Enveloppe enveloppe : user->getLastBudget().autres_depenses) {
            montant = 0;

            for (Depense depense : enveloppe.list_depense) montant += depense.montant_depense;
            total_depense += montant;
            valeurs_autres_depenses->append(QString::fromStdString(enveloppe.libelle_enveloppe), montant);

            QLabel *labelMontantDepense = new QLabel(QString::fromStdString(std::to_string(montant)));

            if (montant > enveloppe.budget_prevu)
                labelMontantDepense->setStyleSheet("color: red;");

            tableWidget_autres_depenses->setCellWidget(cpt, 0, new QLabel(QString::fromStdString(enveloppe.libelle_enveloppe)));
            tableWidget_autres_depenses->setCellWidget(cpt, 1, labelMontantDepense);
            tableWidget_autres_depenses->setCellWidget(cpt, 2, new QLabel(QString::fromStdString(std::to_string(enveloppe.budget_prevu))));

            cpt += 1;
        }

        // ====================================================================================================== a propos des revenus
        cpt = 0;
        for (Revenu revenu : user->getLastBudget().list_revenus) {
            total_revenu += revenu.montant_revenu;

            tableWidget_revenus->setCellWidget(cpt, 0, new QLabel(QString::fromStdString(revenu.libelle_revenu)));
            tableWidget_revenus->setCellWidget(cpt, 1, new QLabel(QString::fromStdString(std::to_string(revenu.montant_revenu))));

            cpt += 1;
        }

        pgBarDepense->setValue(total_depense * 100 / total_revenu);
    }
}

void AccueilView::setStyle() {
    labelRevenu->setStyleSheet("QLabel { font: 12pt; }");
    labelFixes->setStyleSheet("QLabel { font: 12pt; }");
    labelVariables->setStyleSheet("QLabel { font: 12pt; }");
    labelAutres->setStyleSheet("QLabel { font: 12pt; }");

    for (int i = 0; i < 3; i += 1) {
        tableWidget_revenus->setColumnWidth(i, 300);
        tableWidget_depenses_fixes->setColumnWidth(i, 300);
        tableWidget_depenses_variables->setColumnWidth(i, 300);
        tableWidget_autres_depenses->setColumnWidth(i, 300);
    }

    tableWidget_revenus->setStyleSheet("QTableWidget {border: none; gridline-color: white;}");
    tableWidget_depenses_fixes->setStyleSheet("QTableWidget {border: none; gridline-color: white;}");
    tableWidget_depenses_variables->setStyleSheet("QTableWidget {border: none; gridline-color: white;}");
    tableWidget_autres_depenses->setStyleSheet("QTableWidget {border: none; gridline-color: white;}");

    tableWidget_revenus->horizontalHeader()->setVisible(false);
    tableWidget_revenus->verticalHeader()->setVisible(false);
    tableWidget_depenses_fixes->horizontalHeader()->setVisible(false);
    tableWidget_depenses_fixes->verticalHeader()->setVisible(false);
    tableWidget_depenses_variables->horizontalHeader()->setVisible(false);
    tableWidget_depenses_variables->verticalHeader()->setVisible(false);
    tableWidget_autres_depenses->horizontalHeader()->setVisible(false);
    tableWidget_autres_depenses->verticalHeader()->setVisible(false);

    pgBarDepense->setFixedSize(300, 30);
    pgBarDepense->setStyleSheet(
        "QProgressBar {"
            "border: 1px solid gray;"
            "border-radius: 10px;"
            "text-align: center;"
        "}"
    );
}

void AccueilView::addToWindow() {

    chart_depenses_fixes->addSeries(valeurs_depenses_fixes);
    chart_depenses_variables->addSeries(valeurs_depenses_variables);
    chart_autres_depenses->addSeries(valeurs_autres_depenses);

    chart_depenses_fixes->setTitle("Détail de mes dépenses");
    chart_depenses_variables->setTitle("Détail de mes dépenses");
    chart_autres_depenses->setTitle("Détail de mes dépenses");

    hBox_revenus->addWidget(labelRevenu);
    hBox_revenus->addWidget(pgBarDepense);
    layout->addLayout(hBox_revenus, 0, 0);
    layout->addWidget(tableWidget_revenus, 1, 0);

    hBox_depenses_fixes->addWidget(labelFixes);
    hBox_depenses_fixes->addWidget(chartView_depenses_fixes);
    layout->addLayout(hBox_depenses_fixes, 2, 0);
    layout->addWidget(tableWidget_depenses_fixes, 3, 0);

    hBox_depenses_variables->addWidget(labelVariables);
    hBox_depenses_variables->addWidget(chartView_depenses_variables);
    layout->addLayout(hBox_depenses_variables, 0, 1);
    layout->addWidget(tableWidget_depenses_variables, 1, 1);

    hBox_autres_depenses->addWidget(labelAutres);
    hBox_autres_depenses->addWidget(chartView_autres_depenses);
    layout->addLayout(hBox_autres_depenses, 2, 1);
    layout->addWidget(tableWidget_autres_depenses, 3, 1);
}

void AccueilView::clearAll() {
    valeurs_depenses_fixes->clear();
    valeurs_depenses_variables->clear();
    valeurs_autres_depenses->clear();

    // chart_depenses_fixes->removeAllSeries();
    // chart_depenses_variables->removeAllSeries();
    // chart_autres_depenses->removeAllSeries();

    tableWidget_depenses_fixes->clearContents();
    tableWidget_depenses_variables->clearContents();
    tableWidget_autres_depenses->clearContents();
    tableWidget_revenus->clearContents();

    pgBarDepense->setValue(0);
}

QFrame* AccueilView::getFrame() {
    return frame;
}