#include "Soldier.hpp"

namespace WarGame {

	class FootSoldier : public Soldier {
	
		public:
		FootSoldier(int player_num): Soldier(100, 10, player_num, 100){}
		FootSoldier(int health, int damage, int p, int m_h): Soldier(health, damage, p, m_h){}
		~FootSoldier() {};
		
		 void FullAttack(vector<vector<Soldier*>>& board, pair<int, int> source) override {
				 Attack(board, source);	
		}
	
		 void Attack(vector<vector<Soldier*>>& board, pair<int, int> source) override {
			pair<int, int> target = closest_enemy(board, source);
			if (make_pair(-100, -100) == target) {
				return;
			}
			Soldier *enemy = board[target.first][target.second];
			Soldier *source_soldier = board[source.first][source.second];
			int new_health = enemy->get_health_points() - source_soldier->get_damage_point();
			enemy->set_health_points(new_health);
			if (enemy->get_health_points() <= 0) {
				delete enemy;
				board[target.first][target.second] = nullptr;
			}
			
		}
	};
}
