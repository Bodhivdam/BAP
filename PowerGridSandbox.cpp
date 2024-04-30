#include "PowerGridSandbox.h"

PowerGridSandbox::PowerGridSandbox(int size, float slopeValue) : gridSize(size), slope(slopeValue), map(size, std::vector<int>(size, 0)) {}

void PowerGridSandbox::setSlope(float slopeValue) {    // Slope is linear factor of distance with power loss
    slope = slopeValue;
}

void PowerGridSandbox::addConnection(int fromRow, int fromColumn, int toRow, int toColumn, float capacity, float powerFlow, int direction) {
    float distance = sqrt(pow(fromRow - toRow, 2) + pow(fromColumn - toColumn, 2));     // Pythagoras
    float lineLosses = std::min(0.1f, slope * distance);        // linear relationship: losses = slope * distance. Max 10% powerloss
    float actualPowerFlow = powerFlow * (1 - lineLosses);

    connections.push_back({fromRow, fromColumn, toRow, toColumn, capacity, actualPowerFlow, direction, lineLosses});
}

void PowerGridSandbox::addGenerator(int row, int column, float power) {
    if (row < 0 || row >= gridSize || column < 0 || column >= gridSize) {
        throw std::invalid_argument("Generator position is outside the grid.");
    }
    map[row][column] = generators.size() + 1;
    generators.push_back({row, column, power});
}

void PowerGridSandbox::addConsumer(int row, int column, float power) {
    if (row < 0 || row >= gridSize || column < 0 || column >= gridSize) {
        throw std::invalid_argument("Consumer position is outside the grid.");
    }
    map[row][column] = -consumers.size() - 1;
    consumers.push_back({row, column, power});
}

void PowerGridSandbox::calculatePowerFlows() {
    // Your power flow calculation logic here
}

void PowerGridSandbox::printConnections() {
    for (const auto& connection : connections) {
        std::cout << "| " << connection.fromRow << " | " << connection.fromColumn << " | "
                  << connection.toRow << " | " << connection.toColumn << " | "
                  << connection.capacity << " | " << connection.powerFlow << " | "
                  << connection.direction << " |" << std::endl;
    }
}
