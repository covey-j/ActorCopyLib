#include "ActorValueUtil.h"
#include "PerkUtil.h"
#include "BSTArrayUtil.h"

namespace ActorValueUtil {
	class ActorValueList {
	public:
		static ActorValueList* GetSingleton() {
			REL::Relocation<ActorValueList**> avInfo{ REL::ID(514139) };
			return *avInfo;
		}
		uint32_t	unk00;	// 00
		uint32_t	pad04;	// 04
		ActorValueInfo* avInfo[RE::to_underlying(ActorValue::kTotal)]; //08
	};

	ActorValueInfo* GetActorValueInfo(ActorValue av) {
		return ActorValueList::GetSingleton()->avInfo[RE::to_underlying(av)];
	}

	BSTArray<BGSPerk*> GetAllPerkRanks(BGSPerk* perk) {
		BSTArray<BGSPerk*> perkRanks;
		while (perk) {
			perkRanks.push_back(perk);
			perk = perk->nextPerk;
		}
		return perkRanks;
	}

	BSTArray<BGSPerk*> GetSkillPerks(ActorValue av) {
		BSTArray<BGSPerk*> perks;
		BSTArray<BGSSkillPerkTreeNode*> skillTreeNodes;
		BGSSkillPerkTreeNode* root = GetSkillPerkTree(av);
		skillTreeNodes = PerkUtil::DFS(root, skillTreeNodes);
		for (BGSSkillPerkTreeNode* node : skillTreeNodes) {
			perks = BSTArrayUtil::Append<BGSPerk>(perks, GetAllPerkRanks(node->perk));
		}
		return perks;
	}

	BGSSkillPerkTreeNode* GetSkillPerkTree(ActorValue av) {
		ActorValueInfo* avInfo = GetActorValueInfo(av);
		return avInfo->perkTree;
	}
}