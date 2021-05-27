CC = g++

src_dir = src
obj_dir = obj
bin_dir = bin

$(bin_dir)/TermPong: directories $(obj_dir)/coordinate.o $(obj_dir)/TermPong.o
	$(CC) -Wall $(obj_dir)/coordinate.o $(obj_dir)/TermPong.o -o $(bin_dir)/TermPong -lncurses

directories:
	mkdir obj
	mkdir bin

$(obj_dir)/coordinate.o : $(src_dir)/coordinate.cpp $(src_dir)/coordinate.h
	$(CC) -Wall -c $(src_dir)/coordinate.cpp -o $(obj_dir)/coordinate.o

$(obj_dir)/TermPong.o : $(src_dir)/TermPong.cpp
	$(CC) -Wall -c $(src_dir)/TermPong.cpp -o $(obj_dir)/TermPong.o


.PHONY: clean
clean:
	rm -rf $(bin_dir)/*
	rm -rf $(obj_dir)/*