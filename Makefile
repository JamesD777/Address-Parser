#James Dunlap
#Jcd160230
#3377.501

# Flags for the C++ implicit rules
CXX = g++
CXXFLAGS =
CPPFLAGS = -Wall
#Set up lex and flags
LEX = /bin/flex
LFLAGS = 
#set up bison and flags
YACC = /bin/bison
YFLAGS = -dy
#name for backup
PROJECTNAME = CS3377.address.parser
#name for .out file
EXECFILE = parse
#objects
OBJS = parse.o scan.o myproject.o

all: $(EXECFILE)
#remove created files
clean:
	rm -f $(OBJS) $(EXECFILE) y.tab.h *~ \#* scanner parser
#create object and link files
$(EXECFILE):	$(OBJS)
	$(CXX) -o $@ $(OBJS)
	ln -s ./parse parser
	ln -s ./parse scanner
#create a backup of your project
backup:
	@make clean
	@mkdir -p ~/backups; chmod 700 ~/backups
	@$(eval CURDIRNAME := $(shell basename "`pwd`"))
	@$(eval MKBKUPNAME := ~/backups/$(PROJECTNAME)-$(shell date +'%Y.%m.%d-%H:%M:%S').tar.gz)
	@echo
	@echo Writing Backup file to: $(MKBKUPNAME)
	@echo
	@-tar zcfv $(MKBKUPNAME) ../$(CURDIRNAME) 2> /dev/null
	@chmod 600 $(MKBKUPNAME)
	@echo
	@echo Done!
