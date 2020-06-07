#include "Soldier.hpp"

namespace WarGame {

	class Sniper : public Soldier {

	public:
		Sniper(int player_num): Soldier(100, 50, player_num, 100){}
		Sniper(int health, int damage, int p, int m_h) : Soldier(health, damage, p, m_h) {}
		~Sniper() {};

		pair<int, int> strongest(vector<vector<Soldier*>>& board, pair<int, int> source) {
			int max = 0;
			int temp_max;
			pair<int, int> target = make_pair(-100, -100);
			Soldier *source_soldier = board[source.first][source.second];
			for (int i = 0; i < board.size(); i++) {
				for (int j = 0; j < board[0].size(); j++) {
					if ((board[i][j] != nullptr) && (board[i][j]->get_player_number() != source_soldier->get_player_number())) {
						temp_max = board[i][j]->get_health_points();
						if (temp_max > max) {
							max = temp_max;
							target = { i, j };
						}
					}
				}
			}
			return target;
		}

		 void Attack(vector<std::vector<Soldier*>>& board, std::pair<int, int> source) override {
			pair<int, int> target = strongest(board, source);
			if (make_pair(-100, -100) != target) {
				Soldier *enemy = board[target.first][target.second];
				Soldier *source_soldier = board[source.first][source.second];
				int new_health = enemy->get_health_points() - source_soldier->get_damage_point();
				enemy->set_health_points(new_health);
				if (enemy->get_health_points() <= 0) {
					delete enemy;
					board[target.first][target.second] = nullptr;
				}
			}
			

		}

		 void FullAttack(vector<vector<Soldier*>>& board, pair<int, int> source) override {
			Attack(board, source);
	
		}
	};
}