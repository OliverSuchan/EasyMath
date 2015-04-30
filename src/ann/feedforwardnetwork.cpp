#include "feedforwardnetwork.hpp"

FeedForwardNetwork::FeedForwardNetwork(std::vector<int> p_layers)
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(0, 1);
    if(p_layers.size() > 1)
    {
        int biggestLayer = p_layers.at(0);
        for(int i = 1; i < p_layers.size(); i++)
        {
            if(p_layers.at(i) > biggestLayer)
                biggestLayer = p_layers.at(i);
            Dimension dim = Dimension();
            dim.m_rowCount = p_layers.at(i - 1);
            dim.m_colCount = p_layers.at(i);
            Matrix<double> m = Matrix<double>(dim.m_rowCount, dim.m_colCount);

            for(int j = 0; j < dim.m_rowCount; j++)
            {
                for(int k = 0; k < dim.m_colCount; k++)
                {
                    m.setVal(dist(mt), j, k);
                    std::cout << m.getVal(j, k) << " ";
                }
                std::cout << std::endl;
            }
            m_weights.push_back(m);
            std::cout << std::endl;
        }

        m_thresholds = new Matrix<double>(biggestLayer, p_layers.size());
    }
}
