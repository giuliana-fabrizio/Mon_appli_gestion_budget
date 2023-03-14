#include "../Fichiers_hpp/view.hpp"

# include <iostream>

View::View(Model *model) {
    this->model = model;
    menu = new Menu();
    accueilView = new AccueilView(model);
    nvBudgetView = new NvBudgetView();
    stackedWidget = new QStackedWidget(&window);
    vBoxLayout = new QVBoxLayout();
    setStyle();
    addWidget();
    addToScene(1);
    window.show();
}

void View::setStyle() {
    window.resize(500, 500);
    window.setStyleSheet(
        "QWidget {"
            "background: white;"
        "}"
    );
}

void View::addWidget() {
    stackedWidget->addWidget(accueilView->getFrame());
    stackedWidget->addWidget(nvBudgetView->getFrame());

    vBoxLayout->addWidget(menu->getMenuBar());
    vBoxLayout->addWidget(stackedWidget);

    window.setLayout(vBoxLayout);
}

void View::addToScene(int nb) {
    switch (nb) {
        case 1:
            stackedWidget->setCurrentIndex(0);
            break;
        case 2:
            stackedWidget->setCurrentIndex(1);
            break;
        case 3:
            // stackedWidget->setCurrentIndex(2);
            break;
        case 4:
            // stackedWidget->setCurrentIndex(3);
            break;
    }
}

Menu* View::getMenu() {
    return menu;
}

NvBudgetView* View::getNvBudgetView() {
    return nvBudgetView;
}