all:
	gcc graphtolist.cpp -o graphtolist 
	gcc listtomat.cpp -o listtomat 
	gcc gd.cpp -o gd 
	gcc ungd.cpp -o ungd 
	gcc listtotrick.cpp -o listtotrick 

clean:
	rm graphtolist 
	rm listtomat 
	rm gd 
	rm ungd 
	rm listtotrick 