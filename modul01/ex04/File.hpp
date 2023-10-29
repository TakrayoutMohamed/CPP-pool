#ifndef FILE_HPP
# define FILE_HPP
# include <iostream>
# include <fstream>

class File
{
	private:
		std::string &_fileName;
	public:
		File(std::string fileName);
		~File();
		void		setFileName(std::string& fileName);
		std::string	File::getFileName(void);
		int			openFile(std::string);
		int			readFile(std::string);
};

#endif
