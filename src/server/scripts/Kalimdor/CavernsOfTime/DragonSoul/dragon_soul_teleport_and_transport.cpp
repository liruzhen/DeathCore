/*
 * Copyright (C) 2016 DeathCore <http://www.noffearrdeathproject.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "dragon_soul.h"

class npc_eiendormi : public CreatureScript
{
public:
	npc_eiendormi() : CreatureScript("npc_eiendormi") { }
	bool OnGossipHello(Player* player, Creature* creature)
	{
		if (InstanceScript* instance = creature->GetInstanceScript())
		{
			if (instance->GetBossState(BOSS_MORCHOK) == DONE)
			{
				player->TeleportTo(967, -1870.114f, -3077.727f, -176.308f, 0.390f);
			}
		}
		player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
		return true;
	}
};

class npc_valeera_tele : public CreatureScript
{
public:
	npc_valeera_tele() : CreatureScript("npc_valeera_tele") { }
	bool OnGossipHello(Player* player, Creature* creature)
	{
		if (InstanceScript* instance = creature->GetInstanceScript())
		{
			if (instance->GetBossState(BOSS_MORCHOK) == DONE)
			{
				player->TeleportTo(967, -1735.930f, -1818.239f, -219.328f, 0.0f);
			}
		}
		player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
		return true;
	}
};

class npc_nethestrasz : public CreatureScript
{
public:
	npc_nethestrasz() : CreatureScript("npc_nethestrasz") { }
	bool OnGossipHello(Player* player, Creature* creature)
	{
		if (InstanceScript* instance = creature->GetInstanceScript())
		{
			if (instance->GetBossState(BOSS_HAGARA) == DONE)
			{
				player->TeleportTo(967, -1786.69f, -2393.67f, 341.355f, 0.16f);
			}
		}
		player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
		return true;
	}
};

class travel_to_wyrmrest_base : public CreatureScript
{
public:
	travel_to_wyrmrest_base() : CreatureScript("travel_to_wyrmrest_base") { }
	bool OnGossipHello(Player* player, Creature* creature)
	{
		if (InstanceScript* instance = creature->GetInstanceScript())
		{
			if (instance->GetBossState(DATA_PORTALS_ON_OFF) == DONE)
			{
				player->TeleportTo(967, -1793.22f, -2391.78f, 45.604f, 5.871f);
				player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
			}
		}
		player->CLOSE_GOSSIP_MENU();
		return true;
	}
};

class travel_to_the_eye_of_eternity : public CreatureScript
{
public:
	travel_to_the_eye_of_eternity() : CreatureScript("travel_to_the_eye_of_eternity") { }
	bool OnGossipHello(Player* player, Creature* creature)
	{
		if (InstanceScript* instance = creature->GetInstanceScript())
		{
			if (instance->GetBossState(BOSS_UNSLEEPING) == DONE && instance->GetBossState(BOSS_WARLORD) == DONE)
			{
				player->TeleportTo(967, 13629.7f, 13611.9f, 123.482f, 3.468f);
				player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
			}
		}
		player->CLOSE_GOSSIP_MENU();
		return true;
	}
};

class travel_to_the_deck_of_the_skyfire : public CreatureScript
{
public:
	travel_to_the_deck_of_the_skyfire() : CreatureScript("travel_to_the_deck_of_the_skyfire") { }
	bool OnGossipHello(Player* player, Creature* creature)
	{
		if (InstanceScript* instance = creature->GetInstanceScript())
		{
			if (instance->GetBossState(BOSS_ULTRAXION) == DONE)
			{
				player->TeleportTo(967, 13397.298f, -12131.405f, 153.8732f, 3.152f);
				player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
			}
		}
		player->CLOSE_GOSSIP_MENU();
		return true;
	}
};

class travel_to_Spine : public CreatureScript
{
public:
	travel_to_Spine() : CreatureScript("travel_to_Spine") { }
	bool OnGossipHello(Player* player, Creature* creature)
	{
		if (InstanceScript* instance = creature->GetInstanceScript())
		{
			if (instance->GetBossState(BOSS_WARMASTER) == DONE)
			{
				player->TeleportTo(967, -13855.28f, -13667.97f, 268.03f, 1.64f);
				player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
			}
		}
		player->CLOSE_GOSSIP_MENU();
		return true;
	}
};


class travel_to_Maelstrom : public CreatureScript
{
public:
	travel_to_Maelstrom() : CreatureScript("travel_to_Maelstrom") { }
	bool OnGossipHello(Player* player, Creature* creature)
	{
		if (InstanceScript* instance = creature->GetInstanceScript())
		{
			if (instance->GetBossState(BOSS_ULTRAXION) == DONE)  //Need Spine Done
			{
				player->TeleportTo(967, -12120.15f, -12175.022f, 2.56f, 5.77f);
				player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
			}
		}
		player->CLOSE_GOSSIP_MENU();
		return true;
	}
};


void AddSC_dragon_soul_teleport_and_transport()
{
	new npc_eiendormi();
	new npc_valeera_tele();
	new npc_nethestrasz();
	new travel_to_wyrmrest_base;
	new travel_to_Spine;
	new travel_to_the_eye_of_eternity;
	new travel_to_the_deck_of_the_skyfire;
	new travel_to_Maelstrom;
}
