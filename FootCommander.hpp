#include "Soldier.hpp"

namespace WarGame {

	class FootCommander : public Soldier {
	public:
		FootCommander(int player_num): Soldier(150, 20){}
	};
}