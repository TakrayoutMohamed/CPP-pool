# include "./Serializer.hpp"

int	main(void)
{
	Data *pdata;
	pdata = new Data;
	Data *serializeDeserialize;
	pdata->nbr = 10;
	pdata->str = "alvares";
	std::cout << " the sizeof(uintptr_t) : " << sizeof(uintptr_t) << " the sizeof(Data *) : " << sizeof(Data *) << std::endl;
	std::cout << "************** data befor serializing it ********** " << std::endl;
	std::cout << "data->nbr : " << pdata->nbr << std::endl;
	std::cout << "data->str : " << pdata->str << std::endl;
	std::cout << "************** data after serializing it ********** " << std::endl;
	serializeDeserialize = Serializer::deserialize(Serializer::serialize(pdata));
	std::cout << "data->nbr : " << serializeDeserialize->nbr << std::endl;
	std::cout << "data->str : " << serializeDeserialize->str << std::endl;
	std::cout << "************** data after serializing it  ********** " << std::endl;
	std::cout << "data->nbr : " << pdata->nbr << std::endl;
	std::cout << "data->str : " << pdata->str << std::endl;
	delete pdata;
	return (0);
}