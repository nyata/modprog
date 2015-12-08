# Makefile
# for create album
# png file convert to pdf and connected
# 4/12/2015 Nagisa YATA

CONV = convert
PHOTOS = $(sort $(wildcard 09/chimp???.png))

all: chimp

chimp:
	for i in $(basename $(PHOTOS)) ; do \
		$(CONV) $$i.png $$i.pdf ; \
		done
	pdftk $(addsuffix .pdf, $(basename $(PHOTOS))) cat output movie.pdf
	# Maybe case of timming, below wildcard doesn't work
	# pdftk $(sort $(wildcard 09/chimp???.pdf)) cat output movie.pdf

.PHONY: clean

clean:
	rm -f 09/chimp*.pdf
	rm -f movie.pdf
