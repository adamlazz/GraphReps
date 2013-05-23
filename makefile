all:
	gcc graphtolist.cpp -o graphtolist # compile
	gcc listtomat.cpp -o listtomat # compile
	gcc gd.cpp -o gd # compile
	gcc ungd.cpp -o ungd # compile

clean:
	rm graphtolist # remove executable
	rm listtomat # remove executable
	rm gd # remove executable
	rm ungd # remove executable