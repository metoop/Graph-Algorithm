class Solution {
  public:
    void buildLinks(Node * node, unordered_map < Node * , Node * > & transMap) {

      Node * nodeCopy = new Node(node -> val);
      transMap[node] = nodeCopy;

      for (auto neigh: node -> neighbors) {
        if (transMap.find(neigh) == transMap.end())
          buildLinks(neigh, transMap);
        nodeCopy -> neighbors.push_back(transMap[neigh]);
      }

    }

  Node * cloneGraph(Node * node) {
    if (node == nullptr)
      return node;

    unordered_map < Node * , Node * > transMap;
    buildLinks(node, transMap);

    return transMap[node];
  }
};
