#include "Soldier.hpp"

namespace WarGame {

	class Paramedic : public Soldier {
	public:
		Paramedic(int player_num): Soldier(100, 0){}
	};
}