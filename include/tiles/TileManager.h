#pragma once
#include <cstdint>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

#define TOTAL_ROW 16
#define TOTAL_COLUMN 12
#define CELL_SIZE 50

class TileManager
{
public:
    void createLevel(int level);
    int getTileID(int row, int column);

private:
    int tileIDs[TOTAL_ROW][TOTAL_COLUMN];
};