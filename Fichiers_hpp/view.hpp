#ifndef VIEW_HPP
#define VIEW_HPP

#include "accueil_view.hpp"
#include "menu.hpp"
#include "utilisateur_model.hpp"
#include "nv_budget_view.hpp"

#include <iostream>
#include <QtWidgets>

class View {

    public:
        View(Utilisateur *user);
        void setStyle();
        void addWidget();
        void addToScene(int nb);
        Menu *getMenu();
        AccueilView *getAccueilView();
        NvBudgetView *getNvBudgetView();

    private:
        Menu *menu;
        Utilisateur *user;
        AccueilView *accueilView;
        NvBudgetView *nvBudgetView;
        QStackedWidget *stackedWidget;
        QVBoxLayout *vBoxLayout;
        QWidget window;
};

#endif