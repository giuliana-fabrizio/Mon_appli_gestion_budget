#include "../Fichiers_hpp/menu.hpp"

Menu::Menu() {
    menuBar = new QMenuBar();
    menu = new QMenu("Menu", menuBar);
    init();
}

void Menu::init() {
    pageAccueil = menu->addAction("Accueil");
    pageBudget = menu->addAction("Définir un nouveau budget");
    pageDepense = menu->addAction("Définir une nouvelle dépense");
    pageHistorique = menu->addAction("Historique des dépenses");

    menuBar->addMenu(menu);
}

QMenuBar* Menu::getMenuBar() {
    return menuBar;
}

QAction* Menu::getActionPageAccueil() {
    return pageAccueil;
}

QAction* Menu::getActionPageBudget() {
    return pageBudget;
}

QAction* Menu::getActionPageDepense() {
    return pageDepense;
}

QAction* Menu::getActionPageHistorique() {
    return pageHistorique;
}

// QObject::connect(pageAccueil, &QAction::triggered, &accueilTriggered);
// QObject::connect(pageBudget, &QAction::triggered, &budgetTriggered);
// QObject::connect(pageDepense, &QAction::triggered, &depenseTriggered);
// QObject::connect(pageHistorique, &QAction::triggered, &historiqueTriggered);

// static void accueilTriggered() {
//     std::cout << "Click sur pageAccueil " << std::endl;
// }

// static void budgetTriggered() {
//     std::cout << "Click sur pageNvBudget " << std::endl;
// }

// static void depenseTriggered() {
//     std::cout << "Click sur pageDepense " << std::endl;
// }

// static void historiqueTriggered() {
//     std::cout << "Click sur pageHistorique " << std::endl;
// }