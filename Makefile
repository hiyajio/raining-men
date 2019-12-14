hallelujah: hallelujah.cpp
	g++ -std=c++11 raining_man.cpp hallelujah.cpp gfx2_mac.o -lX11 -I/opt/X11/include/ -L/opt/X11/lib/ -o hallelujah

clean:
	rm hallelujah
