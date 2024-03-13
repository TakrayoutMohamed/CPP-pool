#include "./PmergeMe.hpp"

double getTimeNow()
{
	struct timeval t;

    gettimeofday(&t, NULL);
    return(static_cast<double> (t.tv_sec) + static_cast<double>(t.tv_usec / 1000000.00));
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error :" << std::endl;
		std::cerr << "Syntax to run the program: " << std::endl;
		std::cerr << "./PmergeMe \"positive numbers\" " << std::endl;
		return (1);
	}
	try
	{
		double		startVectorTime;
		double		endVectorTime;
		double		startDequeTime;
		double		endDequeTime;
		PmergeMe 	pm;
		std::string args;

		int i = 1;
		while (i < argc)
		{
			args =  args + " "  + argv[i] + " ";
			i++;
		}
		if (!pm.parseData(args))
			return (1);
		pm.printVector("Befor : ", pm.getDataVector());
		startVectorTime = getTimeNow();
		pm.sortVector();
		endVectorTime = (getTimeNow() - startVectorTime) * 1000000.00;
		pm.printVector("After : ", pm.getDataVector());
		startDequeTime = getTimeNow();
		pm.sortDeque();
		endDequeTime = (getTimeNow() - startDequeTime) * 1000000.00;
		std::cout << "Time to process a range of "<< pm.getDataVector().size() <<" elements with std::[Vector] : " << std::fixed << endVectorTime << "us" << std::endl;
		std::cout << "Time to process a range of "<< pm.getDataDeque().size() <<" elements with std::[Deque] : " << std::fixed << endDequeTime << "us" << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << "Exception Error of type : " << e.what() << std::endl;
	}
	return (0);
}