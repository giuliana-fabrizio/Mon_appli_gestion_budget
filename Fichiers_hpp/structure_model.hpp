#include <iostream>

#ifndef DATE_HPP
#define DATE_HPP

struct Date {
    int jour;
    int mois;
    int annee;

    int compareDate(Date date);
    std::string toString();
};

#endif



#ifndef BUDGET_HPP
#define BUDGET_HPP

struct Budget {
    Date date_debut;
    Date date_fin;
    double montant;
};

#endif



#ifndef DEPENSE_HPP
#define DEPENSE_HPP

struct Depense {
    Date date_depense;
    double montant_depense;
    std::string category;
    std::string description_depense;
};

#endif