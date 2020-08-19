#pragma once

using namespace RE;

namespace NPCUtil {
	class NPCCopier {
	public:
		NPCCopier();
		NPCCopier(RE::TESNPC* destination, RE::TESNPC* source);
		
		void CopyBodyTintColor();
		void CopyFaceData();
		void CopyFaceDataMorphs();
		void CopyFaceDataParts();
		void CopyFaceTexture();
		void CopyGenderAnimations();
		void CopyHairColor();
		void CopyHeadParts();
		void CopyHeadRelatedData();
		void CopyHeight();
		void CopyRace();
		void CopySex();
		void CopySkin();
		void CopyWeight();

		~NPCCopier();
	private:
		RE::TESNPC* destination;
		RE::TESNPC* source;

		BGSColorForm* GetDefaultHairColor(TESRace* race, SEX sex);
		BGSTextureSet* GetDefaultFaceTexture(TESRace* race, SEX sex);
	};

	BSTArray<SpellItem*> GetSpells(TESNPC* npc);
	void RemoveAllHeadParts(TESNPC* npc);
	void RemoveHeadPart(TESNPC* npc, TESNPC::HeadPartType type);
	void SetActorBaseDataFlag(TESActorBaseData* actorBaseData, ACTOR_BASE_DATA::Flag flag, bool enable);
	void SetOppositeGenderAnimations(TESNPC* npc, bool useOppositeGenderAnims);
	void SexChange(TESNPC* npc);
}