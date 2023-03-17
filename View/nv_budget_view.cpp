#include "../Fichiers_hpp/nv_budget_view.hpp"


NvBudgetView::NvBudgetView() {
    labelPage = new QLabel("Définir un nouveau budget");
    labelDateDebut = new QLabel("Date de début :");
    labelDateFin = new QLabel("Date de fin :");
    labelPrevoir = new QLabel("Prevoyez vos enveloppe");
    // QLabel *labelAnnee = new QLabel(QString::number(annee_courante));

    comboBoxJourDebut = new QComboBox();
    comboBoxJourFin = new QComboBox();
    comboBoxMoisDebut = new QComboBox();
    comboBoxMoisFin = new QComboBox();

    validator = new QDoubleValidator();

    tableWidget_revenus = new QTableWidget(5, 2);
    tableWidget_depenses_fixes = new QTableWidget(Model::getDepensesFixesPredefinies().size(), 2);
    tableWidget_depenses_variables = new QTableWidget(Model::getDepensesVariablesPredefinies().size(), 2);
    tableWidget_autres_depenses = new QTableWidget(Model::getAutresDepensesPredefinies().size(), 2);

    btnValide = new QPushButton("Valider");
    frame = new QFrame();

    hBoxDateDebut = new QHBoxLayout();
    hBoxDateFin = new QHBoxLayout();
    hBoxTablesWidget = new QHBoxLayout();

    layout = new QGridLayout(frame);

    init();
    setStyle();
    addToWindow();
}

void NvBudgetView::init() {
    int cpt = 0;

    for (int i = 1; i <= 31; i += 1) {
        comboBoxJourDebut->addItem(QString::number(i));
        comboBoxJourFin->addItem(QString::number(i));
        if (i <= 12) {
            comboBoxMoisDebut->addItem(QString::number(i));
            comboBoxMoisFin->addItem(QString::number(i));
        }
    }

    for (int i = 0; i < 5; i += 1) {
        tableWidget_revenus->setCellWidget(i, 0, new QLineEdit());
        lineText = new QLineEdit();
        lineText->setValidator(validator);
        tableWidget_revenus->setCellWidget(i, 1, lineText);
    }

    for (std::string s: Model::getDepensesFixesPredefinies()) {
        tableWidget_depenses_fixes->setCellWidget(cpt, 0, new QLabel(QString::fromStdString(s)));
        lineText = new QLineEdit();
        lineText->setValidator(validator);
        tableWidget_depenses_fixes->setCellWidget(cpt, 1, lineText);

        cpt += 1;
    }

    cpt = 0;
    for (std::string s: Model::getDepensesVariablesPredefinies()) {
        tableWidget_depenses_variables->setCellWidget(cpt, 0, new QLabel(QString::fromStdString(s)));
        lineText = new QLineEdit();
        lineText->setValidator(validator);
        tableWidget_depenses_variables->setCellWidget(cpt, 1, lineText);
        cpt += 1;
    }

    cpt = 0;
    for (std::string s: Model::getAutresDepensesPredefinies()) {
        tableWidget_autres_depenses->setCellWidget(cpt, 0, new QLabel(QString::fromStdString(s)));
        lineText = new QLineEdit();
        lineText->setValidator(validator);
        tableWidget_autres_depenses->setCellWidget(cpt, 1, lineText);
        cpt += 1;
    }
}

void NvBudgetView::setStyle() {
    btnValide->setGeometry(10, 10, 80, 30);
}

void NvBudgetView::addToWindow() {
    hBoxDateDebut->addWidget(labelDateDebut);
    hBoxDateDebut->addWidget(comboBoxJourDebut);
    hBoxDateDebut->addWidget(comboBoxMoisDebut);

    hBoxDateFin->addWidget(labelDateFin);
    hBoxDateFin->addWidget(comboBoxJourFin);
    hBoxDateFin->addWidget(comboBoxMoisFin);

    hBoxTablesWidget->addWidget(tableWidget_revenus);
    hBoxTablesWidget->addWidget(tableWidget_depenses_fixes);
    hBoxTablesWidget->addWidget(tableWidget_depenses_variables);
    hBoxTablesWidget->addWidget(tableWidget_autres_depenses);

    layout->addWidget(labelPage, 0, 0);
    layout->addLayout(hBoxDateDebut, 1, 0);
    layout->addLayout(hBoxDateFin, 2, 0);
    layout->addWidget(labelPrevoir, 3, 0);
    layout->addLayout(hBoxTablesWidget, 4, 0);
    layout->addWidget(btnValide, 5, 0);
}

QComboBox* NvBudgetView::getComboBoxJourDebut() {
    return comboBoxJourDebut;
}

QComboBox* NvBudgetView::getComboBoxJourFin() {
    return comboBoxJourFin;
}

QComboBox* NvBudgetView::getComboBoxMoisDebut() {
    return comboBoxMoisDebut;
}

QComboBox* NvBudgetView::getComboBoxMoisFin() {
    return comboBoxMoisFin;
}

QTableWidget* NvBudgetView::getTableWidgetRevenus() {
    return tableWidget_revenus;
}

QTableWidget* NvBudgetView::getTableWidgetDepensesFixes() {
    return tableWidget_depenses_fixes;
}

QTableWidget* NvBudgetView::getTableWidgetDepensesVariables() {
    return tableWidget_depenses_variables;
}

QTableWidget* NvBudgetView::getTableWidgetAutresDepenses() {
    return tableWidget_autres_depenses;
}

QPushButton *NvBudgetView::getBtnValide() {
    return btnValide;
}

QFrame* NvBudgetView::getFrame() {
    return frame;
}