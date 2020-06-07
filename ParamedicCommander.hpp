#include "Soldier.hpp"

namespace WarGame {

	class ParamedicCommander : public Paramedic {

	public:
		ParamedicCommander(int player_num): Paramedic(200, 0, player_num, 200){}
		~ParamedicCommander() {};

		 void FullAttack(vector<vector<Soldier*>>& board, pair<int, int> source) override {
			Attack(board, source);
			Soldier *source_soldier = board[source.first][source.second];
			for (int i = 0; i < board.size(); i++) {
				for (int j = 0; j < board[0].size(); j++) {
					if ((board[i][j] != nullptr) && (board[i][j]->get_player_number() == source_soldier->get_player_number())) {
						if (dynamic_cast<Paramedic*>(board[i][j]) && !dynamic_cast<ParamedicCommander*>(board[i][j])) {
							pair<int, int> target = make_pair(i, j);
							Attack(board, target);
						}
					}

				}
			}
		}
	};
}
