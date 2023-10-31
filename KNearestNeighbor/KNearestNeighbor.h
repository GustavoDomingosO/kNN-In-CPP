//
// Created by Gustavo Domingos on 9/18/2023.
//

#ifndef KNN_KNEARESTNEIGHBOR_H
#define KNN_KNEARESTNEIGHBOR_H

#include "../Distance/DistanceCalculator.h"
#include "../DataStructure/DataPoint.h"
#include <vector>
#include <string>
#include <iostream>
#include <map>

class KNearestNeighbor : public DistanceCalculator {

private:

    std::vector<DataPoint> trainingDataSet;
    std::vector<DataPoint> testDataSet;


public:

    KNearestNeighbor(const std::vector<DataPoint>& _trainingDataSet, const std::vector<DataPoint>& _testDataSet):
            trainingDataSet(_trainingDataSet), testDataSet(_testDataSet){

    }

    std::vector<std::string> kNNResult(int k){
        std::vector<double> result(k, std::numeric_limits<double>::max());
        std::vector<std::string> tempTypes(k, "");
        std::vector<std::string> types(testDataSet.size());
        double temp_value = 0.0;
        for (size_t i = 0; i < testDataSet.size(); ++i) {
            for (const auto & o : trainingDataSet){
                temp_value = euclidianDistance(testDataSet[i], o);
                for (size_t l = 0; l < result.size(); ++l) {
                    if(temp_value < result[l]){
                        for(size_t y = result.size() - 1; y > l; --y){
                            result[y] = result[y-1];
                            tempTypes[y] = tempTypes[y-1];
                        }
                        result[l] = temp_value;
                        tempTypes[l] = o.getClassificacao();
                        break;
                    }
                }
            }

            std::string maxLabel = tempTypes[0];
            int maxValue = -1;
            std::map<std::string, int> labelPerValue;
            for(const auto & _tempType : tempTypes){
                labelPerValue[_tempType] = 0;
            }
            for(const auto & _tempType : tempTypes){
                labelPerValue[_tempType]++;
            }

            for (const auto& pair : labelPerValue) {
                if(pair.second > maxValue){
                    maxValue = pair.second;
                    maxLabel = pair.first;
                }
            }

            types[i] = maxLabel;

            for (double & test : result) {
                test = INT_MAX;
            }
            for (auto & tempType : tempTypes) {
                tempType = "";
            }
            temp_value = 0.0;
        }
        return types;
    }

    ~KNearestNeighbor() override;
};

KNearestNeighbor::~KNearestNeighbor() = default;


#endif //KNN_KNEARESTNEIGHBOR_H
