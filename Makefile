include Make.defines.linux

PROGS = myls read-write get-put getpid

all: $(PROGS)


clean:
	rm -rf $(PROGS) $(TEMPFILES)
