#include "Soldier.hpp"

namespace WarGame {

	class Sniper : public Soldier {
	public:
		Sniper(int player_num): Soldier(100, 50){}
	};
}