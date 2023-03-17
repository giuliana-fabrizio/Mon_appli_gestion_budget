#include "../Fichiers_hpp/model.hpp"

Model::Model() {}

int Model::getIndex(std::string var, std::vector<std::string> vecteur) {
    int pos = 0;
    for (std::string s : vecteur) {
        if (s == var) return pos;
        pos += 1;
    }
    return pos;
}

std::vector<std::string> Model::getAutresDepensesPredefinies() {
    std::vector<std::string> autres_depenses_predefinies = {"Cadeaux", "Voyage"};
    return autres_depenses_predefinies;
}

std::vector<std::string> Model::getDepensesFixesPredefinies() {
    std::vector<std::string> depenses_fixes_predefinies = {"Logement", "Impot sur le revenu", "Assurance auto", "Assurance logement", "Tel. mobile", "Internet"};
    return depenses_fixes_predefinies;
}

std::vector<std::string> Model::getDepensesVariablesPredefinies() {
    std::vector<std::string> depenses_variables_predefinies = {"Courses", "Habillement", "Divers"};
    return depenses_variables_predefinies;
}

// std::vector<double> Model::listerHistoriqueDepenseParCategory(Date debut, Date fin) {
//     std::vector<double> list;

//     for (int i = 0; i < (int)listCategories.size(); i += 1) list[i] = 0;

//     for (Depense depense : user->listerHistoriqueDepense(debut, fin)) {
//         list[getIndex(depense.category, listCategories)] += depense.montant_depense;
//     }

//     return list;
// }