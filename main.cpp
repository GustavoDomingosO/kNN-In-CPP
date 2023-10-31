
#include<iostream>
#include<string>
#include<vector>
#include "DataStructure/DataPoint.h"
#include "KNearestNeighbor/KNearestNeighbor.h"

double euclidianDistance(const DataPoint& _trainingData, const DataPoint& _testData){
    std::vector<double> characteristicsTrain = _trainingData.getCaracteristicas();
    std::vector<double> characteristicsTest = _testData.getCaracteristicas();
    double sum = 0;
    for(size_t i = 0; i < characteristicsTrain.size(); i++){
        sum += pow((characteristicsTrain[i] - characteristicsTest[i]), 2);
    }
    return sqrt(sum);
}

int main (){
    
    std::vector<double> dataExample1 = {1.5, 3.9, 6.9, 1.1};
    std::vector<double> dataExample2 = {3.3, 9.7, 10.0, 2.5};
    std::vector<double> dataExample3 = {3.9, 9.9, 1.0, 2.6};
    std::vector<double> dataExample4 = {4.7, 1.6, 3.2, 3.3};
    std::vector<double> dataExample5 = {2.4, 8.2, 0.0, 4.0};
    std::vector<double> dataExample6 = {1.1, 5.2, 7.1, 6.2};
    std::vector<double> dataExample7 = {3.9, 9.9, 2.6, 1.7};
    std::vector<std::string> characteristicsNames = {"One", "Two", "Three", "Four"};
    std::string classification1 = "Bad";
    std::string classification2 = "Bad";
    std::string classification3 = "Good";
    std::string classification4 = "Good";
    std::string classification5 = "Bad";

    DataPoint trainingData1(dataExample1, classification1 , characteristicsNames);
    DataPoint trainingData2(dataExample2, classification2 , characteristicsNames);
    DataPoint trainingData3(dataExample3, classification3 , characteristicsNames);
    DataPoint trainingData4(dataExample4, classification4 , characteristicsNames);
    DataPoint trainingData5(dataExample5, classification5 , characteristicsNames);
    DataPoint testData1(dataExample6, "" , characteristicsNames);
    DataPoint testData2(dataExample7, "" , characteristicsNames);
    std::vector<DataPoint> training = {trainingData1, trainingData2, trainingData3, trainingData4, trainingData5};
    std::vector<DataPoint> test = {testData1, testData2};

    /*for (size_t i = 0; i < test.size(); ++i) {
        for (size_t o = 0; o < training.size(); ++o) {
            std::cout << "Distances of testData" << i + 1 << " to trainingData" << o + 1 << " is: " << euclidianDistance(training[o], test[i]) << std::endl;
        }
    }*/

    KNearestNeighbor kNN(training, test);

    std::vector<std::string> result = kNN.kNNResult(3);

    for(const auto & i : result) {
        std::cout << "Result for " << i << std::endl;
    }


    return 0;
}