#include "doctest.h"
#include <iostream>
#include "Board.hpp"
#include "FootSoldier.hpp"
#include "FootCommander.hpp"
#include "Sniper.hpp"
#include "SniperCommander.hpp"
#include "Paramedic.hpp"
#include "ParamedicCommander.hpp"


using namespace std;
using namespace WarGame;

TEST_CASE("FootSoldier"){//15
    Board board (8, 8);
    CHECK(board.has_soldiers(1) == false);
    CHECK(board.has_soldiers(2) == false);

    board[{0,1}] = new FootSoldier(1);
	board[{0,5}] = new FootSoldier(1);

    board[{7,1}] = new FootSoldier(2);
	board[{7,5}] = new FootSoldier(2);

    CHECK(board.has_soldiers(1) == true);
    CHECK(board.has_soldiers(2) == true);

    board.move(1,{0,1},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    CHECK_THROWS(board.move(1,{0,1},WarGame::Board::MoveDIR::Up));
    board.move(1,{7,1},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    CHECK_THROWS(board.move(1,{7,1},WarGame::Board::MoveDIR::Up));

    board.move(1,{0,5},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    CHECK_THROWS(board.move(1,{0,5},WarGame::Board::MoveDIR::Up));
    board.move(1,{7,5},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    CHECK_THROWS(board.move(1,{7,5},WarGame::Board::MoveDIR::Up));
 
}

TEST_CASE("FootCommander"){
    Board board (8, 8);

    CHECK(board.has_soldiers(1) == false);
    CHECK(board.has_soldiers(2) == false);

    board[{0,1}] = new FootCommander(1);
	board[{0,5}] = new FootCommander(1);

    board[{7,1}] = new FootCommander(2);
	board[{7,5}] = new FootCommander(2);

    CHECK(board.has_soldiers(1) == true);
    CHECK(board.has_soldiers(2) == true);

    board.move(1,{0,1},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    CHECK_THROWS(board.move(1,{0,1},WarGame::Board::MoveDIR::Up));
    board.move(1,{7,1},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    CHECK_THROWS(board.move(1,{7,1},WarGame::Board::MoveDIR::Up));

    board.move(1,{0,5},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    CHECK_THROWS(board.move(1,{0,5},WarGame::Board::MoveDIR::Up));
    board.move(1,{7,5},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    CHECK_THROWS(board.move(1,{7,5},WarGame::Board::MoveDIR::Up));
 
}

TEST_CASE("Sniper"){
    Board board (8, 8);

    CHECK(board.has_soldiers(1) == false);
    CHECK(board.has_soldiers(2) == false);

    board[{0,1}] = new Sniper(1);
	board[{0,5}] = new Sniper(1);

    board[{7,1}] = new Sniper(2);
	board[{7,5}] = new Sniper(2);

    CHECK(board.has_soldiers(1) == true);
    CHECK(board.has_soldiers(2) == true);

    board.move(1,{0,1},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    CHECK_THROWS(board.move(1,{0,1},WarGame::Board::MoveDIR::Up));
    board.move(1,{7,1},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    CHECK_THROWS(board.move(1,{7,1},WarGame::Board::MoveDIR::Up));

    board.move(1,{0,5},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    CHECK_THROWS(board.move(1,{0,5},WarGame::Board::MoveDIR::Up));
    board.move(1,{7,5},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    CHECK_THROWS(board.move(1,{7,5},WarGame::Board::MoveDIR::Up));
 
}
TEST_CASE("SniperCommander"){
    Board board (8, 8);

    CHECK(board.has_soldiers(1) == false);
    CHECK(board.has_soldiers(2) == false);

    board[{0,1}] = new SniperCommander(1);
	board[{0,5}] = new SniperCommander(1);

    board[{7,1}] = new SniperCommander(2);
	board[{7,5}] = new SniperCommander(2);

    CHECK(board.has_soldiers(1) == true);
    CHECK(board.has_soldiers(2) == true);

    board.move(1,{0,1},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    CHECK_THROWS(board.move(1,{0,1},WarGame::Board::MoveDIR::Up));
    board.move(1,{7,1},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    CHECK_THROWS(board.move(1,{7,1},WarGame::Board::MoveDIR::Up));

    board.move(1,{0,5},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    CHECK_THROWS(board.move(1,{0,5},WarGame::Board::MoveDIR::Up));
    board.move(1,{7,5},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    CHECK_THROWS(board.move(1,{7,5},WarGame::Board::MoveDIR::Up));
 
}


TEST_CASE("FootSoldier and Sniper"){
    Board board (8, 8);

    CHECK(board.has_soldiers(1) == false);
    CHECK(board.has_soldiers(2) == false);

    board[{0,1}] = new Sniper(1);
	board[{0,5}] = new FootSoldier(1);

    board[{7,1}] = new FootSoldier(2);
	board[{7,5}] = new Sniper(2);

    CHECK(board.has_soldiers(1) == true);
    CHECK(board.has_soldiers(2) == true);

    board.move(1,{0,1},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    CHECK_THROWS(board.move(1,{0,1},WarGame::Board::MoveDIR::Up));
    board.move(1,{7,1},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    CHECK_THROWS(board.move(1,{7,1},WarGame::Board::MoveDIR::Up));

    board.move(1,{0,5},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    CHECK_THROWS(board.move(1,{0,5},WarGame::Board::MoveDIR::Up));
    board.move(1,{7,5},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    CHECK_THROWS(board.move(1,{7,5},WarGame::Board::MoveDIR::Up));
 
}

TEST_CASE("FootSoldier, Sniper, FootCommander"){
    Board board (8, 8);

    CHECK(board.has_soldiers(1) == false);
    CHECK(board.has_soldiers(2) == false);

    board[{0,1}] = new Sniper(1);
	board[{0,5}] = new FootSoldier(1);
    board[{0,6}] = new FootCommander(1);

    board[{7,1}] = new FootSoldier(2);
	board[{7,5}] = new Sniper(2);
    board[{0,6}] = new FootCommander(1);

    CHECK(board.has_soldiers(1) == true);
    CHECK(board.has_soldiers(2) == true);

    board.move(1,{0,1},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    CHECK_THROWS(board.move(1,{0,1},WarGame::Board::MoveDIR::Up));
    board.move(1,{7,1},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    CHECK_THROWS(board.move(1,{7,1},WarGame::Board::MoveDIR::Up));

    board.move(1,{0,5},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    CHECK_THROWS(board.move(1,{0,5},WarGame::Board::MoveDIR::Up));
    board.move(1,{7,5},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    CHECK_THROWS(board.move(1,{7,5},WarGame::Board::MoveDIR::Up));

    board.move(1,{0,6},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    CHECK_THROWS(board.move(1,{0,6},WarGame::Board::MoveDIR::Up));
    board.move(1,{7,6},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    CHECK_THROWS(board.move(1,{7,6},WarGame::Board::MoveDIR::Up));
 
}

TEST_CASE("FootSoldier, Sniper, FootCommander, SniperCommander"){
    Board board (8, 8);

    CHECK(board.has_soldiers(1) == false);
    CHECK(board.has_soldiers(2) == false);

    board[{0,1}] = new Sniper(1);
	board[{0,5}] = new FootSoldier(1);
    board[{0,4}] = new FootCommander(1);
	board[{0,6}] = new SniperCommander(1);

    board[{7,1}] = new FootSoldier(2);
	board[{7,5}] = new Sniper(2);
    board[{7,2}] = new FootCommander(1);
	board[{7,6}] = new SniperCommander(1);

    CHECK(board.has_soldiers(1) == true);
    CHECK(board.has_soldiers(2) == true);

    board.move(1,{0,1},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    CHECK_THROWS(board.move(1,{0,1},WarGame::Board::MoveDIR::Up));
    board.move(1,{7,1},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    CHECK_THROWS(board.move(1,{7,1},WarGame::Board::MoveDIR::Up));

    board.move(1,{0,5},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    CHECK_THROWS(board.move(1,{0,5},WarGame::Board::MoveDIR::Up));
    board.move(1,{7,5},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    CHECK_THROWS(board.move(1,{7,5},WarGame::Board::MoveDIR::Up));

    board.move(1,{0,4},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    CHECK_THROWS(board.move(1,{0,4},WarGame::Board::MoveDIR::Up));
    board.move(1,{0,6},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    CHECK_THROWS(board.move(1,{0,6},WarGame::Board::MoveDIR::Up));

    board.move(1,{7,2},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    CHECK_THROWS(board.move(1,{7,2},WarGame::Board::MoveDIR::Up));
    board.move(1,{7,6},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    CHECK_THROWS(board.move(1,{7,6},WarGame::Board::MoveDIR::Up));
 
}

