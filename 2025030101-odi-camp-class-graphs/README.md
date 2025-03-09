## Graphs and Trees

Graphs are an abstract data structure that is composed by nodes or vertices, which are connected through edges, we use graphs to represent relationships between different elements.

Some examples of graphs in real life: 

- Buildings and the path between each of these.
- Airports and the available routes between each of them.
- A set of people and the acquaintances that this people have between each other.

Nodes can represent any entity that can be related to another depending on the context. They are usually drawn in a graphic as circles or dots.

Edges represent the relationships between the entities we represent as nodes. They can be directional, or bidirectional, just like a street can be one-way or two-ways, and in some cases traversing them could have a "cost" or "weight", like customs between cities you have to pay or time you spend in the driving between buildings. Edges are usually drawn as lines or arrows that connect the nodes.

When reasoning about time complexity of graph-based algorithms we use V for nodes and E for edges. Meaning that if, for example, an algorithm has a worst case scenario that grows linearly as nodes and edges are added, the big O would look like `O(V+E)`.

### Ways to represent graphs

Nodes are usually identified in competitive programming problems with numbers, this makes it easier to represent the connections using the following methods:

**Edge Lists**: By only storing which nodes are connected to which ones in the form of two numbers, where the first represent the element where the edge starts from and the second number where the edge ends. Iterating through these lists results in a time complexity of `O(E)`. A graph which form resembles a triangle with three nodes would have the following edge list.

```
1 2
2 3
3 1
```

This is the most common way problems use to represent graphs in the input data of a test case. Normally the problems will specify when edges are one-directional, but by default consider these problem inputs bi-directional.

**Adjacency Matrices**: By creating a two-dimensional array of V columns and V rows. Where when there is a path between from one node A to another node B we mark `adjacency_matrix[A][B]` with an 1 or the number of the cost of traveling through that edge. Let's take the previous example we used and make an adjacency matrix with it.

```cpp
int adj[3][3] = {
  {0, 1, 1},
  {1, 0, 1},
  {1, 1, 0}
};
```

If we were to add an additional fourth node that is connected to the first one, the adjacency list would look like this:

```cpp
int adj[4][4] = {
  {0, 1, 1, 1},
  {1, 0, 1, 0},
  {1, 1, 0, 0},
  {1, 0, 0, 0}
};
```

Naturally to traverse a list like this it has a time complexity of `O(V^2)`, and similarly the space needed to store the adjacency matrix will be always `V^2`. Knowing if two nodes are connected here has a complexity of `O(1)`.

**Adjacency List**: In this approach we create a list of lists, each with variable lengths, each list pertains to a node number, meaning that the first list will contain all the numbers that the first node is connected to, the second list will contain the second node connections and so on.

Going back to our last four node example, here is how it would look like:

```cpp
vector<vector<int>> adj = {
  {2, 3, 4},
  {1, 3},
  {1, 2},
  {1}
}
```

Since the first node is connected to all the other nodes, its adjacency list is 2, 3 and 4, and since the fourth node is connected only to the first node, its adjacency list is 1.

While adjacency lists are the preferred method of storing graphs in competitive programming is important to note that its growth in space will be determined by the amount of edges, and in a graph that has all its nodes connected with each other, the space occupied will equal the space needed to store an adjacency matrix.

On the other hand if there are multiple edges that have the same start and end, an adjacency list will be able to represent these cases.

Moreover the time complexity of determining if two nodes are connected is of `O(V)` instead of `O(1)`, but cases where this makes a difference are very rare.

