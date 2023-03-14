#ifndef NvBudget_View_HPP
#define NvBudget_View_HPP

#include <QtWidgets>

class NvBudgetView {

    public:
        NvBudgetView();
        void init();
        void setStyle();
        void addToWindow();
        QComboBox *getComboBoxJourDebut();
        QComboBox *getComboBoxJourFin();
        QComboBox *getComboBoxMoisDebut();
        QComboBox *getComboBoxMoisFin();
        QTextEdit *getTextEditRevenu();
        QTextEdit *getTextEditTypeRevenu();
        QPushButton *getBtnValide();
        QFrame *getFrame();

    private:
        QLabel *labelPage;
        QLabel *labelDateDebut;
        QLabel *labelDateFin;
        QLabel *labelRevenu;
        QLabel *labelLibelleRevenu;
        QComboBox *comboBoxJourDebut;
        QComboBox *comboBoxJourFin;
        QComboBox *comboBoxMoisDebut;
        QComboBox *comboBoxMoisFin;
        QTextEdit *textEditRevenu;
        QTextEdit *textEditTypeRevenu;
        QPushButton *btnValide;
        QFrame *frame;
        QGridLayout *layout;
};

#endif