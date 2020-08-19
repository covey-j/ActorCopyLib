#pragma once

using namespace RE;

namespace PerkUtil {
	BSTArray<BGSPerk*> Append(BSTArray<BGSPerk*> array, BSTArray<BGSPerk*> appendix);
	BSTArray<BGSSkillPerkTreeNode*> Append(BSTArray<BGSSkillPerkTreeNode*> array, BSTArray<BGSSkillPerkTreeNode*> appendix);
	BSTArray<BGSSkillPerkTreeNode*> DFS(BGSSkillPerkTreeNode* root, BSTArray<BGSSkillPerkTreeNode*> visitedNodes);
	BSTArray<BGSPerk*> GetAllSkillPerks();
	bool Visited(BGSSkillPerkTreeNode* node, BSTArray<BGSSkillPerkTreeNode*> visitedNodes);
}