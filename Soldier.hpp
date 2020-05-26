#pragma once

namespace WarGame {

	class Soldier {
	private:
		int damage_point;
		int player_number;
		int health_points;

	public:
		
		
		Soldier(int health, int damage, uint p) 
		: health_points(health), damage_point(damage), player_number(p){}

		virtual ~Soldier() {};

		int get_health_points() {
			return this->health_points;
		}
		void set_health_points(int h_p) {
			this->health_points = h_p;
		}
		int get_damage_point() {
			return this->damage_point;
		}

		int get_player_number() {
			return this->player_number;
		}
		
		virtual void Attack(std::vector<std::vector<Soldier*>> &board, std::pair<int, int> location) = 0;


	};

}