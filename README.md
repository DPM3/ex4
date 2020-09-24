# Ex4

## Planning:
First of all we fixed some of the cache code from the previous assignment
	so that it will be more SOLID and put all of our caching code in it's own file.
We created a server interface and we implemented it with mySerialServer.
We also created a clientHandler interface and we implemented it with myClientHandler
	as well as myTestClientHandler for testing
We changed operatorID to be an interface instead of a struct.
We made a different class that implements operatorID for each algorithm.
We made an Element class that is either a block or not a block and contains the
	cost to move to the block.
We made a Grid class that contains a list of list of Elements.
The Grid class is used to represent graphs.
We made a parser that recieves the information from the server and the creates a
	grid to represent the graph.

## server error codes:

## Distance function:
Instead of just calculating the steps it takes to get to the end we used this
	distance function we found online:
> int distanceFromEnd(GraphPoint p) const {
>    return 10 * (abs((int)p.x() - (int)end.x()) + abs((int)p.y() - (int)end.y())) -
>            6 * std::min(abs((int)p.x() - (int)m_end.y()), abs((int)p.y() - (int)m_end.y()));
> }
This function's advantage is that it prefers paths that go through the center of the grid,
	which increases the possible routes therefore leading to better results.

