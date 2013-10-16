include Make.defines.linux

PROGS = myls read-write get-put getpid exe error1

all: $(PROGS)


clean:
	rm -rf $(PROGS) $(TEMPFILES)
