#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "model.hpp"
#include "view.hpp"

#include "structure_model.hpp"

class Controller {

    public:
        Controller(Model *model, View *view);
        void connect();
        void changePage(int nb);
        void addBudget();

    private:
        Model *model;
        View *view;
};

#endif