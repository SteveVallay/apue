include Make.defines.linux

PROGS = myls read-write

all: $(PROGS)


clean:
	rm -rf $(PROGS) $(TEMPFILES)
