#include "../Fichiers_hpp/utilisateur_model.hpp"


Utilisateur::Utilisateur() {}

void Utilisateur::ajouterBudget(Date debut, Date fin, std::vector<double> prevision_dps_fixes, std::vector<double> prevision_dps_variables, std::vector<double> prevision_autres_dps, std::vector<Revenu> revenu_dispo) {
    Budget budget = {debut, fin};

    for (int i = 0; i < (int) Data::autres_depenses_predefinies.size(); i += 1) {
        Enveloppe enveloppe = {prevision_autres_dps[i], Data::autres_depenses_predefinies[i]};
        budget.autres_depenses.push_back(enveloppe);
    }

    for (int i = 0; i < (int) Data::depenses_fixes_predefinies.size(); i += 1) {
        Enveloppe enveloppe = {prevision_dps_fixes[i], Data::depenses_fixes_predefinies[i]};
        budget.depenses_fixes.push_back(enveloppe);
    }

    for (int i = 0; i < (int) Data::depenses_variables_predefinies.size(); i += 1) {
        Enveloppe enveloppe = {prevision_dps_variables[i], Data::depenses_variables_predefinies[i]};
        budget.depenses_variables.push_back(enveloppe);
    }

    for (Revenu revenu : revenu_dispo) budget.list_revenus.push_back(revenu);

    historique_budget.push_back(budget);
}

void Utilisateur::ajouterDepense(Date date, double montant, std::string description, int id_categorie, int id_enveloppe) {
    Depense depense = {date, montant, description};

    switch (id_categorie) {
        default:
            historique_budget[historique_budget.size()-1].depenses_fixes[id_enveloppe].list_depense.push_back(depense);
            break;

        case 1:
            historique_budget[historique_budget.size()-1].depenses_variables[id_enveloppe].list_depense.push_back(depense);
            break;

        case 2:
            historique_budget[historique_budget.size()-1].autres_depenses[id_enveloppe].list_depense.push_back(depense);
            break;
    }
}

std::vector<Budget> Utilisateur::getHistoriqueBudget() {
    return historique_budget;
}

Budget Utilisateur::getLastBudget() {
    return historique_budget[historique_budget.size()-1];
}

// int main() {
//     Date debutBudG = {1, 12, 2023};
//     Date finBudG = {31, 12, 2023};
//     Date depense = {3, 12, 2023};
//     Revenu revenu = {2045.86, "salaire"};
//     double montant = 50.53;
//     std::string description = "Ours en peluche pour Jerémy";

//     Utilisateur *user = new Utilisateur();
//     user->ajouterBudget(debutBudG, finBudG, revenu);
//     user->ajouterDepense(depense, montant, description, 0);
//     std::cout << user->getHistoriqueBudget()[user->getHistoriqueBudget().size()-1].autres_depenses[0].list_depense[0].description_depense << std::endl;
// }