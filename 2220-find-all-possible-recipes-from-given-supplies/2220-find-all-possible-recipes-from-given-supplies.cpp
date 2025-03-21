class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        set<string> available(supplies.begin(), supplies.end());  // Stash of what we got
        unordered_map<string, vector<string>> needs;  // Recipe → Required Ingredients

        for (int i = 0; i < recipes.size(); i++)
            needs[recipes[i]] = ingredients[i];

        bool updated = true;
        while (updated) {  // Keep going until we can't make anything new
            updated = false;
            for (auto& r : recipes) {
                if (available.count(r)) continue;  // Already made
                
                bool canMake = true;
                for (string& ing : needs[r]) {
                    if (!available.count(ing)) {  // Missing ingredients? Nah, ain't cookin' that.
                        canMake = false;
                        break;
                    }
                }
                
                if (canMake) {
                    available.insert(r);  // We made it! Add to supplies
                    updated = true;
                }
            }
        }
        
        vector<string> res;
        for (auto& r : recipes) if (available.count(r)) res.push_back(r);
        return res;
    }
};