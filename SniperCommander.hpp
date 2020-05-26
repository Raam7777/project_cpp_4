#include "Soldier.hpp"

namespace WarGame {

	class SniperCommander : public Soldier {

	public:
		SniperCommander(int player_num): Soldier(120, 100, player_num){}
		~SniperCommander() {};

		virtual void Attack(std::vector<std::vector<Soldier*>>& board, std::pair<int, int> location) override {}
	};
}