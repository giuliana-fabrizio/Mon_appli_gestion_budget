#ifndef MODEL_UTILISATEUR_HPP
#define MODEL_UTILISATEUR_HPP

#include <iostream>
#include <vector>

#include "structure_model.hpp"

class Utilisateur {

    public:
        Utilisateur(Date date_naissance, std::string nom_user, std::string passwd,
                    std::string prenom_user,
                    std::string username);
        bool connexion(std::string username, std::string passwd);
        void ajouterBudget(Date date_debut, Date date_fin, double montant);
        void ajouterDepense(Date date, double montant, std::string description,
                            std::string category);
        std::vector<Depense> listerHistoriqueDepense(Date date_debut, Date date_fin);
        void modifierProfil(Date date_naissance, std::string nom, std::string prenom,
                            std::string username);
        Date getDateNaissance();
        std::string getNomUser();
        std::string getPasswd();
        std::string getPrenomUser();
        std::string getUsername();
        std::vector<Budget> getHistoriqueBudget();
        std::vector<Depense> getHistoriqueDepense();

    private:
        Date date_naissance;
        std::string nom_user;
        std::string passwd;
        std::string prenom_user;
        std::string username;
        std::vector<Budget> historique_budget;
        std::vector<Depense> historique_depense;
};

#endif