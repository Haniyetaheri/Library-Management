#include "Erore.h"
#include <string>
#include <iostream>
//constructor and access functions of erroe class  :
Erore::Erore(std::string mas)
{
	massae = mas;
}
void Erore::get_massae()
{
	std::cout << massae;
}
