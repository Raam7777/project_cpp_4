#include "Soldier.hpp"

namespace WarGame {

	class Paramedic : public Soldier {

	public:
		Paramedic(int player_num): Soldier(100, 0, player_num){}
		~Paramedic() {};
		virtual void Attack(std::vector<std::vector<Soldier*>>& board, std::pair<int, int> location) override {}
	};
}