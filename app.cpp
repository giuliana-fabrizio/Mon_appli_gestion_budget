#include "./Fichiers_hpp/global.hpp"


int main(int argc, char **argv) {
    QApplication app (argc, argv);

    Utilisateur *user = new Utilisateur();
    View *view = new View(user);
    Controller *controller = new Controller(user, view);

    QMessageBox::information(view->getWindow(), "Information 📇",
            "Allez dans menu > ajouter un nouveau budget pour définir et suivre votre premier budget 😆");

    return app.exec();
}