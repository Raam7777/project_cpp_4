#include "Board.hpp"
using namespace std;
namespace WarGame {

	Soldier *& Board::operator[](pair<int, int> location) {
		return board[location.first][location.second];
	}

	Soldier* Board::operator[](pair<int, int> location) const {
		return board[location.first][location.second];
	}

	void Board::move(uint player_num, pair<int, int> source, MoveDIR direction) {
		if (source.first < 0 || source.first >= board.size() || source.second < 0 || source.second >=board[0].size()) {
			throw invalid_argument("The source is outside the board border");
		}

		pair<int, int> target;
		if (board[source.first][source.second] == nullptr) {
			throw invalid_argument("There is no soldier in this location");
		}

		Soldier *soldier = this->board[source.first][source.second];
		if (soldier->get_player_number() != player_num) {
			throw invalid_argument("The soldier in this location is not yours");
		}
		if (direction == Up) target = make_pair(source.first + 1, source.second);
		else if (direction == Down) target = make_pair(source.first - 1, source.second);
		else if (direction == Left) target = make_pair(source.first, source.second - 1);
		else if (direction == Right) target = make_pair(source.first, source.second + 1);

		if (target.first < 0 || target.first >= board.size() || target.second < 0 || target.second >= board[0].size()) {
			throw invalid_argument("The target is outside the board border");
		}

		if (board[target.first][target.second] != nullptr) {
			throw invalid_argument("There is another soldier in this location");
		}
		else {
			board[source.first][source.second] = nullptr;
			board[target.first][target.second] = soldier;
			soldier->FullAttack(board, target);
		}
	}

	bool Board::has_soldiers(uint player) const {
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[i].size(); j++) {
				if (board[i][j] != nullptr && board[i][j]->get_player_number() == player) {
					return true;
				}
			}
		}
		return false;
	}

}