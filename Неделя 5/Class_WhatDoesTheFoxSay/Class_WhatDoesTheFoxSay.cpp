#include <iostream>
#include <string>
#include <fstream>
#include "Ringiding.h"

int main()
{
	WhatDoesTheFoxSay fox;
	fox.SetState(WhatDoesTheFoxSay::WhatDoesTheFoxSayState::bird);

	switch (fox.GetState())
	{
	case WhatDoesTheFoxSay::WhatDoesTheFoxSayState::bird:
		std::cout << "tweet" << std::endl;
		break;
	case WhatDoesTheFoxSay::WhatDoesTheFoxSayState::cat:
		std::cout << "meow" << std::endl;
		break;
	case WhatDoesTheFoxSay::WhatDoesTheFoxSayState::fox:
		std::cout << "Ring-ding-ding-ding-dingeringeding!" << std::endl;
		break;
	}

	return 0;

}