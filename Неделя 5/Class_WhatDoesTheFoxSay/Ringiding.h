#pragma once

class WhatDoesTheFoxSay
{
public:

	enum WhatDoesTheFoxSayState
	{
		cat,
		bird,
		fox
	};


	WhatDoesTheFoxSayState GetState()
	{
		return State;
	}

	void SetState(WhatDoesTheFoxSayState State);

private:
	WhatDoesTheFoxSayState State;
};