//
// Created by Gustavo Domingos on 9/18/2023.
//

#ifndef KNN_DATAPOINT_H
#define KNN_DATAPOINT_H

#include <utility>
#include<vector>
#include<string>
#include<algorithm>

// kNN só trabalha com número, então podemos utilizar um vector de double.

class DataPoint {
public:
    DataPoint(const std::vector<double>& caracteristics ,std::string  classify,
              const std::vector<std::string>& classesNames)
            : caracteristicas(caracteristics), classificacao(std::move(classify)), nomeDasCaracteristicas(classesNames){

    }

    virtual ~DataPoint() = default;

    [[nodiscard]] const std::vector<double>& getCaracteristicas() const {
        return this->caracteristicas;
    }

    [[nodiscard]] const std::string& getClassificacao() const {
        return this->classificacao;
    }

    [[nodiscard]] const std::vector<std::string>& getNomeDasCaracteristicas() const {
        return this->nomeDasCaracteristicas;
    }

    double RetornaValordaCaracteristica (const std::string& nomeDeCarac){
        int index = 0;
        auto iter = std::find(this->nomeDasCaracteristicas.begin(), this->nomeDasCaracteristicas.end(), nomeDeCarac);
        try {
            if (iter != this->nomeDasCaracteristicas.end()) {
                index = std::distance(this->nomeDasCaracteristicas.begin(), iter);
            } else {
                throw "Element not found!";
            }
        } catch(const char*){
            return -1.0;
        }

        return this->caracteristicas[index];
    }



private:
    std::vector<double> caracteristicas;
    std::string classificacao;
    std::vector<std::string> nomeDasCaracteristicas;
};

#endif //KNN_DATAPOINT_H
