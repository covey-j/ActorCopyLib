#pragma once

using namespace RE;

namespace PerkUtil {
	BSTArray<BGSSkillPerkTreeNode*> DFS(BGSSkillPerkTreeNode* root, BSTArray<BGSSkillPerkTreeNode*> visitedNodes);
	BSTArray<BGSPerk*> GetAllSkillPerks();
	bool Visited(BGSSkillPerkTreeNode* node, BSTArray<BGSSkillPerkTreeNode*> visitedNodes);
}