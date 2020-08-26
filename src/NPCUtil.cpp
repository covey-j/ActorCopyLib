#include "NPCUtil.h"

namespace NPCUtil {
	NPCCopier::NPCCopier() {
		destination = nullptr;
		source = nullptr;
	}

	NPCCopier::NPCCopier(RE::TESNPC* destination, RE::TESNPC* source) {
		this->destination = destination;
		this->source = source;
	}

	void NPCCopier::CopyBodyTintColor() {
		if (destination && source)
			destination->bodyTintColor = source->bodyTintColor;
	}

	void NPCCopier::CopyFaceData() {
		CopyFaceDataMorphs();
		CopyFaceDataParts();
	}

	void NPCCopier::CopyFaceDataMorphs() {
		if (source && source->faceData && source->faceData->morphs)
			for (int i = 0; i < TESNPC::FaceData::Morphs::kTotal; i++)
				SetFaceMorph(destination, source->faceData->morphs[i], i);
	}

	void NPCCopier::CopyFaceDataParts() {
		if (source && source->faceData && source->faceData->parts)
			for (int i = 0; i < TESNPC::FaceData::Parts::kTotal; i++)
				SetFacePreset(destination, source->faceData->parts[i], i);
	}

	void NPCCopier::CopyFaceTexture() {
		if (!source)
			return;

		BGSTextureSet* faceTexture = nullptr;

		if (source->headRelatedData)
			faceTexture = source->headRelatedData->faceDetails;
		else
			faceTexture = GetDefaultFaceTexture(source->race, source->GetSex());
		if (faceTexture)
			destination->SetFaceTexture(faceTexture);
		else
			destination->SetFaceTexture(nullptr);
	}

	void NPCCopier::CopyGenderAnimations() {
		if (source)
			SetOppositeGenderAnimations(destination, source->UsesOppositeGenderAnims());
	}

	void NPCCopier::CopyHairColor() {
		if (!destination || !source)
			return;
		
		BGSColorForm* hairColor = nullptr;
		if (source->headRelatedData)
			hairColor = source->headRelatedData->hairColor;
		else
			hairColor = GetDefaultHairColor(source->race, source->GetSex());
		if (hairColor)
			destination->SetHairColor(hairColor);
	}

	void NPCCopier::CopyHeadParts() {
		RemoveAllHeadParts(destination);
		for (int i = 0; i < source->numHeadParts; i++)
			if (source->headParts && source->headParts[i])
				destination->ChangeHeadPart(source->headParts[i]);
	}

	void NPCCopier::CopyHeadRelatedData() {
		CopyHairColor();
		CopyFaceTexture();
	}

	void NPCCopier::CopyHeight() {
		if (destination && source)
			destination->height = source->GetHeight();
	}

	void NPCCopier::CopySex() {
		if (destination && source)
			if (destination->GetSex() != source->GetSex())
				SexChange(destination);
	}

	void NPCCopier::CopySkin() {
		if (destination && source) {
			destination->skin = source->skin;
			destination->farSkin = source->farSkin;
		}
	}

	void NPCCopier::CopyRace() {
		if (destination && source) {
			destination->race = source->race;
			destination->originalRace = source->originalRace;
		}
	}

	void NPCCopier::CopyWeight() {
		if (destination && source)
			destination->weight = source->GetWeight();
	}

	NPCCopier::~NPCCopier() {}

	BGSColorForm* GetDefaultHairColor(TESRace* race, SEX sex) {
		if (race && (race->data.flags & RACE_DATA::Flag::kFaceGenHead))
			return race->faceRelatedData[sex]->defaultHairColor;
		else
			return nullptr;
	}

	BGSTextureSet* GetDefaultFaceTexture(TESRace* race, SEX sex) {
		if (race && (race->data.flags & RACE_DATA::Flag::kFaceGenHead))
			return race->faceRelatedData[sex]->defaultFaceDetailsTextureSet;
		else
			return nullptr;
	}

	BSTArray<SpellItem*> GetSpells(TESNPC* npc) {
		BSTArray<SpellItem*> spells;
		if (npc && npc->actorEffects)
			for (uint32_t i = 0; i < npc->actorEffects->numSpells; i++)
				spells.push_back(npc->actorEffects->spells[i]);
		return spells;
	}

	void RemoveAllHeadParts(TESNPC* npc) {
		if (npc && npc->headParts)
			while (npc->numHeadParts > 0)
				if (npc->headParts[0])
					RemoveHeadPart(npc, npc->headParts[0]->type.get());
	}

	void RemoveHeadPart(TESNPC* npc, TESNPC::HeadPartType type) {
		if (npc) {
			using func_t = decltype(&RemoveHeadPart);
			REL::Relocation<func_t> func{ REL::ID(24247) };
			return func(npc, type);
		}
	}

	void SetActorBaseDataFlag(TESActorBaseData* actorBaseData, ACTOR_BASE_DATA::Flag flag, bool enable) {
		if (actorBaseData) {
			using func_t = decltype(&SetActorBaseDataFlag);
			REL::Relocation<func_t> func{ REL::ID(14261) };
			return func(actorBaseData, flag, enable);
		}
	}

	void SetFaceMorph(TESNPC* npc, float value, uint32_t n) {
		if (npc && npc->faceData && n < TESNPC::FaceData::Morphs::kTotal) {
			using func_t = void (*)(TESNPC*, uint32_t, float);
			REL::Relocation<func_t> func{ REL::ID(24183) };
			return func(npc, n, value);
		}
	};

	void SetFacePreset(TESNPC* npc, uint32_t value, uint32_t n) {
		if (npc && npc->faceData && n < TESNPC::FaceData::kTotalPresets) {
			using func_t = decltype(&SetFacePreset);
			REL::Relocation<func_t> func{ REL::ID(24185) };
			return func(npc, n, value);
		}
	};

	void SetOppositeGenderAnimations(TESNPC* npc, bool useOppositeGenderAnims) {
		SetActorBaseDataFlag(npc, ACTOR_BASE_DATA::Flag::kOppositeGenderanims, useOppositeGenderAnims);
	}

	void SexChange(TESNPC* npc) {
		if (!npc)
			return;

		SEX sex = npc->GetSex();
		if (sex == SEX::kFemale)
			sex = SEX::kMale;
		else if (sex == SEX::kMale)
			sex = SEX::kFemale;
		SetActorBaseDataFlag(npc, ACTOR_BASE_DATA::Flag::kFemale, sex);
	}
}

