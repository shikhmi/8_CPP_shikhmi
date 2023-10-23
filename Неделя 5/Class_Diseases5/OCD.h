#pragma once
#include <string>
#include "Disease.h"
class OCD: public Disease
{
private:
	int excessive_pedantry();
public:
	virtual int frightening_drives();
	int apathy() override;
	std::string storytelling() override;
};

