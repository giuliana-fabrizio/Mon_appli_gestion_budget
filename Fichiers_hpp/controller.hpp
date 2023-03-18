#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "utilisateur_model.hpp"
#include "structure_model.hpp"
#include "view.hpp"

#include "structure_model.hpp"

class Controller {

    public:
        Controller(Utilisateur *user, View *view);
        void connect();
        void changePage(int nb);
        void addBudget();
        void donneInfos(int index);
        void addDepense();

    private:
        Utilisateur *user;
        View *view;
};

#endif