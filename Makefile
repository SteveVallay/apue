include Make.defines.linux

PROGS = myls read-write get-put getpid exe error1 error2 get-uid-gid signal\
		lseek

all: $(PROGS)

$(LIB):
	make  -C lib

$(PROGS): $(LIB)

clean:
	rm -rf $(PROGS) $(TEMPFILES)
