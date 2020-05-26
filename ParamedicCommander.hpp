#include "Soldier.hpp"

namespace WarGame {

	class ParamedicCommander : public Soldier {

	public:
		ParamedicCommander(int player_num): Soldier(200, 0, player_num){}
		~ParamedicCommander() {};

		virtual void Attack(std::vector<std::vector<Soldier*>>& board, std::pair<int, int> location) override {}
	};
}
