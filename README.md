# GraphReps
GraphReps is a set of C++ programs that convert graph representations.

Uses [GraphDraw.jar](http://multires.caltech.edu/~keenan/GraphDraw/index.html). GraphDraw.jar is a Java program that allows you to draw simple graphs. GraphDraw also allows you to view properly formatted graph files.

# Installation

```
git clone git@github.com:adamlazz/GraphReps.git
cd GraphReps
make
```

# Graph Format
Graphs are stored in text files. Note the empty line at the end of the files. All three representations denote the same graph.

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
3 : 1 3

```

Note: vertices with no adjacencies require a space after the colon.

# Program Purposes & Information
### graphtolist
Takes an adjacency matrix file as input, and generates graph's normal adjacency list.

```
./graphtolist <adjmat_file>
```

### listtomat
Takes a normal adjacency list file as input, and generates graph's adjacency matrix.

```
./listtomat <adjlist_file>
```

### gd
Takes a normal adjacency matrix as input, and generates a GraphDraw-formatted adjacency matrix

```
./gd <adjmat_file>
```

### ungd
Takes a GraphDraw-formatted adjacency matrix as input, and generates a normal adjacency matrix

```
./ungd <adjmat_file>
```

### GraphDraw.jar
To create a GraphDraw-formatted adjacency matrix from GraphDraw, use the command

```
java -jar GraphDraw.jar
```

Credit to Dr. C. Hoang