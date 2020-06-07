#include "Soldier.hpp"

namespace WarGame {

	class FootCommander : public FootSoldier {

	public:
		FootCommander(int player_num): FootSoldier(150, 20, player_num, 150){}
		~FootCommander() {};

		 void FullAttack(vector<vector<Soldier*>>& board, pair<int, int> source) override {
			Attack(board, source);
			Soldier *source_soldier = board[source.first][source.second];
			for (int i = 0; i < board.size(); i++) {
				for (int j = 0; j < board[0].size(); j++) {
					if ((board[i][j] != nullptr) && (board[i][j]->get_player_number() == source_soldier->get_player_number())) {
						if (dynamic_cast<FootSoldier*>(board[i][j]) && !dynamic_cast<FootCommander*>(board[i][j])) {
							pair<int, int> target = make_pair(i, j);
							Attack(board, target);
						}
					}
						
				}
			}
		}
		
	};
}