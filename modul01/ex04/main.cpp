#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

std::string	replace_text(std::string line, std::string toReplace, std::string newStr)
{
	std::string newLine;
	// std::size_t	found;
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
			newLine.append(line[i]+"");
		i++;
	}
	return (newLine);
}

// void	write_to_file(std::ofstream newFile, std::string line)
// {
// 	newFile << line;
// 	newFile << std::endl;
// 	return ;
// }

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Error : ";
		std::cout << "./no_sed filePath/fileName word new_word"<< std::endl;
		return (1);
	}
	std::string	fileName = argv[1];
	std::string	strToReplace = argv[2];
	std::string	strReplace = argv[3];
	std::string	line;
	std::ifstream	currentFile(argv[1]);
	std::ofstream	newFile("ooook.replace");

	// std::cout << "file name :"<< fileName<< std::endl;
	// std::cout << "string to replace :"<< strToReplace<< std::endl;
	// std::cout << "string replace :"<< strReplace<< std::endl;
	// currentfile.open(fileName);//here we open the file to read from
	// if (!currentfile.is_open())
	// {
	// 	std::cout << "Error: could not open the file " << fileName;
	// 	std::cout << std::endl;
	// 	return (EXIT_FAILURE);
	// }
	// newFile.open(fileName + ".replace");
	// if (!newFile.is_open())
	// {
	// 	std::cout << "Error: could not create new file: " << fileName << ".replace";
	// 	std::cout << std::endl;
	// 	return (EXIT_FAILURE);
	// }
	while (1)
	{
		std::getline(currentFile, line);//read one line from the file and put it into string line
		if (currentFile.eof())
			break ;
		// std::cout << line << std::endl;
		newFile << replace_text(line, strToReplace, strReplace);
		newFile << std::endl;
		// write_to_file(newFile, replace_text(line, strToReplace, strReplace));
		// std::cout << line.find(strReplace);
		// break;
		
	}



	return (0);
}