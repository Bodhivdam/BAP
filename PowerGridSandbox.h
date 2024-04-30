#ifndef BAP_OUR_CODE_POWERGRIDSANDBOX_H
#define BAP_OUR_CODE_POWERGRIDSANDBOX_H

#include <iostream>
#include <vector>
#include <stdexcept>
#include <cmath>

struct PowerNode {
    int row;
    int column;
    float power;
};

struct Connection {
    int fromRow;
    int fromColumn;
    int toRow;
    int toColumn;
    float capacity;
    float powerFlow;
    int direction; // 0 for normal, 1 for reversed
    float lineLosses;
};

class PowerGridSandbox {
private:
    int gridSize;
    float slope;
    std::vector<std::vector<int>> map;
    std::vector<PowerNode> generators;
    std::vector<PowerNode> consumers;
    std::vector<Connection> connections;

public:
    PowerGridSandbox(int n, float slopeValue);
    void setSlope(float slopeValue);
    void addGenerator(int row, int column, float power);
    void addConsumer(int row, int column, float power);
    void addConnection(int fromRow, int fromColumn, int toRow, int toColumn, float capacity, float powerFlow, int direction);
    void calculatePowerFlows();
    void printConnections();
};


#endif //BAP_OUR_CODE_POWERGRIDSANDBOX_H
