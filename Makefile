BUILD := ./out
LDLIBS := -lm
SRCS := questionnaire.tex settings.tex cover.tex
LATEXMK=latexmk
LATEXMKFLAGS=-file-line-error -interaction=batchmode -outdir=$(BUILD) --shell-escape -silent -synctex=1 -lualatex

.PHONY: all
all: $(BUILD)/questionnaire.pdf $(BUILD)/correction.pdf sources/polygons

$(BUILD)/questionnaire.pdf: $(SRCS)
	$(LATEXMK) $(LATEXMKFLAGS) questionnaire.tex

$(BUILD)/correction.pdf: correction.tex sources/polygons.c
	$(LATEXMK) $(LATEXMKFLAGS) correction.tex

.PHONY: clean
clean:
	rm -rf $(BUILD)
