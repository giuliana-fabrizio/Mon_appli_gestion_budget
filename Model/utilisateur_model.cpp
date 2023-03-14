#include "../Fichiers_hpp/utilisateur_model.hpp"


Utilisateur::Utilisateur() {
    autres_depenses_predefinies = {"Cadeaux", "Voyage"};
    depenses_fixes_predefinies = {"Logement", "Impot sur le revenu", "Assurance auto", "Assurance logement", "Tel. mobile", "Internet"};
    depenses_variables_predefinies = {"Courses", "Habillement", "Divers"};
}

void Utilisateur::ajouterBudget(Date debut, Date fin, Revenu revenu) {
    Budget budget = {debut, fin};

    for (std::string s: autres_depenses_predefinies) {
        Enveloppe enveloppe = {0, s};
        budget.autres_depenses.push_back(enveloppe);
    }

    for (std::string s: depenses_fixes_predefinies) {
        Enveloppe enveloppe = {0, s};
        budget.depenses_fixes.push_back(enveloppe);
    }

    for (std::string s: depenses_variables_predefinies) {
        Enveloppe enveloppe = {0, s};
        budget.depenses_variables.push_back(enveloppe);
    }

    budget.list_revenus.push_back(revenu);
    historique_budget.push_back(budget);
}

void Utilisateur::ajouterDepense(Date date, double montant, std::string description, int id_enveloppe) {
    Depense depense = {date, montant, description};
    historique_budget[historique_budget.size()-1].autres_depenses[id_enveloppe].list_depense.push_back(depense);
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