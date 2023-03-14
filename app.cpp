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
    user->ajouterBudget(debutBudG, finBudG, revenu);
    user->ajouterDepense(depense, montant, description, 0);


    Model *model = new Model(user);
    View *view = new View(model);
    Controller *controller = new Controller(model, view);

    return app.exec();
}