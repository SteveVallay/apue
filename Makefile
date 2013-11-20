include Make.defines.linux

PROGS = myls read-write get-put getpid exe error1 error2 get-uid-gid signal\
		lseek \
		file-hole\
		make-big-file

all: $(PROGS)

$(LIB):
	make  -C lib

$(PROGS): $(LIB)

clean:
	rm -rf $(PROGS) $(TEMPFILES)
