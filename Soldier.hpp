#pragma once
#include <math.h>
using namespace std;
namespace WarGame {

	class Soldier {
	private:
		int damage_point;
		int player_number;
		int health_points;
		int max_health;

	public:
		
		Soldier(int health, int damage, int p, int m_h) 
		: health_points(health), damage_point(damage), player_number(p), max_health(m_h){}

		virtual ~Soldier() {};

		int get_max_health() {
			return this->max_health;
		}

		int get_health_points() {
			return this->health_points;
		}
		void set_health_points(int damage) {
			this->health_points = damage;
		}
		int get_damage_point() {
			return this->damage_point;
		}

		int get_player_number() {
			return this->player_number;
		}

		double distance(pair<int, int> source, pair<int, int> target) {
			double x1, x2, y1, y2;
			x1 = source.first;
			y1 = source.second;
			x2 = target.first;
			y2 = target.second;
			return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
		}

		pair<int, int> closest_enemy(vector<vector<Soldier*>> &board, pair<int, int> source) {
			double dist = board.size() * board.size();
			double temp_dist;
			pair<int, int> target = make_pair(-100, -100);
			Soldier *source_soldier = board[source.first][source.second];
			for (int i = 0; i < board.size(); i++) {
				for (int j = 0; j < board[i].size(); j++) {
					if (board[i][j] != nullptr && board[i][j]->get_player_number() != source_soldier->get_player_number()) {
						pair<int, int> temp_target = {i, j};
						temp_dist = distance(source, temp_target);
						if (temp_dist < dist) {
							dist = temp_dist;
							target = temp_target;
						}
					}
				}
			}
			return target;
		}
		
		virtual void Attack(vector<vector<Soldier*>> &board, pair<int, int> location) = 0;
		virtual void FullAttack(vector<std::vector<Soldier*>>& board, std::pair<int, int> source) = 0;
		
	};

	

}