include Make.defines.linux

PROGS = myls read-write get-put getpid exe error1

all: $(PROGS)

$(LIB):
	make  -C lib

$(PROGS): $(LIB)

clean:
	rm -rf $(PROGS) $(TEMPFILES)
