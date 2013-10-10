include Make.defines.linux

PROGS = myls read-write get-put

all: $(PROGS)


clean:
	rm -rf $(PROGS) $(TEMPFILES)
