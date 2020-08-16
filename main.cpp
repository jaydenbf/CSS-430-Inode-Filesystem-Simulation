/*
 * Givens:
 * A disk contains 1000 512K blocks (0-999)
 * Permissions and file type(first byte) should be -rwxr--r--
 * Use only direct blocks (no indirect blocks)
 * uid = CSS430 gid = CSS430
 *
 * Only commands used are:
 * Create new file: NF filename numblocks
 *      Creates file of 4 blocks.
 * Add to file: MF filename numblocks
 *      Add 3 blocks to file.
 * Delete file: DF filename
 *      Delete file.
 * Delete blocks: DB filename numblocks
 *      Delete numblocks from file.
 * Print: PR
 *      Print all file system contents, including inode,
 *      disk map, and disk directory.
 */

#include <string>
#include <iostream>
#include <vector>
#include "Commands.h"

//Function Prototypes
std::vector<std::string> parseInput(const std::string& input);  //Parses commands given to the program.
                                                                //Returns vector because its not easy
                                                                //to return arrays.

int main() {
    std::cout << "Welcome to a simulation of an Inode File System! Use \"quit\" to leave the program!\nWritten by:\n";
    std::cout << "Logan Petersen\n";
    //ADD YOUR NAME HERE.
    //cout << "NAME"\n;
    //cout << "NAME"\n;

    //Local Variables
    std::string consoleInput;
    std::vector<std::string> givenCommand;
    bool disk[1000] = {false};

    do {
        std::getline(std::cin, consoleInput);
        givenCommand = parseInput(consoleInput);

        //Switch statement doesn't work effectively on strings unless you convert each string
        //to int, so therefore if is being used. :(
        if(givenCommand.at(1) == "NF") {
            Commands::NF(givenCommand[1], givenCommand[2], disk);
        }
        else if(givenCommand.at(1) == "MF") {
            Commands::MF(givenCommand[1], givenCommand[2], disk);
        }
        else if(givenCommand.at(1) == "DF") {
            Commands::DF(givenCommand[1], disk);
        }
        else if(givenCommand.at(1) == "DB") {
            Commands::DB(givenCommand[1], givenCommand[2], disk);
        }
        else if(givenCommand.at(1) == "PR") {
            std::cout << Commands::PR(disk);
        }
        else if (givenCommand.at(1) != "quit") {
            std::cout << "Invalid Command.\n";
        }
    } while(consoleInput != "quit");
    return 0;
}

std::vector<std::string> parseInput(const std::string& input) {    //Parses commands given to the program.
                                                            //Returns vector because its not easy
                                                            //to return arrays.
    //Local Variables
    std::vector<std::string> returnVector;
    std::string temporaryStorage;

    //Parse the string into components.
    for(char i : input) {
        if(i != ' ') {
            temporaryStorage.push_back(i);
        }
        else {
            returnVector.push_back(temporaryStorage);
            temporaryStorage.clear();
        }
    }
    return returnVector;
}