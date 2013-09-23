include Make.defines.linux

PROGS = myls

all: $(PROGS)


clean:
	rm -rf $(PROGS) $(TEMPFILES)
