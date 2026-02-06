#compiler used
CXX=g++

#compiler flag
CXXFLAG = --std=c++17 -Wall -Werror -Wextra -o

#file name
CXXFILENAME = src/two_link_fk.cpp

#Target file
Target = output

#all
all : $(Target)

$(Target):$(CXXFILENAME)
	$(CXX) $(CXXFLAG) $(Target) $(CXXFILENAME)

#clean file
clean: 
	rm -rf $(Target)