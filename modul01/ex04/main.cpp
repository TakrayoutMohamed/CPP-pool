// #include "./File.hpp"
#include <iostream>
#include <fstream>
#include <string>

// void	write_to_file(std::ofstream file, std::string text)
// {

// }

// std::ofstream	open_file(std::string fileToOpen)
// {
// 	std::ofstream	file;

// 	file.open(fileToOpen);
// 	return (file);
// }
std::string	replace_text(std::string line, char *str1, char *str2)
{
	std::string newLine;
	std::size_t	found;
	int			i;


	i = 0;
	found = line.find(str1);
	// if (found != std::string::npos)
	while (line[i] != '\0')
	{
		newLine.append(line[i]);
	}
}

void	write_to_file(std::ofstream newFile, const char * line)
{
	newFile << line;
	newFile << std::endl;
	return ;
}

int	main(int argc, char **argv)
{
	std::string	fileName;
	std::string	stringToReplace;
	std::string	stringReplace;
	std::string	line;
	std::ofstream	newFile;
	std::ifstream	currentfile;

	if (argc != 4)
	{
		std::cout << "Error : ";
		std::cout << "./no_sed filePath/fileName word new_word"<< std::endl;
		return (EXIT_FAILURE);
	}
	fileName = argv[1];
	stringToReplace = argv[2];
	stringReplace = argv[3];
	// std::cout << "file name :"<< fileName<< std::endl;
	// std::cout << "string to replace :"<< stringToReplace<< std::endl;
	// std::cout << "string replace :"<< stringReplace<< std::endl;
	currentfile.open(fileName);//here we open the file to read from
	if (!currentfile.is_open())
	{
		std::cout << "Error: could not open the file " << fileName;
		std::cout << std::endl;
		return (EXIT_FAILURE);
	}
	newFile.open(fileName + ".replace");
	if (!newFile.is_open())
	{
		std::cout << "Error: could not create new file: " << fileName << ".replace";
		std::cout << std::endl;
		return (EXIT_FAILURE);
	}
	while (1)
	{
		std::getline(currentfile, line);//read one line from the file and put it into string line
		if (currentfile.eof())
			break ;
		// std::cout << line << std::endl;
		std::cout << line.find(stringReplace);
		break;
		
	}



	return (0);
}