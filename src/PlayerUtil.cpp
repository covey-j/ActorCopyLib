#include "PlayerUtil.h"

namespace PlayerUtil {
	ActorToPlayerCopier::ActorToPlayerCopier(PlayerCharacter* player, Actor* actor) : ActorCopier(player, actor) {
		this->player = player;
		this->actor = actor;
	}

	void ActorToPlayerCopier::AddTeachableSpells() {
		BSTArray<SpellItem*> spells = ActorUtil::GetSpells(actor);
		spells = SpellUtil::GetTeachableEquivalents(spells);
		ActorUtil::AddSpellsFromList(player, spells);
	}

	void ActorToPlayerCopier::CopyAppearance() {
		if (!player)
			return;
		CopySex();
		CopyGenderAnimations();
		CopyFaceData();
		CopyHeadParts();
		CopyHeadRelatedData();
		CopySkin();
		CopyRace();
		CopyWeight();
		ActorUtil::ResetSkeleton(player);
		CopyBodyTintColor();
		ResetPlayerTintMasks(player);
		CopyTintMasks();
		player->DoReset3D(true);
	}

	void ActorToPlayerCopier::CopyTintMasks() {
		// TODO
	}

	void ActorToPlayerCopier::CopyRace() {
		if (player && actor) {
			player->charGenRace = actor->GetRace();
			player->RE::Actor::SwitchRace(actor->GetRace(), true);
			ActorCopier::CopyRace();
		}
	}

	void ModPerkPoints(PlayerCharacter* player, int mod) {
		if (!player)
			return;
		if (mod < 0)
			player->perkCount = static_cast<uint8_t>(std::max(player->perkCount + mod, 0));
		else
			player->perkCount = static_cast<uint8_t>(std::min(player->perkCount + mod, 0xFF));
	}

	void RefundPerks(PlayerCharacter* player) {
		ModPerkPoints(player, ActorUtil::GetSkillPerks(player).size());
		ActorUtil::RemoveSkillPerks(player);
	}

	// Reallocates player->tintMasks and changes the player's tintMasks to those of the correct race/sex
	void ResetPlayerTintMasks(PlayerCharacter* player) {
		using func_t = decltype(&ResetPlayerTintMasks);
		REL::Relocation<func_t> func{ REL::ID(39610) };
		return func(player);
	}
}