LIBDIR := lib
TESTDIR := test
SRCDIR := src

DEPDIR := .dep
OBJDIR := .obj

$(shell mkdir -p $(DEPDIR) >/dev/null)
  #-p don't emit error if existing, make parent directories as needed
$(shell mkdir -p $(OBJDIR) >/dev/null)


DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)/$*.Td
  #-MT change the target of the rule
  #  $@ file name of the target of the rule
  #-MD generate a dependency output file as side-effect of compilation
  #  -MMD like -MD but doesn't mention system headers
  #  -MP add phony target for each dependency (to be able to detect removal)
  #  -MF with -MMD overrides default dependency output file
  #    $* stem with which an implicit rule matches (part that matches %)

CPPFLAGS = -Wall -Wextra -g
  #-Wall -Wextra warnings
  #-O3 max opt
  #-g produce debugging information
  #-pg produce profiling information

COMPILE= g++ $(DEPFLAGS) $(CPPFLAGS) -c
  #-c compile but do not link

POSTCOMPILE = @mv -f $(DEPDIR)/$*.Td $(DEPDIR)/$*.d && touch $@
  #-f no prompt before overwrite

LIBS = $(wildcard $(LIBDIR)/*.cxx)
  #wildcard otherwise expansion isn't automatic when variable is set
TESTS = $(wildcard $(TESTDIR)/*.cxx)
SRCS = $(wildcard $(SRCDIR)/*.cxx)

OBJECTS = $(patsubst $(LIBDIR)/%.cxx,$(OBJDIR)/%.o,$(LIBS))
  #patsubst pattern substitution pattern,replacement,text
TESTOBJS = $(patsubst $(TESTDIR)/%.cxx,$(OBJDIR)/%.to,$(TESTS))

burr_v2.exe : $(OBJECTS) $(OBJDIR)/burr_v2.mo
	g++ $(CPPFLAGS) -o burr_v2.exe $(OBJECTS) $(OBJDIR)/burr_v2.mo

run_test.exe : $(OBJECTS) $(TESTOBJS)
	g++ $(CPPFLAGS) -o run_test.exe $(OBJECTS) $(TESTOBJS)

$(OBJDIR)/%.o : $(LIBDIR)/%.cxx
  #cancels built-in implicit rule
$(OBJDIR)/%.to : $(LIBDIR)/%.cxx
$(OBJDIR)/%.mo : $(LIBDIR)/%.cxx

$(OBJDIR)/%.o : $(LIBDIR)/%.cxx $(DEPDIR)/%.d
	$(COMPILE) $(OUTPUT_OPTION) $<
	$(POSTCOMPILE)

$(OBJDIR)/%.to : $(TESTDIR)/%.cxx $(DEPDIR)/%.d
	$(COMPILE) -I $(LIBDIR) $(OUTPUT_OPTION) $<
	$(POSTCOMPILE)

$(OBJDIR)/%.mo : $(SRCDIR)/%.cxx $(DEPDIR)/%.d
	$(COMPILE) -I $(LIBDIR) $(OUTPUT_OPTION) $<
	$(POSTCOMPILE)

  #OUTPUT_OPTION empty or -o $@
  #$< the name of the first prerequisite

$(DEPDIR)/%.d: ;
  #do nothing

.PRECIOUS: $(DEPDIR)/%.d
  #.PRECIOUS preserve despite being intermediate files

include $(wildcard $(patsubst $(LIBDIR)/%,$(DEPDIR)/%.d,$(basename $(LIBS))))
  #basename extract name without suffix
include $(wildcard $(patsubst $(TESTDIR)/%,$(DEPDIR)/%.d,$(basename $(TESTS))))
include $(wildcard $(patsubst $(SRCDIR)/%,$(DEPDIR)/%.d,$(basename $(SRCS))))

.PHONY : clean
  #.PHONY not really name of file
clean :
	rm -f burr_v2.exe run_test.exe $(OBJDIR)/* $(DEPDIR)/*

