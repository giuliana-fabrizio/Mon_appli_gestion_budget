#ifndef MODEL_HPP
#define MODEL_HPP

#include <iostream>
#include <vector>

class Model {

    public:
        Model();
        static std::vector<std::string> getAutresDepensesPredefinies();
        static std::vector<std::string> getDepensesFixesPredefinies();
        static std::vector<std::string> getDepensesVariablesPredefinies();

    protected:
        int getIndex(std::string var, std::vector<std::string>);
        // std::vector<double> listerHistoriqueDepenseParCategory(Date debut, Date fin);
};

#endif