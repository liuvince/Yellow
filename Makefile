BINDIR = /usr/local/bin
EXEC = play

all:
	(cd lib; $(MAKE) $@)
	(cd src; $(MAKE) $@)
	(cd src; mv $(EXEC) ..)
clean:
	(cd lib; $(MAKE) $@)
	(cd src; $(MAKE) $@)
	rm -f $(EXEC)

install:
	(cd src; $(MAKE) BINDIR=$(BINDIR) $@)

.PHONY: all clean install

