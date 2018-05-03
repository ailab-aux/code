

RM = rm -f

all: xmltest

xmltest: xml.cc 
	g++ -std=c++11  -o $@ $^ -static -L/usr/local/lib -ltinyxml2

clean:
	-$(RM) xmltest

