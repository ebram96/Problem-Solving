struct Node
{
    int steps;
    string gene;
    
    friend bool operator< (const Node& first, const Node& second)
    { return first.steps < second.steps; }
};
class Solution {
private:
    priority_queue<Node> pq;
    set<string> mutations;
    
    inline bool validMutaion(const string& m)
    { return mutations.find(m) != mutations.end(); }

public:
    int minMutation(string start, string end, vector<string>& bank) {
        mutations = set<string>(bank.begin(), bank.end());
        
        if(!validMutaion(end))
            return -1;
        
        string exchanges = "ACGT";
        map<string, bool> done;
        done[start] = true;
        pq.push({0, start});
        while(!pq.empty())
        {
            Node node = pq.top();
            pq.pop();
            
            for(int i = 0; i < 8; i++)
                for(int j = 0; j < 4; j++)
                {
                    if(exchanges[j] == node.gene[i])
                        continue;
                    
                    string newGene = node.gene;
                    newGene[i] = exchanges[j];
                    
                    if(done[newGene] || !validMutaion(newGene))
                        continue;
                    
                    if(newGene == end)
                        return node.steps + 1;
                    
                    done[newGene] = true;
                    pq.push({node.steps + 1, newGene});
                }
        }
        
        return -1;
    }
};
