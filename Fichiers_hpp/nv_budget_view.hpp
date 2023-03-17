#ifndef NvBudget_View_HPP
#define NvBudget_View_HPP

#include <QtWidgets>

#include "model.hpp"

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

        QTableWidget* getTableWidgetRevenus();
        QTableWidget* getTableWidgetDepensesFixes();
        QTableWidget* getTableWidgetDepensesVariables();
        QTableWidget* getTableWidgetAutresDepenses();

        QPushButton *getBtnValide();
        QFrame *getFrame();

    private:
        QLabel *labelPage;
        QLabel *labelDateDebut;
        QLabel *labelDateFin;
        QLabel *labelPrevoir;

        QComboBox *comboBoxJourDebut;
        QComboBox *comboBoxJourFin;
        QComboBox *comboBoxMoisDebut;
        QComboBox *comboBoxMoisFin;

        QDoubleValidator *validator;
        QLineEdit *lineText;

        QTableWidget *tableWidget_revenus;
        QTableWidget *tableWidget_depenses_fixes;
        QTableWidget *tableWidget_depenses_variables;
        QTableWidget *tableWidget_autres_depenses;

        QPushButton *btnValide;
        QFrame *frame;

        QHBoxLayout *hBoxDateDebut;
        QHBoxLayout *hBoxDateFin;
        QHBoxLayout *hBoxTablesWidget;

        QGridLayout *layout;
};

#endif