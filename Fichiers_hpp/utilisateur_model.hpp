#ifndef MODEL_UTILISATEUR_HPP
#define MODEL_UTILISATEUR_HPP

#include <iostream>
#include <vector>

#include "structure_model.hpp"

class Utilisateur {

    public:
        Utilisateur();
        void ajouterBudget(Date debut, Date fin, Revenu revenu);
        void ajouterDepense(Date date, double montant, std::string description, int id_enveloppe);
        std::vector<Budget> getHistoriqueBudget();
        Budget getLastBudget();

    private:
        std::vector<std::string> autres_depenses_predefinies;
        std::vector<std::string> depenses_fixes_predefinies;
        std::vector<std::string> depenses_variables_predefinies;

        std::vector<Budget> historique_budget;
};

#endif