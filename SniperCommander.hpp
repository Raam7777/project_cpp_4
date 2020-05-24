#include "Soldier.hpp"

namespace WarGame {

	class SniperCommander : public Soldier {
	public:
		SniperCommander(int player_num): Soldier(120, 100){}
	};
}