#include "Soldier.hpp"

namespace WarGame {

	class FootCommander : public Soldier {

	public:
		FootCommander(int player_num): Soldier(150, 20, player_num){}

		~FootCommander() {};

		// Inherited via Soldier
		virtual void Attack(std::vector<std::vector<Soldier*>>& board, std::pair<int, int> location) override {}
	};
}