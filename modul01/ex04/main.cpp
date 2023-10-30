#include <iostream>
#include <fstream>
#include <string>

std::string	replace_text(std::string line, std::string toReplace, std::string newStr)
{
	std::string	newLine;
	int			i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line.compare(i, toReplace.length(), toReplace) == 0)
		{
			newLine.append(newStr);
			i = i + toReplace.length();
			continue ;
		}
		else
			newLine  = newLine + line[i];
		i++;
	}
	return (newLine);
}

int	main(int argc, char **argv)
{
	std::string	fileName;
	std::string	strToReplace;
	std::string	strReplace;
	std::string	line;
	std::ifstream	currentFile;
	std::ofstream	newFile;
	if (argc != 4)
	{
		std::cout << "Error : ";
		std::cout << "./no_sed filePath/fileName word new_word"<< std::endl;
		return (1);
	}
	fileName = argv[1];
	strToReplace = argv[2];
	strReplace = argv[3];

	currentFile.open(fileName);
	if (!currentFile.is_open())
	{
		std::cout << "the file "<< fileName << " entered could not be opened ";
		std::cout << std::endl;
		return (EXIT_FAILURE);
	}
	newFile.open(fileName + ".replace");
	if (!newFile.is_open())
	{
		std::cout << "the file :"<< fileName + ".replace" << "entered could not be created ";
		std::cout << std::endl;
		return (EXIT_FAILURE);
	}
	while (std::getline(currentFile, line))
	{
		// std::cout << line << std::endl;
		newFile << replace_text(line, strToReplace, strReplace);
		newFile << std::endl;
	}
	return (0);
}