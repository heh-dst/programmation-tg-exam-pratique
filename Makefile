BUILD := ./out
SRCS := questionnaire.tex settings.tex cover.tex questionbank.tex questions.tex answersheet.tex
LATEXMK=latexmk
LATEXMKFLAGS=-file-line-error -interaction=batchmode -outdir=$(BUILD) --shell-escape -silent -synctex=1 -lualatex

.PHONY: all
all: $(BUILD)/questionnaire.pdf

$(BUILD)/questionnaire.pdf: $(SRCS)
	$(LATEXMK) $(LATEXMKFLAGS) questionnaire.tex

.PHONY: clean
clean:
	rm -rf $(BUILD)
