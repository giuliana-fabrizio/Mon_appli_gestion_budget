#ifndef VIEW_HPP
#define VIEW_HPP

#include "accueil_view.hpp"
#include "menu.hpp"
#include "model.hpp"
#include "nv_budget_view.hpp"

#include <iostream>
#include <QtWidgets>

class View {

    public:
        View(Model *model);
        void setStyle();
        void addWidget();
        void addToScene(int nb);
        Menu *getMenu();
        NvBudgetView *getNvBudgetView();

    private:
        Menu *menu;
        Model *model;
        AccueilView *accueilView;
        NvBudgetView *nvBudgetView;
        QStackedWidget *stackedWidget;
        QVBoxLayout *vBoxLayout;
        QWidget window;
};

#endif