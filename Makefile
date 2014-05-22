include Make.defines.linux

PROGS = myls read-write get-put getpid exe error1 error2 get-uid-gid signal\
		lseek \
		file-hole\
		make-big-file\
		io-efficiency \
		get-fd-flag \
		change-fd-flag\
		file-type \
		access\
		umask \
		chmod \
		unlink \
		symlink-readlink \
		utime \
		mkdir-rmdir


all: $(PROGS)

$(LIB):
	make  -C lib

$(PROGS): $(LIB)

clean:
	rm -rf $(PROGS) $(TEMPFILES)
