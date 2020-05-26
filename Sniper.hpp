#include "Soldier.hpp"

namespace WarGame {

	class Sniper : public Soldier {

	public:
		Sniper(int player_num): Soldier(100, 50, player_num){}
		~Sniper() {};

		virtual void Attack(std::vector<std::vector<Soldier*>>& board, std::pair<int, int> location) override {}
	};
}