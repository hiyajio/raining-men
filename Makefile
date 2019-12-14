hallelujah: hallelujah.cpp
	g++ -std=c++11 raining_man.cpp hallelujah.cpp gfx2_mac.o -lX11 -I/opt/X11/include/ -L/opt/X11/lib/ -o hallelujah

clean:
	rm hallelujah

# CMP = g++ -std=c++11
# CLASS = raining_man
# MAIN = hallelujah
# EXEC = rainman

# $(EXEC): $(CLASS).o $(MAIN).o
# 	$(CMP) -g gfx2_mac.o -lX11 -I/opt/X11/include/ -L/opt/X11/lib/ $(CLASS).o $(MAIN).o -o $(EXEC)

# $(CLASS).o: $(CLASS).cpp $(CLASS).h
# 	$(CMP) -c -g $(CLASS).cpp -o $(CLASS).o

# $(MAIN).o: $(MAIN).cpp $(CLASS).h
# 	$(CMP) -c -g $(MAIN).cpp -o $(MAIN).o

# clean:
# 	rm rainman
