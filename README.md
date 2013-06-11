# GraphReps
GraphReps is a set of C++ programs that convert representations of graphs.

Uses [GraphDraw.jar](http://multires.caltech.edu/~keenan/GraphDraw/index.html). GraphDraw.jar is a Java program that allows you to draw simple graphs. GraphDraw also allows you to view properly formatted graph files.

To create a GraphDraw-formatted adjacency matrix from GraphDraw, use the command:

```
java -jar GraphDraw.jar
```

# Installation

```
git clone git@github.com:adamlazz/GraphReps.git
cd GraphReps
make
```

# Graph Formats
Graphs are stored in text files. Note the empty line at the end of the files. All representations below denote the same graph.

### GraphDraw-formatted adjacency matrix

```
U
4
0 0 1 0
0 0 1 1
1 1 0 1
0 1 1 0

```

Where 'U' means undirected and '4' denotes that the graph has 4 vertices.

### Normal adjacency matrix

```
0 0 1 0
0 0 1 1
1 1 0 1
0 1 1 0

```

### Adjacency list

```
0 : 2
1 : 2 3
2 : 0 1 3
3 : 1 2

```

Note: vertices with no adjacencies require a space after the colon.

### Trick

```
4 4
1 3
2 3
2 4
3 4
```

Where the first line contains the number of vertices and edges. All following contain the node numbers (from 1 to n) incident to each edge.

For use with [trick.c](http://mat.gsia.cmu.edu/COLOR/solvers/trick.c).

# Program Purposes & Usage
### graphtolist
Takes an adjacency matrix file as input, and generates an adjacency list.

```
./graphtolist <adjmat_file>
```

### listtomat
Takes a adjacency list file as input, and generates an adjacency matrix.

```
./listtomat <adjlist_file>
```

### gd
Takes a normal adjacency matrix as input, and generates a GraphDraw-formatted adjacency matrix.

```
./gd <adjmat_file>
```

### ungd
Takes a GraphDraw-formatted adjacency matrix as input, and generates a normal adjacency matrix.

```
./ungd <adjmat_file>
```

### listtotrick
Takes an adjacency list as input, and generates the Trick-formatted graph.

```
./ungd <adjlist_file>
```

Credit to Dr. C. Hoang