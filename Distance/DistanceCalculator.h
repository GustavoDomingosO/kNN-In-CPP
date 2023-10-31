//
// Created by Gustavo Domingos on 9/18/2023.
//

#ifndef KNN_DISTANCECALCULATOR_H
#define KNN_DISTANCECALCULATOR_H

#include <vector>
#include <cmath>
#include "../DataStructure/DataPoint.h"

class DistanceCalculator {
private:

public:

    DistanceCalculator();

    virtual ~DistanceCalculator();


    //The inside vector is for the training set and the outside is for the testSet
    virtual double euclidianDistance(const DataPoint& _trainingData, const DataPoint& _testData){
        std::vector<double> caracteristicasTrain = _trainingData.getCaracteristicas();
        std::vector<double> caracteristicasTest = _testData.getCaracteristicas();
        double soma = 0;
        for(size_t i = 0; i < caracteristicasTrain.size(); i++){
            soma += pow((caracteristicasTrain[i] - caracteristicasTest[i]), 2);
        }
        return sqrt(soma);
    }

};

DistanceCalculator::~DistanceCalculator() = default;

DistanceCalculator::DistanceCalculator() {

}

#endif //KNN_DISTANCECALCULATOR_H
