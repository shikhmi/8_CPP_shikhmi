#pragma once
#include "OCD.h"
class Panic_Attacks: public OCD
{
	int frightening_drives() override;
	int panic_attacks();
	int apathy() override;
};

