#include "pch.h"
#include "../PasdideEmpire/PlayerCharacter.h"
#include "../PasdideEmpire/WarriorJob.h"

TEST(TestPlayerCharacter, TestMoveForward) {
	PlayerCharacter l_player(0, 0, std::string(), new WarriorJob(), 0, 0, 0, 0, 0, Inventory());
	l_player.move(5, 6);
	EXPECT_EQ(l_player.getX(), 5);
	EXPECT_EQ(l_player.getY(), 6);
}

TEST(TestPlayerCharacter, TestMoveBackward) {
	PlayerCharacter l_player(0, 0, std::string(), new WarriorJob(), 0, 0, 0, 0, 0, Inventory());
	l_player.move(-4, -3);
	EXPECT_EQ(l_player.getX(), -4);
	EXPECT_EQ(l_player.getY(), -3);
}