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
        QTextEdit *getTextEditMontant();
        QPushButton *getBtnValide();
        QFrame *getFrame();

    private:
        QLabel *labelPage;
        QLabel *labelDateDebut;
        QLabel *labelDateFin;
        QLabel *labelMontant;
        QComboBox *comboBoxJourDebut;
        QComboBox *comboBoxJourFin;
        QComboBox *comboBoxMoisDebut;
        QComboBox *comboBoxMoisFin;
        QTextEdit *textEditMontant;
        QPushButton *btnValide;
        QFrame *frame;
        QGridLayout *layout;
};

#endif