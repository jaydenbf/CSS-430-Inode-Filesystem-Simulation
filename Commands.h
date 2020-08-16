#ifndef CSS_430_INODE_FILESYSTEM_SIMULATION_COMMANDS_H
#define CSS_430_INODE_FILESYSTEM_SIMULATION_COMMANDS_H

#include <string>

class Commands {
public:
    static void NF(std::string fileName, std::string blockCount, bool disk[]);
    static void MF(std::string fileName, std::string blockCount, bool disk[]);
    static void DF(std::string fileName, bool disk[]);
    static void DB(std::string fileName, std::string numBlocks, bool disk[]);
    static std::string PR(bool disk[]);

};


#endif //CSS_430_INODE_FILESYSTEM_SIMULATION_COMMANDS_H
