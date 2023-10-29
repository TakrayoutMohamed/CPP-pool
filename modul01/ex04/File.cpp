#include "./File.hpp"

File::File(std::string fileName) :_fileName(fileName)
{
}

File::~File()
{
}

void	File::setFileName(std::string &fileName)
{
	this->_fileName = fileName;
}

std::string	File::getFileName(void)
{
	return (this->_fileName);
}
