#include "../Fichiers_hpp/nv_budget_view.hpp"


NvBudgetView::NvBudgetView() {
    labelPage = new QLabel("Définir un nouveau budget");
    labelDateDebut = new QLabel("Date de début :");
    labelDateFin = new QLabel("Date de fin :");
    labelRevenu = new QLabel("Saisir un revenu :");
    labelLibelleRevenu = new QLabel("Saisir le type revenu :");

    comboBoxJourDebut = new QComboBox();
    comboBoxJourFin = new QComboBox();
    comboBoxMoisDebut = new QComboBox();
    comboBoxMoisFin = new QComboBox();

    // QLabel *labelAnnee = new QLabel(QString::number(annee_courante));

    textEditRevenu = new QTextEdit();
    btnValide = new QPushButton("Valider");
    frame = new QFrame();
    layout = new QGridLayout(frame);

    init();
    setStyle();
    addToWindow();
}

void NvBudgetView::init() {
    for (int i = 1; i <= 31; i += 1) {
        comboBoxJourDebut->addItem(QString::number(i));
        comboBoxJourFin->addItem(QString::number(i));
        if (i <= 12) {
            comboBoxMoisDebut->addItem(QString::number(i));
            comboBoxMoisFin->addItem(QString::number(i));
        }
    }
}

void NvBudgetView::setStyle() {
    btnValide->setGeometry(10, 10, 80, 30);
}

void NvBudgetView::addToWindow() {
    layout->addWidget(labelPage, 0, 0);
    layout->addWidget(labelDateDebut, 1, 0);
    layout->addWidget(comboBoxJourDebut, 1, 1);
    layout->addWidget(comboBoxMoisDebut, 1, 2);
    // layout->addWidget(labelAnnee, 1, 3);
    layout->addWidget(labelDateFin, 2, 0);
    layout->addWidget(comboBoxJourFin, 2, 1);
    layout->addWidget(comboBoxMoisFin, 2, 2);
    // layout->addWidget(labelAnnee, 2, 3);
    layout->addWidget(labelRevenu, 3, 0);
    layout->addWidget(textEditRevenu, 3, 1);
    layout->addWidget(labelLibelleRevenu, 4, 0);
    layout->addWidget(textEditTypeRevenu, 4, 1);
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

QTextEdit* NvBudgetView::getTextEditRevenu() {
    return textEditRevenu;
}

QTextEdit* NvBudgetView::getTextEditTypeRevenu() {
    return textEditTypeRevenu;
}

QPushButton *NvBudgetView::getBtnValide() {
    return btnValide;
}

QFrame* NvBudgetView::getFrame() {
    return frame;
}