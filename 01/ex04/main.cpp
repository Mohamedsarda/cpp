#include <iostream>
#include <fstream>
#include <string>

int main(int c, char **arg)
{
    if (c != 4)
    {
        std::cout << "To use the program, enter ./main <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string fileName = arg[1];
    std::string fileReplace = fileName + ".replace";
    std::string s1 = arg[2];
    std::string s2 = arg[3];

    if (s1.empty() || s2.empty())
    {
        std::cout << "S1 and S2 can't be empty" << std::endl;
        return (1);
    }
    std::ifstream file(fileName);
    if (!file.is_open())
    {
        std::cout << "Couldn't open the file: " << fileName << std::endl;
        return 1;
    }

    std::ofstream outFile(fileReplace);
    if (!outFile.is_open())
    {
        std::cout << "Couldn't create the file: " << fileReplace << std::endl;
        file.close();
        return 1;
    }

    std::string content;
    size_t      pos;
    size_t      foundPos;
    while (std::getline(file, content))
    {
        std::string newContent;
        pos = 0;
        foundPos = 0;
        
        while ((foundPos = content.find(s1, pos)) != std::string::npos)
        {
            newContent += content.substr(pos, foundPos - pos);
            newContent += s2;
            pos = foundPos + s1.length();
        }
        newContent += content.substr(pos);
        outFile << newContent << std::endl;
    }
    // Close the files
    file.close();
    outFile.close();

    std::cout << "File processing complete. Output written to: " << fileReplace << std::endl;

    return 0;
}
