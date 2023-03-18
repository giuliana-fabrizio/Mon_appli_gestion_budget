#include "../Fichiers_hpp/controller.hpp"

#include <iostream>

Controller::Controller(Utilisateur *user, View *view) {
    this->user = user;
    this->view = view;
    connect();
}

void Controller::connect() {
    QObject::connect(view->getMenu()->getActionPageAccueil(), &QAction::triggered, [=]() {
        changePage(1);
    });
    QObject::connect(view->getMenu()->getActionPageBudget(), &QAction::triggered, [=]() {
        changePage(2);
    });
    QObject::connect(view->getMenu()->getActionPageDepense(), &QAction::triggered, [=]() {
        changePage(3);
    });
    QObject::connect(view->getMenu()->getActionPageHistorique(), &QAction::triggered, [=]() {
        changePage(4);
    });

    QObject::connect(view->getNvBudgetView()->getBtnValide(), &QPushButton::clicked, [=]() {
        addBudget();
    });
    QObject::connect(view->getNvleDepenseView()->getBtnValide(), &QPushButton::clicked, [=]() {
        addDepense();
    });

    QObject::connect(view->getNvleDepenseView()->getComboBoxCategorieDepense(), QOverload<int>::of(&QComboBox::currentIndexChanged), [=]() {
        donneInfos(view->getNvleDepenseView()->getComboBoxCategorieDepense()->currentIndex());
    });
}

void Controller::changePage(int nb) {
    view->addToScene(nb);
}

void Controller::addBudget() {
    // verification date coherente
    int jourDebut = view->getNvBudgetView()->getComboBoxJourDebut()->currentIndex() + 1;
    int moisDebut = view->getNvBudgetView()->getComboBoxMoisDebut()->currentIndex() + 1;
    int jourFin = view->getNvBudgetView()->getComboBoxJourFin()->currentIndex() + 1;
    int moisFin = view->getNvBudgetView()->getComboBoxMoisFin()->currentIndex() + 1;
    int annee = 2023;

    std::vector<double> prevision_dps_fixes;
    std::vector<double> prevision_dps_variables;
    std::vector<double> prevision_autres_dps;
    std::vector<Revenu> revenu_dispos;

    Date debut = {jourDebut, moisDebut, annee};
    Date fin = {jourFin, moisFin, annee};

    for (int i = 0; i < view->getNvBudgetView()->getTableWidgetDepensesFixes()->rowCount(); i += 1) {
        QLineEdit* lineEdit = qobject_cast<QLineEdit*>(view->getNvBudgetView()->getTableWidgetDepensesFixes()->cellWidget(i, 1));
        prevision_dps_fixes.push_back(lineEdit->text().toDouble());
        std::cout << lineEdit->text().toStdString() << std::endl;
    }

    for (int i = 0; i < view->getNvBudgetView()->getTableWidgetDepensesVariables()->rowCount(); i += 1) {
        QLineEdit* lineEdit = qobject_cast<QLineEdit*>(view->getNvBudgetView()->getTableWidgetDepensesVariables()->cellWidget(i, 1));
        prevision_dps_variables.push_back(lineEdit->text().toDouble());
        std::cout << lineEdit->text().toStdString() << std::endl;
    }

    for (int i = 0; i < view->getNvBudgetView()->getTableWidgetAutresDepenses()->rowCount(); i += 1) {
        QLineEdit* lineEdit = qobject_cast<QLineEdit*>(view->getNvBudgetView()->getTableWidgetAutresDepenses()->cellWidget(i, 1));
        prevision_autres_dps.push_back(lineEdit->text().toDouble());
        std::cout << lineEdit->text().toStdString() << std::endl;
    }

    for (int i = 0; i < view->getNvBudgetView()->getTableWidgetRevenus()->rowCount(); i += 1) {
        QLineEdit* libelle_revenu = qobject_cast<QLineEdit*>(view->getNvBudgetView()->getTableWidgetRevenus()->cellWidget(i, 0));
        QLineEdit* montant = qobject_cast<QLineEdit*>(view->getNvBudgetView()->getTableWidgetRevenus()->cellWidget(i, 1));
        Revenu revenu = {montant->text().toDouble(), libelle_revenu->text().toStdString()};
        revenu_dispos.push_back(revenu);
        std::cout << libelle_revenu->text().toStdString() << std::endl;
    }

    user->ajouterBudget(debut, fin, prevision_dps_fixes, prevision_dps_variables, prevision_autres_dps, revenu_dispos);

    view->getAccueilView()->clearAll();
    view->getAccueilView()->init();
    changePage(1);
}

void Controller::donneInfos(int index) {
    view->getNvleDepenseView()->initComboBoxEnveloppe(index);
}

void Controller::addDepense() {
    int jour = view->getNvleDepenseView()->getComboBoxJour()->currentIndex() + 1;
    int mois = view->getNvleDepenseView()->getComboBoxMois()->currentIndex() + 1;
    int annee = 2023;
    Date date = {jour, mois, annee};

    int id_categorie = view->getNvleDepenseView()->getComboBoxCategorieDepense()->currentIndex();
    int id_enveloppe = view->getNvleDepenseView()->getComboBoxEnveloppe()->currentIndex();

    double montant = view->getNvleDepenseView()->getLineEditMontant()->text().toDouble();

    std::string description = view->getNvleDepenseView()->getLineEditDescription()->text().toStdString();

    user->ajouterDepense(date, montant, description, id_categorie, id_enveloppe);

    view->getAccueilView()->clearAll();
    view->getAccueilView()->init();
    changePage(1);
}