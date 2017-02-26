void couple::set_state(g_cost)
{
	gift_cost = g_cost;


	switch(Girl.type) {
		case 0 : Girl.happiness = log(gift_cost / Girl.budget);
			break;
		case 1 : Girl.happiness = gift_cost / Girl.budget;
			break;
		case 2 ; Girl.happiness = exp(gift_cost / Girl.budget);
			break;
	}

	switch(Boy.type) {
		case 0 : Boy.happiness = Boy.budget - gift_cost;
			break;
		case 1 : Boy.happiness = Girl.happpiness;
			break;
		case 2 : Boy.happiness = Girl.intelligence;
			break;
	}

	happiness = Boy.happiness + Girl.happiness;
	compatibility = (Boy.budget - Girl.budget) + abs(Boy.attraction - Girl.attraction) + abs(Boy.intelligence - Girl.intelligence);
		
}
