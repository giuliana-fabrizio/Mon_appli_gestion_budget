#include "../Fichiers_hpp/controller.hpp"

#include <iostream>

Controller::Controller(Model *model, View *view) {
    this->model = model;
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
    // Date debut = { + 1}
}