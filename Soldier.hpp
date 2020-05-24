#pragma once

namespace WarGame {

	class Soldier {
		int health_points;
		int damage_point;

	public:
		
		Soldier(int health, int damage) 
		: health_points(health), damage_point(damage){}

		int get_health_points() {
			return health_points;
		}
		void set_health_points(int h_p) {
			health_points = h_p;
		}
		int get_damage_point() {
			return damage_point;
		}
		void set_damage_point(int d_p) {
			damage_point = d_p;
		}
		//virtual void shoot(Board& board, std::pair<int, int> location) {};


	};

}