#include "../Fichiers_hpp/utilisateur_model.hpp"


Utilisateur::Utilisateur(Date date_naissance, std::string nom_user, std::string passwd,
            std::string prenom_user,
            std::string username) {
    this->date_naissance = date_naissance;
    this->nom_user = nom_user;
    this->passwd = passwd;
    this->prenom_user = prenom_user;
    this->username = username;
}

bool Utilisateur::connexion(std::string username, std::string passwd) {
    if (username == this->username && passwd == this->passwd) return true;
    return false;
}

void Utilisateur::ajouterBudget(Date date_debut, Date date_fin, double montant) {
    Budget dernier_budget = {date_debut, date_fin, montant};
    historique_budget.push_back(dernier_budget);
}

void Utilisateur::ajouterDepense(Date date, double montant, std::string description,
                    std::string category) {
    Depense derniere_depense = {date, montant, category, description};
    historique_depense.push_back(derniere_depense);
}

std::vector<Depense> Utilisateur::listerHistoriqueDepense(Date date_debut, Date date_fin) {
    std::vector<Depense> list;
    for (Depense depense: historique_depense) {
        if ((depense.date_depense.compareDate(date_debut) == 2) &&
            (depense.date_depense.compareDate(date_fin) == 1))
            list.push_back(depense);
        if (depense.date_depense.compareDate(date_fin) == 2) return list;
    }
    return list;
}

void Utilisateur::modifierProfil(Date date_naissance, std::string nom, std::string prenom,
                    std::string username) {
    this->date_naissance = date_naissance;
    nom_user = nom;
    prenom_user = prenom;
    this->username = username; // faire méthode à part selon si on gère plrs utilisateur
}

Date Utilisateur::getDateNaissance() {
    return date_naissance;
}

std::string Utilisateur::getNomUser() {
    return nom_user;
}

std::string Utilisateur::getPasswd() {
    return passwd;
}

std::string Utilisateur::getPrenomUser() {
    return prenom_user;
}

std::string Utilisateur::getUsername() {
    return username;
}

std::vector<Budget> Utilisateur::getHistoriqueBudget() {
    return historique_budget;
}

std::vector<Depense> Utilisateur::getHistoriqueDepense() {
    return historique_depense;
}