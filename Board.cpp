#include "Board.hpp"
namespace WarGame {

	Soldier *& Board::operator[](std::pair<int, int> location) {
		//return board[0][1];
	}

	Soldier* Board::operator[](std::pair<int, int> location) const {
		//return board[location.first][location.second];
	}

	void Board::move(uint player_number, std::pair<int, int> source, MoveDIR direction) {

	}

	bool Board::has_soldiers(uint player_number) const {
		/*for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[i].size(); j++) {
				Soldier* soldier = board[i][j];
				if (soldier != nullptr && soldier->get_player_number() == player_number) {
					return true;
				}
			}
		}*/
		return true;
	}

}