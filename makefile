CC = g++
CFLAGS  = -g -Wall
default: singh_dimple_pa3_lcs singh_dimple_pa3_floyd

singh_dimple_pa3_lcs.o: singh_dimple_pa3_lcs.cpp
	$(CC) $(CFLAGS) -c singh_dimple_pa3_lcs.cpp
	
singh_dimple_pa3_floyd.o: singh_dimple_pa3_floyd.cpp
	$(CC) $(CFLAGS) -c singh_dimple_pa3_floyd.cpp


clean:
	$(RM) singh_dimple_pa3_lcs singh_dimple_pa3_floyd *.o *~
