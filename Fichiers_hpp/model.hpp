#ifndef MODEL_HPP
#define MODEL_HPP

#include <iostream>
#include "utilisateur_model.hpp"

class Model {
    public:
        Model(Utilisateur *user);
        Utilisateur *getUser();

    protected:
        Utilisateur *user;
        std::vector<std::string> listCategories;
        int getIndex(std::string var, std::vector<std::string>);
        // std::vector<double> listerHistoriqueDepenseParCategory(Date debut, Date fin);
};

#endif