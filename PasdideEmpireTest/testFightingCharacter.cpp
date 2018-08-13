#include "pch.h"
#include "../PasdideEmpire/PlayerCharacter.h"
#include "../PasdideEmpire/WarriorJob.h"

TEST(TestFightingCharacter, TestTakeDammage) {
	PlayerCharacter l_player(0, 0, std::string(), new WarriorJob(), 10, 5, 0, 0, 0, Inventory());
	l_player.takeDammage(4);
	EXPECT_EQ(l_player.getCurrentHp(), 1);
}

TEST(TestFightingCharacter, TestHeal) {
	PlayerCharacter l_player(0, 0, std::string(), new WarriorJob(), 10, 5, 0, 0, 0, Inventory());
	l_player.heal(4);
	EXPECT_EQ(l_player.getCurrentHp(), 9);
}

TEST(TestFightingCharacter, TestOverHeal) {
	PlayerCharacter l_player(0, 0, std::string(), new WarriorJob(), 10, 5, 0, 0, 0, Inventory());
	l_player.heal(9);
	EXPECT_EQ(l_player.getCurrentHp(), 10);
}
