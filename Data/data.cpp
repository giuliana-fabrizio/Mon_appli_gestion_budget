#include "../Fichiers_hpp/data.hpp"


// int Model::getIndex(std::string var, std::vector<std::string> vecteur) {
//     int pos = 0;
//     for (std::string s : vecteur) {
//         if (s == var) return pos;
//         pos += 1;
//     }
//     return pos;
// }

std::vector<std::string> Data::composants_budget = {"Revenus", "Dépenses fixes", "Dépenses variables", "Autres dépenses"};
std::vector<std::string> Data::autres_depenses_predefinies = {"Cadeaux", "Voyage"};
std::vector<std::string> Data::depenses_fixes_predefinies = {"Logement", "Impot sur le revenu", "Assurance auto", "Assurance logement", "Tel. mobile", "Internet"};
std::vector<std::string> Data::depenses_variables_predefinies = {"Courses", "Habillement", "Divers"};