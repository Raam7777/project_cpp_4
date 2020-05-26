#include "Soldier.hpp"

namespace WarGame {

	class FootSoldier : public Soldier {
	
		public:
		FootSoldier(int player_num): Soldier(100, 10, player_num){}
		~FootSoldier() {};
		
		virtual void Attack(std::vector<std::vector<Soldier*>>& board, std::pair<int, int> location) override {}

		
	};
}
