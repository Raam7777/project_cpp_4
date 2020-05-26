
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

	board[{5, 2}] = new FootSoldier(1);
	board[{0,5}] = new FootSoldier(1);

    board[{7,0}] = new FootSoldier(2);
	board[{7,5}] = new FootSoldier(2);

    CHECK(board.has_soldiers(1) == true);
    CHECK(board.has_soldiers(2) == true);
	CHECK(board[{5, 2}]->get_health_points() == 100);
	CHECK(board[{0, 5}]->get_health_points() == 100);
	CHECK(board[{7, 0}]->get_health_points() == 100);
	CHECK(board[{7, 5}]->get_health_points() == 100);


    board.move(1,{5,2},WarGame::Board::MoveDIR::Down);
    CHECK(board.has_soldiers(2) == true);
    CHECK(board.has_soldiers(1) == true);

    board.move(1,{7,0},WarGame::Board::MoveDIR::Left);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));

    board.move(1,{0,5},WarGame::Board::MoveDIR::Down);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));

    board.move(1,{7,5},WarGame::Board::MoveDIR::Left);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
}

TEST_CASE("FootCommander"){
    Board board (8, 8);

    CHECK(!board.has_soldiers(1));
    CHECK(!board.has_soldiers(2));

    board[{5,2}] = new FootCommander(1);
	board[{0,5}] = new FootCommander(1);

    board[{7,1}] = new FootCommander(2);
	board[{7,5}] = new FootCommander(2);

    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));

	CHECK(board[{5, 2}]->get_health_points() == 150);
	CHECK(board[{0, 5}]->get_health_points() == 150);
	CHECK(board[{7, 1}]->get_health_points() == 150);
	CHECK(board[{7, 5}]->get_health_points() == 150);

    board.move(1,{5,2},WarGame::Board::MoveDIR::Down);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));

    board.move(1,{7,1},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));

    board.move(1,{0,5},WarGame::Board::MoveDIR::Down);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
   
    board.move(1,{7,5},WarGame::Board::MoveDIR::Left);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
 
}

TEST_CASE("Sniper"){
    Board board (8, 8);

    CHECK(!board.has_soldiers(1));
    CHECK(!board.has_soldiers(2));

    board[{5,2}] = new Sniper(1);
	board[{0,5}] = new Sniper(1);

    board[{7,1}] = new Sniper(2);
	board[{7,5}] = new Sniper(2);

    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
	CHECK(board[{5, 2}]->get_health_points() == 100);
	CHECK(board[{0, 5}]->get_health_points() == 100);
	CHECK(board[{7, 1}]->get_health_points() == 100);
	CHECK(board[{7, 5}]->get_health_points() == 100);

	board.move(1, { 5,2 }, WarGame::Board::MoveDIR::Down);
	CHECK(board[{7, 1}]->get_health_points() == 50);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
 
    board.move(1,{7,1},WarGame::Board::MoveDIR::Right);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));

    board.move(1,{0,5},WarGame::Board::MoveDIR::Down);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    
    board.move(1,{7,5},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
  
 
}
TEST_CASE("SniperCommander"){
    Board board (8, 8);

    CHECK(!board.has_soldiers(1));
    CHECK(!board.has_soldiers(2));

    board[{0,1}] = new SniperCommander(1);
	board[{0,5}] = new SniperCommander(1);

    board[{7,1}] = new SniperCommander(2);
	board[{7,5}] = new SniperCommander(2);

    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));

    board.move(1,{0,1},WarGame::Board::MoveDIR::Right);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    
    board.move(1,{7,1},WarGame::Board::MoveDIR::Left);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));

    board.move(1,{0,5},WarGame::Board::MoveDIR::Down);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    
    board.move(1,{7,5},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
}


TEST_CASE("FootSoldier and Sniper"){
    Board board (8, 8);

    CHECK(!board.has_soldiers(1));
    CHECK(!board.has_soldiers(2));

    board[{5,2}] = new Sniper(1);
	board[{0,5}] = new FootSoldier(1);

    board[{7,1}] = new FootSoldier(2);
	board[{7,8}] = new Sniper(2);

    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
	CHECK(board[{5, 2}]->get_health_points() == 100);
	CHECK(board[{0, 5}]->get_health_points() == 100);
	CHECK(board[{7, 1}]->get_health_points() == 100);
	CHECK(board[{7, 8}]->get_health_points() == 100);

    board.move(1,{5,2},WarGame::Board::MoveDIR::Down);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    
    board.move(1,{7,1},WarGame::Board::MoveDIR::Right);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
   
    board.move(1,{0,5},WarGame::Board::MoveDIR::Down);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    
    board.move(1,{7,8},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
}

TEST_CASE("FootSoldier, Sniper, FootCommander"){
    Board board (8, 8);

    CHECK(!board.has_soldiers(1));
    CHECK(!board.has_soldiers(2));

    board[{0,1}] = new Sniper(1);
	board[{5,2}] = new FootSoldier(1);
    board[{0,6}] = new FootCommander(1);

    board[{7,5}] = new FootSoldier(2);
	board[{7,1}] = new Sniper(2);
    board[{7,6}] = new FootCommander(2);

    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
	CHECK(board[{0, 1}]->get_health_points() == 100);
	CHECK(board[{5, 2}]->get_health_points() == 100);
	CHECK(board[{0, 6}]->get_health_points() == 150);
	CHECK(board[{7, 5}]->get_health_points() == 100);
	CHECK(board[{7, 1}]->get_health_points() == 100);
	CHECK(board[{7, 6}]->get_health_points() == 150);

    board.move(1,{0,1},WarGame::Board::MoveDIR::Down);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    
    board.move(1,{7,1},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));

    board.move(1,{5,2},WarGame::Board::MoveDIR::Down);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    
    board.move(1,{7,5},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));

    board.move(1,{0,6},WarGame::Board::MoveDIR::Left);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    
    board.move(1,{7,6},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
}

TEST_CASE("FootSoldier, Sniper, FootCommander, SniperCommander"){
    Board board (8, 8);

    CHECK(!board.has_soldiers(1));
    CHECK(!board.has_soldiers(2));

    board[{0,1}] = new Sniper(1);
	board[{5,2}] = new FootSoldier(1);
    board[{0,4}] = new FootCommander(1);
	board[{0,6}] = new SniperCommander(1);

    board[{7,1}] = new FootSoldier(2);
	board[{7,5}] = new Sniper(2);
    board[{7,2}] = new FootCommander(2);
	board[{7,6}] = new SniperCommander(2);

    CHECK(board.has_soldiers(1));
    CHECK(board.has_soldiers(2));
	CHECK(board[{0, 1}]->get_health_points() == 100);
	CHECK(board[{5, 2}]->get_health_points() == 100);
	CHECK(board[{0, 4}]->get_health_points() == 150);
	CHECK(board[{0, 6}]->get_health_points() == 120);
	CHECK(board[{7, 1}]->get_health_points() == 100);
	CHECK(board[{7, 5}]->get_health_points() == 100);
	CHECK(board[{7, 2}]->get_health_points() == 150);
	CHECK(board[{7, 6}]->get_health_points() == 120);

    board.move(1,{0,1},WarGame::Board::MoveDIR::Down);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    
    board.move(1,{7,1},WarGame::Board::MoveDIR::Right);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
  
    board.move(1,{0,5},WarGame::Board::MoveDIR::Down);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    
    board.move(1,{7,5},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
  
    board.move(1,{0,4},WarGame::Board::MoveDIR::Right);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    
    board.move(1,{0,6},WarGame::Board::MoveDIR::Left);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
    
    board.move(1,{7,2},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));

    board.move(1,{7,6},WarGame::Board::MoveDIR::Up);
    CHECK(board.has_soldiers(2));
    CHECK(board.has_soldiers(1));
}

TEST_CASE("Exceptions") {
	Board board(8, 8);

	board[{0, 0}] = new FootCommander(1);
	board[{0, 5}] = new FootSoldier(1);
	board[{4, 7}] = new Sniper(1);
	board[{7, 1}] = new Paramedic(1);

	board[{7, 7}] = new FootCommander(2);
	board[{2, 7}] = new FootSoldier(2);
	board[{0, 7}] = new Sniper(2);
	board[{7, 4}] = new Paramedic(2);

	CHECK_THROWS(board.move(1, { 0, 5 }, WarGame::Board::MoveDIR::Up));
	CHECK_THROWS(board.move(1, { 0, 0 }, WarGame::Board::MoveDIR::Left));
	CHECK_THROWS(board.move(1, { 4, 7 }, WarGame::Board::MoveDIR::Right));
	CHECK_THROWS(board.move(1, { 7, 1 }, WarGame::Board::MoveDIR::Down));
	CHECK_THROWS(board.move(2, { 7, 7 }, WarGame::Board::MoveDIR::Right));
	CHECK_THROWS(board.move(2, { 2, 7 }, WarGame::Board::MoveDIR::Right));
	CHECK_THROWS(board.move(2, { 0, 7 }, WarGame::Board::MoveDIR::Up));
	CHECK_THROWS(board.move(2, { 7, 4 }, WarGame::Board::MoveDIR::Down));
}
