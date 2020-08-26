#include "ActorUtil.h"
#include "ActorValueUtil.h"
#include "PerkUtil.h"

namespace ActorUtil {
	ActorCopier::ActorCopier(Actor* destination, Actor* source) {
		this->destination = destination;
		this->source = source;
		TESNPC* destinationBase = destination ? destination->GetActorBase() : nullptr;
		TESNPC* sourceBase = source ? source->GetActorBase() : nullptr;
		baseCopier = NPCUtil::NPCCopier(destinationBase, sourceBase);
	}
	
	void ActorCopier::AddSkillPerks() {
		if (!source)
			return;
		for (BGSPerk* perk : GetSkillPerks(source))
			destination->AddPerk(perk);
	}

	void ActorCopier::CopyAttributes() {
		if (destination && source) {
			destination->SetActorValue(ActorValue::kHealth, source->GetActorValue(ActorValue::kHealth));
			destination->SetActorValue(ActorValue::kMagicka, source->GetActorValue(ActorValue::kMagicka));
			destination->SetActorValue(ActorValue::kStamina, source->GetActorValue(ActorValue::kStamina));
		}
	}

	void ActorCopier::CopyBodyTintColor() {
		baseCopier.CopyBodyTintColor();
	}

	void ActorCopier::CopyFaceData() {
		baseCopier.CopyFaceData();
	}

	// TODO: Fix
	void ActorCopier::CopyFactions() {
		if (!destination || !source)
			return;
		auto factionChanges = destination->extraList.GetByType<ExtraFactionChanges>();
		if (factionChanges)
			factionChanges->factionChanges.clear();

		auto hasFaction = [=](TESFaction* faction, uint8_t rank) {
			TESNPC* destinationBase = destination->GetActorBase();
			if (destinationBase)
				for (FACTION_RANK f : destinationBase->factions)
					if (f.faction == faction && f.rank == rank)
						return true;
			return false;
		};

		auto addFactionsToDestination = [=](TESFaction* faction, uint8_t rank) {
			auto factionInfo = FACTION_RANK();
			factionInfo.faction = faction;
			factionInfo.rank = rank;
			if (!hasFaction(faction, rank) && factionChanges)
				factionChanges->factionChanges.push_back(factionInfo);
			return false;
		};
		
		source->VisitFactions(addFactionsToDestination);
	}

	void ActorCopier::CopyGenderAnimations() {
		baseCopier.CopyGenderAnimations();
	}

	void ActorCopier::CopyHeadParts() {
		baseCopier.CopyHeadParts();
	}

	void ActorCopier::CopyHeadRelatedData() {
		baseCopier.CopyHeadRelatedData();
	}

	void ActorCopier::CopyHeight() {
		baseCopier.CopyHeight();
	}

	void ActorCopier::CopyRace() {
		if (destination && source && source->race)
			destination->RE::Actor::SwitchRace(source->race, false);
		baseCopier.CopyRace();
	}

	void ActorCopier::CopySex() {
		baseCopier.CopySex();
	}

	void ActorCopier::CopySkills() {
		if (destination && source)
			for (ActorValue av = ActorValue::kOneHanded; av < ActorValue::kHealth; av++)
				destination->SetActorValue(av, source->GetActorValue(av));
	}

	void ActorCopier::CopySkin() {
		baseCopier.CopySkin();
	}

	void ActorCopier::CopyWeight() {
		baseCopier.CopyWeight();
	}	

	ActorCopier::~ActorCopier() {
		baseCopier.~NPCCopier();
	}

	void AddSpellsFromList(Actor* actor, BSTArray<SpellItem*> spells) {
		if (actor)
			for (SpellItem* spell : spells)
				actor->AddSpell(spell);
	}

	BSTArray<BGSPerk*> GetSkillPerks(Actor* actor) {
		BSTArray<BGSPerk*> actorSkillPerks;
		if (!actor)
			return actorSkillPerks;
		BSTArray<BGSPerk*> allSkillPerks = PerkUtil::GetAllSkillPerks();
		for (BGSPerk* perk : allSkillPerks) {
			if (actor->HasPerk(perk))
				actorSkillPerks.push_back(perk);
		}
		return actorSkillPerks;
	}

	BSTArray<SpellItem*> GetSpells(Actor* actor) {
		BSTArray<SpellItem*> spells;
		if (actor) {
			for (SpellItem* spell : actor->addedSpells)
				spells.push_back(spell);
			for (SpellItem* spell : NPCUtil::GetSpells(actor->GetActorBase()))
				spells.push_back(spell);
		}
		
		return spells;
	}

	void RemoveAllAddedSpells(Actor* actor) {
		if (actor)
			for (SpellItem* spell : actor->addedSpells)
				actor->RemoveSpell(spell);
	}

	void RemoveSkillPerks(Actor* actor) {
		if (actor)
			for (BGSPerk* perk : GetSkillPerks(actor))
				actor->RemovePerk(perk);
	}

	void RemoveSpellsExceptWhitelisted(Actor* actor, BSTArray<SpellItem*> whitelist) {
		// TODO
	}

	void RemoveBlacklistedSpells(Actor* actor, BSTArray<SpellItem*> blacklist) {
		if (actor)
			for (SpellItem* spell : blacklist)
				actor->RemoveSpell(spell);
	}

	void ResetSkeleton(Actor* actor) {
		if (actor && actor->currentProcess) {
			actor->currentProcess->Set3DUpdateFlag(RESET_3D_FLAGS::kSkeleton);
		}
	}

	void SexChange(Actor* actor) {
		if (actor)
			NPCUtil::SexChange(actor->GetActorBase());
	}
}