#include "Soldier.hpp"

namespace WarGame {

	class Paramedic : public Soldier {

	public:
		Paramedic(int player_num): Soldier(100, 0, player_num, 100){}
		Paramedic(int health, int damage, int p, int m_h) : Soldier(health, damage, p, m_h) {}
		~Paramedic() {};

		bool to_heal(vector<vector<Soldier*>>& board, int x, int y, int player_num) {
			Soldier *soldier = board[x][y];
			if (x < 0 || y >= board.size() || x >= board.size() || y < 0) {
				return false;
			}
			if (soldier != nullptr && soldier->get_player_number() == player_num) {
				return true;
			}
			return false;
		}

		 void Attack(vector<vector<Soldier*>>& board, pair<int, int> source) override {
			int x = source.first;
			int y = source.second;
			Soldier *soldier; 
			int health;
			int num = board[x][y]->get_player_number();
			if (to_heal(board, x - 1, y - 1, num)) {
				soldier = board[x - 1][y - 1];
				health = soldier->get_max_health();
				soldier->set_health_points(health);
			}
			if (to_heal(board, x, y - 1, num)) {
				soldier = board[x][y - 1];
				health = soldier->get_max_health();
				soldier->set_health_points(health);
			}
			if (to_heal(board, x - 1, y, num)) {
				soldier = board[x - 1][y];
				health = soldier->get_max_health();
				soldier->set_health_points(health);
			}
			if (to_heal(board, x - 1, y + 1, num)) {
				soldier = board[x - 1][y + 1];
				health = soldier->get_max_health();
				soldier->set_health_points(health);
			}
			if (to_heal(board, x, y + 1, num)) {
				soldier = board[x][y + 1];
				health = soldier->get_max_health();
				soldier->set_health_points(health);
			}
			if (to_heal(board, x + 1, y + 1, num)) {
				soldier = board[x + 1][y + 1];
				health = soldier->get_max_health();
				soldier->set_health_points(health);
			}
			if (to_heal(board, x + 1, y, num)) {
				soldier = board[x + 1][y];
				health = soldier->get_max_health();
				soldier->set_health_points(health);
			}
			if (to_heal(board, x + 1, y - 1, num)) {
				soldier = board[x + 1][y - 1];
				health = soldier->get_max_health();
				soldier->set_health_points(health);
			}	
		}

		 void FullAttack(vector<vector<Soldier*>>& board, pair<int, int> source) override {
			Attack(board, source);
		}
	};
}