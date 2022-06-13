#include "tiles/TileManager.h"
#include "objects/ObjectManager.h"
#include "objects/GameObject.h"

void TileManager::createLevel(int level)
{
    std::string fileName = std::string("levels/level");
    std::ifstream fileStream;
    fileStream.open(fileName.append(std::to_string(level)).append(".txt").c_str());
    std::stringstream readedData;

    int outputArray[TOTAL_ROW][TOTAL_COLUMN];

    if (fileStream.is_open())
    {
        for (int j = 0; j < TOTAL_COLUMN; j++)
        {  
            for (int i = 0; i < TOTAL_ROW; i++)
            {
                fileStream >> outputArray[i][j];
            }
        }
    }
    else
        std::cout << fileName << " is not found!" << std::endl;
        for (int j = 0; j < TOTAL_COLUMN; j++)
        {  
            for (int i = 0; i < TOTAL_ROW; i++)
            {
            int id = outputArray[i][j];
            int objectID = -1;
            switch(id)
            {
                case 1:
                    objectID = ObjectManager::createObject<GameObject>(1, "res/1.png", i * CELL_SIZE, j * CELL_SIZE);
                break;
                case 2:
                    objectID = ObjectManager::createObject<GameObject>(1, "res/2.png", i * CELL_SIZE, j * CELL_SIZE);
                break;
                case 3:
                    objectID = ObjectManager::createObject<GameObject>(1, "res/3.png", i * CELL_SIZE, j * CELL_SIZE);
                break;
                case 4:
                    objectID = ObjectManager::createObject<GameObject>(1, "res/4.png", i * CELL_SIZE, j * CELL_SIZE);
                break;
                case 5:
                    objectID = ObjectManager::createObject<GameObject>(1, "res/5.png", i * CELL_SIZE, j * CELL_SIZE);
                break;
                case 6:
                    objectID = ObjectManager::createObject<GameObject>(1, "res/6.png", i * CELL_SIZE, j * CELL_SIZE);
                break;
                case 7:
                    objectID = ObjectManager::createObject<GameObject>(1, "res/7.png", i * CELL_SIZE, j * CELL_SIZE);
                break;
                case 8:
                    objectID = ObjectManager::createObject<GameObject>(1, "res/8.png", i * CELL_SIZE, j * CELL_SIZE);
                break;
                case 9:
                    objectID = ObjectManager::createObject<GameObject>(1, "res/9.png", i * CELL_SIZE, j * CELL_SIZE);
                break;
            }
            tileIDs[i][j] = objectID;
        }
    }
    std::cout << "Level " << level << " created!" << std::endl;
}

int TileManager::getTileID(int row, int column)
{
    return tileIDs[column / CELL_SIZE][row / CELL_SIZE];
}