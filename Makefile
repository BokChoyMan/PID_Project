# General Format:
# {target} : {dependencies}
# [TAB]		terminal commands

c1 : c1_starter.cpp pid_helper.o
	g++ $^ -o $@
	./c1
	make clean

c2 : c2_starter.cpp pid_helper.o
	g++ $^ -o $@
	./c2
	make clean

c3 : c3_starter.cpp pid_helper.o
	g++ $^ -o $@
	./c3
	make clean

clean :
	rm -rf c1 c2 c3

