#include "./Fichiers_hpp/global.hpp"


int main(int argc, char **argv) {
    QApplication app (argc, argv);
    QWidget window;


    Date debutBudG = {1, 12, 2023};
    Date finBudG = {31, 12, 2023};
    Date depense = {3, 12, 2023};
    Revenu revenu = {2045.86, "salaire"};
    double montant = 50.53;
    std::string description = "Ours en peluche pour Jerémy";

    Utilisateur *user = new Utilisateur();
    std::vector<Revenu> list_revenu;
    std::vector<double> prevision_dps_fixes;
    std::vector<double> prevision_dps_variables;
    std::vector<double> prevision_autres_dps;

    list_revenu.push_back(revenu);
    prevision_dps_fixes.push_back(montant);
    prevision_dps_variables.push_back(montant);
    prevision_autres_dps.push_back(montant);

    user->ajouterBudget(debutBudG, finBudG, prevision_dps_fixes, prevision_dps_variables, prevision_autres_dps, list_revenu);
    user->ajouterDepense(depense, montant, description, 0);
    user->ajouterDepense(depense, montant, description, 0);

    View *view = new View(user);
    Controller *controller = new Controller(user, view);

    return app.exec();
}