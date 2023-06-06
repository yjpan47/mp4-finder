CPP=clang++
CPPFLAGS=-Wall -g
EXE=mp4finder

all: $(EXE)

%: %.c
	$(CPP) $(CPPFLAGS) $< -o $@

clean:
	rm -rf *.o $(EXE)