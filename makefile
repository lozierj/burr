LIBDIR := lib
SRCDIR := src
TESTDIR := test
BINDIR := bin

DEPDIR := .dep
OBJDIR := .obj

$(shell mkdir -p $(DEPDIR)/$(LIBDIR) $(OBJDIR)/$(LIBDIR) >/dev/null)
$(shell mkdir -p $(DEPDIR)/$(SRCDIR) $(OBJDIR)/$(SRCDIR) >/dev/null)
$(shell mkdir -p $(DEPDIR)/$(TESTDIR) $(OBJDIR)/$(TESTDIR) >/dev/null)
  #-p don't emit error if existing, make parent directories as needed

DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)/$*.Td
  #-MT change the target of the rule
  #  $@ file name of the target of the rule
  #-MD generate a dependency output file as side-effect of compilation
  #  -MMD like -MD but doesn't mention system headers
  #  -MP add phony target for each dependency (to be able to detect removal)
  #  -MF with -MMD overrides default dependency output file
  #    $* stem with which an implicit rule matches (part that matches %)

CPPFLAGS = -Wall -Wextra -std=c++14 -O3 -DNDEBUG
  #-Wall -Wextra warnings
  #-O3 max opt
  #-g produce debugging information
  #-pg produce profiling information

COMPILE= g++ $(DEPFLAGS) $(CPPFLAGS) -c
  #-c compile but do not link

POSTCOMPILE = @mv -f $(DEPDIR)/$*.Td $(DEPDIR)/$*.d && touch $@
  #-f no prompt before overwrite

LIBS = $(wildcard $(LIBDIR)/*.cxx)
TESTS = $(wildcard $(TESTDIR)/*.cxx)
  #wildcard otherwise expansion isn't automatic when variable is set

OBJECTS = $(patsubst $(LIBDIR)/%.cxx,$(OBJDIR)/$(LIBDIR)/%.o,$(LIBS))
TESTOBJS = $(patsubst $(TESTDIR)/%.cxx,$(OBJDIR)/$(TESTDIR)/%.o,$(TESTS))
  #patsubst pattern substitution pattern,replacement,text

.PHONY: all
all: burr tests

burr : $(OBJECTS) $(OBJDIR)/$(SRCDIR)/burr_v2.o
	g++ $(CPPFLAGS) -o $(BINDIR)/burr_v2.exe \
	$(OBJECTS) $(OBJDIR)/$(SRCDIR)/burr_v2.o

tests : $(OBJECTS) $(TESTOBJS)
	g++ $(CPPFLAGS) -o $(BINDIR)/run_test.exe $(OBJECTS) $(TESTOBJS)

$(OBJDIR)/%.o : %.cxx
  #cancels built-in implicit rule

$(OBJDIR)/%.o : %.cxx $(DEPDIR)/%.d
	$(COMPILE) $(OUTPUT_OPTION) $<
	$(POSTCOMPILE)

  #OUTPUT_OPTION empty or -o $@
  #$< the name of the first prerequisite

$(DEPDIR)/%.d: ;
  #do nothing

.PRECIOUS: $(DEPDIR)/%.d
  #.PRECIOUS preserve despite being intermediate files

include $(DEPDIR)/$(SRCDIR)/burr_v2.d
include $(wildcard $(patsubst %,$(DEPDIR)/%.d,$(basename $(LIBS) $(TESTS))))
  #basename extract name without suffix

.PHONY : clean
  #.PHONY not really name of file
clean :
	rm -f $(BINDIR)/* $(DEPDIR)/*/* $(OBJDIR)/*/*
