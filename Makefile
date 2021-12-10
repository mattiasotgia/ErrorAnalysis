dir = ../lib

all: | $(dir) ErrorAnalysis.cpp
	echo "building lib..."
	g++ -dynamiclib -o ../lib/libErrorAnalysis.dylib ErrorAnalysis.cpp `root-config --glibs --cflags`

$(dir):
	echo "Folder $(dir) does not exist"
	mkdir -p $@

clean: ../lib
	rm ../lib/libErrorAnalysis.dylib
	rmdir ../lib