#ifndef FEEDFORWARDNETWORK_HPP
#define FEEDFORWARDNETWORK_HPP

#include <vector>
#include <random>
#include "matrix.hpp"

class FeedForwardNetwork
{
private:
    typedef std::vector<Matrix<double>> Weights;
    Weights m_weights;
    Matrix<double> *m_thresholds;
    std::vector<int> m_layers;

public:
    FeedForwardNetwork(std::vector<int> p_layers);
};

#endif // FEEDFORWARDNETWORK_HPP
