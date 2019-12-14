project: project.cpp
	g++ -std=c++11 gamescreen.cpp project.cpp gfx2_mac.o -lX11 -I/opt/X11/include/ -L/opt/X11/lib/ -o project

clean:
	rm project
