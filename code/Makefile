CXX = g++
CXXFLAGS = -Wall -g
OBJPATH = obj
EXEPATH = bin/Debug
$(EXEPATH)/Pub.exe: $(OBJPATH)/main.o $(OBJPATH)/paper.o $(OBJPATH)/database.o $(OBJPATH)/user.o $(OBJPATH)/admin.o $(OBJPATH)/system.o
	$(CXX) $(CXXFLAGS) -o Pub.exe main.o paper.o database.o user.o admin.o system.o
$(OBJPATH)/main.o: main.cpp paper.h database.h user.h admin.h system.h
	$(CXX) $(CXXFLAGS) -c main.cpp
$(OBJPATH)/paper.o: paper.cpp paper.h
	$(CXX) $(CXXFLAGS) -c paper.cpp
$(OBJPATH)/database.o: database.cpp paper.h database.h user.h admin.h
	$(CXX) $(CXXFLAGS) -c database.cpp
$(OBJPATH)/user.o: user.cpp user.h system.h
	$(CXX) $(CXXFLAGS) -c user.cpp
$(OBJPATH)/admin.o: admin.cpp paper.h database.h user.h admin.h system.h
	$(CXX) $(CXXFLAGS) -c admin.cpp
$(OBJPATH)/system.o: system.cpp system.h database.h paper.h admin.h user.h
	$(CXX) $(CXXFLAGS) -c system.cpp
