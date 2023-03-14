#include "../Fichiers_hpp/model.hpp"

Model::Model(Utilisateur *user) {
    this->user = user;
    listCategories = {"abonnements", "alimentaire", "logement", "santé", "sorties-voyage", "transports", "vêtements", "autres"};
}

Utilisateur* Model::getUser() {
    return user;
}

int Model::getIndex(std::string var, std::vector<std::string> vecteur) {
    int pos = 0;
    for (std::string s : vecteur) {
        if (s == var) return pos;
        pos += 1;
    }
    return pos;
}

std::vector<double> Model::listerHistoriqueDepenseParCategory(Date debut, Date fin) {
    std::vector<double> list;

    for (int i = 0; i < (int)listCategories.size(); i += 1) list[i] = 0;

    for (Depense depense : user->listerHistoriqueDepense(debut, fin)) {
        list[getIndex(depense.category, listCategories)] += depense.montant_depense;
    }

    return list;
}