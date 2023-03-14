#include "./Fichiers_hpp/global.hpp"


int main(int argc, char **argv) {
    QApplication app (argc, argv);
    QWidget window;


    Date date_naissance = {27, 11, 2002};
    Utilisateur *user = new Utilisateur(date_naissance, "nom", "passwd", "prenom", "username");
    Date date_debut = {1, 12, 2023};
    Date date_fin = {31, 12, 2023};
    user->ajouterBudget(date_debut, date_fin, 545);
    Date dateDepense = {2, 12, 2023};
    user->ajouterDepense(dateDepense, 52.23, "Cadeau de Noël pour Philip (peluche ours)", "autre");
    user->ajouterDepense(dateDepense, 35.89, "Course heddomadaire (shampooing, brosse à dent, nems)", "nourriture");

    Model *model = new Model(user);
    View *view = new View(model);
    Controller *controller = new Controller(model, view);

    return app.exec();
}