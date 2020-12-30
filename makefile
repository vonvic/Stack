# Specify compiler, linker, and flags
CC := g++
LINK := g++
FLAGS := -Wall -g -Iinclude

MAINEXE := mainexe
TESTEXE := testexe

OBJDIR := build
SRCDIR := src
LIBDIR := lib
TESTDIR := tests
INCDIR := include

SRCFILES := $(wildcard $(SRCDIR)/*.cpp)
LIBFILES := $(wildcard $(LIBDIR)/*.cpp)
TESTFILES := $(wildcard $(TESTDIR)/*.cpp)
INCFILES := $(wildcard $(INCDIR)/*.h)

SRCOBJ := $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SRCFILES))
LIBOBJ += $(patsubst $(LIBDIR)/%.cpp, $(OBJDIR)/%.o, $(LIBFILES))

TESTOBJ := $(patsubst $(TESTDIR)/%.cpp, $(OBJDIR)/%.o, $(TESTFILES))

all: run
# Compile and run file!
run: $(MAINEXE) $(INCFILES)
	./$(MAINEXE)

test: $(TESTEXE)
	./$(TESTEXE)

$(MAINEXE): $(SRCOBJ) $(LIBOBJ)
	$(CC) -o $@ $^ $(FLAGS)

$(TESTEXE): $(TESTOBJ) $(LIBOBJ)
	$(CC) -o $@ $^ $(FLAGS)

.PHONY: all run test

$(SRCOBJ): $(SRCFILES) $(INCFILES)
	$(CC) -c -o $@ $< $(FLAGS)

$(TESTOBJ): $(TESTFILES) $(INCFILES)
	$(CC) -c -o $@ $< $(FLAGS)

$(LIBOBJ): $(LIBOBJ) $(INCFILES)
	$(CC) -c -o $@ $< $(FLAGS)